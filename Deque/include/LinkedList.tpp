/**
 * @file LinkedList.tpp
 * Implementation file for the LinkedList class.
 * 
 * This file contains the implementation of the LinkedList class, which provides
 * a linked list data structure.
 * 
 */

#ifndef LINKED_LIST_TPP
#define LINKED_LIST_TPP

#include "LinkedList.h"

/**
 * Default constructor.
 * 
 * Initializes an empty linked list.
 * 
 */
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), tailPtr(nullptr), count(0) {
}

/**
 * Destructor.
 * 
 * Deallocates all nodes in the linked list.
 * 
 */
template<class ItemType>
LinkedList<ItemType>::~LinkedList() {
  clear();
}

/**
 * Gets the number of elements in the list.
 * 
 * @return The number of elements in the list.
 * 
 */
template<class ItemType>
int LinkedList<ItemType>::size() const {
  return count;
}

/**
 * Checks if the list is empty.
 * 
 * @return True if the list is empty, false otherwise.
 * 
 */
template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
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
bool LinkedList<ItemType>::addFront(const ItemType& entry) {
  Node<ItemType>* newNodePtr = new Node<ItemType>();
  newNodePtr->setItem(entry);

  if (headPtr == nullptr) {
    headPtr = newNodePtr; 
  } else {
    newNodePtr->setNext(headPtr);
    headPtr->setPrev(newNodePtr);
    headPtr = newNodePtr;
  }

  if (tailPtr == nullptr) {
    tailPtr = newNodePtr;
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
bool LinkedList<ItemType>::addBack(const ItemType& entry) {
  Node<ItemType>* newNodePtr = new Node<ItemType>();
  newNodePtr->setItem(entry);

  if (tailPtr == nullptr) {
    tailPtr = newNodePtr; 
  } else {
    newNodePtr->setPrev(tailPtr);
    tailPtr->setNext(newNodePtr);
    tailPtr = newNodePtr;
  }

  if (headPtr == nullptr) {
    headPtr = newNodePtr;
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
bool LinkedList<ItemType>::removeFront() {
  if (headPtr == nullptr) {
    return false;
  }

  // Get head node
  Node<ItemType>* nodeToDeletePtr = headPtr;

  // If only one node in list
  if (tailPtr == headPtr) {
    tailPtr = nullptr;
    headPtr = nullptr;
  } else {
    // Set next node as new head
    Node<ItemType>* nextNodePtr = headPtr->getNext();
    nextNodePtr->setPrev(nullptr);
    headPtr = nextNodePtr;
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
bool LinkedList<ItemType>::removeBack() {
  if (tailPtr == nullptr) {
    return false;
  }

  // Get tail node
  Node<ItemType>* nodeToDeletePtr = tailPtr;

  // If only one node in list
  if (headPtr == tailPtr) {
    headPtr = nullptr;
    tailPtr = nullptr;
  } else {
    // Set prev node as new tail
    Node<ItemType>* prevNodePtr = tailPtr->getPrev();
    prevNodePtr->setNext(nullptr);
    tailPtr = prevNodePtr;
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
Node<ItemType>* LinkedList<ItemType>::peekFront() {
  return headPtr;
}

/**
 * Retrieves element from the back of the list.
 * 
 * @pre The list is not empty.
 * @return The element at the back of the list.
 * 
 */
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::peekBack() {
  return tailPtr;
}

/**
 * Clears all elements from the list.
 * 
 */
template<class ItemType>
void LinkedList<ItemType>::clear() {
  clear(headPtr);
  headPtr = nullptr;
  count = 0;
}

/**
 * Helper function.
 * Clears the list starting from a specific node.
 * 
 * @param curPtr The node to start clearing from.
 */
template<class ItemType>
void LinkedList<ItemType>::clear(Node<ItemType>* curPtr) {
  if (curPtr != nullptr) {
    Node<ItemType>* nodeToDeletePtr = curPtr;
    curPtr = curPtr->getNext();
    clear(curPtr);

    delete nodeToDeletePtr;
    curPtr = nullptr;
    count--;
  }
}

/**
 * Checks if the list contains a specific element.
 * 
 * @param entry The element to check for.
 * @return True if the element is found, false otherwise.
 * 
 */
template<class ItemType>
bool LinkedList<ItemType>::contains(const ItemType& entry) const {
  return traverseToPtr(entry, headPtr) != nullptr;
}

/**
 * Traverses the list to find a specific element.
 * 
 * @param target The element to find.
 * @param curPtr The current node pointer.
 * @return Pointer to the node containing the target element, or nullptr if not found.
 * 
 */
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::traverseToPtr(const ItemType& target, Node<ItemType>* curPtr) const {

  Node<ItemType>* result = nullptr;
  if (curPtr != nullptr) {
    if (target == curPtr->getItem()) {
      result = curPtr;
    } else {
      curPtr = curPtr->getNext();
      result = traverseToPtr(target, curPtr);
    }
  }

  return result;
}

#endif