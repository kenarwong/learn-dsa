#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag: public BagInterface<ItemType>
{
public:
   LinkedBag();
   LinkedBag(const LinkedBag<ItemType>& aBag);
   virtual ~LinkedBag();
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   void clear();
   int getFrequencyOf(const ItemType& anEntry) const;
   bool contains(const ItemType& anEntry) const;
   std::vector<ItemType> toVector() const;

private:
    Node<ItemType>* headPtr; // Pointer to first node
    Node<ItemType>* tailPtr; // Pointer to last node
    int itemCount; // Current count of bag items

    Node<ItemType>* getPointerTo(const ItemType& target, Node<ItemType>* curPtr) const;
    void fillVector(std::vector<ItemType>& bagContents, Node<ItemType>* curPtr) const;

    void clear(Node<ItemType>* curPtr);
};

#endif