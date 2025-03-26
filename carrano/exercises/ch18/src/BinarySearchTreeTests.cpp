#include <iostream>
#include <string>
#include "BinarySearchTree.h" 
#include <cassert>
#include <vector>
#include <functional>

void testBinarySearchTreeAddAndContains() {
  BinarySearchTree<int> bst;
  bst.add(10);
  bst.add(5);
  bst.add(15);

  assert(bst.contains(10) == true);
  assert(bst.contains(5) == true);
  assert(bst.contains(15) == true);
  assert(bst.contains(20) == false);
}

void testBinarySearchTreeRemove() {
  BinarySearchTree<int> bst;
  bst.add(10);
  bst.add(5);
  bst.add(15);
  bst.remove(10);

  // Test basic remove
  assert(bst.contains(10) == false);
  assert(bst.contains(5) == true);
  assert(bst.contains(15) == true);

  // Clear
  bst.clear();
  assert(bst.isEmpty() == true);

  std::vector<int> items = {42, 17, 23, 8, 34, 56, 3, 29, 11, 19, 27, 31, 45, 50, 6, 1, 14, 21, 38, 49};
  for (int item : items) {
    bst.add(item);
  }

  for (int item : items) {
    assert(bst.contains(item) == true);
  }

  // Test failed remove
  int itemToRemove = 99;  // Does not exist in tree
  assert(bst.contains(itemToRemove) == false);

  assert(bst.remove(itemToRemove) == false);
  for (int item : items) {
    assert(bst.contains(item) == true);
  }

  // Remove random item
  int randInt = rand() % 20;
  itemToRemove = items[randInt];

  assert(bst.remove(itemToRemove) == true);
  for (int item : items) {
    bst.contains(item) == (item == itemToRemove);
  }
}

void testBinarySearchTreeInOrderTraversal() {
  BinarySearchTree<int> bst;
  bst.add(10);
  bst.add(5);
  bst.add(15);
  bst.add(3);
  bst.add(7);

  std::vector<int> expected = {3, 5, 7, 10, 15};
  size_t index = 0;
  std::function<void(std::shared_ptr<BinaryNode<int>>)> visit = [&expected, &index](std::shared_ptr<BinaryNode<int>> curPtr) {
    int item = curPtr->getItem();
    // std::cout << "Visiting: " << item << std::endl;

    assert(item == expected[index]);
    ++index;
  };
  
  bst.inorderTraverse(visit);

  assert(index == expected.size());
}

void testBinarySearchTreeGetEntry()
{
  BinarySearchTree<int> bst;
  bst.add(10);
  bst.add(5);
  bst.add(15);
  bst.add(3);
  bst.add(7);

  // Test existing entries
  assert(bst.getEntry(10) == 10);
  assert(bst.getEntry(5) == 5);
  assert(bst.getEntry(15) == 15);
  assert(bst.getEntry(3) == 3);
  assert(bst.getEntry(7) == 7);

  // Test non-existing entry
  try
  {
    bst.getEntry(20);
    assert(false); // Should not reach here
  }
  catch (const std::runtime_error &e)
  {
    assert(true); // Exception should be thrown
  }
}

int BinarySearchTreeTests() {
  testBinarySearchTreeAddAndContains();
  testBinarySearchTreeRemove();
  testBinarySearchTreeInOrderTraversal();
  testBinarySearchTreeGetEntry();

  std::cout << "All Binary Search Tree tests passed!" << std::endl;
  return 0;
}
