#include "crow/crow_all.h"
#include "StoreSpeedyJsonHandler.h"
#include "api/api_util.h"
#include "constants.h"
#include "api/endpoints/endpoints.h"

#include "config.h"
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <atomic>
#include <sstream>

// Atomic boolean to keep track of the server running state
std::atomic<bool> server_running{true};

int main() {
    crow::SimpleApp app;  // Create a Crow application
    defineRoutes(app);    // Define application routes

    int port = 8080;
    int max_port = 8100;  // Define the maximum port to try
    bool server_started = false;

    // Attempt to start the server on a port within the range
    while (!server_started && port <= max_port) {
        try {
            app.port(port).multithreaded().run();
            server_started = true;
            logMessage("Server started on port " + std::to_string(port));
        } catch (const boost::system::system_error& e) {
            if (e.code() == boost::system::errc::address_in_use) {
                logMessage("Port " + std::to_string(port) + " in use. Trying next port...");
            } else {
                logMessage("Exception: " + std::string(e.what()));
            }
            port++;
        } catch (const std::exception& e) {
            logMessage("Exception: " + std::string(e.what()));
            return 1;
        }
    }

    if (!server_started) {
        logMessage("No available ports found in the range 8080-8100.");
        return 1;
    }

    // Start a separate thread for the main server logic loop
    std::thread server_logic_thread([]() {
        while (server_running) {
            // Server logic: Add your server-side tasks here
            std::this_thread::sleep_for(std::chrono::seconds(10)); // Placeholder for periodic task

            // Periodic log statement
            logMessage("Server is running...");
        }
    });

    // Wait for the server logic thread to finish before exiting
    server_logic_thread.join();

    return 0;
}
