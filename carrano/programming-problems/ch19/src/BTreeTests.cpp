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
      // std::cout << items[i] << " ";
      assert(items[i] == expected[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  std::cout << "BTreeAddTests passed." << std::endl;
}

void BTreeLeafNodeRemoveTests() {
  Balanced234Tree<int> tree1;

  assert(tree1.remove(1) == false);
  
  tree1.add(1);
  tree1.add(2);
  tree1.add(3);
  assert(tree1.getHeight() == 1);
  assert(tree1.getNumberOfNodes() == 1);
  assert(tree1.contains(1));
  assert(tree1.contains(2));
  assert(tree1.contains(3));

  assert(tree1.remove(4) == false);
  assert(tree1.getHeight() == 1);
  assert(tree1.getNumberOfNodes() == 1);
  assert(tree1.contains(1));
  assert(tree1.contains(2));
  assert(tree1.contains(3));

  tree1.remove(1);
  assert(tree1.getHeight() == 1);
  assert(tree1.getNumberOfNodes() == 1);
  assert(!tree1.contains(1));
  assert(tree1.contains(2));
  assert(tree1.contains(3));

  tree1.remove(2);
  assert(tree1.getHeight() == 1);
  assert(tree1.getNumberOfNodes() == 1);
  assert(!tree1.contains(1));
  assert(!tree1.contains(2));
  assert(tree1.contains(3));

  tree1.remove(3);
  assert(tree1.getHeight() == 0);
  assert(tree1.getNumberOfNodes() == 0);

  tree1.add(1);
  tree1.add(2);
  tree1.add(3);
  tree1.add(4);
  assert(tree1.getHeight() == 2);
  tree1.add(5);
  assert(tree1.getHeight() == 2);

  tree1.remove(5);
  assert(tree1.getHeight() == 2);
  tree1.remove(4);
  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 3);

  tree1.clear();
  assert(tree1.isEmpty());
  assert(tree1.getHeight() == 0);
  assert(tree1.getNumberOfNodes() == 0);

  tree1.add(5);
  tree1.add(4);
  tree1.add(3);
  tree1.add(2);
  assert(tree1.getHeight() == 2);
  tree1.add(1);
  assert(tree1.getHeight() == 2);

  tree1.remove(1);
  assert(tree1.getHeight() == 2);
  tree1.remove(2);
  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 3);

  tree1.clear();
  assert(tree1.isEmpty());
  assert(tree1.getHeight() == 0);
  assert(tree1.getNumberOfNodes() == 0);

  tree1.add(1);
  tree1.add(5);
  tree1.add(10);
  tree1.add(2);
  tree1.add(3);
  assert(tree1.getHeight() == 2);
  tree1.add(8);
  tree1.add(9);
  assert(tree1.getHeight() == 2);
  tree1.add(4);
  tree1.add(6);
  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 5);

  int expected[] = {2, 5, 9, 1, 3, 4, 6, 8, 10};
  int expectedIndex = 0;
  tree1.preorder([expected, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  tree1.remove(4);
  tree1.remove(6);
  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 5);

  std::cout << "BTreeLeafNodeRemoveTests passed." << std::endl;
}

void BTreeFuseTests() {
  Balanced234Tree<int> tree1;
  
  int addOrder[] = {1, 5, 10, 2, 3, 8, 9, 4, 6};
  for(int i = 0; i < 9; i++) {
    tree1.add(addOrder[i]);
  }
  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 5);

  int expected[] = {2, 5, 9, 1, 3, 4, 6, 8, 10};
  int expectedIndex = 0;
  tree1.preorder([expected, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  tree1.add(7);
  assert(tree1.getHeight() == 3);
  assert(tree1.getNumberOfNodes() == 7);

  // fuse root
  assert(tree1.remove(5));

  int expected2[] = {2, 4, 9, 1, 3, 6, 7, 8, 10};
  expectedIndex = 0;
  tree1.preorder([expected2, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected2[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 5);

  tree1.add(5);

  int expected3[] = {4, 2, 1, 3, 7, 9, 5, 6, 8, 10};
  expectedIndex = 0;
  tree1.preorder([expected3, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected3[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 3);
  assert(tree1.getNumberOfNodes() == 8);

  // pre-emptive fuse right sibling
  assert(tree1.remove(1));

  int expected4[] = {7, 4, 2, 3, 5, 6, 9, 8, 10};
  expectedIndex = 0;
  tree1.preorder([expected4, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected4[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 3);
  assert(tree1.getNumberOfNodes() == 7);

  // pre-emptive fuse left sibling
  assert(tree1.remove(10));

  int expected5[] = {4, 7, 2, 3, 5, 6, 8, 9};
  expectedIndex = 0;
  tree1.preorder([expected5, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected5[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 4);

  tree1.remove(3);
  tree1.remove(6);

  int expected6[] = {4, 7, 2, 5, 8, 9};
  expectedIndex = 0;
  tree1.preorder([expected6, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected6[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 4);

  // fuse root item (no new root)
  assert(tree1.remove(4));

  int expected7[] = {7, 2, 5, 8, 9};
  expectedIndex = 0;
  tree1.preorder([expected7, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected7[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 3);

  tree1.remove(5);
  tree1.remove(9);

  int expected8[] = {7, 2, 8};
  expectedIndex = 0;
  tree1.preorder([expected8, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected8[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 3);

  // pre-emptive fuse (new root)
  assert(tree1.remove(2));

  int expected9[] = {7, 8};
  expectedIndex = 0;
  tree1.preorder([expected9, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected9[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 1);
  assert(tree1.getNumberOfNodes() == 1);

  std::cout << "BTreeFuseTests passed." << std::endl;
}

void BTreeRotateTests() {

  Balanced234Tree<int> tree1;
  
  int addOrder[] = {1, 5, 10, 2, 3, 8, 9, 4, 6};
  for(int i = 0; i < 9; i++) {
    tree1.add(addOrder[i]);
  }
  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 5);

  int expected[] = {2, 5, 9, 1, 3, 4, 6, 8, 10};
  int expectedIndex = 0;
  tree1.preorder([expected, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 5);

  // rotate left (leaf)
  assert(tree1.remove(1));

  int expected2[] = {3, 5, 9, 2, 4, 6, 8, 10};
  expectedIndex = 0;
  tree1.preorder([expected2, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected2[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 5);

  // rotate right (leaf)
  assert(tree1.remove(10));

  int expected3[] = {3, 5, 8, 2, 4, 6, 9};
  expectedIndex = 0;
  tree1.preorder([expected3, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected3[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 5);

  tree1.add(10);
  tree1.add(11);
  tree1.add(12);
  tree1.add(1);

  int expected4[] = {5, 3, 1, 2, 4, 8, 10, 6, 9, 11, 12};
  expectedIndex = 0;
  tree1.preorder([expected4, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected4[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 3);
  assert(tree1.getNumberOfNodes() == 8);

  // rotate left (internal)
  assert(tree1.remove(1));

  int expected5[] = {8, 3, 5, 2, 4, 6, 10, 9, 11, 12};
  expectedIndex = 0;
  tree1.preorder([expected5, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected5[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 3);
  assert(tree1.getNumberOfNodes() == 8);

  // rotate right (internal)
  assert(tree1.remove(12));

  int expected6[] = {5, 3, 2, 4, 8, 10, 6, 9, 11};
  expectedIndex = 0;
  tree1.preorder([expected6, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected6[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 3);
  assert(tree1.getNumberOfNodes() == 8);

  std::cout << "BTreeRotateTests passed." << std::endl;
}

void BTreeInorderTests() {
  Balanced234Tree<int> tree1;
  
  int addOrder[] = {1, 5, 10, 2, 3, 8, 9, 4, 6};
  for(int i = 0; i < 9; i++) {
    tree1.add(addOrder[i]);
  }
  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 5);

  int expected[] = {2, 5, 9, 1, 3, 4, 6, 8, 10};
  int expectedIndex = 0;
  tree1.preorder([expected, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 5);

  // inorder predecessor (leaf)
  assert(tree1.remove(5));

  int expected2[] = {2, 4, 9, 1, 3, 6, 8, 10};
  expectedIndex = 0;
  tree1.preorder([expected2, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected2[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 5);

  // inorder successor (leaf)
  assert(tree1.remove(4));

  int expected3[] = {2, 6, 9, 1, 3, 8, 10};
  expectedIndex = 0;
  tree1.preorder([expected3, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected3[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 2);
  assert(tree1.getNumberOfNodes() == 5);

  tree1.clear();
  assert(tree1.isEmpty());
  assert(tree1.getHeight() == 0);
  assert(tree1.getNumberOfNodes() == 0);

  int addOrder2[] = {1, 100, 50, 25, 75, 45, 55, 35, 65, 15, 85, 5, 95, 2, 99};
  for(int i = 0; i < 15; i++) {
    tree1.add(addOrder2[i]);
  }

  int expected4[] = {50, 5, 25, 1, 2, 15, 35, 45, 75, 95, 55, 65, 85, 99, 100};
  expectedIndex = 0;
  tree1.preorder([expected4, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected4[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 3);
  assert(tree1.getNumberOfNodes() == 9);

  // inorder predecessor (internal)
  assert(tree1.remove(50));

  int expected5[] = {45, 5, 25, 1, 2, 15, 35, 75, 95, 55, 65, 85, 99, 100};
  expectedIndex = 0;
  tree1.preorder([expected5, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected5[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 3);
  assert(tree1.getNumberOfNodes() == 9);

  tree1.remove(35);

  int expected6[] = {45, 5, 1, 2, 15, 25, 75, 95, 55, 65, 85, 99, 100};
  expectedIndex = 0;
  tree1.preorder([expected6, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected6[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 3);
  assert(tree1.getNumberOfNodes() == 8);

  // inorder successor (internal)
  assert(tree1.remove(45));

  int expected7[] = {55, 5, 1, 2, 15, 25, 75, 95, 65, 85, 99, 100};
  expectedIndex = 0;
  tree1.preorder([expected7, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected7[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 3);
  assert(tree1.getNumberOfNodes() == 8);

  tree1.remove(55);

  int expected8[] = {65, 5, 1, 2, 15, 25, 95, 75, 85, 99, 100};
  expectedIndex = 0;
  tree1.preorder([expected8, &expectedIndex](int *items, int n) -> void {
    for(int i = 0; i < n; i++) {
      // std::cout << items[i] << " ";
      assert(items[i] == expected8[expectedIndex++]);
    }
    // std::cout << std::endl;
  });

  assert(tree1.getHeight() == 3);
  assert(tree1.getNumberOfNodes() == 7);

  std::cout << "BTreeInorderTests passed." << std::endl;
}
void BTreeTests() {
  std::cout << "Running BTreeTests..." << std::endl;

  BTreeConstructorTests();
  BTreeAddTests();
  BTreeLeafNodeRemoveTests();
  BTreeFuseTests();
  BTreeRotateTests();
  BTreeInorderTests();

  std::cout << "BTreeTests passed." << std::endl;
}