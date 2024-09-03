#include "DoublyLinkedNode.h"

template<class ItemType>
DoublyLinkedNode<ItemType>::DoublyLinkedNode() : prev(nullptr), next(nullptr) {
}

template<class ItemType>
DoublyLinkedNode<ItemType>::DoublyLinkedNode(const ItemType& anItem) : item(anItem), prev(nullptr), next(nullptr) {
}

template<class ItemType>
DoublyLinkedNode<ItemType>::DoublyLinkedNode(const ItemType& anItem, DoublyLinkedNode<ItemType>* prevNodePtr, DoublyLinkedNode<ItemType>* nextNodePtr) : item(anItem), prev(prevNodePtr), next(nextNodePtr) {
}

template<class ItemType> 
void DoublyLinkedNode<ItemType>::setNext(DoublyLinkedNode<ItemType>* nextNodePtr) {
  next = nextNodePtr;
}

template<class ItemType> 
void DoublyLinkedNode<ItemType>::setPrev(DoublyLinkedNode<ItemType>* prevNodePtr) {
  prev = prevNodePtr;
}

template<class ItemType>
ItemType DoublyLinkedNode<ItemType>::getItem() const {
  return item;
}

template<class ItemType>
void DoublyLinkedNode<ItemType>::setItem(const ItemType& anItem) {
  item = anItem;
}

template<class ItemType>
DoublyLinkedNode<ItemType>* DoublyLinkedNode<ItemType>::getNext() const {
  return next;
}

template<class ItemType>
DoublyLinkedNode<ItemType>* DoublyLinkedNode<ItemType>::getPrev() const {
  return prev;
}