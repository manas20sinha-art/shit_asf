#pragma once
#include <cstdint>
#include <string>

struct PacketInfo {
    uint32_t id;
    std::string timestamp;
    std::string srcIp;
    std::string dstIp;
    uint16_t srcPort;
    uint16_t dstPort;
    std::string protocol;
    uint32_t length;
};