//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Listing 16-2.

/** A class of nodes for a link-based binary tree.
 @file BinaryNode.h */
 
#ifndef BINARY_NODE_
#define BINARY_NODE_
#include <iostream>
#include <memory>

template<class ItemType>
class BinaryNode
{
private:
   ItemType                              item;          // Data portion
   std::shared_ptr<BinaryNode<ItemType>> leftChildPtr;  // Pointer to left child
   std::shared_ptr<BinaryNode<ItemType>> rightChildPtr; // Pointer to right child
   
public:
   BinaryNode();
   BinaryNode(const ItemType& anItem);
   BinaryNode(const ItemType& anItem,
              std::shared_ptr<BinaryNode<ItemType>> leftPtr,
              std::shared_ptr<BinaryNode<ItemType>> rightPtr);
   ~BinaryNode();
   
   void setItem(const ItemType& anItem);
   ItemType getItem() const;
   
   bool isLeaf() const;
   
   auto getLeftChildPtr() const;
   auto getRightChildPtr() const;
   
   void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr);
   void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr);
}; // end BinaryNode

template<class ItemType>
BinaryNode<ItemType>::BinaryNode() : 
  leftChildPtr(nullptr), rightChildPtr(nullptr), item(ItemType())
{
}  // end default constructor

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem) : 
  leftChildPtr(nullptr), rightChildPtr(nullptr), item(anItem)
{
}  // end constructor

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
                                 std::shared_ptr<BinaryNode<ItemType>> leftPtr,
                                 std::shared_ptr<BinaryNode<ItemType>> rightPtr) : 
  item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr)
{
}  // end constructor

template <class ItemType>
BinaryNode<ItemType>::~BinaryNode()
{
  // auto item = this->getItem();
  // std::cout << "Node with item " << item << " destroyed" << std::endl;
}

template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
  item = anItem;
}  // end setItem

template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
  return item;
}  // end getItem

template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
  return (leftChildPtr == nullptr && rightChildPtr == nullptr);
}  // end isLeaf

template<class ItemType>
auto BinaryNode<ItemType>::getLeftChildPtr() const
{
  return leftChildPtr;
}  // end getLeftChildPtr

template<class ItemType>
auto BinaryNode<ItemType>::getRightChildPtr() const
{
  return rightChildPtr;
}  // end getRightChildPtr

template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr)
{
  leftChildPtr = leftPtr;
}  // end setLeftChildPtr

template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr)
{
  rightChildPtr = rightPtr;
}  // end setRightChildPtr

// #include "BinaryNode.cpp"
#endif 
