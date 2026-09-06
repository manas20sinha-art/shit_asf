#pragma once

#include "PacketData.hpp"
#include <vector>

// Forward declarations or direct includes for GLFW
struct GLFWwindow;

class DashboardUI {
public:
    DashboardUI() = default;
    ~DashboardUI() = default;

    // Initializes ImGui and ImPlot contexts
    void init(GLFWwindow* window);

    // Renders the main dashboard interface each frame
    void render(const std::vector<PacketInfo>& packets);

    // Cleans up ImGui backends
    void shutdown();

private:
    void renderPacketTable(const std::vector<PacketInfo>& packets);
    void renderProtocolChart(const std::vector<PacketInfo>& packets);
};