cmake_minimum_required(VERSION 3.10)
project(StoreSolver VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Use file(GLOB ...) to collect all .cpp files in the source directory
file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Add the executable target with the collected source files
add_executable(StoreSolver ${SRC_FILES})

# Set the C++ standard for the target
set_property(TARGET StoreSolver PROPERTY CXX_STANDARD 20)
