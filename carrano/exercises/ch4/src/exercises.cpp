#include "headers.h"
#include "Node.h"
#include "ExerciseLinkedBag.h"
#include "DoublyLinkedBag.h"
#include <stdlib.h> 

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

void Exercise2() {
  std::cout << "Exercise 2" << std::endl;

  ExerciseLinkedBag<std::string>* ptr = new ExerciseLinkedBag<std::string>();

  ptr->addToRear("Hello");
  ptr->addToRear("world");

  // Clean up
  delete ptr;
  ptr = nullptr;
}

void Exercise3() {
  std::cout << "Exercise 3" << std::endl;

  ExerciseLinkedBag<std::string>* ptr = new ExerciseLinkedBag<std::string>();

  ptr->addToRear("Hello");
  ptr->addToRear("world");

  std::cout << "(Iterative) Current size: " << ptr->getCurrentSizeIteratively() << std::endl;
  std::cout << "(Recursive) Current size: " << ptr->getCurrentSizeRecursively() << std::endl;

  // Clean up
  delete ptr;
  ptr = nullptr;
}

void Exercise4() {
  std::cout << "Exercise 4" << std::endl;

  ExerciseLinkedBag<std::string>* ptr = new ExerciseLinkedBag<std::string>();

  ptr->addToRear("Hello");
  ptr->addToRear("world");
  ptr->addToRear("world");
  ptr->addToRear("world");
  ptr->addToRear("world");

  std::cout << "(Recursive) The frequency of \"world\" is: " << ptr->getFrequencyOf("world") << std::endl;

  // Clean up
  delete ptr;
  ptr = nullptr;
}

void Exercise5() {
  std::cout << "Exercise 5" << std::endl;

  std::string arr[5] = {"Hello", "world", "world", "world", "world"};

  ExerciseLinkedBag<std::string>* ptr = new ExerciseLinkedBag<std::string>(arr, 5);

  std::cout << "The size of the list is: " << ptr->getCurrentSize() << std::endl;

  // Clean up
  delete ptr;
  ptr = nullptr;
}

void Exercise6() {
  std::cout << "Exercise 6" << std::endl;

  ExerciseLinkedBag<std::string>* ptr = new ExerciseLinkedBag<std::string>();

  ptr->addToRear("0");
  ptr->addToRear("1");
  ptr->addToRear("2");
  ptr->addToRear("3");
  ptr->addToRear("4");

  ptr->removeRandomEntry();

  std::vector<std::string> vec = ptr->toVector();
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << std::endl;
  }

  // Clean up
  delete ptr;
  ptr = nullptr;
}

void Exercise7() {
  std::cout << "Exercise 7" << std::endl;

  Node<std::string>* nodePtr4 = new Node<std::string>("4", nullptr); 
  Node<std::string>* nodePtr3 = new Node<std::string>("3", nodePtr4); 
  Node<std::string>* nodePtr2 = new Node<std::string>("2", nodePtr3); 
  Node<std::string>* nodePtr1 = new Node<std::string>("1", nodePtr2); 
  Node<std::string>* nodePtr0 = new Node<std::string>("0", nodePtr1); 

  Node<std::string>* iPtr = nodePtr0;
  while (iPtr != nullptr) {
    std::cout << iPtr->getItem() << std::endl;
    iPtr = iPtr->getNext();
  }

  std::string arr[5] = {"0", "1", "2", "3", "4"};
  for (int i = 0; i < 5; i++) {
    std::cout << arr[i] << std::endl;
  }

  // Clean up
  delete nodePtr0;
  delete nodePtr1;
  delete nodePtr2;
  delete nodePtr3;
  delete nodePtr4;
}

void Exercise8() {
  std::cout << "Exercise 8" << std::endl;

  Node<std::string>* nodePtr4 = new Node<std::string>("4", nullptr); 
  Node<std::string>* nodePtr3 = new Node<std::string>("3", nodePtr4); 
  Node<std::string>* nodePtr2 = new Node<std::string>("2", nodePtr3); 
  Node<std::string>* nodePtr1 = new Node<std::string>("1", nodePtr2); 
  Node<std::string>* nodePtr0 = new Node<std::string>("0", nodePtr1); 

  srand(time(0));
  int n = rand() % 5;

  Node<std::string>* iPtr = nodePtr0;
  int i = 0;
  while (iPtr != nullptr) {
    if (i == n){
      std::cout << iPtr->getItem() << std::endl;
    }
    iPtr = iPtr->getNext();
    i++;
  }

  std::string arr[5] = {"0", "1", "2", "3", "4"};
  std::cout << arr[n] << std::endl;

  // Clean up
  nodePtr0 = nullptr;
  nodePtr1 = nullptr;
  nodePtr2 = nullptr;
  nodePtr3 = nullptr;
  nodePtr4 = nullptr;
}

void Exercise9() {
  std::cout << "Exercise 9" << std::endl;
  
  Node<std::string>* nodePtr4 = new Node<std::string>("4", nullptr); 
  Node<std::string>* nodePtr3 = new Node<std::string>("3", nodePtr4); 
  Node<std::string>* nodePtr2 = new Node<std::string>("2", nodePtr3); 
  Node<std::string>* nodePtr1 = new Node<std::string>("1", nodePtr2); 
  Node<std::string>* nodePtr0 = new Node<std::string>("0", nodePtr1); 
  Node<std::string>* headPtr = nodePtr0;

  //std::string toDelete = "2";
  //std::string toDelete = "0";
  std::string toDelete = "4";

  // Linked list delete
  bool found = false;
  Node<std::string>* iPtr = headPtr;
  while (!found && iPtr != nullptr) {
    if (iPtr->getItem() == toDelete) {
      Node<std::string>* nodeToDeletePtr = headPtr;
      iPtr->setItem(headPtr->getItem());
      headPtr = headPtr->getNext();

      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;

      found = true;
    }
    iPtr = iPtr->getNext();
  }

  iPtr = headPtr;
  while (iPtr != nullptr) {
    std::cout << iPtr->getItem() << std::endl;
    iPtr = iPtr->getNext();
  }

  // Array delete
  found = false;
  int size = 5;
  std::string replaceValue = "";
  std::string arr[size] = {"0", "1", "2", "3", "4"};

  int i = size - 1;
  std::string temp;
  while (!found && i >= 0) {
    temp = arr[i];
    arr[i] = replaceValue;
    replaceValue = temp;
  
    if(temp == toDelete) {
      found = true;
      size--;
    }
  
    i--;
  }

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << std::endl;
  }

  // Clean up
  while (headPtr != nullptr) {
    Node<std::string>* nodeToDeletePtr = headPtr;
    headPtr = headPtr->getNext();

    nodeToDeletePtr->setNext(nullptr);
    delete nodeToDeletePtr;
    nodeToDeletePtr = nullptr;
  }

}

void Exercise10() {
  std::cout << "Exercise 10" << std::endl;

  DoublyLinkedNode<std::string>* nodePtr0 = new DoublyLinkedNode<std::string>("0");
  DoublyLinkedNode<std::string>* nodePtr1 = new DoublyLinkedNode<std::string>("1");
  DoublyLinkedNode<std::string>* nodePtr2 = new DoublyLinkedNode<std::string>("2");
  DoublyLinkedNode<std::string>* nodePtr3 = new DoublyLinkedNode<std::string>("3");

  nodePtr0->setNext(nodePtr1);
  nodePtr1->setNext(nodePtr2);
  nodePtr2->setNext(nodePtr3);
  nodePtr3->setPrev(nodePtr2);
  nodePtr2->setPrev(nodePtr1);
  nodePtr1->setPrev(nodePtr0);

  DoublyLinkedNode<std::string>* curPtr = nodePtr0;
  while (curPtr != nullptr) {
    std::cout << curPtr->getItem() << std::endl;
    curPtr = curPtr->getNext();
  }

  curPtr = nodePtr3;
  while (curPtr != nullptr) {
    std::cout << curPtr->getItem() << std::endl;
    curPtr = curPtr->getPrev();
  }

  delete nodePtr0;
  delete nodePtr1;
  delete nodePtr2;
  delete nodePtr3;
}

void Exercise11() {
  std::cout << "Exercise 11" << std::endl;

  DoublyLinkedBag<std::string>* bag = new DoublyLinkedBag<std::string>();
  std::cout << "isEmpty(): " << bag->isEmpty() << std::endl;

  bag->add("Wilson");
  bag->add("Smith");
  bag->add("Jones");
  bag->add("Baker");
  bag->add("Able");
  std::cout << "getCurrentSize(): " << bag->getCurrentSize() << std::endl;
  std::cout << "isEmpty(): " << bag->isEmpty() << std::endl;

  bag->clear();
  std::cout << "isEmpty(): " << bag->isEmpty() << std::endl;

  delete bag;
}

void Exercise12() {
  std::cout << "Exercise 12" << std::endl;

  DoublyLinkedBag<std::string>* bag = new DoublyLinkedBag<std::string>();

  bag->add("Wilson");
  bag->add("Smith");
  bag->add("Jones");
  bag->add("Baker");
  bag->add("Able");
  std::cout << "getCurrentSize(): " << bag->getCurrentSize() << std::endl;

  bag->remove("Able");
  std::cout << "getCurrentSize(): " << bag->getCurrentSize() << std::endl;
  bag->remove("Wilson");
  std::cout << "getCurrentSize(): " << bag->getCurrentSize() << std::endl;

  for(auto it : bag->toVector()) {
    std::cout << it << std::endl;
  }

  delete bag;
}