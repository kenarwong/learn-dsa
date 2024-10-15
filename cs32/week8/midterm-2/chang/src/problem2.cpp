#include "headers.h"
#include <iostream>
using namespace std;

class LinkedList
{
public:
    LinkedList(): head(nullptr) {}  // append value to the list
    ~LinkedList();
    void append(int value);
    void print() const;             // show the items in the list opposite order
    void printReverse() const;      // show the items in the list in the
    void reverse();                 // change list so items are in the opposite order
    int sum() const;                // return the sum of the values in the list

private:
    struct Node
    {
        int num;
        Node* next;
    };

    Node* head; // this is the only data member, do not add any others

    void printReverseHelper(const Node* p) const;
    Node* reverseHelper (Node* current, Node* previous);
    int sumHelper(const Node* p) const;
    void removeNodes(Node* p);
};

void Problem2() {
    std::cout << "Problem 2" << std::endl;

    LinkedList list;
    cout << list.sum() << endl;         // writes 0
    int values[4] = {30, 10, 40, 20};
    for (int i = 0; i < 4; i++)
        list.append(values[i]);
    list.print();                       // writes 30 10 40 20
    cout << list.sum() << endl;        // writes 100
    list.printReverse();                // writes 20 40 10 30
    list.print();                       // writes 30 10 40 20 (list wasn't changed)
    list.reverse();                     // this changes the list
    list.print();                       // writes 20 40 10 30
}

void LinkedList::append(int value)
{
  Node *current = new Node;
  current->num = value;
  current->next = nullptr;
  if (head == nullptr)
  {
    head = current;
  }
  else
  {
    Node *ptr = head;
    while (ptr->next != nullptr) {
      ptr = ptr->next;
    }
    ptr->next = current;
  }
}

void LinkedList::print() const
{
    for (const Node* ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->num << " ";
    cout << endl;
}

void LinkedList::printReverse() const
{
    printReverseHelper(head);
    cout << endl;
}

void LinkedList::printReverseHelper(const Node* p) const
{
    if(p == nullptr)
        return;

    printReverseHelper(p->next);

    cout << p->num << " ";
}

void LinkedList::reverse()
{
    head = reverseHelper(head, nullptr);
}

LinkedList::Node* LinkedList::reverseHelper(Node* current, Node* previous) 
{
    if(current == nullptr)
        return previous; // will become new head
    Node* last_node = reverseHelper(current->next, current);

    current->next = previous;
    return last_node; // bubble head up
}

int LinkedList::sum() const
{
    return sumHelper(head);
}

int LinkedList::sumHelper(const LinkedList::Node* p) const
{
    if (p == nullptr) {
        return 0;
    }

    return p->num + sumHelper(p->next);
}

LinkedList::~LinkedList()
{
    removeNodes(head);
}

void LinkedList::removeNodes(Node* p) 
{
    if (p == nullptr) {
        return;
    }

    Node* toDelete = p;
    p = p->next;
    delete toDelete;

    removeNodes(p);
}