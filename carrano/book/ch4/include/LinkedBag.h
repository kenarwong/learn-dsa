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
   int getCurrentSize() const override;
   bool isEmpty() const override;
   bool add(const ItemType& newEntry) override;
   bool remove(const ItemType& anEntry) override;
   void clear() override;
   int getFrequencyOf(const ItemType& anEntry) const override;
   bool contains(const ItemType& anEntry) const override;
   std::vector<ItemType> toVector() const override;

private:
    Node<ItemType>* headPtr; // Pointer to first node
    Node<ItemType>* tailPtr; // Pointer to last node
    int itemCount; // Current count of bag items

    Node<ItemType>* getPointerTo(const ItemType& target, Node<ItemType>* curPtr) const;
    void fillVector(std::vector<ItemType>& bagContents, Node<ItemType>* curPtr) const;

    void clear(Node<ItemType>* curPtr);
};

//// Explicit instantiation because we are separating the interface from the implementation
//// C++ can't handle generic classes at runtime
//template class LinkedBag<std::string>;

// Alternative to explicit instantiation
#include "LinkedBag.cpp"
#endif