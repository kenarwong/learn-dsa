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

  assert(tree2.contains(1));

  tree1.clear();
  assert(tree1.isEmpty());
  assert(tree1.getHeight() == 0);
  assert(tree1.getNumberOfNodes() == 0);

  tree2.clear();
  assert(tree2.isEmpty());
  assert(tree2.getHeight() == 0);
  assert(tree2.getNumberOfNodes() == 0);

  assert(!tree2.contains(1));

  std::cout << "BTreeConstructorTests passed." << std::endl;
}

void BTreeAddTests() {
  Balanced234Tree<int> tree1;
  int testInt1 = 25;
  assert(tree1.add(testInt1));
  assert(!tree1.isEmpty());
  assert(tree1.getHeight() == 1);
  assert(tree1.getNumberOfNodes() == 1);

  int testInt2 = 20;
  assert(tree1.add(testInt2));
  assert(tree1.getHeight() == 1);
  assert(tree1.getNumberOfNodes() == 1);

  int testInt3 = 5;
  assert(tree1.add(testInt3));
  assert(tree1.getHeight() == 1);
  assert(tree1.getNumberOfNodes() == 1);

  // split root
  int testInt4 = 1;
  assert(tree1.add(testInt4));
  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 3);

  int testInt5 = 2;
  assert(tree1.add(testInt5));
  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 3);

  // split left child
  int testInt6 = 3;
  assert(tree1.add(testInt6));
  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 4);

  int testInt7 = 4;
  assert(tree1.add(testInt7));
  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 4);

  // split middle child
  int testInt8 = 6;
  assert(tree1.add(testInt8));
  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 5);

  // split root
  int testInt9 = 7;
  assert(tree1.add(testInt9));
  assert(tree1.getHeight() == 3);
  assert(tree1.getNumberOfNodes() == 7);

  assert(tree1.contains(testInt1));
  assert(tree1.contains(testInt2));
  assert(tree1.contains(testInt3));
  assert(tree1.contains(testInt4));
  assert(tree1.contains(testInt5));
  assert(tree1.contains(testInt6));
  assert(tree1.contains(testInt7));
  assert(tree1.contains(testInt8));
  assert(tree1.contains(testInt9));

  // int expected[] = {4, 2, 1, 3, 20, 5, 6, 7, 25};
  // int expectedIndex = 0;
  // tree1.preorder([expected, &expectedIndex](int *items, int n) -> void {
  //   for(int i = 0; i < n; i++) {
  //     std::cout << items[i] << " ";
  //     assert(items[i] == expected[expectedIndex++]);
  //   }
  //   std::cout << std::endl;
  // });

  tree1.add(8);
  tree1.add(9);
  tree1.add(10);
  tree1.add(11);

  int expected[] = {4, 8, 2, 1, 3, 6, 5, 7, 20, 9, 10, 11, 25};
  int expectedIndex = 0;
  tree1.preorder([expected, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      std::cout << items[i] << " ";
      assert(items[i] == expected[expectedIndex++]);
    }
    std::cout << std::endl;
  });

  std::cout << "BTreeAddTests passed." << std::endl;
}

void BTreeTests() {
  std::cout << "Running BTreeTests..." << std::endl;

  BTreeConstructorTests();
  BTreeAddTests();

  std::cout << "BTreeTests passed." << std::endl;
}