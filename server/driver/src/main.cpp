#include "crow/crow_all.h"
#include "StoreSpeedyJsonHandler.h"
#include "api/api_util.h"
#include "compute_path.h"
#include "update_aisle_data.h"
#include "ping.h"
#include "update_location.h"
#include "grocery_list.h"
#include "update_grocery_list.h"
#include "check_item.h"
#include "constants.h"

#include "config.h"
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

void ensureDirectoryExists(const std::string& dir) {
    if(LOG_FUNC_CALLS) {
        std::cout << "ensureDirectoryExists() called" << std:: endl;
    }
    std::ifstream file(dir.c_str());
    if (!file) {
        std::system(("mkdir -p " + dir).c_str()); // Make a directory if it doesn't already exist
    }
}

void ensureFileExists(const std::string& filePath, const Json::Value& defaultValue) {
    if(LOG_FUNC_CALLS) {
        std::cout << "ensureFileExists() called" << std:: endl;
    }
    std::ifstream file(filePath);
    if (!file.good()) {
        std::ofstream outFile(filePath);
        outFile << defaultValue.toStyledString();
        outFile.close();
    }
}

crow::response handleError(const std::exception& e) {
    return crow::response(500, e.what());
}

Json::Value readJsonData(const std::string& filePath, const Json::Value& defaultValue) {
    if(LOG_FUNC_CALLS) {
        std::cout << "readJsonData() (in main.cpp) called" << std:: endl;
    }
    ensureFileExists(filePath, defaultValue);
    return StoreSpeedyJsonHandler::readJsonFile(filePath);
}

void validateGroceryListJson(const Json::Value& jsonData) {
    if (!jsonData.isMember("items") || !jsonData["items"].isArray()) {
        throw std::runtime_error("Invalid JSON structure: 'items' key missing or not an array.");
    }
}

void addItemToGroceryList(const std::string& userId, const std::string& location, const std::string& item) {
    if(LOG_FUNC_CALLS) {
        std::cout << "addItemToGroceryList() called" << std:: endl;
    }
    std::string filePath = storagePath + "users/" + userId + "/" + location + "_grocery_list.json";
    std::ifstream file(filePath, std::ifstream::binary);
    Json::Value root;

    if (file.is_open()) {
        file >> root;
        file.close();
    } else {
        root["items"] = Json::arrayValue;
    }

    // Check for duplicates
    for (const auto& existingItem : root["items"]) {
        if (existingItem.asString() == item) {
            return; // Item already exists, do nothing
        }
    }

    root["items"].append(item);

    std::ofstream outFile(filePath, std::ofstream::binary);
    outFile << root;
    outFile.close();
}

void defineRoutes(crow::SimpleApp& app) {
    defineComputePathEndpoint(app);
    defineUpdateAisleDataEndpoint(app);
    definePingEndpoint(app);
    defineUpdateLocationEndpoint(app);
    defineGroceryListEndpoint(app);
    defineUpdateGroceryListEndpoint(app);
    defineCheckItemEndpoint(app);
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
