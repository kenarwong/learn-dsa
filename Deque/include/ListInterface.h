/**
 * @file ListInterface.h
 * Abstract base class defining a generic list interface.
 *
 * This file contains the definition of the ListInterface class template,
 * which provides a generic interface for a list data structure. The class
 * is abstract and must be inherited by concrete list implementations.
 *
 */
#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H

/**
 * @class ListInterface
 * An abstract base class that defines a list interface.
 *
 * @tparam ItemType The type of elements stored in the list.
 */

template<class ItemType>
class ListInterface
{
public:
  /**
   * Retrieves the number of elements in the list.
   * @pre None.
   * @post None.
   * @return The total number of elements currently in the list.
   */
  virtual int size() const = 0;
  
  /**
   * @brief Checks if the list is empty.
   * @pre None.
   * @post None.
   * @return True if the list is empty, false otherwise.
   */
  virtual bool isEmpty() const = 0;

  /**
   * Adds an element to the front of the list.
   * 
   * @param entry The element to add.
   * @return True if the addition was successful, false otherwise.
   * 
   */
  virtual bool addFront(const ItemType& entry) = 0;

  /**
   * Adds an element to the back of the list.
   * 
   * @param entry The element to add.
   * @return True if the addition was successful, false otherwise.
   * 
   */
  virtual bool addBack(const ItemType& entry) = 0;

  /**
   * Removes an element from the front of the list.
   * 
   * @param entry The element to remove.
   * @return True if the removal was successful, false otherwise.
   * 
   */
  virtual bool removeFront() = 0;

  /**
   * Removes an element from the back of the list.
   * 
   * @param entry The element to remove.
   * @return True if the removal was successful, false otherwise.
   * 
   */
  virtual bool removeBack() = 0;

  /**
   * @brief Clears all elements from the list.
   * @pre None.
   * @post The list is empty, and the number of elements is 0.
   */
  virtual void clear() = 0;
  
  /**
   * @brief Determines if the list contains a specified element.
   * @pre None.
   * @post None.
   * @param entry The element to search for.
   * @return True if the list contains entry, false otherwise.
   */
  virtual bool contains(const ItemType& entry) const = 0;
  
  /**
   * @brief Virtual destructor to clean up the list and free memory.
   * @pre None.
   * @post All dynamically allocated memory is freed.
   */
  virtual ~ListInterface() { }
};

#endif