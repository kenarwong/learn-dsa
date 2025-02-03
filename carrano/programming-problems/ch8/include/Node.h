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
    void setPrev(Node<ItemType>* prevNodePtr);
    ItemType getItem() const;
    Node<ItemType>* getNext() const;
    Node<ItemType>* getPrev() const;

  privateco:
    ItemType item;
    Node<ItemType>* next;
    Node<ItemType>* prev;
};

template<class ItemType>
Node<ItemType>::Node() : next(nullptr) {
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr) {
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr) {
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {
  item = anItem;
}

template<class ItemType> 
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
  next = nextNodePtr;
}

template<class ItemType> 
void Node<ItemType>::setPrev(Node<ItemType>* prevNodePtr) {
  prev = prevNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const {
  return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
  return next;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getPrev() const {
  return prev;
}

//// Explicit instantiation because we are separating the interface from the implementation
//// C++ can't handle generic classes at runtime
//template class Node<std::string>;
//
//// Alternative to explicit instantiation
////#include "Node.cpp"
#endif