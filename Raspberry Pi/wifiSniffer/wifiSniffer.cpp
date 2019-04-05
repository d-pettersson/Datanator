/* ------------ *
 * WIFI SNIFFER *
 * ------------ */

#include <algorithm>
#include <fstream>

#include "wifiSniffer.h"
#include "oscPack.h"


#define PRINT_OUT
//#define OSC_OUT

/* ------------------- *
 * Default constructor *
 * ------------------- */

WifiSniffer::WifiSniffer() = default;

/* --------------------------- *
 * Create config & run sniffer *
 * --------------------------- */

void WifiSniffer::run(const std::string& interface) {
    Tins::SnifferConfiguration config;
    config.set_promisc_mode(true);
    config.set_filter("");
    config.set_rfmon(true);

    Tins::Sniffer sniffer(interface, config);

#ifdef PRINT_OUT
    std::cout << "* ------------ * ---------------- *\n"
              << "* WIFI SNIFFER * Running on \033[1;32m" + interface + "\033[0m *\n"
              << "* ------------ * ---------------- *\n\n";
#endif


    sniffer.sniff_loop(make_sniffer_handler(this, &WifiSniffer::callback));
}

/* --------------------------------------- *
 * Get inner_pdus from RawPDU and use them *
 * --------------------------------------- */

bool WifiSniffer::callback(Tins::PDU &pdu) {

    // grab IP addresses from RawPDU
    Tins::IP ip = pdu.rfind_pdu<Tins::RawPDU>().to<Tins::IP>();

    // grab MAC addresses from RawPDU
    Tins::EthernetII mac = pdu.rfind_pdu<Tins::RawPDU>().to<Tins::EthernetII>();

    // grab TCP for src port
//    Tins::TCP tcp = pdu.rfind_pdu<Tins::RawPDU>().to<Tins::TCP>();


#ifdef PRINT_OUT

    // print results to console
    resultPrint(ip, mac);

#endif

#ifdef OSC_OUT

    // concat ip addr + mac addr
    std::string outputStr = ip.src_addr().to_string() + ' ' + mac.src_addr().to_string() + ' ' + ip.dst_addr().to_string() + ' ' + mac.dst_addr().to_string();

    std::string ipSrcAddr = ip.src_addr().to_string();
    std::string ipDstAddr = ip.dst_addr().to_string();
    std::string macSrcAddr = mac.src_addr().to_string();
    std::string macDstAddr = mac.dst_addr().to_string();

    // create new sender
    oscPack sendOsc;

//    std::regex dot("\\.");
//    ipSrcAddr = std::regex_replace(ipSrcAddr, dot, "");
//    long long int ipSrcInteger = std::stoll(ipSrcAddr);
//
//    int sum = sumOfNum(ipSrcInteger);
//
//    ipSrcAddr = std::to_string(sum);


    sendOsc.oscSender(outputStr, "/pi");

#endif

    return true;
}

/* ----------------------------- *
 * Print ips and MACs to console *
 * ----------------------------- */

void WifiSniffer::resultPrint(Tins::IP ip, Tins::EthernetII mac) {
    // format helpers
    int lenSrcIp = ip.src_addr().to_string().length();
    int lenDstIp = ip.dst_addr().to_string().length();

    std::string colSrc = "\033[1;32m";  // green formatting for source
    std::string colDst = "\033[1;31m";  // red formatting for destination
    std::string colEnd = "\033[0m";     // common end formatting string
    std::string tabSrc, tabDst;

    lenSrcIp < 11 ? tabSrc = "\t\t" : tabSrc = "\t";
    lenDstIp < 11 ? tabDst = "\t\t" : tabDst = "\t";

    std::string vendor = macVendor(mac);

    // print results
    std::cout << colSrc + "src: " + colEnd << ip.src_addr() << tabSrc << colSrc + "src mac: " + colEnd << mac.src_addr()// << colSrc + "\tsrc port: " + colEnd << tcp.sport()
              << colDst + "\t\tdst: " + colEnd << ip.dst_addr() << tabDst << colDst + "dst mac: " + colEnd << mac.dst_addr() << '\n' << colSrc + "src vendor: " + colEnd << vendor << '\n';
}

/* ----------------- *
 * MAC vendor lookup *
 * ----------------- */

std::string WifiSniffer::macVendor(Tins::EthernetII mac) {
    std::string line;

    std::string macSrcAddr = mac.src_addr().to_string();
    macSrcAddr.erase(std::remove(macSrcAddr.begin(), macSrcAddr.end(), ':'), macSrcAddr.end());
    macSrcAddr.erase(6,6);

    std::ifstream macVendorList;
    macVendorList.open("mac-vendor.txt");
    std::ofstream missingVendors;
    missingVendors.open ("missingVendors.txt", std::ios::app);

    while (getline(macVendorList, line)) {
        if (line.find(macSrcAddr) != std::string::npos) {
            line.erase(0, 7);
            return line;
        }
    }
    missingVendors << macSrcAddr << '\n';
    return "Unknown vendor";
}

/* -------------- *
 * Sum of numbers *
 * -------------- */

int WifiSniffer::sumOfNum(long long int& num) {
    long long int a = 0;
    int sum = 0;
    while (num > 0)
    {
        a = num % 10;
        num /= 10;
        sum += a;
    }
    return sum;
}