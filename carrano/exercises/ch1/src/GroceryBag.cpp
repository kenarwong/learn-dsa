#include "headers.h"
#include "GroceryBag.h"

// Implement all virtual functions
int GroceryBag::getCurrentSize() const {
    return items.size();
}

bool GroceryBag::isEmpty() const {
    return items.empty();
}

bool GroceryBag::add(const std::string& newEntry) {
    items.push_back(newEntry);
    return true;
}

bool GroceryBag::remove(const std::string& anEntry) {
    auto it = std::find(items.begin(), items.end(), anEntry);
    if (it != items.end()) {
        items.erase(it);
        return true;
    }
    return false;
}

void GroceryBag::clear() {
    items.clear();
}

bool GroceryBag::contains(const std::string& anEntry) const {
    return std::find(items.begin(), items.end(), anEntry) != items.end();
    return true;
}

int GroceryBag::getFrequencyOf(const std::string& anEntry) const {
    return std::count(items.begin(), items.end(), anEntry);
    return true;
}

std::vector<std::string> GroceryBag::toVector() const {
    return items;
}