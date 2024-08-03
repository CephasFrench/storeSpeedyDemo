#include "grocery_list.h"
#include "StoreSpeedyJsonHandler.h"
#include "constants.h"  // Include constants
#include <chrono>
#include <thread>
#include <json/json.h>  // Include JSON library

void defineGroceryListEndpoint(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/grocery_list/<string>/<string>").methods("GET"_method)
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
}
