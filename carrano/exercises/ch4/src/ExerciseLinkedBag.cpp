#include "ExerciseLinkedBag.h"

// Default constructor
template<class ItemType>
ExerciseLinkedBag<ItemType>::ExerciseLinkedBag() : LinkedBag<ItemType>() {
  // Initialize any member variables here
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
int ExerciseLinkedBag<ItemType>::getCurrentSize() const {
  return this->getCurrentSize();
}