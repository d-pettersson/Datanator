/* ----------- *
 * OSC RELATED *
 * ----------- */

#include <iostream>
#include <oscpack/osc/OscTypes.h>

#ifndef WIFISNIFFER_OSCPACK_H
#define WIFISNIFFER_OSCPACK_H


struct oscPack {
    void oscSender(const std::string& input, const std::string& address);
};


/* ---------------- *
 * Helper functions *
 * ---------------- */

//char *strToChar(const std::string& input); // convert str to char array


#endif //WIFISNIFFER_OSCPACK_H
