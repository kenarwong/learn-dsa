#include <iostream>
#include <string>
#include "BinaryNodeTree.h" 
#include <cassert>

void testIntBinaryNodeTree() {
  BinaryNodeTree<int> tree;

  // Test isEmpty on an empty tree
  assert(tree.isEmpty() == true);

  // Test add method
  tree.add(10);
  tree.add(20);
  tree.add(30);
  tree.add(40);
  tree.add(50);
  assert(tree.isEmpty() == false);

  tree.clear();
  assert(tree.isEmpty() == true);

  // Test remove on 1 node tree
  tree.add(10);

  assert(tree.remove(10) == true);
  assert(tree.contains(10) == false);
  assert(tree.isEmpty() == true);

  // Test on a 3 node tree
  tree.add(10);
  tree.add(20);
  tree.add(30);

  // Test getHeight method
  assert(tree.getHeight() == 2);

  // Test getNumberOfNodes method
  assert(tree.getNumberOfNodes() == 3);

  // Test contains method
  assert(tree.contains(10) == true);
  assert(tree.contains(1) == false);

  // Test remove method
  assert(tree.remove(20) == true);
  assert(tree.contains(10) == true);
  assert(tree.contains(20) == false);
  assert(tree.contains(30) == true);
  assert(tree.isEmpty() == false);

  tree.clear();
  assert(tree.isEmpty() == true);

  // Test on a 5 node tree
  tree.add(10);
  tree.add(20);
  tree.add(30);
  tree.add(40);
  tree.add(50);

  // Test remove method
  assert(tree.remove(30) == true);
  assert(tree.contains(10) == true);
  assert(tree.contains(20) == true);
  assert(tree.contains(30) == false);
  assert(tree.contains(40) == true);
  assert(tree.contains(50) == true);
  assert(tree.isEmpty() == false);

  tree.clear();
  assert(tree.isEmpty() == true);

  // Test delete of node with two children
  tree.add(10);
  tree.add(20);
  tree.add(30);
  tree.add(40);
  tree.add(50);

  // Test remove method
  assert(tree.remove(10) == true);
  assert(tree.contains(10) == false);
  assert(tree.contains(20) == true);
  assert(tree.contains(30) == true);
  assert(tree.contains(40) == true);
  assert(tree.contains(50) == true);
  assert(tree.isEmpty() == false);

  tree.clear();
  assert(tree.isEmpty() == true);
}

void testStringBinaryNodeTree() {
  BinaryNodeTree<std::string> tree;

  // Test isEmpty on an empty tree
  assert(tree.isEmpty() == true);

  // Test add method
  tree.add("hello");
  assert(tree.isEmpty() == false);

  // Test getHeight method
  assert(tree.getHeight() == 1);

  // Test getNumberOfNodes method
  assert(tree.getNumberOfNodes() == 1);

  // Test contains method
  assert(tree.contains("hello") == true);
  assert(tree.contains("world") == false);

  // Test remove method
  assert(tree.remove("hello") == true);
  assert(tree.isEmpty() == true);
}

int BinaryTreeTests() {
  testIntBinaryNodeTree();
  testStringBinaryNodeTree();

  std::cout << "All tests passed!" << std::endl;
  return 0;
}