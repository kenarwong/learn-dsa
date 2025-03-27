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

  //------------------------------------------------------------
  //    Private Utility Methods Section:
  //    Recursive helper methods for the public methods.
  //------------------------------------------------------------
  int getHeightHelper(std::shared_ptr<QuadNode<ItemType>> subTreePtr) const;
  int getNumberOfNodesHelper(std::shared_ptr<QuadNode<ItemType>> subTreePtr) const;
   
  // Places a value in the correct node in the tree
  bool placeValue(std::shared_ptr<QuadNode<ItemType>> subTreePtr,
                 const ItemType& newValue);

  // Splits a child 4-node, updates current node with middle value,
  // links split children to parent node.
  std::shared_ptr<QuadNode<ItemType>> split(
      std::shared_ptr<QuadNode<ItemType>> subTreePtr,
      std::shared_ptr<QuadNode<ItemType>> childPtr);

  void destroyTree(std::shared_ptr<QuadNode<ItemType>>& subTreePtr);

protected:
          
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

  // Returns a pointer to the node containing the given value,
  // or nullptr if not found.
  std::shared_ptr<QuadNode<ItemType>> findNode(std::shared_ptr<QuadNode<ItemType>> subTreePtr, const ItemType &targets) const;

public:
  //------------------------------------------------------------
  // Constructor and Destructor Section.
  //------------------------------------------------------------
  Balanced234Tree();
  Balanced234Tree(const ItemType &rootItem);
  virtual ~Balanced234Tree();

  //------------------------------------------------------------
  // Public Methods Section.
  //------------------------------------------------------------
  bool isEmpty() const;
  int getHeight() const;
  int getNumberOfNodes() const;

  bool add(const ItemType &newEntry);
  bool remove(const ItemType &target);
  void clear();

  bool contains(const ItemType &anEntry) const;

  //------------------------------------------------------------
  // Public Traversals Section.
  //------------------------------------------------------------
  // void preorderTraverse(void visit(ItemType &)) const;
  // void inorderTraverse(void visit(ItemType &)) const;
  // void postorderTraverse(void visit(ItemType &)) const;

  // void preorderTraverse(std::function<void(std::shared_ptr<QuadNode<ItemType>>)> visit) const;
  // void inorderTraverse(std::function<void(std::shared_ptr<QuadNode<ItemType>>)> visit) const;
  // void postorderTraverse(std::function<void(std::shared_ptr<QuadNode<ItemType>>)> visit) const;
};

#endif

template <class ItemType>
void Balanced234Tree<ItemType>::destroyTree(std::shared_ptr<QuadNode<ItemType>>& subTreePtr)
{
  if (subTreePtr != nullptr)
  {
    for (int i = 0; i < subTreePtr->getChildCount(); i++)
    {
      auto child = subTreePtr->getChild(i);
      destroyTree(child);
    }
    subTreePtr.reset(); // Decrement reference count to node
                        // this only ensures that there are no dangling pointers
                        // it does not directly free the memory        
                        // once all references are gone, the shared_ptr memory management recognizes this
                        // and memory will be freed
  }
}

template <class ItemType>
int Balanced234Tree<ItemType>::
    getHeightHelper(std::shared_ptr<QuadNode<ItemType>> subTreePtr) const
{
  if (subTreePtr == nullptr) {
    return 0;
  } else {
    int height = 0;
    for (int i = 0; i < subTreePtr->getChildCount(); i++)
    {
      auto child = subTreePtr->getChild(i);
      int childHeight = getHeightHelper(child);
      if (childHeight > height)
      {
        height = childHeight;
      }
    }

    return 1 + height;
  }
}

template<class ItemType>
int Balanced234Tree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<QuadNode<ItemType>> subTreePtr) const
{
  if (subTreePtr == nullptr) {
    return 0;
  } else if (subTreePtr->isLeaf()) {
    return 1;
  } else {
    int numNodes = 0;
    for (int i = 0; i < subTreePtr->getChildCount(); i++)
    {
      auto child = subTreePtr->getChild(i);
      numNodes += getNumberOfNodesHelper(child);
    }
    return 1 + numNodes;
  }
}

template <class ItemType>
std::shared_ptr<QuadNode<ItemType>> Balanced234Tree<ItemType>::split(
  std::shared_ptr<QuadNode<ItemType>> subTreePtr, 
  std::shared_ptr<QuadNode<ItemType>> childPtr
) {
  // split if child node is full
  if (childPtr->isFourNode()) {
    auto newLeftNodePtr = std::make_shared<QuadNode<ItemType>>(
      childPtr->getItem(0)
    );
    auto newRightNodePtr = std::make_shared<QuadNode<ItemType>>(
      childPtr->getItem(2)
    );

    // leaf nodes don't have children
    if (!childPtr->isLeaf()) {
      // children of new node are original's 2 left children
      newLeftNodePtr->insertChild(childPtr->getChild(0), 0);
      newLeftNodePtr->insertChild(childPtr->getChild(1), 1);

      // children of new node to original's 2 right children
      newRightNodePtr->insertChild(childPtr->getChild(2), 0);
      newRightNodePtr->insertChild(childPtr->getChild(3), 1);
    }

    // if parent is null (child is root)
    if (subTreePtr == nullptr) {
      // create new node with middle value, set children to new nodes
      return std::make_shared<QuadNode<ItemType>>(
        childPtr->getItem(1),
        newLeftNodePtr,
        newRightNodePtr
      );
    } else {
      // if parent is not null
      // insert middle value into parent
      int pos = subTreePtr->insertItem(childPtr->getItem(1));

      // remove current child from parent
      subTreePtr->removeChild(pos);

      // set children of parent to new nodes
      subTreePtr->insertChild(newLeftNodePtr, pos);
      subTreePtr->insertChild(newRightNodePtr, pos+1);
    }
  } 

  return subTreePtr;
}

template <class ItemType>
bool Balanced234Tree<ItemType>::placeValue(
  std::shared_ptr<QuadNode<ItemType>> subTreePtr,
  const ItemType& newValue
) {
  // Empty tree
  if (subTreePtr == nullptr) {
    return false;
  }

  // node is parent and never full
  // can only perform splits on children
  if (subTreePtr->isFourNode()) {
    return false;
  }

  // if this node is leaf, insert
  if (subTreePtr->isLeaf()) {
    subTreePtr->insertItem(newValue);
    return true;
  } else {
    // if not leaf node (internal)

    // find child to insert value
    int i = 0;
    while (i < subTreePtr->getItemCount()) {
      if (newValue < subTreePtr->getItem(i)) {
        break;
      }
      i++;
    }
    auto child = subTreePtr->getChild(i);

    // split child if full
    if (child->isFourNode()) {
      split(subTreePtr, child);

      // find child again after split
      int i = 0;
      while (i < subTreePtr->getItemCount()) {
        if (newValue < subTreePtr->getItem(i)) {
          break;
        }
        i++;
      }
      child = subTreePtr->getChild(i);
    }

    // traverse to child
    return placeValue(child, newValue);
  }
}


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

template <class ItemType>
std::shared_ptr<QuadNode<ItemType>> Balanced234Tree<ItemType>::findNode(std::shared_ptr<QuadNode<ItemType>> subTreePtr, const ItemType& target) const
{
  if (subTreePtr == nullptr) {
    return nullptr;
  }

  // search keys
  int i = 0;
  while (i < subTreePtr->getItemCount())
  {
    if (target < subTreePtr->getItem(i))
    {
      break;
    } else if (target == subTreePtr->getItem(i)) {
      return subTreePtr; // found
    }
    i++;
  }
  auto child = subTreePtr->getChild(i);

  // search child
  return findNode(child, target);
}

template <class ItemType>
inline Balanced234Tree<ItemType>::Balanced234Tree() : rootPtr(nullptr)
{
}
template <class ItemType>

inline Balanced234Tree<ItemType>::Balanced234Tree(const ItemType &rootItem)
{
  this->rootPtr = std::make_shared<QuadNode<ItemType>>(rootItem);
}

template <class ItemType>
inline Balanced234Tree<ItemType>::~Balanced234Tree()
{
  destroyTree(this->rootPtr);
}

template <class ItemType>
inline bool Balanced234Tree<ItemType>::isEmpty() const
{
  return this->rootPtr == nullptr;
}

template <class ItemType>
inline int Balanced234Tree<ItemType>::getHeight() const
{
  return this->getHeightHelper(this->rootPtr);
}

template <class ItemType>
inline int Balanced234Tree<ItemType>::getNumberOfNodes() const
{
  return this->getNumberOfNodesHelper(this->rootPtr);
}

template <class ItemType>
inline bool Balanced234Tree<ItemType>::add(const ItemType &newEntry)
{
  // Empty tree
  if (this->rootPtr == nullptr) {
    this->rootPtr = std::make_shared<QuadNode<ItemType>>(newEntry);
    return true;
  }
  
  // Split root if full
  if (this->rootPtr->isFourNode()) {
    // Root is full
    this->rootPtr = this->split(nullptr, this->rootPtr);
  }

  // Place value
  return placeValue(this->rootPtr, newEntry);
}

template <class ItemType>
inline bool Balanced234Tree<ItemType>::remove(const ItemType &target)
{
  // bool isSuccessful = false;
  // this->rootPtr = removeValue(this->rootPtr, target, isSuccessful);
  // return isSuccessful;
  return false;
}

template <class ItemType>
inline void Balanced234Tree<ItemType>::clear()
{
  this->destroyTree(this->rootPtr);
  this->rootPtr = nullptr;
}

template <class ItemType>
inline bool Balanced234Tree<ItemType>::contains(const ItemType &anEntry) const
{
  try
  {
    std::shared_ptr<QuadNode<ItemType>> node = findNode(this->rootPtr, anEntry);
    if (node == nullptr)
    {
      return false;
    }

    return true;
  }
  catch (NotFoundException &e)
  {
    return false;
  }

  return false;
}

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