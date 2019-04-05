#include <iostream>
#include "tins/tins.h"
#include "wifiSniffer.h"



int main() {
    try {
        WifiSniffer sniffer;
        sniffer.run("wlan1");
    }
    catch(const std::exception& e) {
        std::cout << e.what();
    }
}