#!/bin/bash

# Function to check for updates
check_for_updates() {
    read -p "Do you want to check for updates in necessary libraries and packages? (y/n): " -r
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        echo "Checking for updates in necessary libraries and packages..."
        if command -v brew > /dev/null; then
            brew update && brew upgrade
        fi
        if command -v apt-get > /dev/null; then
            sudo apt-get update && sudo apt-get upgrade -y
        fi
        if command -v npm > /dev/null; then
            npm update
        fi
    else
        echo "Skipping updates."
    fi
}

# Function to kill processes using a specific port
kill_process_on_port() {
    PORT=$1
    if command -v lsof > /dev/null; then
        lsof -ti tcp:$PORT | xargs kill -9
    elif command -v netstat > /dev/null; then
        fuser -k "$PORT"/tcp
    else
        echo "Neither lsof nor netstat is available to kill processes on port $PORT"
        exit 1
    fi
}

# Function to start the backend
start_backend() {
    echo "Starting backend..."

    BACKEND_DIR="$(pwd)/backEnd/src"
    BUILD_DIR="$BACKEND_DIR/build"

    # Kill any process using port 8080
    kill_process_on_port 8080

    # Check if the backend directory exists
    if [ ! -d "$BACKEND_DIR" ]; then
        echo "Backend directory does not exist: $BACKEND_DIR"
        exit 1
    fi
    
    # Check if CMakeLists.txt exists
    if [ ! -f "$BACKEND_DIR/CMakeLists.txt" ]; then
        echo "CMakeLists.txt not found in $BACKEND_DIR"
        exit 1
    fi

    # Navigate to the backend directory
    cd "$BACKEND_DIR" || { echo "Failed to navigate to backend directory"; exit 1; }

    # Clean, configure, build, and run the backend
    rm -rf "$BUILD_DIR"
    mkdir -p "$BUILD_DIR"
    cd "$BUILD_DIR" || { echo "Failed to navigate to build directory"; exit 1; }

    # Manually set the source directory for CMake
    if ! cmake "$BACKEND_DIR"; then
        echo "CMake configuration failed"
        exit 1
    fi

    if ! cmake --build .; then
        echo "Build failed"
        exit 1
    fi

    # Run the backend server
    if ! ./storeSpeedyPOC & then
        echo "Failed to start backend server"
        exit 1
    fi
    BACKEND_PID=$!

    # Return to the root directory
    cd ../../../..
}

# Function to start the frontend
start_frontend() {
    echo "Starting frontend..."

    # Use the absolute path to the frontEnd directory
    FRONTEND_DIR="/Users/cameronhardin/Desktop/storeSpeedyPOC/frontEnd"

    # Kill any process using port 8081 and 8082
    kill_process_on_port 8081
    kill_process_on_port 8082

    # Navigate to the frontend directory
    if [ ! -d "$FRONTEND_DIR" ]; then
        echo "Frontend directory does not exist: $FRONTEND_DIR"
        exit 1
    fi

    # Install frontend dependencies
    echo "Installing frontend dependencies..."
    cd "$FRONTEND_DIR" || { echo "Failed to navigate to frontend directory"; exit 1; }
    if ! npm install; then
        echo "Failed to install frontend dependencies"
        exit 1
    fi

    # Open a new terminal window and run npx expo start
    if command -v osascript > /dev/null; then
        # macOS specific command to open a new terminal window
        osascript <<EOF
tell application "Terminal"
    do script "cd $FRONTEND_DIR && npx expo start --port 8082"
end tell
EOF
    elif command -v gnome-terminal > /dev/null; then
        # Linux with GNOME Terminal
        gnome-terminal -- bash -c "cd $FRONTEND_DIR && npx expo start --port 8082; exec bash"
    elif command -v xterm > /dev/null; then
        # Generic X terminal emulator
        xterm -hold -e "cd $FRONTEND_DIR && npx expo start --port 8082"
    else
        echo "No compatible terminal emulator found to open a new window for the frontend."
        exit 1
    fi
}

# Ensure the script runs in an interactive terminal
if [ -t 1 ]; then
    echo "Running in an interactive terminal."
else
    echo "This script must be run in an interactive terminal."
    exit 1
fi

# Ask the user whether to check for updates
check_for_updates

# Trap to kill background processes on script exit
trap "if [ ! -z $BACKEND_PID ]; then kill $BACKEND_PID; fi" EXIT

# Start the backend and frontend
start_backend
start_frontend

echo "App is running. Backend has been started. Frontend is starting in a new terminal window."
