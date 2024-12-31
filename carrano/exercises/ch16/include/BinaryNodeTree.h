//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Listing 16-3.

/** ADT binary tree: Link-based implementation.
 @file BinaryNodeTree.h */
 
#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"
#include <iostream>
#include <memory>
#include <algorithm>
#include <functional>
#include <vector>

template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
private:
   std::shared_ptr<BinaryNode<ItemType>> rootPtr;
   
protected:
  // //------------------------------------------------------------
  // // Protected Utility Methods Section:
  // // Recursive helper methods for the public methods.
  // //------------------------------------------------------------
  int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
  int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
   
  // Recursively adds a new node to the tree in a left/right fashion to keep tree balanced.
  auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                   std::shared_ptr<BinaryNode<ItemType>> newNodePtr);
  
  // Removes the given target from the binary tree to which subTreePtr points.
  // Returns a pointer to the node at this tree location after the value is removed.
  // Sets isSuccessful to true if the removal is successful, or false otherwise.
  virtual std::shared_ptr<BinaryNode<ItemType>> removeValue(std::shared_ptr<BinaryNode<ItemType>>& subTreePtr,
                           const ItemType target, bool& isSuccessful);
   
  // Removes the item in the node, N, to which nodePtr points.
  // Returns a pointer to the node at this tree location after node N is deleted.
  std::shared_ptr<BinaryNode<ItemType>> removeNode(std::shared_ptr<BinaryNode<ItemType>>& subTreePtr);

  // Removes the leftmost node in the left subtree of the node pointed to by nodePtr.
  // Sets inorderSuccessor to the value in this node.
  // Returns a pointer to the revised subtree.
  std::shared_ptr<BinaryNode<ItemType>> removeLeftMostNode(std::shared_ptr<BinaryNode<ItemType>>& subTreePtr,
                           ItemType& inorderSuccessor);

  // // Copies values up the tree to overwrite value in current node until
  // // a leaf is reached; the leaf is then removed, since its value is stored in the parent.
  // void moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);
  
  // Recursively searches for target value in the tree by using a
  // preorder traversal.
  std::shared_ptr<BinaryNode<ItemType>> findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target, bool& success) const;
  
  // Copies the tree rooted at treePtr and returns a pointer to the root of the copy.
  std::shared_ptr<BinaryNode<ItemType>> copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;
  
  // Recursively deletes all nodes from the tree.
  void destroyTree(std::shared_ptr<BinaryNode<ItemType>>& subTreePtr);
  
  // Recursive traversal helper methods:
  void preorder(std::function<void(std::shared_ptr<BinaryNode<ItemType>>)> visit, std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
  void inorder(std::function<void(std::shared_ptr<BinaryNode<ItemType>>)> visit, std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
  void postorder(std::function<void(std::shared_ptr<BinaryNode<ItemType>>)> visit, std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
   
public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinaryNodeTree();
   BinaryNodeTree(const ItemType& rootItem);
   BinaryNodeTree(const ItemType& rootItem,
                  const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                  const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);
   BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>>& tree);
   virtual ~BinaryNodeTree();
   
  //------------------------------------------------------------
  // Public BinaryTreeInterface Methods Section.
  //------------------------------------------------------------
  bool isEmpty() const;
  int getHeight() const;
  int getNumberOfNodes() const;
   
  ItemType getRootData() const; // throw(PrecondViolatedExcept);
  void setRootData(const ItemType& newData);
   
  bool add(const ItemType& newData); // Adds an item to the tree
  bool remove(const ItemType& data); // Removes specified item from the tree
  void clear();
   
  ItemType getEntry(const ItemType& anEntry) const; // throw(NotFoundException);
  bool contains(const ItemType& anEntry) const;
   
  //------------------------------------------------------------
  // Public Traversals Section.
  //------------------------------------------------------------
  void preorderTraverse(void visit(ItemType&)) const;
  void inorderTraverse(void visit(ItemType&)) const;
  void postorderTraverse(void visit(ItemType&)) const;
   
  //------------------------------------------------------------
  // Overloaded Operator Section.
  //------------------------------------------------------------
  BinaryNodeTree<ItemType>& operator=(const BinaryNodeTree& rightHandSide);

  //------------------------------------------------------------
  // Added functions for Final Exam Practice (Choi)
  //------------------------------------------------------------
  std::shared_ptr<BinaryNode<ItemType>> getRootPtr() const { return rootPtr; }
  int nodeCount(std::shared_ptr<BinaryNode<ItemType>> node);
  int edgeCount(std::shared_ptr<BinaryNode<ItemType>> node);
  int leafCount(std::shared_ptr<BinaryNode<ItemType>> node);
  std::shared_ptr<BinaryNode<ItemType>> closestCommonAncestor(
    std::shared_ptr<BinaryNode<ItemType>> current, 
    std::shared_ptr<BinaryNode<ItemType>> node1, 
    std::shared_ptr<BinaryNode<ItemType>> node2);

}; // end BinaryNodeTree

template<class ItemType>
int BinaryNodeTree<ItemType>::
    getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
  if (subTreePtr == nullptr)
    return 0;
  else
    return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                        getHeightHelper(subTreePtr->getRightChildPtr()));
}  // end getHeightHelper

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
  if (subTreePtr == nullptr)
    return 0;
  else
    return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) +
           getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
} // end getNumberOfNodesHelper

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>>& subTreePtr, const ItemType target, bool &isSuccessful)
{
  // never reached
  // // if empty tree
  // if (subTreePtr == nullptr) {
  //   isSuccessful = false;
  //   return subTreePtr;                                           
  // }

  // item to remove is root of a subtree
  if (subTreePtr->getItem() == target) {
    subTreePtr = removeNode(subTreePtr);                      // removeNode will handle deletion, and return the link for the parent to set
    isSuccessful = true;
    return subTreePtr;
  }
  
  // check left subtree
  auto left = subTreePtr->getLeftChildPtr();
  if (left != nullptr) {
    auto tempPtr = removeValue(left, target, isSuccessful);   // returns link
    subTreePtr->setLeftChildPtr(tempPtr);                     // set left child to new link, this is where real deletion happens

    // if not sucessful, need to continue to check right subtree
    // else immediately return self as link
    if (isSuccessful) {
      return subTreePtr;                                      // returns self as link (no change)
    }
  }

  // check right subtree
  auto right = subTreePtr->getRightChildPtr();
  if (right != nullptr) {
    auto tempPtr = removeValue(right, target, isSuccessful);  // returns link
    subTreePtr->setRightChildPtr(tempPtr);                   // set left child to new link, this is where real deletion happens

    // if successful
    if (isSuccessful) {
      return subTreePtr;                                      // returns self as link (no change)
    }
  }

  // dead-end
  // this node is a leaf, and the value was not found
  isSuccessful = false;
  return subTreePtr;                                          // returns self as link (no change)                 
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>>& subTreePtr)
{
  if (subTreePtr->isLeaf()) {
    return nullptr;
  }

  // if only one child
  auto left = subTreePtr->getLeftChildPtr();
  auto right = subTreePtr->getRightChildPtr();

  // if right child is null, return left child
  // if left child is null, return right child
  if (left == nullptr && right != nullptr) {
    return subTreePtr->getRightChildPtr();
  } else if (left != nullptr && right == nullptr) {
    return subTreePtr->getLeftChildPtr();
  }

  // if two children
  ItemType inorderSuccessor;                                    // need to determine inorder successor
  auto tempPtr = removeLeftMostNode(right, inorderSuccessor);   // find left most node in right subtree
  subTreePtr->setRightChildPtr(tempPtr);
  subTreePtr->setItem(inorderSuccessor);
  return subTreePtr;
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::removeLeftMostNode(std::shared_ptr<BinaryNode<ItemType>> &subTreePtr, ItemType &inorderSuccessor)
{
  if (subTreePtr->getLeftChildPtr() == nullptr) {
    inorderSuccessor = subTreePtr->getItem();
    return removeNode(subTreePtr);
  } else {
    auto left = subTreePtr->getLeftChildPtr();
    auto tempPtr = removeLeftMostNode(left, inorderSuccessor);
    subTreePtr->setLeftChildPtr(tempPtr);
    return subTreePtr;
  }
}

// template <class ItemType>
// void BinaryNodeTree<ItemType>::moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
// {
//   if (subTreePtr->isLeaf()) {
//     return;
//   }
// 
//   auto left = subTreePtr->getLeftChildPtr();
//   auto right = subTreePtr->getRightChildPtr();
// 
//   if (left != nullptr) {
//     // set this item to left child's value
//     subTreePtr->setItem(left->getItem());
// 
//     // move down left subtree first
//     moveValuesUpTree(left)
//   } else {
//     // set this item to right child's value
//     subTreePtr->setItem(right->getItem());
// 
//     // move down right subtree 
//     moveValuesUpTree(right)
//   }
// 
//   return false; // do not delete this node
// }

template<class ItemType>
auto BinaryNodeTree<ItemType>::
     balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                 std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{

  if (subTreePtr == nullptr)
    return newNodePtr;
  else
  {
    auto leftPtr = subTreePtr->getLeftChildPtr();
    auto rightPtr = subTreePtr->getRightChildPtr();

    if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
    {
      rightPtr = balancedAdd(rightPtr, newNodePtr);
      subTreePtr->setRightChildPtr(rightPtr);
    }
    else
    {
      leftPtr = balancedAdd(leftPtr, newNodePtr);
      subTreePtr->setLeftChildPtr(leftPtr);
    } // end if

    return subTreePtr;
  } // end if
}  // end balancedAdd

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType &target, bool &success) const
{
  success = false;
  std::shared_ptr<BinaryNode<ItemType>> targetNode = nullptr;

    std::function<void(std::shared_ptr<BinaryNode<ItemType>>)> visit = [&target, &targetNode, &success](std::shared_ptr<BinaryNode<ItemType>> curPtr) {
        if (curPtr->getItem() == target)
        {
            targetNode = curPtr;
            success = true;
        }
    };

  preorder(visit, treePtr);

  if (success)
    return targetNode;
  else
    throw NotFoundException("Item not found in tree");
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::
    copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const
{
  std::shared_ptr<BinaryNode<ItemType>> newTreePtr;

  // Copy tree nodes during a preorder traversal
  if (oldTreeRootPtr != nullptr)
  {
    // Copy node
    newTreePtr = std::make_shared<BinaryNode<ItemType>>(oldTreeRootPtr->getItem(),
                                                        nullptr, nullptr);
    newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
    newTreePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
  } // end if
  // Else tree is empty (newTreePtr is nullptr)

  return newTreePtr;
} // end copyTree

template<class ItemType>
void BinaryNodeTree<ItemType>::
     destroyTree(std::shared_ptr<BinaryNode<ItemType>>& subTreePtr)
{
  if (subTreePtr != nullptr)
  {
    auto left = subTreePtr->getLeftChildPtr();
    auto right = subTreePtr->getRightChildPtr();
    destroyTree(left);
    destroyTree(right);
    subTreePtr.reset(); // Decrement reference count to node
                        // this only ensures that there are no dangling pointers
                        // it does not directly free the memory        
                        // once all references are gone, the shared_ptr memory management recognizes this
                        // and memory will be freed
    // std::cout << "Reference count for subTreePtr: " << subTreePtr.use_count() << std::endl;
  } // end if
}  // end destroyTree

template<class ItemType>
void BinaryNodeTree<ItemType>::
     preorder(std::function<void(std::shared_ptr<BinaryNode<ItemType>>)> visit,
             std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
  if (treePtr != nullptr)
  {
    visit(treePtr);
    preorder(visit, treePtr->getLeftChildPtr());
    preorder(visit, treePtr->getRightChildPtr());
  } // end if
}  // end preorder

template<class ItemType>
void BinaryNodeTree<ItemType>::
     inorder(std::function<void(std::shared_ptr<BinaryNode<ItemType>>)> visit,
             std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
  if (treePtr != nullptr)
  {
    inorder(visit, treePtr->getLeftChildPtr());
    visit(treePtr);
    inorder(visit, treePtr->getRightChildPtr());
  } // end if
}  // end inorder

template<class ItemType>
void BinaryNodeTree<ItemType>::
     postorder(std::function<void(std::shared_ptr<BinaryNode<ItemType>>)> visit,
             std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
  if (treePtr != nullptr)
  {
    postorder(visit, treePtr->getLeftChildPtr());
    postorder(visit, treePtr->getRightChildPtr());
    visit(treePtr);
  } // end if
}  // end postorder

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr)
{
}  // end default constructor

template<class ItemType>
BinaryNodeTree<ItemType>::
BinaryNodeTree(const ItemType& rootItem)
      : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{
} // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::
BinaryNodeTree(const ItemType& rootItem,
               const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
               const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr)
      : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem,
                                                       copyTree(leftTreePtr->rootPtr),
                                                       copyTree(rightTreePtr->rootPtr)))
{
} // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::
BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>>& treePtr)
// BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr)
{
   rootPtr = copyTree(treePtr->rootPtr);
}  // end copy constructor

template <class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
  destroyTree(rootPtr);
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
  return (rootPtr == nullptr);
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
  return getHeightHelper(rootPtr);
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
  return getNumberOfNodesHelper(rootPtr);
}

template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const
{
  if (isEmpty())
    throw PrecondViolatedExcept("getRootData() called with empty tree.");

  return rootPtr->getItem();
}

template <class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType &newData)
{
  if (isEmpty())
    rootPtr = std::make_shared<BinaryNode<ItemType>>(newData);
  else
    rootPtr->setItem(newData);
}

template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
   auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
   rootPtr = balancedAdd(rootPtr, newNodePtr);
   
   return true;
}  // end add

template <class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType &data)
{
  bool isSuccessful = false;
  rootPtr = removeValue(rootPtr,data,isSuccessful); // removeValue returns a link to the new root

  return isSuccessful;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::clear()
{
  destroyTree(rootPtr); // removes pointers to all nodes
}

template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType &anEntry) const
{
  try {
    bool success = false;
    auto node = findNode(rootPtr, anEntry, success);
    return node->getItem();
  } catch (NotFoundException &e) {
    throw e;
  }
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType &anEntry) const
{
  try {
    bool success = false;
    findNode(rootPtr, anEntry, success);
    return success;
  } catch (NotFoundException &e) {
    return false;
  }
}

template <class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
  auto visitWrapper = [&visit](std::shared_ptr<BinaryNode<ItemType>> curPtr) {
    ItemType item = curPtr->getItem();
    visit(item);
  };
  preorder(visitWrapper, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
  auto visitWrapper = [&visit](std::shared_ptr<BinaryNode<ItemType>> curPtr) {
    ItemType item = curPtr->getItem();
    visit(item);
  };
  inorder(visitWrapper, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
  auto visitWrapper = [&visit](std::shared_ptr<BinaryNode<ItemType>> curPtr) {
    ItemType item = curPtr->getItem();
    visit(item);
  };
  postorder(visitWrapper, rootPtr);
}

template <class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree &rightHandSide)
{
  if (this != &rightHandSide)
  {
    destroyTree(rootPtr);
    rootPtr = copyTree(rightHandSide.rootPtr);
  }

  return *this;
}

template <class ItemType>
inline int BinaryNodeTree<ItemType>::nodeCount(std::shared_ptr<BinaryNode<ItemType>> node)
{
  if (node == nullptr) {
    return 0;
  }

  // Assumes nodes can have variable number of children (instead of just 2)
  std::vector<std::shared_ptr<BinaryNode<ItemType>>> children;
  children.push_back(node->getLeftChildPtr());
  children.push_back(node->getRightChildPtr());

  int nodes = 1;  // initialize with this node as 1
  for (auto& child : children) {
    nodes += nodeCount(child); // accumulate each child's node count
  }

  return nodes;
}

template <class ItemType>
inline int BinaryNodeTree<ItemType>::edgeCount(std::shared_ptr<BinaryNode<ItemType>> node)
{
  // no edges when tree is empty
  if (node == nullptr) {
    return 0;
  }

  return nodeCount(node) - 1;
}

template <class ItemType>
inline int BinaryNodeTree<ItemType>::leafCount(std::shared_ptr<BinaryNode<ItemType>> node)
{
  if (node == nullptr) {
    return 0;
  }

  // Assumes nodes can have variable number of children (instead of just 2)
  std::vector<std::shared_ptr<BinaryNode<ItemType>>> children;
  children.push_back(node->getLeftChildPtr());
  children.push_back(node->getRightChildPtr());

  // Determine if this is a leaf
  int leaves = 0;
  for (auto& child : children) {
    leaves += leafCount(child); // accumulate children's leaf count
  }

  if (leaves > 0) {
    return leaves;
  } else {
    // If children report no leaves, then this is a leaf
    return 1;
  }

}

template <class ItemType>
inline std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::closestCommonAncestor(
  std::shared_ptr<BinaryNode<ItemType>> current, 
  std::shared_ptr<BinaryNode<ItemType>> node1, 
  std::shared_ptr<BinaryNode<ItemType>> node2)
{
  // Assume node1 and node2 are always valid nodes
  // Assume node values are unique
  // Assume if two nodes have the same value, then they are the same node
  // This will be returned on first call and will not trigger on any later recursive call
  if (node1->getItem() == node2->getItem()) {
    return node1;
  }

  // Can assume that node1 and node2 are different and exist somewhere in the tree

  // assume current is closest common ancestor
  // check if this node is node1 or node2
  //  if it is either
  //    update close common ancestor to be 
  //  if not, search left tree
  //    once node1 is found, update closest common ancestor
  //    search right tree for node2

  return std::shared_ptr<BinaryNode<ItemType>>();
}

#endif