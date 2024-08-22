#include "GroceryBag.cpp"
#include <iostream>
using namespace std;

void Exercise4() {
  // Set up the grocery list
  string groceries[] = {"apple", "bread", "eggs", "milk"};

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
  cout << "Grocery Bag: ";
  for (auto item : groceryBag.toVector()) {
    cout << item << " ";
  }
  cout << endl;

  cout << "Fragile Bag: ";
  for (auto item : fragileBag.toVector()) {
    cout << item << " ";
  }
  cout << endl;
}

/** 
  @pre The bag is not empty.
  @post If successful, all occurrences of item have been removed from the bag.
  @param bag The bag to search.
  @param item The item to count.
  @return The number of times item appears in bag.
 */
int removeAndcountOccurrences(GroceryBag& bag, const string& item) {
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
  // Set up grocery list
  string groceries[] = {"apple", "bread", "eggs", "bread", "milk"};

  // Create grocery bag
  GroceryBag groceryBag = GroceryBag();

  // Empty grocery bag use case
  cout << "The number of breads in the bag is: ";
  cout << removeAndcountOccurrences(groceryBag, "bread") << endl;

  // Add items to the grocery bag
  for (auto item : groceries) {
    groceryBag.add(item);
  }

  cout << "The number of breads in the bag is: ";
  cout << removeAndcountOccurrences(groceryBag, "bread") << endl;

  // No count of item in bag use case
  cout << "The number of muffins in the bag is: ";
  cout << removeAndcountOccurrences(groceryBag, "muffin") << endl;

  // Display the contents of the bag
  cout << "Grocery Bag: ";
  for (auto item : groceryBag.toVector()) {
    cout << item << " ";
  }
}

int main() {
  Exercise4();
  Exercise5();
  
  return 0;
}