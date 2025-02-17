/**
 * @file CircularHeaderLinkedList.tpp
 * Implementation file for the CircularHeaderLinkedList class.
 * 
 * This file contains the implementation of the CircularHeaderLinkedList class, which provides
 * a linked list data structure.
 * 
 */

#ifndef LINKED_LIST_TPP
#define LINKED_LIST_TPP

#include "CircularHeaderLinkedList.h"

/**
 * Default constructor.
 * 
 * Initializes an empty linked list.
 * 
 */
template<class ItemType>
CircularHeaderLinkedList<ItemType>::CircularHeaderLinkedList() : header(new Node<ItemType>()), count(0) {
}

/**
 * Destructor.
 * 
 * Deallocates all nodes in the linked list.
 * 
 */
template<class ItemType>
CircularHeaderLinkedList<ItemType>::~CircularHeaderLinkedList() {
  clear();
  delete header;
}

/**
 * Gets the number of elements in the list.
 * 
 * @return The number of elements in the list.
 * 
 */
template<class ItemType>
int CircularHeaderLinkedList<ItemType>::size() const {
  return count;
}

/**
 * Checks if the list is empty.
 * 
 * @return True if the list is empty, false otherwise.
 * 
 */
template<class ItemType>
bool CircularHeaderLinkedList<ItemType>::isEmpty() const {
  return count == 0;
}

/**
 * Adds an element to the front of the list.
 * 
 * @param entry The element to add.
 * @return True if the addition was successful, false otherwise.
 * 
 */
template<class ItemType>
bool CircularHeaderLinkedList<ItemType>::addFront(const ItemType& entry) {
  Node<ItemType>* newNodePtr = new Node<ItemType>();
  newNodePtr->setItem(entry);

  Node<ItemType>* headPtr = header->getNext();
  Node<ItemType>* tailPtr = header->getPrev();

  // Empty list
  if (headPtr == nullptr) {
    header->setNext(newNodePtr);
    header->setPrev(newNodePtr);

    // Point to self
    newNodePtr->setNext(newNodePtr);
    newNodePtr->setPrev(newNodePtr);
  } else {
    // Update header
    header->setNext(newNodePtr);

    // New node now points to previous head and current tail
    newNodePtr->setNext(headPtr);
    newNodePtr->setPrev(tailPtr);

    // Previous head now second
    headPtr->setPrev(newNodePtr);

    // Tail now points to new node
    tailPtr->setNext(newNodePtr);
  }

  count++;

  return true;
}

/**
 * Adds an element to the back of the list.
 * 
 * @param entry The element to add.
 * @return True if the addition was successful, false otherwise.
 * 
 */
template<class ItemType>
bool CircularHeaderLinkedList<ItemType>::addBack(const ItemType& entry) {
  Node<ItemType>* newNodePtr = new Node<ItemType>();
  newNodePtr->setItem(entry);

  Node<ItemType>* headPtr = header->getNext();
  Node<ItemType>* tailPtr = header->getPrev();

  // Empty list
  if (tailPtr == nullptr) {
    header->setNext(newNodePtr);
    header->setPrev(newNodePtr);

    // Point to self
    newNodePtr->setNext(newNodePtr);
    newNodePtr->setPrev(newNodePtr);
  } else {
    // Update header
    header->setPrev(newNodePtr);

    // New node now points to previous tail and current head
    newNodePtr->setPrev(tailPtr);
    newNodePtr->setNext(headPtr);

    // Head now points to new node
    headPtr->setPrev(newNodePtr);

    // Previous tail now second last
    tailPtr->setNext(newNodePtr);
  }

  count++;

  return true;
}

/**
 * Removes an element from the front of the list.
 * 
 * @return True if the removal was successful, false otherwise.
 * 
 */
template<class ItemType>
bool CircularHeaderLinkedList<ItemType>::removeFront() {
  Node<ItemType>* nodeToDeletePtr = header->getNext();
  Node<ItemType>* tailPtr = header->getPrev();

  if (nodeToDeletePtr == nullptr) {
    return false;
  }

  // If only one node in list
  if (tailPtr == nodeToDeletePtr) {
    header->setNext(nullptr);
    header->setPrev(nullptr);
  } else {
    // Set next node as new head
    Node<ItemType>* nextNodePtr = nodeToDeletePtr->getNext();
    header->setNext(nextNodePtr);

    // Link new head with tail and vice versa
    nextNodePtr->setPrev(tailPtr);
    tailPtr->setNext(nextNodePtr);
  }

  // Delete front node
  nodeToDeletePtr->setNext(nullptr);
  nodeToDeletePtr->setPrev(nullptr);
  delete nodeToDeletePtr;

  count--;

  return true;
}

/**
 * Removes an element from the back of the list.
 * 
 * @return True if the removal was successful, false otherwise.
 * 
 */
template<class ItemType>
bool CircularHeaderLinkedList<ItemType>::removeBack() {
  Node<ItemType>* headPtr = header->getNext();
  Node<ItemType>* nodeToDeletePtr = header->getPrev();

  if (nodeToDeletePtr == nullptr) {
    return false;
  }

  // If only one node in list
  if (headPtr == nodeToDeletePtr) {
    header->setNext(nullptr);
    header->setPrev(nullptr);
  } else {
    // Set prev node as new tail
    Node<ItemType>* prevNodePtr = nodeToDeletePtr->getPrev();
    header->setPrev(prevNodePtr);

    // Link new tail with head and vice versa
    prevNodePtr->setNext(headPtr);
    headPtr->setPrev(prevNodePtr);
  }

  // Delete back node
  nodeToDeletePtr->setNext(nullptr);
  nodeToDeletePtr->setPrev(nullptr);
  delete nodeToDeletePtr;

  count--;

  return true;
}

/**
 * Retrieves element from the front of the list.
 * 
 * @pre The list is not empty.
 * @return The element at the front of the list.
 * 
 */
template<class ItemType>
ItemType CircularHeaderLinkedList<ItemType>::peekFront() {
  if (header->getNext() != nullptr) {
    return header->getNext()->getItem();
  }

  return ItemType();
}

/**
 * Retrieves element from the back of the list.
 * 
 * @pre The list is not empty.
 * @return The element at the back of the list.
 * 
 */
template<class ItemType>
ItemType CircularHeaderLinkedList<ItemType>::peekBack() {
  if (header->getPrev() != nullptr) {
    return header->getPrev()->getItem();
  }

  return ItemType();
}

/**
 * Clears all elements from the list.
 * 
 */
template<class ItemType>
void CircularHeaderLinkedList<ItemType>::clear() {
  Node<ItemType>* headPtr = header->getNext();
  if (headPtr == nullptr) {
    return;
  }

  Node<ItemType>* curPtr = headPtr;

  do {
    Node<ItemType>* nodeToDelete = curPtr;
    curPtr = curPtr->getNext();

    nodeToDelete->setNext(nullptr);
    nodeToDelete->setPrev(nullptr);
    delete nodeToDelete;
    nodeToDelete = nullptr;

  } while (curPtr != headPtr);

  header->setNext(nullptr);
  header->setPrev(nullptr);

  count = 0;
}

/**
 * Checks if the list contains a specific element.
 * 
 * @param entry The element to check for.
 * @return True if the element is found, false otherwise.
 * 
 */
template<class ItemType>
bool CircularHeaderLinkedList<ItemType>::contains(const ItemType& entry) const {
  Node<ItemType>* headPtr = header->getNext();
  if (headPtr == nullptr) {
    return false;
  }

  Node<ItemType>* curPtr = headPtr;

  do {
    if (entry == curPtr->getItem()) {
      return true;
    }
    curPtr = curPtr->getNext();
  } while (curPtr != headPtr);

  return false;
}

// /**
//  * Traverses the list to find a specific element.
//  * 
//  * @param target The element to find.
//  * @param curPtr The current node pointer.
//  * @return Pointer to the node containing the target element, or nullptr if not found.
//  * 
//  */
// template<class ItemType>
// Node<ItemType>* CircularHeaderLinkedList<ItemType>::traverseToPtr(const ItemType& target, Node<ItemType>* curPtr) const {
// 
//   Node<ItemType>* result = nullptr;
//   if (curPtr != nullptr) {
//     if (target == curPtr->getItem()) {
//       result = curPtr;
//     } else {
//       curPtr = curPtr->getNext();
//       result = traverseToPtr(target, curPtr);
//     }
//   }
// 
//   return result;
// }

#endif