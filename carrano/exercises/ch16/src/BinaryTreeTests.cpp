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

void testCountFunctions() {
  // Test on an empty tree
  BinaryNodeTree<int> tree;
  assert(tree.nodeCount(tree.getRootPtr()) == 0);
  assert(tree.edgeCount(tree.getRootPtr()) == 0);
  assert(tree.leafCount(tree.getRootPtr()) == 0);

  // Test on a 1 node tree
  tree.add(10);
  assert(tree.nodeCount(tree.getRootPtr()) == 1);
  assert(tree.edgeCount(tree.getRootPtr()) == 0);
  assert(tree.leafCount(tree.getRootPtr()) == 1);

  // Test on a 3 node tree
  tree.add(20);
  tree.add(30);
  assert(tree.nodeCount(tree.getRootPtr()) == 3);
  assert(tree.edgeCount(tree.getRootPtr()) == 2);
  assert(tree.leafCount(tree.getRootPtr()) == 2);

  // Test on a 4 node tree
  tree.add(40);
  assert(tree.nodeCount(tree.getRootPtr()) == 4);
  assert(tree.edgeCount(tree.getRootPtr()) == 3);
  assert(tree.leafCount(tree.getRootPtr()) == 2);

  // Test on a 5 node tree
  tree.add(50);
  assert(tree.nodeCount(tree.getRootPtr()) == 5);
  assert(tree.edgeCount(tree.getRootPtr()) == 4);
  assert(tree.leafCount(tree.getRootPtr()) == 2); // Balance add will produce 2 leaves

  // Test on a 6 node tree
  tree.add(60);
  assert(tree.nodeCount(tree.getRootPtr()) == 6);
  assert(tree.edgeCount(tree.getRootPtr()) == 5);
  assert(tree.leafCount(tree.getRootPtr()) == 3);

  // test on a 10 node tree
  // balancedAdd distributes nodes based on subtree height, with bias to the left subtree
  tree.add(70);
  tree.add(80);
  tree.add(90);
  tree.add(100);
  assert(tree.nodeCount(tree.getRootPtr()) == 10);  
  assert(tree.edgeCount(tree.getRootPtr()) == 9);   
  assert(tree.leafCount(tree.getRootPtr()) == 4); 


}

void testClosestCommonAncestor() {
  BinaryNodeTree<int> tree;

  // Test on an empty tree
  assert(tree.closestCommonAncestor(tree.getRootPtr(), nullptr, nullptr) == nullptr);

  // Test on a 1 node tree
  tree.add(10);
  assert(tree.closestCommonAncestor(tree.getRootPtr(), nullptr, nullptr) == nullptr);

  // Test on a 2 node tree
  tree.add(20);
  assert(tree.closestCommonAncestor(tree.getRootPtr(), tree.getRootPtr(), tree.getRootPtr()->getLeftChildPtr()) == tree.getRootPtr());
  assert(tree.closestCommonAncestor(tree.getRootPtr(), tree.getRootPtr()->getLeftChildPtr(), tree.getRootPtr()) == tree.getRootPtr());

  // Test on a 3 node tree
  tree.add(30);
  assert(tree.closestCommonAncestor(tree.getRootPtr(), tree.getRootPtr()->getLeftChildPtr(), tree.getRootPtr()->getRightChildPtr()) == tree.getRootPtr());
  assert(tree.closestCommonAncestor(tree.getRootPtr(), tree.getRootPtr()->getRightChildPtr(), tree.getRootPtr()->getLeftChildPtr()) == tree.getRootPtr());

  // Test on a 4 node tree
  tree.add(40);
  assert(tree.closestCommonAncestor(tree.getRootPtr(), tree.getRootPtr()->getLeftChildPtr(), tree.getRootPtr()->getRightChildPtr()) == tree.getRootPtr());
  assert(tree.closestCommonAncestor(tree.getRootPtr(), tree.getRootPtr()->getRightChildPtr(), tree.getRootPtr()->getLeftChildPtr()) == tree.getRootPtr());

  // Test on a 5 node tree
  tree.add(50);
  assert(tree.closestCommonAncestor(tree.getRootPtr(), tree.getRootPtr()->getLeftChildPtr(), tree.getRootPtr()->getRightChildPtr()) == tree.getRootPtr());
  assert(tree.closestCommonAncestor(tree.getRootPtr(), tree.getRootPtr()->getRightChildPtr(), tree.getRootPtr()->getLeftChildPtr()) == tree.getRootPtr());

  // Test on a 6 node tree
  // balancedAdd
  tree.add(60);
  std::shared_ptr<BinaryNode<int>> leftChild = tree.getRootPtr()->getLeftChildPtr();
  std::shared_ptr<BinaryNode<int>> leftLeftGrandChild = leftChild->getLeftChildPtr();
  std::shared_ptr<BinaryNode<int>> leftRightGrandChild = leftChild->getRightChildPtr();
  assert(tree.closestCommonAncestor(tree.getRootPtr(), leftLeftGrandChild, leftRightGrandChild) == leftChild);

  // Test on a 7 node tree
  // balancedAdd distributes nodes based on subtree height, with bias to the left subtree
  tree.add(70);
  std::shared_ptr<BinaryNode<int>> leftLeftLeftGreatGrandChild = leftLeftGrandChild->getLeftChildPtr();
  assert(tree.closestCommonAncestor(tree.getRootPtr(), leftLeftLeftGreatGrandChild, leftRightGrandChild) == leftChild);
}

int BinaryTreeTests() {
  testIntBinaryNodeTree();
  testStringBinaryNodeTree();
  testCountFunctions();
  testClosestCommonAncestor();

  std::cout << "All Binary Tree tests passed!" << std::endl;
  return 0;
}