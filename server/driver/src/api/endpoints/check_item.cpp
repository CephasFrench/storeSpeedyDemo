#include "check_item.h"
//#include "your_required_headers.h"  // Include necessary headers here

void defineCheckItemEndpoint(crow::SimpleApp& app) {
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
                std::string response = callGeminiApiWithItem(item);
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
                                                    return crow::response("YES");
                                                } else {
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
}
