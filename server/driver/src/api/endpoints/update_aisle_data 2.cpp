#include "update_aisle_data.h"
#include "StoreSpeedyJsonHandler.h"
#include "constants.h"  // Include constants
#include <chrono>
#include <thread>
#include <json/json.h>  // Include JSON library

void defineUpdateAisleDataEndpoint(crow::SimpleApp& app) {
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
}
