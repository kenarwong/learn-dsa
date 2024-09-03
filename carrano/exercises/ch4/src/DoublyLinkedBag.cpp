#include "DoublyLinkedNode.h"
#include "DoublyLinkedBag.h"

template<class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag() : headPtr(nullptr), tailPtr(nullptr), itemCount(0) {}

template<class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag(const DoublyLinkedBag<ItemType>& otherBag) {
  DoublyLinkedNode<ItemType>* otherCurPtr = otherBag.headPtr;
  itemCount = otherBag.itemCount;

  if (otherCurPtr == nullptr) {
    headPtr = nullptr; 
    tailPtr = nullptr; 
  } else {
    headPtr = new DoublyLinkedNode<ItemType>(otherCurPtr->getItem());
    tailPtr = headPtr;

    DoublyLinkedNode<ItemType>* prevPtr = headPtr;
    otherCurPtr = otherCurPtr->getNext();
    while (otherCurPtr != nullptr) {
      tailPtr = new DoublyLinkedNode<ItemType>(otherCurPtr->getItem(), prevPtr, nullptr);
      prevPtr = tailPtr;

      otherCurPtr = otherCurPtr->getNext();
    }
  }
}

template<class ItemType>
DoublyLinkedBag<ItemType>::~DoublyLinkedBag() {
  clear();
}

template<class ItemType>
bool DoublyLinkedBag<ItemType>::isEmpty() const {
  return itemCount == 0;
}

template<class ItemType>
int DoublyLinkedBag<ItemType>::getCurrentSize() const {
  return itemCount;
}

template<class ItemType>
void DoublyLinkedBag<ItemType>::clear() {
  while (headPtr != nullptr) {
    DoublyLinkedNode<ItemType>* toDelete = headPtr;
    headPtr = headPtr->getNext();

    delete toDelete;

    itemCount--;
  }

  tailPtr = nullptr;
}

template<class ItemType>
bool DoublyLinkedBag<ItemType>::add(const ItemType& newEntry) {
  DoublyLinkedNode<ItemType>* node = new DoublyLinkedNode<ItemType>(newEntry);
  node->setNext(headPtr);

  if (isEmpty()) {
    tailPtr = node;
  } else {
    headPtr->setPrev(node);
  }

  headPtr = node;

  itemCount++;

  return true;
};

template<class ItemType>
bool DoublyLinkedBag<ItemType>::remove(const ItemType& anEntry) {
  DoublyLinkedNode<ItemType>* curPtr = headPtr;

  if (curPtr != nullptr && curPtr->getItem() == anEntry) {
    headPtr = curPtr->getNext();
    if(headPtr != nullptr) {
      headPtr->setPrev(nullptr);
    }
    
    delete curPtr;
    itemCount--;

    return true;
  }
  
  while (curPtr != nullptr) {
    if (curPtr->getNext() != nullptr && curPtr->getNext()->getItem() == anEntry) {
      DoublyLinkedNode<ItemType>* nodeToDelete = curPtr->getNext();
      DoublyLinkedNode<ItemType>* nodeAfterDelete = nodeToDelete->getNext();
      curPtr->setNext(nodeAfterDelete);
      if(nodeAfterDelete != nullptr) {
        nodeAfterDelete->setPrev(curPtr);
      } else {
        tailPtr = curPtr;
      }

      delete nodeToDelete;
      itemCount--;

      return true;
    }

    curPtr = curPtr->getNext();
  }

  return false;
}

template<class ItemType>
std::vector<ItemType> DoublyLinkedBag<ItemType>::toVector() const {
  std::vector<ItemType> bagContents;
  DoublyLinkedNode<ItemType>* curPtr = headPtr;

  while (curPtr != nullptr) {
    bagContents.push_back(curPtr->getItem());
    curPtr = curPtr->getNext();
  }

  return bagContents;
}