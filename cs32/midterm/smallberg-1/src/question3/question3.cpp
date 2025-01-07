#include "question3.h"
#include <iostream>
#include <cassert>

void visit(int i) {
  std::cout << i;
}

void TestPushBack()
{
  LinkedList l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  l.traverse(visit);
  std::cout << std::endl;;
} 

void TestUnique() {
  LinkedList l;
  l.push_back(5);
  l.push_back(3);
  l.push_back(3);
  l.push_back(3);
  l.push_back(8);
  l.push_back(2);
  l.push_back(2);
  l.push_back(5);
  l.push_back(5);
  l.push_back(5);
  l.push_back(9);
  l.push_back(7);
  l.push_back(7);
  l.push_back(2);
  l.push_back(2);

  l.traverse(visit);
  std::cout << std::endl;;

  l.unique();

  l.traverse(visit);
  std::cout << std::endl;;
}

void TestDominates() {
  LinkedList l1;
  LinkedList l2;
  assert(l1.dominates(l2));

  l1.push_back(2);
  l1.push_back(5);
  l1.push_back(3);
  l1.push_back(5);
  l1.push_back(7);

  l2.push_back(1);
  l2.push_back(3);
  l2.push_back(3);
  l2.push_back(4);
  l2.push_back(7);

  assert(l1.dominates(l2));

  l2.clear();

  l2.push_back(1);
  l2.push_back(4);
  l2.push_back(4);
  l2.push_back(4);

  assert(!l1.dominates(l2));

  l1.clear();
  l1.push_back(2);
  l1.push_back(5);
  l1.push_back(5);

  assert(!l1.dominates(l2));

}

int main()
{
  std::cout << "Question 3" << std::endl;

  TestPushBack();
  TestUnique();
  TestDominates();

  return 0;
}