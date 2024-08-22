#include "headers.h"
#include "GroceryBag.h"

/** 
  @post If successful, the contents of this bag and the contents of the parameter's bag are combined.
  @param bag A bag  
  @return A new bag that contains the contents of this bag and the parameter's bag.
 */
GroceryBag GroceryBag::bagUnion(const GroceryBag& bag) const {

  std::vector<std::string> newBagItems;

  // Add this bag's items
  for (auto item : this->toVector()) {
    newBagItems.push_back(item);
  }
  // Add parameter bag's items
  for (auto item : bag.toVector()) {
    newBagItems.push_back(item);
  }

  // Sort new bag vector
  std::sort(newBagItems.begin(), newBagItems.end());

  // Add to new bag
  GroceryBag newBag = GroceryBag();
  for (auto item : newBagItems) {
    newBag.add(item);
  }

  return newBag;
}

void Exercise6() {
  std::cout << "Exercise 6" << std::endl;

  GroceryBag bag1 = GroceryBag();
  bag1.add("a");
  bag1.add("b");
  bag1.add("c");

  GroceryBag bag2 = GroceryBag();
  bag2.add("b");
  bag2.add("b");
  bag2.add("d");
  bag2.add("e");

  GroceryBag newBag = bag1.bagUnion(bag2);

  std::vector<std::string> items = newBag.toVector();

  for (auto item : items) {
    std::cout << item << std::endl;
  }
}