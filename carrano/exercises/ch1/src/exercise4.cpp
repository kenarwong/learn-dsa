#include "headers.h"
#include "GroceryBag.h"

void Exercise4() {
  std::cout << "Exercise 4" << std::endl;

  // Set up the grocery list
  std::string groceries[] = {"apple", "bread", "eggs", "milk"};

  // Add items to the GroceryBag
  GroceryBag storeBag = GroceryBag();
  for (auto item : groceries) {
    storeBag.add(item);
  }

  // Remove fragile items from groceryBag and place them in fragileBag
  storeBag.remove(groceries[1]);
  storeBag.remove(groceries[2]);

  GroceryBag fragileBag = GroceryBag();
  fragileBag.add(groceries[1]);
  fragileBag.add(groceries[2]);

  // Remove rest of items and place them in groceryBag
  GroceryBag groceryBag = GroceryBag();

  for (auto item : storeBag.toVector()) {
    storeBag.remove(item);
    groceryBag.add(item);
  }

  // Display the contents of the bags
  std::cout << "Grocery Bag: ";
  for (auto item : groceryBag.toVector()) {
    std::cout << item << " ";
  }
  std::cout << std::endl;

  std::cout << "Fragile Bag: ";
  for (auto item : fragileBag.toVector()) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}