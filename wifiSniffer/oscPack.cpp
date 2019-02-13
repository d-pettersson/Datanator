/* ----------- *
 * OSC RELATED *
 * ----------- */

#include <iostream>
#include <cstring>
#include "oscPack.h"
#include "oscpack/osc/OscOutboundPacketStream.h"
#include "oscpack/ip/UdpSocket.h"

/* ------------ *
 * OSC Settings *
 * ------------ */

#define ADDRESS "192.168.3.1"
#define PORT 57120
#define OUTPUT_BUFFER_SIZE 1024

/* ---------- *
 * OSC Sender *
 * ---------- */

void oscPack::oscSender(const std::string& input, const std::string& address) {
    // prepare transmission socket
    UdpTransmitSocket transmitSocket(IpEndpointName(ADDRESS, PORT));

    // create buffer for data
    char buffer[OUTPUT_BUFFER_SIZE];
    osc::OutboundPacketStream p(buffer, OUTPUT_BUFFER_SIZE);

    // convert str to *char
//    char *outputChar = strToChar(input);

    // send osc messages
    p << osc::BeginBundleImmediate
      << osc::BeginMessage(address.c_str())
      << input.c_str()
      << osc::EndMessage
      << osc::EndBundle;
    transmitSocket.Send(p.Data(), p.Size());

//    delete [] outputChar;
}

/* ---------------- *
 * Helper functions *
 * ---------------- */

//char *strToChar(const std::string& input) {
//    char *out = new char[input.length() + 1];
//    std::strcpy(out, input.c_str());
//    return out;
//}