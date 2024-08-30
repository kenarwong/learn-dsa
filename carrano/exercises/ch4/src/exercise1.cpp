#include "headers.h"
#include "Node.h"
#include "LinkedBag.h"

void Exercise1() {
  std::cout << "Exercise 1" << std::endl;

  Node<std::string>* secondPtr = new Node<std::string>("world", nullptr); 
  Node<std::string>* headPtr = new Node<std::string>("Hello", secondPtr); 

  // Write C++ statements that delete the second node and return it to the system
  Node<std::string>* ptr = headPtr->getNext();
  delete ptr;
  ptr = nullptr;

  // Clean up
  delete headPtr;
  headPtr = nullptr;
  secondPtr = nullptr;
}

// Exercise2
template<class ItemType>
bool LinkedBag<ItemType>::addToRear(const ItemType& newEntry) {

  Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry, nullptr);

  if (isEmpty()) {
    return add(newEntry); 
  }

  Node<ItemType>* oldTailPtr = tailPtr; // Get current tailPtr
  oldTailPtr->setNext(newNodePtr); // Set tailPtr's next node 

  tailPtr = newNodePtr; // New node is now last node
  itemCount++;

  return true;
}

void Exercise2() {
  std::cout << "Exercise 2" << std::endl;

  LinkedBag<std::string>* ptr = new LinkedBag<std::string>();

  ptr->addToRear("Hello");
  ptr->addToRear("world");

  // Clean up
  delete ptr;
  ptr = nullptr;
}