/**
 * @file LinkedList.h
 * Header file for the LinkedList class.
 * 
 * This file contains the definition of the LinkedList class, which implements
 * a linked list. The LinkedList class inherits from the ListInterface
 * class and provides implementations for its virtual methods.
 * 
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListInterface.h"
#include "Node.h"

/**
 * @class LinkedList
 * A template class for a linked list.
 * 
 * This class provides methods to manipulate a linked list, including
 * adding, removing, and checking for elements, as well as clearing the list.
 * 
 * @tparam ItemType The type of elements stored in the list.
 * 
 */
template<class ItemType>
class LinkedList: public ListInterface<ItemType>
{
public:
  /**
   * Default constructor.
   * 
   * Initializes an empty linked list.
   * 
   */
  LinkedList();

  /**
   * Destructor.
   * 
   * Deallocates all nodes in the linked list.
   * 
   */
  virtual ~LinkedList();

  /**
   * Gets the number of elements in the list.
   * 
   * @return The number of elements in the list.
   * 
   */
  int size() const override;

  /**
   * Checks if the list is empty.
   * 
   * @return True if the list is empty, false otherwise.
   * 
   */
  bool isEmpty() const override;

  /**
   * Adds an element to the front of the list.
   * 
   * @param entry The element to add.
   * @return True if the addition was successful, false otherwise.
   * 
   */
  bool addFront(const ItemType& entry) override;

  /**
   * Adds an element to the back of the list.
   * 
   * @param entry The element to add.
   * @return True if the addition was successful, false otherwise.
   * 
   */
  bool addBack(const ItemType& entry) override;

  /**
   * Removes an element from the front of the list.
   * 
   * @param entry The element to remove.
   * @return True if the removal was successful, false otherwise.
   * 
   */
  bool removeFront() override;

  /**
   * Removes an element from the back of the list.
   * 
   * @param entry The element to remove.
   * @return True if the removal was successful, false otherwise.
   * 
   */
  bool removeBack() override;

  /**
   * Retrieves element from the front of the list.
   * 
   * @pre The list is not empty.
   * @return The element at the front of the list.
   * 
   */
  Node<ItemType>* peekFront();

  /**
   * Retrieves element from the back of the list.
   * 
   * @pre The list is not empty.
   * @return The element at the back of the list.
   * 
   */
  Node<ItemType>* peekBack();

  /**
   * Clears all elements from the list.
   * 
   */
  void clear() override;

  /**
   * @brief Checks if the list contains a specific element.
   * 
   * @param entry The element to check for.
   * @return True if the element is found, false otherwise.
   * 
   */
  bool contains(const ItemType& entry) const override;

private:
   Node<ItemType>* headPtr; // Pointer to the first node in the list.
   Node<ItemType>* tailPtr; // Pointer to the last node in the list.
   int count; // The number of elements in the list.

   /**
    * Traverses the list to find a specific element.
    * 
    * @param target The element to find.
    * @param curPtr The current node pointer.
    * @return Pointer to the node containing the target element, or nullptr if not found.
    * 
    */
   Node<ItemType>* traverseToPtr(const ItemType& target, Node<ItemType>* curPtr) const;

   /**
    * Helper function.
    * Clears the list starting from a specific node.
    * 
    * @param curPtr The node to start clearing from.
    */
   void clear(Node<ItemType>* curPtr);
};

#include "LinkedList.tpp"
#endif