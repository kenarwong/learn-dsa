#include "exercises.h"
#include "headers.h"
#include "Node.h"

using namespace std;

int randInt(int min, int max) {
  return rand() % (max - min + 1) + min;
}

void Exercise1() {
  cout << "Exercise 1" << endl;

  int n =  20;
  Node<int>* node = nullptr;
  for (int i = n; i > 0; i--) {
    Node<int>* prev = node;
    node = new Node<int>(randInt(1, 5));
    node->setNext(prev);
  }
  Node<int>* head = node;

  // Print initial
  node = head;
  while (node != nullptr) {
    cout << node->getItem() << " ";
    node = node->getNext();
  }
  cout << endl;

  Node<int>* start = head;

  while (start != nullptr) {
    Node<int>* end = start;

    while (end != nullptr) {
      if (end->getNext() != nullptr && end->getNext()->getItem() == start->getItem()) {
        Node<int>* toDelete = end->getNext();
        end->setNext(end->getNext()->getNext()); // could be nullptr

        delete toDelete;
      
        // next needs to be checked now
        // don't advance yet
      } else {
        // only advance runner if we didn't delete
        end = end->getNext();
      }

    }

    start = start->getNext();
  }

  // Print and clean-up final
  node = head;
  while (node != nullptr) {
    Node<int>* toDelete = node;
    cout << toDelete->getItem() << " ";
    node = node->getNext();

    delete toDelete;
  }
  cout << endl;
}