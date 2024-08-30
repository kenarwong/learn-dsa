#ifndef NODE_
#define NODE_

#include "headers.h"

template<class ItemType>
class Node
{
  public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType getItem() const;
    Node<ItemType>* getNext() const;

  private:
    ItemType item;
    Node<ItemType>* next;
};

// Explicit instantiation because we are separating the interface from the implementation
// C++ can't handle generic classes at runtime
template class Node<std::string>;

//// Alternative to explicit instantiation
//#include "Node.cpp"
#endif