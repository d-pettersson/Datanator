#include <iostream>
#include "tins/tins.h"
#include "wifiSniffer.h"



int main() {
    WifiSniffer sniffer;
    sniffer.run("wlan1");
}