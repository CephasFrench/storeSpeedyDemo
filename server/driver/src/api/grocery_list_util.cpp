#include "grocery_list_util.h"
#include "StoreSpeedyJsonHandler.h"
#include "constants.h"
#include <fstream>
#include <iostream>

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
