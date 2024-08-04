#include "update_grocery_list.h"
#include "StoreSpeedyJsonHandler.h"
#include "constants.h"  // Include constants
#include <chrono>
#include <thread>
#include <json/json.h>  // Include JSON library

void defineUpdateGroceryListEndpoint(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/update_grocery_list/<string>/<string>").methods("POST"_method)
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
                StoreSpeedyJsonHandler::validateGroceryListJson(jsonData);
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
}
