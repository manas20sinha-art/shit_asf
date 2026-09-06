#pragma once
#include "PacketData.hpp"
#include <vector>
#include <string>

class PcapParser {
public:
    PcapParser() = default;
    ~PcapParser() = default;

    bool openFile(const std::string& filepath);
    void parsePackets();

    const std::vector<PacketInfo>& getPackets() const { return m_packets; }

private:
    std::vector<PacketInfo> m_packets;
};