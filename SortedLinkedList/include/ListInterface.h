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
   * @brief Inserts a new element into the list in sorted order.
   * @pre None.
   * @post If successful, entry is added to the list and the number of elements in the list is increased by 1.
   * @param entry The element to be added. Duplicate entries are ignored.
   * @return True if the addition was successful, false otherwise. List remains sorted.
   */
  virtual bool add(const ItemType& entry) = 0;
  
  /**
   * @brief Removes one instance of a specified element from the list, if it exists.
   * @pre None.
   * @post If successful, entry is removed from the list and the number of elements in the list is decreased by 1.
   * @param entry The element to be removed.
   * @return True if the removal was successful, false otherwise. List remains sorted.
   */
  virtual bool remove(const ItemType& entry) = 0;
  
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