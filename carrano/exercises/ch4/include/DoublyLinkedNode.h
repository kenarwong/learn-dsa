#ifndef DOUBLY_LINKED_NODE_
#define DOUBLY_LINKED_NODE_

#include "Node.h"
#include "headers.h"

template<class ItemType>
class DoublyLinkedNode : public Node<ItemType>
{
  public:
    DoublyLinkedNode();
    DoublyLinkedNode(const ItemType& anItem);
    DoublyLinkedNode(const ItemType& anItem, DoublyLinkedNode<ItemType>* prevNodePtr, DoublyLinkedNode<ItemType>* nextNodePtr);
    ItemType getItem() const;
    void setItem(const ItemType& anItem);
    void setNext(DoublyLinkedNode<ItemType>* nextNodePtr);
    void setPrev(DoublyLinkedNode<ItemType>* prevNodePtr);
    DoublyLinkedNode<ItemType>* getNext() const;
    DoublyLinkedNode<ItemType>* getPrev() const;

  private:
    ItemType item;
    DoublyLinkedNode<ItemType>* prev;
    DoublyLinkedNode<ItemType>* next;
};

// Explicit instantiation because we are separating the interface from the implementation
// C++ can't handle generic classes at runtime
template class DoublyLinkedNode<std::string>;

//// Alternative to explicit instantiation
//#include "Node.cpp"
#endif