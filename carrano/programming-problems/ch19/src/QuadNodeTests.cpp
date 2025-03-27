#include "headers.h"
#include "QuadNode.h"
#include <cassert>

void QuadNodeConstructorTests() {
  std::shared_ptr<QuadNode<int>> node1 = std::make_shared<QuadNode<int>>();
  assert(node1->getItemCount() == 0);
  assert(node1->getChildCount() == 0);
  assert(node1->isLeaf());

  int testInt1 = 5;
  std::shared_ptr<QuadNode<int>> node2 = std::make_shared<QuadNode<int>>(testInt1);
  assert(node2->getItemCount() == 1);
  // assert(node2->getItems()[0] == testInt1);
  assert(node2->getItem(0) == testInt1);
  assert(node2->getChildCount() == 0);
  assert(node2->isLeaf());

  int testInt2 = 10;
  std::shared_ptr<QuadNode<int>> node3 = std::make_shared<QuadNode<int>>(testInt1, testInt2);
  assert(node3->getItemCount() == 2);
  // assert(node3->getItems()[0] == testInt1);
  // assert(node3->getItems()[1] == testInt2);
  assert(node3->getItem(0) == testInt1);
  assert(node3->getItem(1) == testInt2);
  assert(node3->getChildCount() == 0);
  assert(node3->isLeaf());

  int testInt3 = 15;
  std::shared_ptr<QuadNode<int>> node4 = std::make_shared<QuadNode<int>>(testInt1, testInt2, testInt3);
  assert(node4->getItemCount() == 3);
  // assert(node4->getItems()[0] == testInt1);
  // assert(node4->getItems()[1] == testInt2);
  // assert(node4->getItems()[2] == testInt3);
  assert(node4->getItem(0) == testInt1);
  assert(node4->getItem(1) == testInt2);
  assert(node4->getItem(2) == testInt3);
  assert(node4->getChildCount() == 0);
  assert(node4->isLeaf());

  std::shared_ptr<QuadNode<int>> nodeA = std::make_shared<QuadNode<int>>(testInt1, node1, node2);
  assert(nodeA->getItemCount() == 1);
  // assert(nodeA->getItems()[0] == testInt1);
  assert(nodeA->getItem(0) == testInt1);
  assert(nodeA->getChildCount() == 2);
  // assert(nodeA->getChildren()[0] == node1);
  // assert(nodeA->getChildren()[1] == node2);
  assert(nodeA->getChild(0) == node1);
  assert(nodeA->getChild(1) == node2);
  assert(nodeA->isTwoNode());

  std::shared_ptr<QuadNode<int>> nodeB = std::make_shared<QuadNode<int>>(testInt1, testInt2, node1, node2, node3);
  assert(nodeB->getItemCount() == 2);
  // assert(nodeB->getItems()[0] == testInt1);
  // assert(nodeB->getItems()[1] == testInt2);
  assert(nodeB->getItem(0) == testInt1);
  assert(nodeB->getItem(1) == testInt2);
  assert(nodeB->getChildCount() == 3);
  // assert(nodeB->getChildren()[0] == node1);
  // assert(nodeB->getChildren()[1] == node2);
  // assert(nodeB->getChildren()[2] == node3);
  assert(nodeB->getChild(0) == node1);
  assert(nodeB->getChild(1) == node2);
  assert(nodeB->getChild(2) == node3);
  assert(nodeB->isThreeNode());

  std::shared_ptr<QuadNode<int>> nodeC = std::make_shared<QuadNode<int>>(testInt1, testInt2, testInt3, node1, node2, node3, node4);
  assert(nodeC->getItemCount() == 3);
  // assert(nodeC->getItems()[0] == testInt1);
  // assert(nodeC->getItems()[1] == testInt2);
  // assert(nodeC->getItems()[2] == testInt3);
  assert(nodeC->getItem(0) == testInt1);
  assert(nodeC->getItem(1) == testInt2);
  assert(nodeC->getItem(2) == testInt3);
  assert(nodeC->getChildCount() == 4);
  // assert(nodeC->getChildren()[0] == node1);
  // assert(nodeC->getChildren()[1] == node2);
  // assert(nodeC->getChildren()[2] == node3);
  // assert(nodeC->getChildren()[3] == node4);
  assert(nodeC->getChild(0) == node1);
  assert(nodeC->getChild(1) == node2);
  assert(nodeC->getChild(2) == node3);
  assert(nodeC->getChild(3) == node4);
  assert(nodeC->isFourNode());

  std::cout << "QuadNodeConstructorTests passed." << std::endl;
}

void QuadNodeInsertRemoveItemTests() {
  int pos;

  std::shared_ptr<QuadNode<int>> node1 = std::make_shared<QuadNode<int>>();
  assert(node1->getItemCount() == 0);
  assert(node1->isLeaf());

  int testInt1 = 5;
  pos = node1->insertItem(testInt1);
  assert(pos == 0);
  assert(node1->getItemCount() == 1);
  // assert(node1->getItems()[0] == testInt1);
  assert(node1->getItem(0) == testInt1);

  int testInt2 = 10;
  pos = node1->insertItem(testInt2);
  assert(pos == 1);
  assert(node1->getItemCount() == 2);
  // assert(node1->getItems()[0] == testInt1);
  // assert(node1->getItems()[1] == testInt2);
  assert(node1->getItem(0) == testInt1);
  assert(node1->getItem(1) == testInt2);

  int testInt3 = 15;
  pos = node1->insertItem(testInt3);
  assert(pos == 2);
  assert(node1->getItemCount() == 3);
  // assert(node1->getItems()[0] == testInt1);
  // assert(node1->getItems()[1] == testInt2);
  // assert(node1->getItems()[2] == testInt3);
  assert(node1->getItem(0) == testInt1);
  assert(node1->getItem(1) == testInt2);
  assert(node1->getItem(2) == testInt3);

  try {
    node1->insertItem(20);
    assert(false);
  } catch (PrecondViolatedExcept &e) {
    // std::cout << "Caught exception: " << e.what() << std::endl;
    assert(node1->getItemCount() == 3);
  }

  node1->removeItem(1);
  assert(node1->getItemCount() == 2);
  // assert(node1->getItems()[0] == testInt1);
  // assert(node1->getItems()[1] == testInt3);
  assert(node1->getItem(0) == testInt1);
  assert(node1->getItem(1) == testInt3);

  node1->removeFirstItem();
  assert(node1->getItemCount() == 1);
  // assert(node1->getItems()[0] == testInt3);
  assert(node1->getItem(0) == testInt3);

  node1->removeLastItem();
  assert(node1->getItemCount() == 0);

  try {
    node1->removeFirstItem();
    assert(false);
  } catch (PrecondViolatedExcept &e) {
    // std::cout << "Caught exception: " << e.what() << std::endl;
    assert(node1->getItemCount() == 0);
  }

  pos = node1->insertItem(testInt3);
  assert(pos == 0);
  pos = node1->insertItem(testInt2);
  assert(pos == 0);
  assert(node1->getItemCount() == 2);
  pos = node1->insertItem(testInt2); // Duplicate
  assert(pos == 0);
  assert(node1->getItemCount() == 2);
  pos = node1->insertItem(testInt1);
  assert(pos == 0);
  assert(node1->getItemCount() == 3);
  // assert(node1->getItems()[0] == testInt1);
  // assert(node1->getItems()[1] == testInt2);
  // assert(node1->getItems()[2] == testInt3);
  assert(node1->getItem(0) == testInt1);
  assert(node1->getItem(1) == testInt2);
  assert(node1->getItem(2) == testInt3);

  std::cout << "QuadNodeInsertItemTests passed." << std::endl;
}

void QuadNodeInsertRemoveChildTests() {
  std::shared_ptr<QuadNode<int>> nodeA = std::make_shared<QuadNode<int>>();
  assert(nodeA->getChildCount() == 0);
  assert(nodeA->isLeaf());

  std::shared_ptr<QuadNode<int>> node1 = std::make_shared<QuadNode<int>>();
  std::shared_ptr<QuadNode<int>> node2 = std::make_shared<QuadNode<int>>();
  std::shared_ptr<QuadNode<int>> node3 = std::make_shared<QuadNode<int>>();
  std::shared_ptr<QuadNode<int>> node4 = std::make_shared<QuadNode<int>>();

  nodeA->insertChild(node1, 0);
  assert(nodeA->getChildCount() == 1);
  // assert(nodeA->getChildren()[0] == node1);
  assert(nodeA->getChild(0) == node1);

  nodeA->insertFirstChild(node2);
  assert(nodeA->getChildCount() == 2);
  // assert(nodeA->getChildren()[0] == node2);
  // assert(nodeA->getChildren()[1] == node1);
  assert(nodeA->getChild(0) == node2);
  assert(nodeA->getChild(1) == node1);

  nodeA->insertLastChild(node3);
  assert(nodeA->getChildCount() == 3);
  // assert(nodeA->getChildren()[0] == node2);
  // assert(nodeA->getChildren()[1] == node1);
  // assert(nodeA->getChildren()[2] == node3);
  assert(nodeA->getChild(0) == node2);
  assert(nodeA->getChild(1) == node1);
  assert(nodeA->getChild(2) == node3);

  nodeA->insertChild(node4, 1);
  assert(nodeA->getChildCount() == 4);
  // assert(nodeA->getChildren()[0] == node2);
  // assert(nodeA->getChildren()[1] == node4);
  // assert(nodeA->getChildren()[2] == node1);
  // assert(nodeA->getChildren()[3] == node3);
  assert(nodeA->getChild(0) == node2);
  assert(nodeA->getChild(1) == node4);
  assert(nodeA->getChild(2) == node1);
  assert(nodeA->getChild(3) == node3);

  try {
    nodeA->insertChild(node4, 0);
    assert(false);
  } catch (PrecondViolatedExcept &e) {
    // std::cout << "Caught exception: " << e.what() << std::endl;
    assert(nodeA->getChildCount() == 4);
  }
  // assert(nodeA->getChildren()[0] == node2);
  // assert(nodeA->getChildren()[1] == node4);
  // assert(nodeA->getChildren()[2] == node1);
  // assert(nodeA->getChildren()[3] == node3);
  assert(nodeA->getChild(0) == node2);
  assert(nodeA->getChild(1) == node4);
  assert(nodeA->getChild(2) == node1);
  assert(nodeA->getChild(3) == node3);

  nodeA->removeChild(1);
  assert(nodeA->getChildCount() == 3);
  // assert(nodeA->getChildren()[0] == node2);
  // assert(nodeA->getChildren()[1] == node1);
  // assert(nodeA->getChildren()[2] == node3);
  assert(nodeA->getChild(0) == node2);
  assert(nodeA->getChild(1) == node1);
  assert(nodeA->getChild(2) == node3);
  assert(nodeA->getChild(3) == nullptr);

  nodeA->removeFirstChild();
  assert(nodeA->getChildCount() == 2);
  // assert(nodeA->getChildren()[0] == node1);
  // assert(nodeA->getChildren()[1] == node3);
  assert(nodeA->getChild(0) == node1);
  assert(nodeA->getChild(1) == node3);
  assert(nodeA->getChild(2) == nullptr);
  assert(nodeA->getChild(3) == nullptr);

  nodeA->removeLastChild();
  assert(nodeA->getChildCount() == 1);
  assert(nodeA->getChildren()[0] == node1);
  assert(nodeA->getChild(0) == node1);
  assert(nodeA->getChild(1) == nullptr);
  assert(nodeA->getChild(2) == nullptr);
  assert(nodeA->getChild(3) == nullptr);

  nodeA->removeChild(0);
  assert(nodeA->getChildCount() == 0);
  assert(nodeA->getChild(0) == nullptr);
  assert(nodeA->getChild(1) == nullptr);
  assert(nodeA->getChild(2) == nullptr);
  assert(nodeA->getChild(3) == nullptr);

  try {
    nodeA->removeChild(0);
    assert(false);
  } catch (PrecondViolatedExcept &e) {
    // std::cout << "Caught exception: " << e.what() << std::endl;
    assert(nodeA->getChildCount() == 0);
  }

  std::cout << "QuadNodeInsertRemoveChildTests passed." << std::endl;
}

void QuadNodeTests() {
  std::cout << "--- QuadNodeTests ---" << std::endl;

  QuadNodeConstructorTests();
  QuadNodeInsertRemoveItemTests();
  QuadNodeInsertRemoveChildTests();

  std::cout << "QuadNodeTests passed." << std::endl;
}