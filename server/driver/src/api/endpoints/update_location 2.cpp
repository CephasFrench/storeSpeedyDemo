#include "update_location.h"
#include "StoreSpeedyJsonHandler.h"
#include "constants.h"  // Include constants
#include <chrono>
#include <thread>
#include <json/json.h>  // Include JSON library

void defineUpdateLocationEndpoint(crow::SimpleApp& app) {
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
}
