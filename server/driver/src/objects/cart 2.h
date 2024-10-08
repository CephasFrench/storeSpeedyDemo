#ifndef CART_H
#define CART_H

#include "item.h"
#include <vector>
#include <string>

class Cart {
public:
    void addItem(const Item& item);
    void removeItem(const std::string& itemName);
    std::vector<Item> getItems() const;

private:
    std::vector<Item> items;
};

#endif // CART_H
