/* ------------ *
 * WIFI SNIFFER *
 * ------------ */

#include <iostream>
#include <tins/tins.h>

#ifndef WIFISNIFFER_SNIFFER_H
#define WIFISNIFFER_SNIFFER_H


class WifiSniffer {
public:
    WifiSniffer();
    void run(const std::string& interface);
private:
    int sumOfNum(long long int& num);
    bool callback(Tins::PDU& pdu);
    void resultPrint(Tins::IP ip, Tins::EthernetII mac);
    std::string macVendor(Tins::EthernetII mac);
    Tins::DNS dns;
};


#endif //WIFISNIFFER_SNIFFER_H

