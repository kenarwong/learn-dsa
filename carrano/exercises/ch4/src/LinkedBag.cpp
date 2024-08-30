#include "LinkedBag.h"

using ItemType = std::string;

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0) {
}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& otherBag) {
  itemCount = otherBag.itemCount;
  Node<ItemType>* origChainPtr = otherBag.headPtr; // Points to nodes in original chain

  if (origChainPtr == nullptr) {
    headPtr = nullptr; // Original bag is empty
    tailPtr = nullptr; // Original bag is empty
  } else {
    // Set headPtr
    // Copy first node
    headPtr = new Node<ItemType>();
    headPtr->setItem(origChainPtr->getItem());

    // Copy remaining nodes
    Node<ItemType>* chainPtr = headPtr; // Points to next node in new chain
    origChainPtr = origChainPtr->getNext(); 

    // Loop through old chain
    while (origChainPtr != nullptr) {
      // Get next item from original chain
      ItemType nextItem = origChainPtr->getItem();

      // Create a new node containing the next item
      Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

      // Link new node to end of new chain
      chainPtr->setNext(newNodePtr);

      // Advance pointer to new next node
      chainPtr = chainPtr->getNext();

      // Advance original-chain pointer
      origChainPtr = origChainPtr->getNext();
    }

    chainPtr->setNext(nullptr); // Flag end of chain
    tailPtr = chainPtr; // Set as tailPtr
  }
}

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag() {
  clear();
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
  return itemCount;
}

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
  return itemCount == 0;
}

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry) {
  // Add to beginning of chain
  Node<ItemType>* newNodePtr = new Node<ItemType>();
  newNodePtr->setItem(newEntry);
  newNodePtr->setNext(headPtr); // New node points to chain
  headPtr = newNodePtr; // New node is now first node

  if (isEmpty()) {
    tailPtr = newNodePtr; // New node is also last node
  }

  itemCount++;

  return true;
}

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry) {
  //Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
  Node<ItemType>* entryNodePtr = getPointerTo(anEntry, headPtr);

  bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
  if (canRemoveItem) {
    // Copy data from first node to located node
    entryNodePtr->setItem(headPtr->getItem());

    // Remove first node
    Node<ItemType>* nodeToDeletePtr = headPtr;
    headPtr = headPtr->getNext();

    // Return node to system
    nodeToDeletePtr->setNext(nullptr);
    delete nodeToDeletePtr;
    nodeToDeletePtr = nullptr;

    itemCount--;
  }

  return canRemoveItem;
}

template<class ItemType>
void LinkedBag<ItemType>::clear() {
  clear(headPtr);
  headPtr = nullptr;
  itemCount = 0;
}

template<class ItemType>
void LinkedBag<ItemType>::clear(Node<ItemType>* curPtr) {
  if (curPtr != nullptr) {
    Node<ItemType>* nodeToDeletePtr = curPtr;
    curPtr = curPtr->getNext();
    clear(curPtr);

    delete nodeToDeletePtr;
    curPtr = nullptr;
    itemCount--;
  }
  //while (headPtr != nullptr) {
  //  headPtr = headPtr->getNext();

  //  // Return node to system
  //  nodeToDeletePtr->setNext(nullptr);
  //  delete nodeToDeletePtr;

  //  nodeToDeletePtr = headPtr;
  //}

  //itemCount = 0;
}

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
  int frequency = 0;
  int counter = 0;
  Node<ItemType>* curPtr = headPtr;
  while ((curPtr != nullptr) && (counter < itemCount)) {
    if (anEntry == curPtr->getItem()) {
      frequency++;
    }

    counter++;
    curPtr = curPtr->getNext();
  }

  return frequency;
}

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const {
  // return getPointerTo(anEntry) != nullptr;
  return getPointerTo(anEntry, headPtr) != nullptr;
}

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const {
  std::vector<ItemType> bagContents;
  Node<ItemType>* curPtr = headPtr;
  //int counter = 0;
  //while ((curPtr != nullptr) && (counter < itemCount)) {
  //  bagContents.push_back(curPtr->getItem());
  //  curPtr = curPtr->getNext();
  //  counter++;
  //}

  fillVector(bagContents, curPtr);

  return bagContents;
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& target, Node<ItemType>* curPtr) const {

  Node<ItemType>* result = nullptr;
  if (curPtr != nullptr) {
    if (target == curPtr->getItem()) {
      result = curPtr;
    } else {
      curPtr = curPtr->getNext();
      result = getPointerTo(target, curPtr);
    }
  }

  return result;

  //int counter = 0;
  //Node<ItemType>* curPtr = headPtr;

  //while((curPtr != nullptr) && (counter < itemCount)) {
  //  if (target == curPtr->getItem()) {
  //    return curPtr;
  //  }

  //  counter++;
  //  curPtr = curPtr->getNext();
  //}

  //return curPtr;
}

template<class ItemType>
void LinkedBag<ItemType>::fillVector(std::vector<ItemType>& bagContents, Node<ItemType>* curPtr) const {
  if (curPtr != nullptr) {
    fillVector(bagContents, curPtr->getNext());
    bagContents.push_back(curPtr->getItem());
  }
}