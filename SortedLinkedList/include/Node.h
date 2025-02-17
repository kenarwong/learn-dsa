/**
 * @file Node.h
 * Definition of the Node class template.
 * 
 * This file contains the definition of the Node class template, which would 
 * represents a node in a linked list. 
 * 
 * Each node stores an item and pointers to the 
 * next and previous nodes in the list.
 */

#ifndef NODE_H
#define NODE_H

/**
 * @class Node
 * A class template for a node in a linked list.
 * 
 * The Node class template represents a node in a linked list. It contains
 * an item of type ItemType and pointers to the next and previous nodes in the list.
 * 
 * @tparam ItemType The type of the item stored in the node.
 */
template<class ItemType>
class Node
{
public:
  /**
   * Default constructor.
   * 
   * Initializes a new Node object with default values.
   */
  Node();
 
  /**
   * Parameterized constructor.
   * 
   * Initializes a new Node object with the specified item.
   * 
   * @param item The item to be stored in the node.
   */
  Node(const ItemType& item);
 
  /**
   * Parameterized constructor.
   * 
   * Initializes a new Node object with the specified item and next node pointer.
   * 
   * @param item The item to be stored in the node.
   * @param nextNodePtr Pointer to the next node in the list.
   */
  Node(const ItemType& item, Node<ItemType>* nextNodePtr);
  
  /**
   * Sets the item stored in the node.
   * 
   * @param item The item to be stored in the node.
   */
  void setItem(const ItemType& item);
  
  /**
   * Sets the pointer to the next node in the list.
   * 
   * @param nextNodePtr Pointer to the next node in the list.
   */
  void setNext(Node<ItemType>* nextNodePtr);
  
  /**
   * Sets the pointer to the previous node in the list.
   * 
   * @param prevNodePtr Pointer to the previous node in the list.
   */
  void setPrev(Node<ItemType>* prevNodePtr);
  
  /**
   * Gets the item stored in the node.
   * 
   * @return The item stored in the node.
   */
  ItemType getItem() const;
  
  /**
   * Gets the pointer to the next node in the list.
   * 
   * @return Pointer to the next node in the list.
   */
  Node<ItemType>* getNext() const;
  
  /**
   * Gets the pointer to the previous node in the list.
   * 
   * @return Pointer to the previous node in the list.
   */
  Node<ItemType>* getPrev() const;

  private:
    ItemType item; // A data item
    Node<ItemType>* next; // Pointer to next node
    Node<ItemType>* prev; // Pointer to previous node
};

// Alternative to explicit instantiation
#include "Node.tpp"
#endif