/* @file ListInterface.h */
#ifndef LIST_INTERFACE_
#define LIST_INTERFACE_

#include "headers.h"

template<class ItemType> // Generic type (single class), must be before class header
class ListInterface // Abstract (base) class
{
// Abstract classes must have at least one virtual method
// No implementation

public:
   /** Gets the current number of entries in this list.
    @return  The integer number of entries currently in the list. */
   virtual int getCurrentSize() const = 0;
   
   /** Sees whether this list is empty.
    @return  True if the list is empty, or false if not. */
   virtual bool isEmpty() const = 0;
   
   /** Adds a new entry to this list in order.
    @post  If successful, newEntry is stored in the list and
       the count of items in the list has increased by 1.
    @param newEntry  The object to be added as a new entry. Duplicates will be ignored.
    @return  True if addition was successful, or false if not. */
   virtual bool add(const ItemType& newEntry) = 0;
   
   /** Removes one occurrence of a given entry from this list,
       if possible.
    @post  If successful, anEntry has been removed from the list
       and the count of items in the list has decreased by 1.
    @param anEntry  The entry to be removed.
    @return  True if removal was successful, or false if not. */
   virtual bool remove(const ItemType& anEntry) = 0;
   
   /** Removes all entries from this list.
    @post  List contains no items, and the count of items is 0. */
   virtual void clear() = 0;
   
   /** Counts the number of times a given entry appears in this list.
    @param anEntry  The entry to be counted.
    @return  The number of times anEntry appears in the list. */
   virtual int getFrequencyOf(const ItemType& anEntry) const = 0;
   
   /** Tests whether this list contains a given entry.
    @param anEntry  The entry to locate.
    @return  True if list contains anEntry, or false otherwise. */
   virtual bool contains(const ItemType& anEntry) const = 0;
   
   /** Empties and then fills a given vector with all entries that
       are in this list.
    @return  A vector containing all the entries in the list. */
   virtual std::vector<ItemType> toVector() const = 0;
   
   /** Destroys this list and frees its assigned memory. (See C++ Interlude 2.) */
   virtual ~ListInterface() { }
}; // end ListInterface

#endif