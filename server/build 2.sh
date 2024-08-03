#!/bin/bash

# Define the build directory
BUILD_DIR="./build"

# Navigate to the build directory or exit if it fails
cd "$BUILD_DIR" || { echo "Failed to navigate to build directory"; exit 1; }

# Remove all contents in the build directory
rm -rf *

# Run CMake configuration in the parent directory
cmake .. || { echo "CMake configuration failed"; exit 1; }

# Build the project
cmake --build . || { echo "Build failed"; exit 1; }

# Execute the built executable
./storeSpeedyDEMO || { echo "Execution failed"; exit 1; }
