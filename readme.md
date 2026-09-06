PCAP Analyzer is a tool for analyzing PCAP files and visualizing network traffic

How to Run

* Windows
  From the project directory:

Configure the project:

cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE="C:/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake"

Build the project:

cmake --build build

Run the program:

.\build\Debug\pcap_analyzer.exe

Make sure to replace C:/path/to/vcpkg with your actual vcpkg path.

* macOS / Linux
  From the project directory:

Configure the project:

cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake

Build the project:

cmake --build build

Run the program:

./build/pcap_analyzer

Again, replace /path/to/vcpkg with your vcpkg installation path

Dependencies
To build and run this project, you’ll need:

* CMake
* A C++ compiler
* vcpkg
* GLFW3
* GLAD
* Dear ImGui
* ImPlot
* libpcap

Project Status

* Basic project structure for the analyzer
* OpenGL rendering environment
* GLFW for window creation and management
* GLAD for loading OpenGL functions
* Dear ImGui for the GUI
* ImPlot for graphs/visualizations
* libpcap added as a dependency (for later PCAP analysis)
* CMake build configuration
* vcpkg for dependency management

Till now , it just sets up the rendering environment and GUI. The next step will be adding actual PCAP analysis and showing data in graphs.
