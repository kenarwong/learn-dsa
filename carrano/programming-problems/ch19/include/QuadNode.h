/** A class of nodes for a link-based 2-3-4 tree.
 @file QuadNode.h */
 
#ifndef QUAD_NODE_
#define QUAD_NODE_

#include "helpers.h"

template<class ItemType>
class QuadNode
{
private:
  ItemType smallItem, middleItem, largeItem;         // Data portion
  std::shared_ptr<QuadNode<ItemType>> leftChildPtr;  // Left-child pointer
  std::shared_ptr<QuadNode<ItemType>> leftMidChildPtr;   // Middle-left-child pointer
  std::shared_ptr<QuadNode<ItemType>> rightMidChildPtr;   // Middle-right-child pointer
  std::shared_ptr<QuadNode<ItemType>> rightChildPtr; // Right-child pointer
   
public:
  QuadNode();
  QuadNode(const ItemType& anItem);
  QuadNode(const ItemType& firstItem,
      const ItemType& secondItem);
  QuadNode(const ItemType& firstItem,
      const ItemType& secondItem,
      const ItemType& thirdItem);
  QuadNode(const ItemType& anItem,
      std::shared_ptr<QuadNode<ItemType>> leftPtr,
      std::shared_ptr<QuadNode<ItemType>> leftMidPtr,
      std::shared_ptr<QuadNode<ItemType>> rightMidPtr,
      std::shared_ptr<QuadNode<ItemType>> rightPtr);
  QuadNode(const ItemType& anItem,
      const ItemType& secondItem,
      std::shared_ptr<QuadNode<ItemType>> leftPtr,
      std::shared_ptr<QuadNode<ItemType>> leftMidPtr,
      std::shared_ptr<QuadNode<ItemType>> rightMidPtr,
      std::shared_ptr<QuadNode<ItemType>> rightPtr);
  QuadNode(const ItemType& anItem,
      const ItemType& secondItem,
      const ItemType& thirdItem,
      std::shared_ptr<QuadNode<ItemType>> leftPtr,
      std::shared_ptr<QuadNode<ItemType>> leftMidPtr,
      std::shared_ptr<QuadNode<ItemType>> rightMidPtr,
      std::shared_ptr<QuadNode<ItemType>> rightPtr);
  
  bool isLeaf() const;
  bool isTwoNode() const;
  bool isThreeNode() const;
  bool isFourNode() const;
  
  ItemType getSmallItem() const;
  ItemType getMiddleItem() const;
  ItemType getLargeItem() const;
  
  void setSmallItem(const ItemType& anItem);
  void setMiddleItem(const ItemType& anItem);
  void setLargeItem(const ItemType& anItem);
  void setItemInOrder(const ItemType& anItem);
  
  auto getLeftChildPtr() const;
  auto getLeftMidChildPtr() const;
  auto getRightMidChildPtr() const;
  auto getRightChildPtr() const;
  
  void setLeftChildPtr(std::shared_ptr<QuadNode<ItemType>> leftPtr);
  void setLeftMidChildPtr(std::shared_ptr<QuadNode<ItemType>> leftMidPtr);
  void setRightMidChildPtr(std::shared_ptr<QuadNode<ItemType>> rightMidPtr);
  void setRightChildPtr(std::shared_ptr<QuadNode<ItemType>> rightPtr);
  void setNextChildPtrInOrder(std::shared_ptr<QuadNode<ItemType>> nextChildPtr);
}; // end QuadNode

template<class ItemType>
QuadNode<ItemType>::QuadNode() : 
  leftChildPtr(nullptr), 
  leftMidChildPtr(nullptr), 
  rightMidChildPtr(nullptr), 
  rightChildPtr(nullptr), 
  item(ItemType())
{
}  // end default constructor

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType& anItem) : 
  leftChildPtr(nullptr), 
  leftMidChildPtr(nullptr), 
  rightMidChildPtr(nullptr), 
  rightChildPtr(nullptr), 
  smallItem(anItem), 
  middleItem(ItemType()), 
  largeItem(ItemType())
{
}  // end constructor

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType& firstItem,
               const ItemType& secondItem) : 
  leftChildPtr(nullptr), 
  leftMidChildPtr(nullptr), 
  rightMidChildPtr(nullptr), 
  rightChildPtr(nullptr), 
  smallItem(firstItem), 
  middleItem(secondItem), 
  largeItem(ItemType())
{
}  // end constructor

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType& firstItem,
               const ItemType& secondItem,
               const ItemType& thirdItem) : 
  leftChildPtr(nullptr), 
  leftMidChildPtr(nullptr), 
  rightMidChildPtr(nullptr), 
  rightChildPtr(nullptr), 
  smallItem(firstItem), 
  middleItem(secondItem), 
  largeItem(thirdItem)
{
}  // end constructor

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType& anItem,
                                 std::shared_ptr<QuadNode<ItemType>> leftPtr,
                                 std::shared_ptr<QuadNode<ItemType>> leftMidPtr,
                                 std::shared_ptr<QuadNode<ItemType>> rightMidPtr,
                                 std::shared_ptr<QuadNode<ItemType>> rightPtr) : 
  leftChildPtr(leftPtr), 
  leftMidChildPtr(leftMidPtr), 
  rightMidChildPtr(rightMidPtr), 
  rightChildPtr(rightPtr),
  smallItem(anItem), 
  middleItem(ItemType()), 
  largeItem(ItemType())
{
}  // end constructor

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType& firstItem,
               const ItemType& secondItem,
               std::shared_ptr<QuadNode<ItemType>> leftPtr,
               std::shared_ptr<QuadNode<ItemType>> leftMidPtr,
               std::shared_ptr<QuadNode<ItemType>> rightMidPtr,
               std::shared_ptr<QuadNode<ItemType>> rightPtr) : 
  leftChildPtr(leftPtr), 
  leftMidChildPtr(leftMidPtr), 
  rightMidChildPtr(rightMidPtr), 
  rightChildPtr(rightPtr),
  smallItem(firstItem), 
  middleItem(secondItem), 
  largeItem(ItemType())
{
}  // end constructor

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType& firstItem,
               const ItemType& secondItem,
               const ItemType& thirdItem,
               std::shared_ptr<QuadNode<ItemType>> leftPtr,
               std::shared_ptr<QuadNode<ItemType>> leftMidPtr,
               std::shared_ptr<QuadNode<ItemType>> rightMidPtr,
               std::shared_ptr<QuadNode<ItemType>> rightPtr) : 
  leftChildPtr(leftPtr), 
  leftMidChildPtr(leftMidPtr), 
  rightMidChildPtr(rightMidPtr), 
  rightChildPtr(rightPtr),
  smallItem(firstItem), 
  middleItem(secondItem), 
  largeItem(thirdItem)
{
}  // end constructor

template <class ItemType>
QuadNode<ItemType>::~QuadNode()
{
  // auto item = this->getItem();
  // std::cout << "Node with item " << item << " destroyed" << std::endl;
}

template<class ItemType>
bool QuadNode<ItemType>::isLeaf() const
{
  return (leftChildPtr == nullptr
          && leftMidChildPtr == nullptr
          && rightMidChildPtr == nullptr
          && rightChildPtr == nullptr);
}  // end isLeaf

template<class ItemType>
bool QuadNode<ItemType>::isTwoNode() const
{
  return (middleItem == ItemType() && largeItem == ItemType());
}  // end isTwoNode

template<class ItemType>
bool QuadNode<ItemType>::isThreeNode() const
{
  return (middleItem != ItemType() && largeItem == ItemType());
}  // end isThreeNode

template<class ItemType>
bool QuadNode<ItemType>::isFourNode() const
{
  return (middleItem != ItemType() && largeItem != ItemType());
}  // end isFourNode

template<class ItemType>
ItemType QuadNode<ItemType>::getSmallItem() const
{
  return smallItem;
}  // end getSmallItem

template<class ItemType>
ItemType QuadNode<ItemType>::getMiddleItem() const
{
  return middleItem;
}  // end getMiddleItem

template<class ItemType>
ItemType QuadNode<ItemType>::getLargeItem() const
{
  return largeItem;
}  // end getLargeItem

template<class ItemType>
void QuadNode<ItemType>::setSmallItem(const ItemType& anItem)
{
  smallItem = anItem;
}  // end setSmallItem

template<class ItemType>
void QuadNode<ItemType>::setMiddleItem(const ItemType& anItem)
{
  middleItem = anItem;
}  // end setMiddleItem

template<class ItemType>
void QuadNode<ItemType>::setLargeItem(const ItemType& anItem)
{
  largeItem = anItem;
}  // end setLargeItem

template <class ItemType>
void QuadNode<ItemType>::setItemInOrder(const ItemType &anItem)
{
  if (isTwoNode()) {
    if (anItem < smallItem) {
      setMiddleItem(getSmallItem());
      setSmallItem(anItem);
    } else {
      setMiddleItem(anItem);
    }
  } else if (isThreeNode()) {
    if (anItem < smallItem) {
      setLargeItem(getMiddleItem());
      setMiddleItem(getSmallItem());
      setSmallItem(anItem);
    } else if (anItem < middleItem) {
      setLargeItem(getMiddleItem());
      setMiddleItem(anItem);
    } else {
      setLargeItem(anItem);
    }
  }
}

template<class ItemType>
auto QuadNode<ItemType>::getLeftMidChildPtr() const
{
  return leftMidChildPtr;
}  // end getLeftMidChildPtr

template<class ItemType>
auto QuadNode<ItemType>::getLeftChildPtr() const
{
  return leftChildPtr;
}  // end getLeftChildPtr

template<class ItemType>
auto QuadNode<ItemType>::getRightChildPtr() const
{
  return rightChildPtr;
}  // end getRightChildPtr

template<class ItemType>
auto QuadNode<ItemType>::getRightMidChildPtr() const
{
  return rightMidChildPtr;
}  // end getRightMidChildPtr

template<class ItemType>
void QuadNode<ItemType>::setLeftMidChildPtr(std::shared_ptr<QuadNode<ItemType>> leftMidPtr)
{
  leftMidChildPtr = leftMidPtr;
}  // end setLeftMidChildPtr

template<class ItemType>
void QuadNode<ItemType>::setLeftChildPtr(std::shared_ptr<QuadNode<ItemType>> leftPtr)
{
  leftChildPtr = leftPtr;
}  // end setLeftChildPtr

template<class ItemType>
void QuadNode<ItemType>::setRightChildPtr(std::shared_ptr<QuadNode<ItemType>> rightPtr)
{
  rightChildPtr = rightPtr;
}  // end setRightChildPtr

template <class ItemType>
void QuadNode<ItemType>::setNextChildPtrInOrder(std::shared_ptr<QuadNode<ItemType>> nextChildPtr)
{
  if (leftChildPtr == nullptr) {
    setLeftChildPtr(nextChildPtr);
  } else if (leftMidChildPtr == nullptr) {
    setLeftMidChildPtr(nextChildPtr);
  } else if (rightMidChildPtr == nullptr) {
    setRightMidChildPtr(nextChildPtr);
  } else {
    setRightChildPtr(nextChildPtr);
  }
}

template<class ItemType>
void QuadNode<ItemType>::setRightMidChildPtr(std::shared_ptr<QuadNode<ItemType>> rightMidPtr)
{
  rightMidChildPtr = rightMidPtr;
}  // end setRightMidChildPtr

#endif