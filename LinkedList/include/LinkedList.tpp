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
 * Adds an element to the list.
 * 
 * @param entry The element to add.
 * @return True if the addition was successful, false otherwise.
 * 
 */
template<class ItemType>
bool LinkedList<ItemType>::add(const ItemType& entry) {
  Node<ItemType>* q = nullptr;
  Node<ItemType>* p = headPtr;

  while (p != nullptr) {
    if (entry == p->getItem()) {
      return false;
    }

    // Insert in place
    if (entry < p->getItem()) {
      break;
    }

    q = p;
    p = p->getNext();
  }

  Node<ItemType>* newNodePtr = new Node<ItemType>();
  newNodePtr->setItem(entry);
  newNodePtr->setNext(p);
  newNodePtr->setPrev(q);

  if (q != nullptr) {
    q->setNext(newNodePtr);
  } else {
    headPtr = newNodePtr; 
  }

  if (p != nullptr) {
    p->setPrev(newNodePtr);
  } else {
    tailPtr = newNodePtr; 
  }

  count++;

  return true;
}

/**
 * Removes an element from the list.
 * 
 * @param entry The element to remove.
 * @return True if the removal was successful, false otherwise.
 * 
 */
template<class ItemType>
bool LinkedList<ItemType>::remove(const ItemType& entry) {
  Node<ItemType>* nodeToDeletePtr = traverseToPtr(entry, headPtr);

  bool canRemoveItem = !isEmpty() && (nodeToDeletePtr != nullptr);
  if (canRemoveItem) {
    Node<ItemType>* prev = nodeToDeletePtr->getPrev();
    Node<ItemType>* next = nodeToDeletePtr->getNext();

    if (prev != nullptr) {
      prev->setNext(next);
    } else {
      headPtr = next;
    }

    if (next != nullptr) {
      next->setPrev(prev);
    } else {
      tailPtr = prev;
    }

    // Return node 
    nodeToDeletePtr->setNext(nullptr);
    nodeToDeletePtr->setPrev(nullptr);
    delete nodeToDeletePtr;
    nodeToDeletePtr = nullptr;

    count--;
  }

  return canRemoveItem;
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