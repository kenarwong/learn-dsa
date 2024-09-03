#ifndef DOUBLY_LINKED_BAG_
#define DOUBLY_LINKED_BAG_

#include "LinkedBag.h"
#include "DoublyLinkedNode.h"

template<class ItemType>
class DoublyLinkedBag: public LinkedBag<ItemType>
{
public:
   DoublyLinkedBag();
   DoublyLinkedBag(const DoublyLinkedBag<ItemType>& otherBag);
   virtual ~DoublyLinkedBag();
   int getCurrentSize() const override;
   bool isEmpty() const override;
   bool add(const ItemType& newEntry) override;
   bool remove(const ItemType& anEntry) override;
   void clear() override;
   //int getFrequencyOf(const ItemType& anEntry) const override;
   //bool contains(const ItemType& anEntry) const override;
   std::vector<ItemType> toVector() const override;

private:
    DoublyLinkedNode<ItemType>* headPtr; // Pointer to first node
    DoublyLinkedNode<ItemType>* tailPtr; // Pointer to last node
    int itemCount; // Current count of bag items

    //Node<ItemType>* getPointerTo(const ItemType& target, Node<ItemType>* curPtr) const;
    //void fillVector(std::vector<ItemType>& bagContents, Node<ItemType>* curPtr) const;

    //void clear(Node<ItemType>* curPtr);
};

// Explicit instantiation because we are separating the interface from the implementation
// C++ can't handle generic classes at runtime
template class DoublyLinkedBag<std::string>;

//// Alternative to explicit instantiation
//#include "LinkedBag.cpp"
#endif