#ifndef ENDPOINTS_H
#define ENDPOINTS_H

#pragma once

#include "crow_all.h"
#include "StoreSpeedyJsonHandler.h"
#include "api_util.h"
#include "constants.h"
#include "config.h"
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

// Function to call the path_solver program
std::future<int> runPathSolver(const std::string& input) {
    return std::async(std::launch::async, [input]() {
        std::string command = "./server/programs/path_solver " + input;
        return std::system(command.c_str());
    });
}

// Utility function to log messages with timestamps
inline void logMessage(const std::string& message) {
    std::ostringstream oss;
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    oss << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S") << " - " << message;
    std::cout << oss.str() << std::endl;
}

inline void ensureDirectoryExists(const std::string& dir) {
    if(LOG_FUNC_CALLS) {
        std::cout << "ensureDirectoryExists() called" << std:: endl;
    }
    std::ifstream file(dir.c_str());
    if (!file) {
        std::system(("mkdir -p " + dir).c_str()); // Make a directory if it doesn't already exist
    }
}

inline void ensureFileExists(const std::string& filePath, const Json::Value& defaultValue) {
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

inline crow::response handleError(const std::exception& e) {
    return crow::response(500, e.what());
}


inline Json::Value readJsonData(const std::string& filePath, const Json::Value& defaultValue) {
    if(LOG_FUNC_CALLS) {
        std::cout << "readJsonData() (in main.cpp) called" << std:: endl;
    }
    ensureFileExists(filePath, defaultValue);
    return StoreSpeedyJsonHandler::readJsonFile(filePath);
}


inline void addItemToGroceryList(const std::string& userId, const std::string& location, const std::string& item) {
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

void validateGroceryListJson(const Json::Value& jsonData) {
    if (!jsonData.isMember("items") || !jsonData["items"].isArray()) {
        throw std::runtime_error("Invalid JSON structure: 'items' key missing or not an array.");
    }
}

inline void defineRoutes(crow::SimpleApp& app) {
    // Compute path endpoint
    CROW_ROUTE(app, "/compute_path").methods("GET"_method)
    ([]() {
        int retries = 0;
        std::string filePath = storagePath + "locations/" + currentLocation + "/aisles/aisle_data.json";

        while (retries < COMPUTE_PATH_MAX_RETRIES) {
            try {
                Json::Value jsonData = readJsonData(filePath, Json::Value(Json::objectValue));
                return crow::response{jsonData.toStyledString()};
            } catch (const std::exception& e) {
                std::cerr << "Error reading JSON data, attempt " << (retries + 1) << ": " << e.what() << std::endl;
                retries++;
                std::this_thread::sleep_for(std::chrono::milliseconds(COMPUTE_PATH_TIMEOUT_DURATION));
            }
        }
        return crow::response(500, "Failed to read JSON data after multiple attempts.");
    });

    // Update aisle data endpoint
    CROW_ROUTE(app, "/update_aisle_data").methods("POST"_method)
    ([](const crow::request& req) {
        int retries = 0;
        std::string filePath = storagePath + "locations/" + currentLocation + "/aisles/aisle_data.json";

        while (retries < UPDATE_AISLE_DATA_MAX_RETRIES) {
            try {
                Json::Value jsonData;
                std::istringstream iss(req.body);
                Json::CharReaderBuilder rbuilder;
                std::string errs;
                if (!Json::parseFromStream(rbuilder, iss, &jsonData, &errs)) {
                    return crow::response(400, "Invalid JSON");
                }
                if (!StoreSpeedyJsonHandler::validateAisleDataJson(jsonData)) {
                    return crow::response(400, "Invalid JSON structure for aisle data");
                }
                StoreSpeedyJsonHandler::writeJsonFile(filePath, jsonData);
                return crow::response(200);
            } catch (const std::exception& e) {
                std::cerr << "Error updating aisle data, attempt " << (retries + 1) << ": " << e.what() << std::endl;
                retries++;
                std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_AISLE_DATA_TIMEOUT_DURATION));
            }
        }
        return crow::response(500, "Failed to update aisle data after multiple attempts.");
    });

    // Ping endpoint
    CROW_ROUTE(app, "/ping").methods("GET"_method)
    ([]() {
        return crow::response(200, "Pong");
    });

    // Update location endpoint
    CROW_ROUTE(app, "/update_location").methods("POST"_method)
    ([](const crow::request& req) {
        int retries = 0;

        while (retries < UPDATE_LOCATION_MAX_RETRIES) {
            try {
                Json::Value jsonBody;
                std::istringstream iss(req.body);
                Json::CharReaderBuilder rbuilder;
                std::string errs;
                if (!Json::parseFromStream(rbuilder, iss, &jsonBody, &errs)) {
                    return crow::response(400, "Invalid JSON");
                }
                if (!jsonBody.isMember("location")) {
                    return crow::response(400, "Invalid JSON");
                }
                currentLocation = jsonBody["location"].asString();
                return crow::response(200);
            } catch (const std::exception& e) {
                std::cerr << "Error updating location, attempt " << (retries + 1) << ": " << e.what() << std::endl;
                retries++;
                std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_LOCATION_TIMEOUT_DURATION));
            }
        }
        return crow::response(500, "Failed to update location after multiple attempts.");
    });

    // Get user's grocery list endpoint
    CROW_ROUTE(app, "/grocery_list/<string>/<string>").methods("GET"_method) //<string><string> takes userID, location (frontend)
    ([](const std::string& userId, const std::string& location) {
        int retries = 0;
        std::string filePath = storagePath + "users/" + userId + "/" + location + "_grocery_list.json";

        while (retries < GROCERY_LIST_MAX_RETRIES) {
            try {
                std::ifstream file(filePath, std::ifstream::binary);
                if (!file.is_open()) {
                    // If the file doesn't exist, create it with an empty grocery list
                    Json::Value root;
                    root["items"] = Json::arrayValue;
                    std::ofstream outFile(filePath, std::ofstream::binary);
                    outFile << root.toStyledString();
                    outFile.close();

                    // Re-open the newly created file
                    file.open(filePath, std::ifstream::binary);
                    if (!file.is_open()) {
                        return crow::response(500, "Failed to create and open the grocery list file.");
                    }
                }

                Json::Value root;
                file >> root;
                file.close();

                if (!root.isMember("items") || !root["items"].isArray()) {
                    return crow::response(400, "Invalid JSON structure: 'items' key missing or not an array.");
                }

                Json::Value response;
                response["items"] = root["items"];
                std::cout << "Grocery list fetched successfully: " << response.toStyledString() << std::endl;
                return crow::response(response.toStyledString());
            } catch (const std::exception& e) {
                std::cerr << "Error reading grocery list, attempt " << (retries + 1) << ": " << e.what() << std::endl;
                retries++;
                std::this_thread::sleep_for(std::chrono::milliseconds(GROCERY_LIST_TIMEOUT_DURATION));
            }
        }
        return crow::response(500, "Failed to read grocery list after multiple attempts.");
    });

    // Update user's grocery list endpoint
    CROW_ROUTE(app, "/update_grocery_list/<string>/<string>").methods("POST"_method) //<string><string> takes userID, location (frontend)
    ([](const crow::request& req, const std::string& userId, const std::string& location) {
        int retries = 0;
        std::string filePath = storagePath + "users/" + userId + "/" + location + "_grocery_list.json";

        while (retries < UPDATE_GROCERY_LIST_MAX_RETRIES) {
            try {
                Json::Value jsonData;
                std::istringstream iss(req.body);
                Json::CharReaderBuilder rbuilder;
                std::string errs;

                if (!Json::parseFromStream(rbuilder, iss, &jsonData, &errs)) {
                    return crow::response(400, "Invalid JSON");
                }

                if (!jsonData.isMember("items") || !jsonData["items"].isArray()) { // Used to be its own method called validateGroceryListJson
                    throw std::runtime_error("Invalid JSON structure: 'items' key missing or not an array.");
                }

                StoreSpeedyJsonHandler::writeJsonFile(filePath, jsonData);
                std::cout << "Grocery list updated successfully." << std::endl;

                return crow::response(200);
            } catch (const std::exception& e) {
                std::cerr << "Error updating grocery list, attempt " << (retries + 1) << ": " << e.what() << std::endl;
                retries++;
                std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_GROCERY_LIST_TIMEOUT_DURATION));
            }
        }
        return crow::response(500, "Failed to update grocery list after multiple attempts.");
    });

    // Check item endpoint, prompts AI with item and adds if response is YES.
    CROW_ROUTE(app, "/check_item").methods("POST"_method)
    ([](const crow::request& req) {
        int retries = 0;

        while (retries < CHECK_ITEM_MAX_RETRIES) {
            try {
                Json::Value jsonBody;
                Json::CharReaderBuilder rbuilder;
                std::string errs;
                std::istringstream iss(req.body);
                if (!Json::parseFromStream(rbuilder, iss, &jsonBody, &errs)) {
                    return crow::response(400, "Invalid JSON");
                }
                if (!jsonBody.isMember("item")) {
                    return crow::response(400, "Missing 'item' field");
                }
                std::string item = jsonBody["item"].asString();
                std::cout << "ITEM IS: " << item << std::endl;
                std::string response = callGeminiApiWithItem(item); // AI call with item
                std::cout << "RESPONSE IS: " << response << std::endl;

                // Parse the response to check if the item is available
                Json::CharReaderBuilder readerBuilder;
                Json::Value jsonResponse;
                std::string parseErrors;
                std::istringstream responseStream(response);
                if (Json::parseFromStream(readerBuilder, responseStream, &jsonResponse, &parseErrors)) {
                    if (jsonResponse.isObject() && jsonResponse.isMember("candidates")) {
                        const Json::Value& candidates = jsonResponse["candidates"];
                        if (candidates.isArray() && !candidates.empty()) {
                            const Json::Value& content = candidates[0]["content"]["parts"];
                            if (content.isArray() && !content.empty()) {
                                std::string text = content[0]["text"].asString();

                                // Remove backticks and "json" keyword
                                size_t firstBacktick = text.find("```json\n");
                                if (firstBacktick != std::string::npos) {
                                    text.erase(firstBacktick, 7); // Remove "```json\n"
                                }
                                size_t lastBacktick = text.rfind("\n```");
                                if (lastBacktick != std::string::npos) {
                                    text.erase(lastBacktick, 4); // Remove "\n```"
                                }

                                // Parse the cleaned JSON text
                                Json::Value nestedJson;
                                std::istringstream nestedStream(text);
                                if (Json::parseFromStream(readerBuilder, nestedStream, &nestedJson, &parseErrors)) {
                                    if (nestedJson.isObject() && nestedJson.isMember("candidates")) {
                                        const Json::Value& nestedCandidates = nestedJson["candidates"];
                                        if (nestedCandidates.isArray() && !nestedCandidates.empty()) {
                                            const Json::Value& nestedContent = nestedCandidates[0]["content"]["parts"];
                                            if (nestedContent.isArray() && !nestedContent.empty()) {
                                                std::string nestedText = nestedContent[0]["text"].asString();
                                                std::cout << "Parsed nested text: " << nestedText << std::endl;
                                                if (nestedText == "YES") {
                                                    addItemToGroceryList("default", currentLocation, item); // Add item to the grocery list

                                                    //updateItemInfo();
                                                    //getItemInfo();

                                                    return crow::response("YES");
                                                } else {

                                                    //promptAIforAlternatinves();

                                                    return crow::response("NO");
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                std::cerr << "Failed to parse Gemini API response: " << parseErrors << std::endl;
                return crow::response(400, "Failed to parse response.");
            } catch (const std::exception& e) {
                std::cerr << "Error checking item, attempt " << (retries + 1) << ": " << e.what() << std::endl;
                retries++;
                std::this_thread::sleep_for(std::chrono::milliseconds(CHECK_ITEM_TIMEOUT_DURATION));
            }
        }
        return crow::response(500, "Failed to check item after multiple attempts.");
    });

    // PATH SOLVING ENDPOINT PLACEHOLDER
    // Define a new endpoint to run the path solver
    CROW_ROUTE(app, "/run_path_solver").methods("POST"_method)
    ([](const crow::request& req) {
        std::string input = req.body;
        logMessage("Received request to run path solver with input: " + input);
        auto result = runPathSolver(input);
        return crow::response(200, "Path solver started");
    });
}

#endif // ENDPOINTS_H
