#include "headers.h"
#include "GroceryBag.h"

/** 
  @pre The bag is not empty.
  @post If successful, all occurrences of item have been removed from the bag.
  @param bag The bag to search.
  @param item The item to count.
  @return The number of times item appears in bag.
 */
int removeAndcountOccurrences(GroceryBag& bag, const std::string& item) {
  int count = 0;
  for (auto bagItem : bag.toVector()) {
    if (bagItem == item) {
      bag.remove(item);
      count++;
    }
  }

  return count;
}

void Exercise5() {
  std::cout << "Exercise 5" << std::endl;

  // Set up grocery list
  std::string groceries[] = {"apple", "bread", "eggs", "bread", "milk"};

  // Create grocery bag
  GroceryBag groceryBag = GroceryBag();

  // Empty grocery bag use case
  std::cout << "The number of breads in the bag is: ";
  std::cout << removeAndcountOccurrences(groceryBag, "bread") << std::endl;

  // Add items to the grocery bag
  for (auto item : groceries) {
    groceryBag.add(item);
  }

  std::cout << "The number of breads in the bag is: ";
  std::cout << removeAndcountOccurrences(groceryBag, "bread") << std::endl;

  // No count of item in bag use case
  std::cout << "The number of muffins in the bag is: ";
  std::cout << removeAndcountOccurrences(groceryBag, "muffin") << std::endl;

  // Display the contents of the bag
  std::cout << "Grocery Bag: ";
  for (auto item : groceryBag.toVector()) {
    std::cout << item << " ";
  }
 std::cout << std::endl;
}