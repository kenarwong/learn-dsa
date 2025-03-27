/** A class of nodes for a link-based 2-3-4 tree.
 @file QuadNode.h */
 
#ifndef QUAD_NODE_
#define QUAD_NODE_

#include "headers.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class QuadNode
{
private:
  ItemType items[3];
  int itemCount = 0;
  std::shared_ptr<QuadNode<ItemType>> children[4]; // Child pointers
  int childCount = 0;
   
public:
  // Constructors
  QuadNode();

  // Leaf nodes
  QuadNode(const ItemType& anItem);
  QuadNode(const ItemType& firstItem,
      const ItemType& secondItem);
  QuadNode(const ItemType& firstItem,
      const ItemType& secondItem,
      const ItemType& thirdItem);

  // Internal nodes
  QuadNode(const ItemType& anItem,
      std::shared_ptr<QuadNode<ItemType>> leftPtr,
      std::shared_ptr<QuadNode<ItemType>> leftMidPtr);
  QuadNode(const ItemType& anItem,
      const ItemType& secondItem,
      std::shared_ptr<QuadNode<ItemType>> leftPtr,
      std::shared_ptr<QuadNode<ItemType>> leftMidPtr,
      std::shared_ptr<QuadNode<ItemType>> rightMidPtr);
  QuadNode(const ItemType& anItem,
      const ItemType& secondItem,
      const ItemType& thirdItem,
      std::shared_ptr<QuadNode<ItemType>> leftPtr,
      std::shared_ptr<QuadNode<ItemType>> leftMidPtr,
      std::shared_ptr<QuadNode<ItemType>> rightMidPtr,
      std::shared_ptr<QuadNode<ItemType>> rightPtr);

  ~QuadNode();
  
  bool isLeaf() const;
  bool isTwoNode() const;
  bool isThreeNode() const;
  bool isFourNode() const;

  int getItemCount() const;
  ItemType *getItems();
  ItemType getItem(int position) const;
  int getChildCount() const;
  std::shared_ptr<QuadNode<ItemType>> *getChildren();
  std::shared_ptr<QuadNode<ItemType>> getChild(int position) const;

  /**
   * Inserts an item to the node
   * 
   * @param anItem The item to insert
   * @pre The node is not full
   * @post The item is inserted into the node in order,
   *  and the item count is incremented. 
   *  Items are shifted to the right to make room for the new item, if needed.
   * @return The position of the inserted item
   */
  int insertItem(const ItemType& anItem);

  /**
   * Replaces an item in the node at the given position
   * 
   * @param anItem The item to replace the current item with
   * @param position The position of the item to replace
   * @pre The node is not empty
   * @post The item at the given position is replaced with the new item
   */
  void replaceItem(const ItemType& anItem, int position);

  /**
   * Removes an item from the node at the given position
   * 
   * @param position The position of the item to remove
   * @pre The node is not empty
   * @post The item at the given position is removed from the node,
   *  and the item count is decremented.
   *  Items to the right of the removed item are shifted to the left, if needed.
   */
  void removeItem(int position);

  void removeFirstItem();
  void removeLastItem();

  /**
   * Inserts a child node to the node
   * 
   * @param childPtr The child node to insert
   * @param position The position to insert the child node
   * @pre The node is not full
   * @post The child node is inserted into the node in the correct position,
   *  and the child count is incremented.
   *  Current children are shifted to the right to make room for the new child, if needed.
   */
  void insertChild(std::shared_ptr<QuadNode<ItemType>> childPtr, int position);

  void insertFirstChild(std::shared_ptr<QuadNode<ItemType>> childPtr);
  void insertLastChild(std::shared_ptr<QuadNode<ItemType>> childPtr);

  /**
   * Removes a child node from the node at the given position
   * 
   * @param position The position of the child to remove
   * @pre The node is not empty
   * @post The child node at the given position is removed from the node,
   *  and the child count is decremented.
   *  Children to the right of the removed child are shifted to the left, if needed.
   */
  void removeChild(int position);
  
  void removeFirstChild();
  void removeLastChild();
};

template<class ItemType>
QuadNode<ItemType>::QuadNode() {}

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType& anItem) 
{
  items[0] = anItem;
  itemCount = 1;
}

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType& firstItem,
               const ItemType& secondItem) 
{
  items[0] = firstItem;
  items[1] = secondItem;
  itemCount = 2;
}

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType& firstItem,
               const ItemType& secondItem,
               const ItemType& thirdItem) 
{
  items[0] = firstItem;
  items[1] = secondItem;
  items[2] = thirdItem;
  itemCount = 3;
}

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType& anItem,
                                 std::shared_ptr<QuadNode<ItemType>> leftPtr,
                                 std::shared_ptr<QuadNode<ItemType>> leftMidPtr) 
{
  items[0] = anItem;
  itemCount = 1;

  children[0] = leftPtr;
  children[1] = leftMidPtr;
  childCount = 2;
}

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType& firstItem,
               const ItemType& secondItem,
               std::shared_ptr<QuadNode<ItemType>> leftPtr,
               std::shared_ptr<QuadNode<ItemType>> leftMidPtr,
               std::shared_ptr<QuadNode<ItemType>> rightMidPtr) 
{
  items[0] = firstItem;
  items[1] = secondItem;
  itemCount = 2;

  children[0] = leftPtr;
  children[1] = leftMidPtr;
  children[2] = rightMidPtr;
  childCount = 3;
}

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType& firstItem,
               const ItemType& secondItem,
               const ItemType& thirdItem,
               std::shared_ptr<QuadNode<ItemType>> leftPtr,
               std::shared_ptr<QuadNode<ItemType>> leftMidPtr,
               std::shared_ptr<QuadNode<ItemType>> rightMidPtr,
               std::shared_ptr<QuadNode<ItemType>> rightPtr) 
{
  items[0] = firstItem;
  items[1] = secondItem;
  items[2] = thirdItem;
  itemCount = 3;

  children[0] = leftPtr;
  children[1] = leftMidPtr;
  children[2] = rightMidPtr;
  children[3] = rightPtr;
  childCount = 4;
}

template<class ItemType>
QuadNode<ItemType>::~QuadNode()
{
  // auto item = this->getItem();
  // std::cout << "Node with item " << item << " destroyed" << std::endl;
}

template<class ItemType>
bool QuadNode<ItemType>::isLeaf() const
{
  return (childCount == 0);
}  

template<class ItemType>
bool QuadNode<ItemType>::isTwoNode() const
{
  return (itemCount == 1);
} 

template<class ItemType>
bool QuadNode<ItemType>::isThreeNode() const
{
  return (itemCount == 2);
}  

template<class ItemType>
bool QuadNode<ItemType>::isFourNode() const
{
  return (itemCount == 3);
}

template<class ItemType>
int QuadNode<ItemType>::getItemCount() const
{
  return itemCount;
}

template<class ItemType>
ItemType *QuadNode<ItemType>::getItems() 
{
  return items;
}

template<class ItemType>
ItemType QuadNode<ItemType>::getItem(int position) const
{
  if (position < 0 || position >= itemCount)
  {
    throw PrecondViolatedExcept("Invalid item position");
  }

  return items[position];
}

template<class ItemType>
int QuadNode<ItemType>::getChildCount() const
{
  return childCount;
}

template<class ItemType>
std::shared_ptr<QuadNode<ItemType>> *QuadNode<ItemType>::getChildren() 
{
  return children;
}

template<class ItemType>
std::shared_ptr<QuadNode<ItemType>> QuadNode<ItemType>::getChild(int position) const
{
  if (position < 0 || position >= childCount)
  {
    return nullptr;
  }

  return children[position];
}

template<class ItemType>
int QuadNode<ItemType>::insertItem(const ItemType& anItem)
{
  if (itemCount < 3)
  {
    int i = 0;
    bool exists = false;
    for (; i < itemCount; i++) {
      if (anItem < items[i]) {
        for (int j = itemCount; j > i; j--) {
          items[j] = items[j-1];
        }
        break;
      } else if (anItem == items[i]) {
        exists = true;
        break;
      }
    }

    // Only insert if item does not exist
    if (!exists) {
      items[i] = anItem;
      itemCount++;
    }

    return i;
  }
  else
  {
    throw PrecondViolatedExcept("Node is full");
  }
}

template <class ItemType>
 void QuadNode<ItemType>::replaceItem(const ItemType &anItem, int position)
{
  if (position < 0 || position >= itemCount)
  {
    throw PrecondViolatedExcept("Invalid item position");
  }

  items[position] = anItem;
}

template<class ItemType>
void QuadNode<ItemType>::removeItem(int position)
{
  if (position < 0 || position >= itemCount)
  {
    throw PrecondViolatedExcept("Invalid item position");
  }

  if (itemCount > 0)
  {
    for (int i = position; i < itemCount-1; i++) {
      items[i] = items[i+1];
    }
    itemCount--;
  } else {
    throw PrecondViolatedExcept("No item to remove");
  }
}

template<class ItemType>
void QuadNode<ItemType>::removeFirstItem()
{
  removeItem(0);
}

template<class ItemType>
void QuadNode<ItemType>::removeLastItem()
{
  removeItem(itemCount-1);
}

template<class ItemType>
void QuadNode<ItemType>::insertChild(std::shared_ptr<QuadNode<ItemType>> childPtr, int position)
{
  if (position < 0 || position > childCount)
  {
    throw PrecondViolatedExcept("Invalid child position");
  }

  if (childCount < 4)
  {
    for (int j = childCount; j > position; j--) {
      children[j] = children[j-1];
    }

    children[position] = childPtr;
    childCount++;
  } else {
    throw PrecondViolatedExcept("Node is full");
  }
}

template<class ItemType>
void QuadNode<ItemType>::insertFirstChild(std::shared_ptr<QuadNode<ItemType>> childPtr)
{
  insertChild(childPtr, 0);
}

template<class ItemType>
void QuadNode<ItemType>::insertLastChild(std::shared_ptr<QuadNode<ItemType>> childPtr)
{
  insertChild(childPtr, childCount);
}

template<class ItemType>
void QuadNode<ItemType>::removeChild(int position)
{
  if (position < 0 || position >= childCount)
  {
    throw PrecondViolatedExcept("Invalid child position");
  }

  if (childCount > 0)
  {
    for (int i = position; i < childCount-1; i++) {
      children[i] = children[i+1];
      children[i+1] = nullptr;
    }
    childCount--;
  } else {
    throw PrecondViolatedExcept("No child to remove");
  }
}

template<class ItemType>
void QuadNode<ItemType>::removeFirstChild()
{
  removeChild(0);
}

template<class ItemType>
void QuadNode<ItemType>::removeLastChild()
{
  removeChild(childCount-1);
}

#endif