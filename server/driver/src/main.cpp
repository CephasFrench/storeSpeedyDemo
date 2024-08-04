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


void validateGroceryListJson(const Json::Value& jsonData) {
    if (!jsonData.isMember("items") || !jsonData["items"].isArray()) {
        throw std::runtime_error("Invalid JSON structure: 'items' key missing or not an array.");
    }
}

int main() {
    crow::SimpleApp app;  // Create a Crow application
    defineRoutes(app);

    int port = 8080;
    int max_port = 8100;  // Define the maximum port to try
    bool server_started = false;

    while (!server_started && port <= max_port) {
        try {
            app.port(port).multithreaded().run();  // Try to run the Crow application on the specified port with multithreading enabled
            server_started = true;  // If successful, break out of the loop
        } catch (const boost::system::system_error& e) {
            if (e.code() == boost::system::errc::address_in_use) {
                // Suppress the specific exception message
                std::cerr << "Port " << port << " in use. Trying next port..." << std::endl;
            } else {
                // Print other exceptions
                std::cerr << "Exception: " << e.what() << std::endl;
            }
            port++;  // Try the next port
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
            return 1;
        }
    }

    if (!server_started) {
        std::cerr << "No available ports found in the range 8080-8100." << std::endl;
        return 1;
    }

    return 0;
}
