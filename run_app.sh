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
    SERVER_DIR="/Users/cameronhardin/Desktop/storeSpeedyDemo/server"

    # Kill any process using port 8080
    kill_process_on_port 8080

    # Navigate to the server directory and run build.sh
    if [ ! -d "$SERVER_DIR" ]; then
        echo "Server directory does not exist: $SERVER_DIR"
        exit 1
    fi
    
    cd "$SERVER_DIR" || { echo "Failed to navigate to server directory"; exit 1; }
    if ! ./build.sh; then
        echo "Failed to build the backend"
        exit 1
    fi

    # Run the backend server in the background
    ./build/storeSpeedyPOC &
    BACKEND_PID=$!
}

# Function to start the frontend
start_frontend() {
    echo "Starting frontend..."
    APP_DIR="/Users/cameronhardin/Desktop/storeSpeedyDemo/app"

    # Kill any process using port 8081 and 8082
    kill_process_on_port 8081
    kill_process_on_port 8082

    # Navigate to the app directory and run run_front.sh
    if [ ! -d "$APP_DIR" ]; then
        echo "App directory does not exist: $APP_DIR"
        exit 1
    fi

    # Open a new interactive terminal window and run run_front.sh
    if command -v osascript > /dev/null; then
        # macOS specific command to open a new terminal window
        osascript <<EOF
tell application "Terminal"
    do script "cd $APP_DIR && ./run_front.sh"
end tell
EOF
    elif command -v gnome-terminal > /dev/null; then
        # Linux with GNOME Terminal
        gnome-terminal -- bash -c "cd $APP_DIR && ./run_front.sh; exec bash"
    elif command -v xterm > /dev/null; then
        # Generic X terminal emulator
        xterm -hold -e "cd $APP_DIR && ./run_front.sh"
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

# Start the backend and frontend concurrently
start_backend &
start_frontend &

wait # Wait for all background processes to complete

echo "App is running. Backend has been started. Frontend is starting in a new terminal window."
