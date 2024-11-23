//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Listing 16-4.

/** Link-based implementation of the ADT binary search tree.
 @file BinarySearchTree.h */
 
#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType>
{
private:
  std::shared_ptr<BinaryNode<ItemType>> rootPtr;

protected:
  //------------------------------------------------------------
  //    Protected Utility Methods Section:
  //    Recursive helper methods for the public methods.
  //------------------------------------------------------------
  // Places a given new node at its proper position in this binary
  // search tree.
  auto placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                 std::shared_ptr<BinaryNode<ItemType>> newNode);

  // // Removes the given target value from the tree while maintaining a
  // // binary search tree.
  // auto removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
  //                  const ItemType target,
  //                  bool& isSuccessful) override;
  //
  // // Removes a given node from a tree while maintaining a binary search tree.
  // auto removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr);
  //
  // // Removes the leftmost node in the left subtree of the node
  // // pointed to by nodePtr.
  // // Sets inorderSuccessor to the value in this node.
  // // Returns a pointer to the revised subtree.
  // auto removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>>subTreePtr,
  //                         ItemType& inorderSuccessor);

  // // Returns a pointer to the node containing the given value,
  // // or nullptr if not found.
  // auto findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
  //               const ItemType& target) const;

public:
  //------------------------------------------------------------
  // Constructor and Destructor Section.
  //------------------------------------------------------------
  BinarySearchTree();
  BinarySearchTree(const ItemType &rootItem);
  BinarySearchTree(const BinarySearchTree<ItemType> &tree);
  virtual ~BinarySearchTree();

  //------------------------------------------------------------
  // Public Methods Section.
  //------------------------------------------------------------
  bool isEmpty() const;
  int getHeight() const;
  int getNumberOfNodes() const;

  ItemType getRootData() const; // throw(PrecondViolatedExcept);
  void setRootData(const ItemType &newData);

  bool add(const ItemType &newEntry);
  bool remove(const ItemType &target);
  void clear();

  ItemType getEntry(const ItemType &anEntry) const; // throw(NotFoundException);
  bool contains(const ItemType &anEntry) const;

  //------------------------------------------------------------
  // Public Traversals Section.
  //------------------------------------------------------------
  void preorderTraverse(void visit(ItemType &)) const;
  void inorderTraverse(void visit(ItemType &)) const;
  void postorderTraverse(void visit(ItemType &)) const;

  void preorderTraverse(std::function<void(std::shared_ptr<BinaryNode<ItemType>>)> visit) const;
  void inorderTraverse(std::function<void(std::shared_ptr<BinaryNode<ItemType>>)> visit) const;
  void postorderTraverse(std::function<void(std::shared_ptr<BinaryNode<ItemType>>)> visit) const;

  //------------------------------------------------------------
  // Overloaded Operator Section.
  //------------------------------------------------------------
  BinarySearchTree<ItemType> &
  operator=(const BinarySearchTree<ItemType> &rightHandSide);
}; // end BinarySearchTree

// #include "BinarySearchTree.cpp"
#endif

template <class ItemType>
inline auto BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNode)
{
  if (subTreePtr == nullptr)
  {
    return newNode;
  }

  if (subTreePtr->getItem() == newNode->getItem())
  {
    // do nothing
  }
  else if (subTreePtr->getItem() > newNode->getItem())
  {
    auto left = subTreePtr->getLeftChildPtr();
    auto tempPtr = placeNode(left, newNode);
    subTreePtr->setLeftChildPtr(tempPtr);
  }
  else
  {
    auto right = subTreePtr->getRightChildPtr();
    auto tempPtr = placeNode(right, newNode);
    subTreePtr->setRightChildPtr(tempPtr);
  }

  return subTreePtr;
}

template <class ItemType>
inline BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr)
{
}
template <class ItemType>
inline BinarySearchTree<ItemType>::BinarySearchTree(const ItemType &rootItem)
{
  this->rootPtr = std::make_shared<BinaryNode<ItemType>>(rootItem);
}

template <class ItemType>
inline BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType> &tree)
{
  this->rootPtr = this->copyTree(tree.rootPtr);
}

template <class ItemType>
inline BinarySearchTree<ItemType>::~BinarySearchTree()
{
  this->destroyTree(this->rootPtr);
}

template <class ItemType>
inline bool BinarySearchTree<ItemType>::isEmpty() const
{
  return this->rootPtr == nullptr;
}

template <class ItemType>
inline int BinarySearchTree<ItemType>::getHeight() const
{
  return this->getHeightHelper(this->rootPtr);
}

template <class ItemType>
inline int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
  return this->getNumberOfNodesHelper(this->rootPtr);
}

template <class ItemType>
inline ItemType BinarySearchTree<ItemType>::getRootData() const
{
  if (isEmpty())
    throw PrecondViolatedExcept("getRootData() called with empty tree.");
  return this->rootPtr->getItem();
}

template <class ItemType>
inline void BinarySearchTree<ItemType>::setRootData(const ItemType &newData)
{
  if (isEmpty())
    this->rootPtr = std::make_shared<BinaryNode<ItemType>>(newData);
  else
    this->rootPtr->setItem(newData);
}

template <class ItemType>
inline bool BinarySearchTree<ItemType>::add(const ItemType &newEntry)
{
  auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newEntry);
  this->rootPtr = placeNode(this->rootPtr, newNodePtr);
  return true;
}

template <class ItemType>
inline bool BinarySearchTree<ItemType>::remove(const ItemType &target)
{
  bool isSuccessful = false;
  this->rootPtr = this->removeValue(this->rootPtr, target, isSuccessful);
  return isSuccessful;
}

template <class ItemType>
inline void BinarySearchTree<ItemType>::clear()
{
  this->destroyTree(this->rootPtr);
  this->rootPtr = nullptr;
}

template <class ItemType>
inline ItemType BinarySearchTree<ItemType>::getEntry(const ItemType &anEntry) const
{
  try
  {
    bool success = false;
    auto node = this->findNode(rootPtr, anEntry, success);
    return node->getItem();
  }
  catch (NotFoundException &e)
  {
    throw e;
  }
}

template <class ItemType>
inline bool BinarySearchTree<ItemType>::contains(const ItemType &anEntry) const
{
  try
  {
    bool success = false;
    this->findNode(rootPtr, anEntry, success);
    return success;
  }
  catch (NotFoundException &e)
  {
    return false;
  }
}

template <class ItemType>
inline void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType &)) const
{
  auto visitWrapper = [&visit](std::shared_ptr<BinaryNode<ItemType>> curPtr)
  {
    ItemType item = curPtr->getItem();
    visit(item);
  };
  this->preorder(visitWrapper, rootPtr);
}

template <class ItemType>
inline void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType &)) const
{
  auto visitWrapper = [&visit](std::shared_ptr<BinaryNode<ItemType>> curPtr)
  {
    ItemType item = curPtr->getItem();
    visit(item);
  };
  this->inorder(visitWrapper, this->rootPtr);
}

template <class ItemType>
inline void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType &)) const
{
  auto visitWrapper = [&visit](std::shared_ptr<BinaryNode<ItemType>> curPtr)
  {
    ItemType item = curPtr->getItem();
    visit(item);
  };
  this->postorder(visitWrapper, this->rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(std::function<void(std::shared_ptr<BinaryNode<ItemType>>)> visit) const
{
  this->preorder(visit, this->rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(std::function<void(std::shared_ptr<BinaryNode<ItemType>>)> visit) const
{
  this->inorder(visit, this->rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(std::function<void(std::shared_ptr<BinaryNode<ItemType>>)> visit) const
{
  this->postorder(visit, this->rootPtr);
}

template <class ItemType>
inline BinarySearchTree<ItemType> &BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType> &rightHandSide)
{
  if (this != &rightHandSide)
  {
    this->destroyTree(this->rootPtr);
    this->rootPtr = this->copyTree(rightHandSide.rootPtr);
  }
  return *this;
}