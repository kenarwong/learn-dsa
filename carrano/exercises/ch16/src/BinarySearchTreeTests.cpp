#include <iostream>
#include <string>
#include "BinarySearchTree.h" 
#include <cassert>
#include <vector>
#include <functional>

void testaddAndContains() {
  BinarySearchTree<int> bst;
  bst.add(10);
  bst.add(5);
  bst.add(15);

  assert(bst.contains(10) == true);
  assert(bst.contains(5) == true);
  assert(bst.contains(15) == true);
  assert(bst.contains(20) == false);

  std::cout << "testaddAndContains passed!" << std::endl;
}

void testRemove() {
  BinarySearchTree<int> bst;
  bst.add(10);
  bst.add(5);
  bst.add(15);
  bst.remove(10);

  assert(bst.contains(10) == false);
  assert(bst.contains(5) == true);
  assert(bst.contains(15) == true);

  std::cout << "testRemove passed!" << std::endl;
}

void testInOrderTraversal() {
  BinarySearchTree<int> bst;
  bst.add(10);
  bst.add(5);
  bst.add(15);
  bst.add(3);
  bst.add(7);

  std::vector<int> expected = {3, 5, 7, 10, 15};
  size_t index = 0;
  std::function<void(std::shared_ptr<BinaryNode<int>>)>  visit = [&expected, &index](std::shared_ptr<BinaryNode<int>> curPtr) {
    int item = curPtr->getItem();
    std::cout << "Visiting: " << item << std::endl;

    assert(item == expected[index]);
    ++index;
  };
  
  bst.inorderTraverse(visit);

  assert(index == expected.size());

  std::cout << "testInOrderTraversal passed!" << std::endl;
}

int BinarySearchTreeTests() {
  testaddAndContains();
  testRemove();
  testInOrderTraversal();

  std::cout << "All tests passed!" << std::endl;
  return 0;
}
