#ifndef GROCERY_BAG_
#define GROCERY_BAG_

#include "BagInterface.h"
#include <string>
#include <algorithm>

// Classes that inherit abstract classes must define all virtual methods
// Otherwise they become abstract classes too

class GroceryBag : public BagInterface<std::string> {
  public:
    int getCurrentSize() const override;
    bool isEmpty() const override;
    bool add(const std::string& newEntry) override;
    bool remove(const std::string& anEntry) override;
    void clear() override;
    bool contains(const std::string& anEntry) const override;
    int getFrequencyOf(const std::string& anEntry) const override;
    std::vector<std::string> toVector() const override;
    GroceryBag bagUnion(const GroceryBag& bag) const;
  private:
    std::vector<std::string> items;
};

#endif