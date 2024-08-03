#include "compute_path.h"
#include "StoreSpeedyJsonHandler.h"
#include "constants.h"  // Include constants
#include <chrono>
#include <thread>

void defineComputePathEndpoint(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/compute_path").methods("GET"_method)
    ([]() {
        int retries = 0;
        std::string filePath = storagePath + "locations/" + currentLocation + "/aisles/aisle_data.json";

        while (retries < COMPUTE_PATH_MAX_RETRIES) {
            try {
                Json::Value jsonData = StoreSpeedyJsonHandler::readJsonFile(filePath);
                return crow::response{jsonData.toStyledString()};
            } catch (const std::exception& e) {
                std::cerr << "Error reading JSON data, attempt " << (retries + 1) << ": " << e.what() << std::endl;
                retries++;
                std::this_thread::sleep_for(std::chrono::milliseconds(COMPUTE_PATH_TIMEOUT_DURATION));
            }
        }
        return crow::response(500, "Failed to read JSON data after multiple attempts.");
    });
}
