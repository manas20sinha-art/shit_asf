cmake_minimum_required(VERSION 3.20)

if(WIN32 AND NOT MSVC)
    set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic" CACHE STRING "")
    set(VCPKG_HOST_TRIPLET "x64-mingw-dynamic" CACHE STRING "")
endif()

project(PCAPAnalyzer LANGUAGES C CXX VERSION 0.1.0)

# Enforce C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile commands for language servers / IDE IntelliSense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create Executable
add_executable(pcap_analyzer ${SOURCES})

# Include directories
target_include_directories(pcap_analyzer PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Find Packages installed via vcpkg
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(implot CONFIG REQUIRED)

# Linking Graphics & Windowing Libraries
target_link_libraries(pcap_analyzer PRIVATE 
    glfw
    glad::glad
    imgui::imgui
    implot::implot
)

# PCAP Library configuration (Cross-platform: Windows & Linux)
if(WIN32)
    # vcpkg provides unofficial-libpcap or npcap on Windows
    find_package(unofficial-libpcap CONFIG QUIET)
    if(unofficial-libpcap_FOUND)
        target_link_libraries(pcap_analyzer PRIVATE unofficial::libpcap::pcap)
    else()
        # Fallback to direct library search if using custom Npcap SDK
        find_library(PCAP_LIB NAMES pcap wpcap)
        if(PCAP_LIB)
            target_link_libraries(pcap_analyzer PRIVATE ${PCAP_LIB})
        endif()
    endif()
    
    # Win32 socket & system libraries required by PCAP / Networking
    target_link_libraries(pcap_analyzer PRIVATE ws2_32 iphlpapi opengl32)
else()
    # Linux system libraries & pcap
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(PCAP REQUIRED libpcap)
    target_include_directories(pcap_analyzer PRIVATE ${PCAP_INCLUDE_DIRS})
    target_link_libraries(pcap_analyzer PRIVATE ${PCAP_LIBRARIES} GL)
endif()

message(STATUS "Project configured successfully for ${CMAKE_SYSTEM_NAME}")
