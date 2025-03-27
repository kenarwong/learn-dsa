#include "headers.h"
#include "Balanced234Tree.h"
#include <cassert>

void BTreeConstructorTests() {
  Balanced234Tree<int> tree1;
  assert(tree1.isEmpty());
  assert(tree1.getHeight() == 0);
  assert(tree1.getNumberOfNodes() == 0);

  Balanced234Tree<int> tree2(1);
  assert(!tree2.isEmpty());
  assert(tree2.getHeight() == 1);
  assert(tree2.getNumberOfNodes() == 1);

  tree1.clear();
  assert(tree1.isEmpty());
  assert(tree1.getHeight() == 0);
  assert(tree1.getNumberOfNodes() == 0);

  tree2.clear();
  assert(tree2.isEmpty());
  assert(tree2.getHeight() == 0);
  assert(tree2.getNumberOfNodes() == 0);

  std::cout << "BTreeConstructorTests passed." << std::endl;
}

void BTreeAddTests() {
  Balanced234Tree<int> tree1;
  int testInt1 = 15;
  assert(tree1.add(testInt1));
  assert(!tree1.isEmpty());
  assert(tree1.getHeight() == 1);
  assert(tree1.getNumberOfNodes() == 1);

  int testInt2 = 10;
  assert(tree1.add(testInt2));
  assert(tree1.getHeight() == 1);
  assert(tree1.getNumberOfNodes() == 1);

  int testInt3 = 5;
  assert(tree1.add(testInt3));
  assert(tree1.getHeight() == 1);
  assert(tree1.getNumberOfNodes() == 1);

  int testInt4 = 9;
  assert(tree1.add(testInt4));
  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 3);

  std::cout << "BTreeAddTests passed." << std::endl;
}

void BTreeTests() {
  std::cout << "Running BTreeTests..." << std::endl;

  BTreeConstructorTests();
  BTreeAddTests();

  std::cout << "BTreeTests passed." << std::endl;
}