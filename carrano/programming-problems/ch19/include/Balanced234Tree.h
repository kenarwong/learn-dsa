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

  void destroyTree(std::shared_ptr<QuadNode<ItemType>>& subTreePtr);
   
  // Places a value in the correct node in the tree
  bool placeValue(std::shared_ptr<QuadNode<ItemType>> subTreePtr,
                 const ItemType& newValue);

  // Splits a child 4-node, updates current node with middle value,
  // links split children to parent node.
  std::shared_ptr<QuadNode<ItemType>> split(
      std::shared_ptr<QuadNode<ItemType>> subTreePtr,
      std::shared_ptr<QuadNode<ItemType>> childPtr);

  // Returns a pointer to the node containing the given value,
  // or nullptr if not found.
  std::shared_ptr<QuadNode<ItemType>> findNode(std::shared_ptr<QuadNode<ItemType>> subTreePtr, const ItemType &targets) const;

  // Rotates an item from a sibling node into the parent node,
  // then an item from the parent node into the destination node.
  void rotate(std::shared_ptr<QuadNode<ItemType>> subTreePtr, int fromChildPos, int toChildPos);

  // Fuses 3 items: 1 item from the parent, and 1 item from each 2-node child
  std::shared_ptr<QuadNode<ItemType>> fuse(
    std::shared_ptr<QuadNode<ItemType>> subTreePtr,
    int parentItemPos
  );

  // Removes the given target value from the tree while maintaining a
  // 2-3-4 search tree.
  bool removeValue(std::shared_ptr<QuadNode<ItemType>>& subTreePtr,
                   const ItemType target);
  
  ItemType findMax(std::shared_ptr<QuadNode<ItemType>> subTreePtr) const;
  ItemType findMin(std::shared_ptr<QuadNode<ItemType>> subTreePtr) const;

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
  void preorderTraverse(std::function<void(ItemType*,int)> visit, std::shared_ptr<QuadNode<ItemType>> curPtr) const;
  void preorder(std::function<void(ItemType*,int)> visit) const;
  // void inorder(void visit(ItemType &)) const;
  // void postorder(void visit(ItemType &)) const;

  // void inorderTraverse(std::function<void(std::shared_ptr<QuadNode<ItemType>>)> visit) const;
  // void postorderTraverse(std::function<void(std::shared_ptr<QuadNode<ItemType>>)> visit) const;
};

#endif

template<class ItemType>
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

template<class ItemType>
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

template<class ItemType>
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

template<class ItemType>
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

template<class ItemType>
void Balanced234Tree<ItemType>::rotate(
  std::shared_ptr<QuadNode<ItemType>> subTreePtr,
  int fromChildPos,
  int toChildPos
) {
  auto fromChild = subTreePtr->getChild(fromChildPos);
  auto toChild = subTreePtr->getChild(toChildPos);

  if (fromChildPos < toChildPos) {
    // if fromChildPos is left of toChildPos (rotate right)

    // move rightmost item from parent to right child
    toChild->insertItem(subTreePtr->getItem(toChildPos-1));
    subTreePtr->removeItem(toChildPos-1);

    // move rightmost item from left child to parent
    subTreePtr->insertItem(fromChild->getItem(fromChild->getItemCount()-1));
    fromChild->removeLastItem();

    // if not leaf
    if (fromChild->getChildCount() > 0) {
      // move rightmost child from left child to leftmost child of right child
      toChild->insertFirstChild(fromChild->getChild(fromChild->getChildCount()-1));
      fromChild->removeLastChild();
    }

  } else {
    // if fromChildPos is right of toChildPos (rotate left)

    // move leftmost item from parent to left child
    toChild->insertItem(subTreePtr->getItem(toChildPos));
    subTreePtr->removeItem(toChildPos);

    // move leftmost item from right child to parent
    subTreePtr->insertItem(fromChild->getItem(0));
    fromChild->removeFirstItem();

    // if not leaf
    if (fromChild->getChildCount() > 0) {
      // move leftmost child from right child to rightmost child of left child
      toChild->insertLastChild(fromChild->getChild(0));
      fromChild->removeFirstChild();
    }
  }
}

template <class ItemType>
std::shared_ptr<QuadNode<ItemType>> Balanced234Tree<ItemType>::fuse(
  std::shared_ptr<QuadNode<ItemType>> subTreePtr,
  int parentItemPos)
{
  // get parent item
  ItemType parentItem = subTreePtr->getItem(parentItemPos);

  // get left and right children
  // @pre both are 2-nodes
  auto left = subTreePtr->getChild(parentItemPos);
  auto right = subTreePtr->getChild(parentItemPos+1);

  // create fused node
  auto fusedNode = std::make_shared<QuadNode<ItemType>>(
    left->getItem(0),
    parentItem,
    right->getItem(0)
  );

  // if not leaf, set children
  // @pre assumed that left and right are either both leaves or both not leaves
  if (!left->isLeaf() && !right->isLeaf()) {
    fusedNode->insertChild(left->getChild(0), 0);
    fusedNode->insertChild(left->getChild(1), 1);
    fusedNode->insertChild(right->getChild(0), 2);
    fusedNode->insertChild(right->getChild(1), 3);
  }

  return fusedNode;
}

template<class ItemType>
ItemType Balanced234Tree<ItemType>::findMax(std::shared_ptr<QuadNode<ItemType>> subTreePtr) const
{
  if (subTreePtr == nullptr) {
    throw NotFoundException("Tree is empty");
  }

  if (subTreePtr->isLeaf()) {
    return subTreePtr->getItem(subTreePtr->getItemCount()-1);
  } else {
    return findMax(subTreePtr->getChild(subTreePtr->getChildCount()-1));
  }
}

template<class ItemType>
ItemType Balanced234Tree<ItemType>::findMin(std::shared_ptr<QuadNode<ItemType>> subTreePtr) const
{
  if (subTreePtr == nullptr) {
    throw NotFoundException("Tree is empty");
  }

  if (subTreePtr->isLeaf()) {
    return subTreePtr->getItem(0);
  } else {
    return findMin(subTreePtr->getChild(0));
  }
}

template<class ItemType>
bool Balanced234Tree<ItemType>::removeValue(
  std::shared_ptr<QuadNode<ItemType>> &subTreePtr, 
  const ItemType target
) {
  if (subTreePtr == nullptr) {
    return false;
  }

  // search key
  int i = 0;
  bool found = false;
  for(;i < subTreePtr->getItemCount();i++) {
    if (target < subTreePtr->getItem(i)) {
      break;
    } else if (subTreePtr->getItem(i) == target) {
      found = true;
      break;
    }
  }

  // if found
  if (found) {
    // only remove keys from leaves

    // if leaf
    if (subTreePtr->isLeaf()) {
      // if only 1 key in node
      if (subTreePtr->getItemCount() == 1) {
        // must be root, we ensure that key to delete is never 2-node
        if (subTreePtr == rootPtr) {
          // delete key, delete root
          subTreePtr->removeItem(i);
          rootPtr = nullptr;
        }
      } else {
        // if 2+ keys in node
        // delete key
        subTreePtr->removeItem(i);
      }

      return true;

    } else {
      // if internal node

      auto leftChild = subTreePtr->getChild(i);
      auto rightChild = subTreePtr->getChild(i+1);

      // if both children are 2-nodes
      if (leftChild->isTwoNode() && rightChild->isTwoNode()) {
        // fuse
        auto fusedNode = fuse(subTreePtr, i);

        // if parent is root and only 1 key
        // otherwise, not possible to have 2-node parent (due to pre-emptive merging)
        if (subTreePtr == rootPtr && subTreePtr->isTwoNode()) {
          // set new root
          rootPtr = fusedNode;
        } else {
          // reassign parent's children
          subTreePtr->removeChild(i);
          subTreePtr->insertChild(fusedNode, i);
          subTreePtr->removeChild(i+1);
          subTreePtr->removeItem(i);
        }

        // recursive remove on fused node
        return removeValue(fusedNode, target);

      } else if (!leftChild->isTwoNode()) {

        // get inorder predecessor
        ItemType pred = findMax(leftChild);
        // recursive remove predecessor
        removeValue(leftChild, pred);
        // replace target with predecessor key
        subTreePtr->replaceItem(pred, i);

      } else if (!rightChild->isTwoNode()) {

        // get inorder successor
        ItemType succ = findMin(rightChild);
        // recursive remove successor
        removeValue(rightChild, succ);
        // replace target with successor key
        subTreePtr->replaceItem(succ, i);

      }

      return true;
    }
  } else {
    // if not found at leaf, then does not exist in tree
    if (subTreePtr->isLeaf()) {
      return false;
    }

    // if not found, find next child to traverse
    auto child = subTreePtr->getChild(i);

    // pre-emptive merging
    if (child->isTwoNode()) {
      // child is 2-node

      // check rotate
      if (i > 0 && !subTreePtr->getChild(i-1)->isTwoNode()) {
        // if child is 2-node and has left sibling, and left sibling is 3+ node
        // rotate right
        rotate(subTreePtr, i-1, i);
      } else if (i < subTreePtr->getChildCount()-1 && !subTreePtr->getChild(i+1)->isTwoNode()) {
        // if child is 2-node and has right sibling, and right sibling is 3+ node
        // rotate left
        rotate(subTreePtr, i+1, i);
      } else {
        // if child is 2-node and has no 3+ node sibling
        std::shared_ptr<QuadNode<ItemType>> fusedNode;

        int first;

        // check fuse
        if (i > 0 && subTreePtr->getChild(i-1)->isTwoNode() ) {
          // if child and left sibling are 2-nodes

          // fuse
          fusedNode = fuse(subTreePtr, i-1);
          first = i-1;

        } else if (i < subTreePtr->getChildCount()-1 && subTreePtr->getChild(i+1)->isTwoNode()) {
          // if child and right sibling are 2-nodes

          // fuse
          fusedNode = fuse(subTreePtr, i);
          first = i;
        }

        // if parent is root and only 1 key
        if (subTreePtr == rootPtr && subTreePtr->isTwoNode()) {
          // set new root
          rootPtr = fusedNode;
        } else {
          // reassign parent's children
          subTreePtr->removeChild(first);
          subTreePtr->insertChild(fusedNode, first);
          subTreePtr->removeChild(first+1);
          subTreePtr->removeItem(first);
        }

        // recursive remove on fused node
        child = fusedNode;
      }
    }

    // recursive remove on child to traverse
    return removeValue(child, target);
  }
}

template<class ItemType>
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

template<class ItemType>
inline Balanced234Tree<ItemType>::Balanced234Tree() : rootPtr(nullptr) {}

template<class ItemType>
inline Balanced234Tree<ItemType>::Balanced234Tree(const ItemType &rootItem)
{
  this->rootPtr = std::make_shared<QuadNode<ItemType>>(rootItem);
}

template<class ItemType>
inline Balanced234Tree<ItemType>::~Balanced234Tree()
{
  destroyTree(this->rootPtr);
}

template<class ItemType>
inline bool Balanced234Tree<ItemType>::isEmpty() const
{
  return this->rootPtr == nullptr;
}

template<class ItemType>
inline int Balanced234Tree<ItemType>::getHeight() const
{
  return this->getHeightHelper(this->rootPtr);
}

template<class ItemType>
inline int Balanced234Tree<ItemType>::getNumberOfNodes() const
{
  return this->getNumberOfNodesHelper(this->rootPtr);
}

template<class ItemType>
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

template<class ItemType>
inline bool Balanced234Tree<ItemType>::remove(const ItemType &target)
{
  // Empty tree
  if (this->rootPtr == nullptr) {
    return false;
  }

  return removeValue(this->rootPtr, target);
}

template<class ItemType>
inline void Balanced234Tree<ItemType>::clear()
{
  this->destroyTree(this->rootPtr);
  this->rootPtr = nullptr;
}

template<class ItemType>
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

template<class ItemType>
inline void Balanced234Tree<ItemType>::preorderTraverse(
  std::function<void(ItemType*, int)> visit,
  std::shared_ptr<QuadNode<ItemType>> curPtr) const
{
  visit(curPtr->getItems(), curPtr->getItemCount());
  for (int i = 0; i < curPtr->getChildCount(); i++)
  {
    preorderTraverse(visit, curPtr->getChild(i));
  }
}

template <class ItemType>
inline void Balanced234Tree<ItemType>::preorder(
  std::function<void(ItemType*, int)> visit
) const
{
  if (this->rootPtr != nullptr)
  {
    this->preorderTraverse(visit, this->rootPtr);
  }
}

// template<class ItemType>
// inline void Balanced234Tree<ItemType>::inorderTraverse(void visit(ItemType &)) const
// {
//   auto visitWrapper = [&visit](std::shared_ptr<QuadNode<ItemType>> curPtr)
//   {
//     ItemType item = curPtr->getItem();
//     visit(item);
//   };
//   this->inorder(visitWrapper, this->rootPtr);
// }

// template<class ItemType>
// inline void Balanced234Tree<ItemType>::postorderTraverse(void visit(ItemType &)) const
// {
//   auto visitWrapper = [&visit](std::shared_ptr<QuadNode<ItemType>> curPtr)
//   {
//     ItemType item = curPtr->getItem();
//     visit(item);
//   };
//   this->postorder(visitWrapper, this->rootPtr);
// }

// template<class ItemType>
// void Balanced234Tree<ItemType>::inorderTraverse(std::function<void(std::shared_ptr<QuadNode<ItemType>>)> visit) const
// {
//   this->inorder(visit, this->rootPtr);
// }

// template<class ItemType>
// void Balanced234Tree<ItemType>::postorderTraverse(std::function<void(std::shared_ptr<QuadNode<ItemType>>)> visit) const
// {
//   this->postorder(visit, this->rootPtr);
// }