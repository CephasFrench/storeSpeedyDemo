#ifndef GROCERY_LIST_UTIL_H
#define GROCERY_LIST_UTIL_H

#include <string>
#include <json/json.h>  // Include JSON library

void addItemToGroceryList(const std::string& userId, const std::string& location, const std::string& item);

#endif // GROCERY_LIST_UTIL_H
