#include "headers.h"
#include "Node.h"
#include "ExerciseLinkedBag.h"
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
  
}
