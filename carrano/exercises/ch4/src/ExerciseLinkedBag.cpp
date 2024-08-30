#include "ExerciseLinkedBag.h"
#include <stdlib.h> 

// Default constructor
template<class ItemType>
ExerciseLinkedBag<ItemType>::ExerciseLinkedBag() : LinkedBag<ItemType>() {
  // Initialize any member variables here
}

template<class ItemType>
ExerciseLinkedBag<ItemType>::ExerciseLinkedBag(const ItemType* arr, size_t size) : LinkedBag<ItemType>() {
  for (int i = 0; i < size; i++) {
    this->add(arr[i]);
  }
}

//// Destructor
//template<class ItemType>
//ExerciseLinkedBag<ItemType>::~ExerciseLinkedBag() {
//  // Clean up any dynamically allocated memory here
//}

// Adds a new entry to the bag
template<class ItemType>
bool ExerciseLinkedBag<ItemType>::addToRear(const ItemType& newEntry) {

  Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry, nullptr);

  if (this->isEmpty()) {
    return this->add(newEntry); 
  }

  Node<ItemType>* oldTailPtr = this->tailPtr; // Get current tailPtr
  oldTailPtr->setNext(newNodePtr); // Set tailPtr's next node 

  this->tailPtr = newNodePtr; // New node is now last node
  this->itemCount++;

  return true;
}

template<class ItemType>
int ExerciseLinkedBag<ItemType>::getCurrentSizeIteratively() const {
  // Iteratively
  Node<ItemType>* curPtr = this->headPtr;
  int count = 0;
  while (curPtr != nullptr) {
    count++;
    curPtr = curPtr->getNext();
  }

  return count;
}
template<class ItemType>
int ExerciseLinkedBag<ItemType>::getCurrentSizeRecursively() const {
  return getCurrentSizeRecursively(0, this->headPtr);
}

template<class ItemType>
int ExerciseLinkedBag<ItemType>::getCurrentSizeRecursively(int count, Node<ItemType>* curPtr) const {
  if (curPtr != nullptr){ 
    return getCurrentSizeRecursively(count + 1, curPtr->getNext());
  }
  return count;
}

template<class ItemType>
int ExerciseLinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
  return getFrequencyOf(0, anEntry, this->headPtr);
}

template<class ItemType>
int ExerciseLinkedBag<ItemType>::getFrequencyOf(int count, const ItemType& anEntry, Node<ItemType>* curPtr) const {
  if (curPtr != nullptr) {
    if (curPtr->getItem() == anEntry) {
      count++;
    }
    return getFrequencyOf(count, anEntry, curPtr->getNext());
  }
  else {
    return count;
  }
}

template<class ItemType>
bool ExerciseLinkedBag<ItemType>::removeRandomEntry() {
  if (this->isEmpty()) {
    return false;
  }

  srand(time(0));
  int randomIndex = rand() % this->getCurrentSize();

  Node<ItemType>* curPtr = this->headPtr;
  while (randomIndex > 1) {
    randomIndex--;
    curPtr = curPtr->getNext();
  }

  Node<ItemType>* nodeToDeletePtr = curPtr->getNext();
  curPtr->setNext(nodeToDeletePtr->getNext());

  nodeToDeletePtr->setNext(nullptr);
  delete nodeToDeletePtr;
  nodeToDeletePtr = nullptr;

  return true;
}