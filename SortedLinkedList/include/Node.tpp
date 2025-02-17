/**
 * @file Node.tpp
 * Implementation file for the Node class.
 * 
 * This file contains the implementation of the Node class, which is used
 * as a building block for linked data structures.
 * 
 */

#ifndef NODE_TPP
#define NODE_TPP

#include "Node.h"

/**
 * Default constructor.
 * 
 * Initializes a node with a null next pointer.
 * 
 */
template<class ItemType>
Node<ItemType>::Node() : next(nullptr) {
}

/**
 * Parameterized constructor.
 * 
 * Initializes a node with the given item and a null next pointer.
 * 
 * @param item The item to store in the node.
 * 
 */
template<class ItemType>
Node<ItemType>::Node(const ItemType& item) : item(item), next(nullptr) {
}

/**
 * Parameterized constructor.
 * 
 * Initializes a node with the given item and next node pointer.
 * 
 * @param item The item to store in the node.
 * @param nextNodePtr Pointer to the next node in the list.
 * 
 */
template<class ItemType>
Node<ItemType>::Node(const ItemType& item, Node<ItemType>* nextNodePtr) : item(item), next(nextNodePtr) {
}

/**
 * Sets the item stored in the node.
 * 
 * @param item The item to store in the node.
 * 
 */
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& item) {
  this->item = item;
}

/**
 * Sets the next node pointer.
 * 
 * @param nextNodePtr Pointer to the next node in the list.
 * 
 */
template<class ItemType> 
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
  next = nextNodePtr;
}

/**
 * Sets the previous node pointer.
 * 
 * @param prevNodePtr Pointer to the previous node in the list.
 * 
 */
template<class ItemType> 
void Node<ItemType>::setPrev(Node<ItemType>* prevNodePtr) {
  prev = prevNodePtr;
}

/**
 * Gets the item stored in the node.
 * 
 * @return The item stored in the node.
 * 
 */
template<class ItemType>
ItemType Node<ItemType>::getItem() const {
  return item;
}

/**
 * Gets the next node pointer.
 * 
 * @return Pointer to the next node in the list.
 * 
 */
template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
  return next;
}

/**
 * Gets the previous node pointer.
 * 
 * @return Pointer to the previous node in the list.
 * 
 */
template<class ItemType>
Node<ItemType>* Node<ItemType>::getPrev() const {
  return prev;
}

#endif