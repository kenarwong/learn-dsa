#include "headers.h"
#include "Node.h"
#include "ExerciseLinkedBag.h"

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


}