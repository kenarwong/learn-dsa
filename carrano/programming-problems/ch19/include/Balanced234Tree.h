/** Link-based implementation of the ADT 2-3-4 search tree.
 @file Balanced234Tree.h */
 
#ifndef BALANCED_234_TREE_
#define BALANCED_234_TREE_

#include "BTreeInterface.h"
#include "QuadNode.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"
#include "headers.h"

template<class ItemType>
class Balanced234Tree : public BTreeInterface<ItemType>
{
private:
  std::shared_ptr<QuadNode<ItemType>> rootPtr;

  // // Splits a child 4-node, updates current node with middle value,
  // // links split children to parent node.
  // void split(std::shared_ptr<QuadNode<ItemType>> subTreePtr,
  //                std::shared_ptr<QuadNode<ItemType>> childPtr);

protected:
  // //------------------------------------------------------------
  // //    Protected Utility Methods Section:
  // //    Recursive helper methods for the public methods.
  // //------------------------------------------------------------
  // int getHeightHelper(std::shared_ptr<QuadNode<ItemType>> subTreePtr) const;
  // int getNumberOfNodesHelper(std::shared_ptr<QuadNode<ItemType>> subTreePtr) const;
   
  // // Places a given new node at its proper position in this 2-3-4
  // // search tree.
  // auto placeNode(std::shared_ptr<QuadNode<ItemType>> subTreePtr,
  //                std::shared_ptr<QuadNode<ItemType>> newNode);
          
  // // Get next largest subtree pointer 
  // // Returns next largest child subtree that is empty
  // auto getNextEmptySubtreePtr(std::shared_ptr<QuadNode<ItemType>> subTreePtr);

  // // Removes the given target value from the tree while maintaining a
  // // 2-3-4 search tree.
  // std::shared_ptr<QuadNode<ItemType>> removeValue(std::shared_ptr<QuadNode<ItemType>>& subTreePtr,
  //                  const ItemType target,
  //                  bool& isSuccessful) override;
  
  // // // Removes a given node from a tree while maintaining a 2-3-4 search tree.
  // // auto removeNode(std::shared_ptr<QuadNode<ItemType>> nodePtr);
  // //
  // // // Removes the leftmost node in the left subtree of the node
  // // // pointed to by nodePtr.
  // // // Sets inorderSuccessor to the value in this node.
  // // // Returns a pointer to the revised subtree.
  // // auto removeLeftmostNode(std::shared_ptr<QuadNode<ItemType>>subTreePtr,
  // //                         ItemType& inorderSuccessor);

  // // Returns a pointer to the node containing the given value,
  // // or nullptr if not found.
  // std::shared_ptr<QuadNode<ItemType>> findNode(std::shared_ptr<QuadNode<ItemType>> treePtr,
  //               const ItemType& target, bool& success) const;

public:
  // //------------------------------------------------------------
  // // Constructor and Destructor Section.
  // //------------------------------------------------------------
  // Balanced234Tree();
  // Balanced234Tree(const ItemType &rootItem);
  // Balanced234Tree(const Balanced234Tree<ItemType> &tree);
  // virtual ~Balanced234Tree();

  // //------------------------------------------------------------
  // // Public Methods Section.
  // //------------------------------------------------------------
  // bool isEmpty() const;
  // int getHeight() const;
  // int getNumberOfNodes() const;

  // ItemType getRootData() const; // throw(PrecondViolatedExcept);
  // void setRootData(const ItemType &newData);

  // bool add(const ItemType &newEntry);
  // bool remove(const ItemType &target);
  // void clear();

  // ItemType getEntry(const ItemType &anEntry) const; // throw(NotFoundException);
  // bool contains(const ItemType &anEntry) const;

  // //------------------------------------------------------------
  // // Public Traversals Section.
  // //------------------------------------------------------------
  // void preorderTraverse(void visit(ItemType &)) const;
  // void inorderTraverse(void visit(ItemType &)) const;
  // void postorderTraverse(void visit(ItemType &)) const;

  // void preorderTraverse(std::function<void(std::shared_ptr<QuadNode<ItemType>>)> visit) const;
  // void inorderTraverse(std::function<void(std::shared_ptr<QuadNode<ItemType>>)> visit) const;
  // void postorderTraverse(std::function<void(std::shared_ptr<QuadNode<ItemType>>)> visit) const;

  // //------------------------------------------------------------
  // // Overloaded Operator Section.
  // //------------------------------------------------------------
  // Balanced234Tree<ItemType> &
  // operator=(const Balanced234Tree<ItemType> &rightHandSide);
}; // end Balanced234Tree

// #include "Balanced234Tree.cpp"
#endif

// template <class ItemType>
// int Balanced234Tree<ItemType>::
//     getHeightHelper(std::shared_ptr<QuadNode<ItemType>> subTreePtr) const
// {
//   if (subTreePtr == nullptr)
//     return 0;
//   else
//     return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()));
// }  // end getHeightHelper

// template<class ItemType>
// int Balanced234Tree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<QuadNode<ItemType>> subTreePtr) const
// {
//   if (subTreePtr == nullptr)
//     return 0;
//   else
//     return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) +
//            getNumberOfNodesHelper(subTreePtr->getMidLeftChildPtr()) +
//            getNumberOfNodesHelper(subTreePtr->getMidRightChildPtr()) +
//            getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
// } // end getNumberOfNodesHelper

// template <class ItemType>
// void Balanced234Tree<ItemType>::split(std::shared_ptr<QuadNode<ItemType>> subTreePtr, 
//   std::shared_ptr<QuadNode<ItemType>> childPtr)
// {
//   if (childPtr->isFourNode()) {
//     // if node is full
//     // split the node

//     // create new node with child's small value 
//     auto newLeftNodePtr = std::make_shared<QuadNode<ItemType>>(childPtr->getSmallItem());

//     // create new node with child's large value 
//     auto newRightNodePtr = std::make_shared<QuadNode<ItemType>>(childPtr->getLargeItem());

//     // Update parent with child's middle item
//     subTreePtr->setItemInOrder(childPtr->getMiddleItem());

//     // return middle item to parent
//     // parent updates node with middle item
//     // then continues to recurse 
//     // subTreePtr->getMiddleItem();
//   } 
//   return;
// }

// template <class ItemType>
// auto Balanced234Tree<ItemType>::placeNode(std::shared_ptr<QuadNode<ItemType>> subTreePtr,
//                std::shared_ptr<QuadNode<ItemType>> newNode)
// {
//   // if (subTreePtr == nullptr)
//   // {
//   //   // insert here
//   //   // return the new node for the parent to link
//   //   return newNode;
//   // }

//   // if node is a duplicate
//   if (newNode->getItem() == subTreePtr->getSmallItem() ||
//       newNode->getItem() == subTreePtr->getMiddleItem() ||
//       newNode->getItem() == subTreePtr->getLargeItem())
//   {
//     // do nothing
//     // return subTreePtr
//   }

//   // determine subtree 
//   auto nextSubtreePtr;

//   if (subTreePtr->isTwoNode()) {
//     // if 2-node

//     if (newNode->getItem() < subTreePtr->getSmallItem())
//     {
//       // leftPtr
//       nextSubtreePtr = subTreePtr->leftPtr;
//     } else {
//       // leftMidPtr
//     }
//   } else if (subTreePtr->isThreeNode()) {
//     // if 3-node

//     if (newNode->getItem() < subTreePtr->getSmallItem())
//     {
//       // leftPtr
//       auto ptr = placeNode(subTreePtr->leftPtr, newNode);
//       subTreePtr->leftPtr = ptr;
//     } else if (newNode->getItem() < subTreePtr->getMiddleItem()) {
//       // leftMidPtr
//     } else {
//       // rightMidPtr
//     }
//   }

//   // if not nullptr
//   if (nextSubtreePtr != nullptr) {
//     // split child if it is full
//     if (nextSubtreePtr->isFourNode()) {
//       split(subTreePtr, nextSubtreePtr);
//     }
//   } else {
//     // insert ?
//   }

//   // auto ptr = placeNode(nextSubtree, newNode);

//   return subTreePtr;
// }


// template <class ItemType>
// std::shared_ptr<QuadNode<ItemType>> Balanced234Tree<ItemType>::removeValue(std::shared_ptr<QuadNode<ItemType>> &subTreePtr, const ItemType target, bool &isSuccessful)
// {
//   // never reached
//   // // if empty tree
//   // if (subTreePtr == nullptr) {
//   //   isSuccessful = false;
//   //   return subTreePtr;
//   // }

//   // item to remove is root of a subtree
//   if (subTreePtr->getItem() == target) {
//     subTreePtr = this->removeNode(subTreePtr);                      // removeNode will handle deletion, and return the link for the parent to set
//     isSuccessful = true;
//   }
//   else if (subTreePtr->getItem() > target)
//   {
//     // check left subtree
//     auto left = subTreePtr->getLeftChildPtr();
//     if (left != nullptr) {
//       auto tempPtr = removeValue(left, target, isSuccessful);   // returns link
//       subTreePtr->setLeftChildPtr(tempPtr);                     // set left child to new link, this is where real deletion happens
//     } else {
//       isSuccessful = false;
//     }
//   } else {
//     // check right subtree
//     auto right = subTreePtr->getRightChildPtr();
//     if (right != nullptr) {
//       auto tempPtr = removeValue(right, target, isSuccessful);  // returns link
//       subTreePtr->setRightChildPtr(tempPtr);                   // set left child to new link, this is where real deletion happens
//     } else {
//       isSuccessful = false;
//     }
//   }

//   return subTreePtr;
// }

// template <class ItemType>
// std::shared_ptr<QuadNode<ItemType>> Balanced234Tree<ItemType>::findNode(std::shared_ptr<QuadNode<ItemType>> treePtr, const ItemType& target, bool& success) const
// {
//   if (treePtr == nullptr) {
//     success = false;
//     return nullptr;
//   }

//   if (treePtr->getItem() == target) {
//     success = true;
//     return treePtr;
//   } else if (treePtr->getItem() > target) {
//     auto left = treePtr->getLeftChildPtr();
//     if (left != nullptr){ 
//       return findNode(left, target, success);
//     } else {
//       success = false;
//       return nullptr;
//     }
//   } else {
//     auto right = treePtr->getRightChildPtr();
//     if (right != nullptr){ 
//       return findNode(right, target, success);
//     } else {
//       success = false;
//       return nullptr;
//     }
//   }
// }

// template <class ItemType>
// inline Balanced234Tree<ItemType>::Balanced234Tree() : rootPtr(nullptr)
// {
// }
// template <class ItemType>
// inline Balanced234Tree<ItemType>::Balanced234Tree(const ItemType &rootItem)
// {
//   this->rootPtr = std::make_shared<QuadNode<ItemType>>(rootItem);
// }

// template <class ItemType>
// inline Balanced234Tree<ItemType>::Balanced234Tree(const Balanced234Tree<ItemType> &tree)
// {
//   this->rootPtr = this->copyTree(tree.rootPtr);
// }

// template <class ItemType>
// inline Balanced234Tree<ItemType>::~Balanced234Tree()
// {
//   this->destroyTree(this->rootPtr);
// }

// template <class ItemType>
// inline bool Balanced234Tree<ItemType>::isEmpty() const
// {
//   return this->rootPtr == nullptr;
// }

// template <class ItemType>
// inline int Balanced234Tree<ItemType>::getHeight() const
// {
//   return this->getHeightHelper(this->rootPtr);
// }

// template <class ItemType>
// inline int Balanced234Tree<ItemType>::getNumberOfNodes() const
// {
//   return this->getNumberOfNodesHelper(this->rootPtr);
// }

// template <class ItemType>
// inline ItemType Balanced234Tree<ItemType>::getRootData() const
// {
//   if (isEmpty())
//     throw PrecondViolatedExcept("getRootData() called with empty tree.");
//   return this->rootPtr->getItem();
// }

// template <class ItemType>
// inline void Balanced234Tree<ItemType>::setRootData(const ItemType &newData)
// {
//   if (isEmpty())
//     this->rootPtr = std::make_shared<QuadNode<ItemType>>(newData);
//   else
//     this->rootPtr->setItem(newData);
// }

// template <class ItemType>
// inline bool Balanced234Tree<ItemType>::add(const ItemType &newEntry)
// {
//   auto newNodePtr = std::make_shared<QuadNode<ItemType>>(newEntry);
//   this->rootPtr = placeNode(this->rootPtr, newNodePtr);
//   return true;
// }

// template <class ItemType>
// inline bool Balanced234Tree<ItemType>::remove(const ItemType &target)
// {
//   bool isSuccessful = false;
//   this->rootPtr = removeValue(this->rootPtr, target, isSuccessful);
//   return isSuccessful;
// }

// template <class ItemType>
// inline void Balanced234Tree<ItemType>::clear()
// {
//   this->destroyTree(this->rootPtr);
//   this->rootPtr = nullptr;
// }

// // Need to update for BST
// template <class ItemType>
// inline ItemType Balanced234Tree<ItemType>::getEntry(const ItemType &anEntry) const
// {
//   bool success = false;
//   auto node = findNode(rootPtr, anEntry, success);
//   if (success) {
//     return node->getItem();
//   } else {
//     throw NotFoundException("Item not found in tree");
//   }
// }

// // Need to update for BST
// template <class ItemType>
// inline bool Balanced234Tree<ItemType>::contains(const ItemType &anEntry) const
// {
//   try
//   {
//     bool success = false;
//     findNode(rootPtr, anEntry, success);
//     return success;
//   }
//   catch (NotFoundException &e)
//   {
//     return false;
//   }
// }

// template <class ItemType>
// inline void Balanced234Tree<ItemType>::preorderTraverse(void visit(ItemType &)) const
// {
//   auto visitWrapper = [&visit](std::shared_ptr<QuadNode<ItemType>> curPtr)
//   {
//     ItemType item = curPtr->getItem();
//     visit(item);
//   };
//   this->preorder(visitWrapper, rootPtr);
// }

// template <class ItemType>
// inline void Balanced234Tree<ItemType>::inorderTraverse(void visit(ItemType &)) const
// {
//   auto visitWrapper = [&visit](std::shared_ptr<QuadNode<ItemType>> curPtr)
//   {
//     ItemType item = curPtr->getItem();
//     visit(item);
//   };
//   this->inorder(visitWrapper, this->rootPtr);
// }

// template <class ItemType>
// inline void Balanced234Tree<ItemType>::postorderTraverse(void visit(ItemType &)) const
// {
//   auto visitWrapper = [&visit](std::shared_ptr<QuadNode<ItemType>> curPtr)
//   {
//     ItemType item = curPtr->getItem();
//     visit(item);
//   };
//   this->postorder(visitWrapper, this->rootPtr);
// }

// template <class ItemType>
// void Balanced234Tree<ItemType>::preorderTraverse(std::function<void(std::shared_ptr<QuadNode<ItemType>>)> visit) const
// {
//   this->preorder(visit, this->rootPtr);
// }

// template <class ItemType>
// void Balanced234Tree<ItemType>::inorderTraverse(std::function<void(std::shared_ptr<QuadNode<ItemType>>)> visit) const
// {
//   this->inorder(visit, this->rootPtr);
// }

// template <class ItemType>
// void Balanced234Tree<ItemType>::postorderTraverse(std::function<void(std::shared_ptr<QuadNode<ItemType>>)> visit) const
// {
//   this->postorder(visit, this->rootPtr);
// }

// template <class ItemType>
// inline Balanced234Tree<ItemType> &Balanced234Tree<ItemType>::operator=(const Balanced234Tree<ItemType> &rightHandSide)
// {
//   if (this != &rightHandSide)
//   {
//     this->destroyTree(this->rootPtr);
//     this->rootPtr = this->copyTree(rightHandSide.rootPtr);
//   }
//   return *this;
// }