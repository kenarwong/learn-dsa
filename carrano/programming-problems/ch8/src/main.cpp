#include "headers.h"
#include "ListTester.h"
#include "LinkedList.h"
#include "Person.h"

int main() {
  //ListTester();
  
  LinkedList<std::string>* list1 = new LinkedList<std::string>();
  list1->add("hat");
  list1->add("doll");
  list1->add("ball");
  Person p1 = Person("Amy",list1);

  LinkedList<std::string>* list2 = new LinkedList<std::string>();
  list2->add("coal");
  list2->add("coal");
  list2->add("coal");
  Person p2 = Person("Paul",list2);

  LinkedList<Person>* niceList = new LinkedList<Person>();
  niceList->add(p1);

  LinkedList<Person>* naughtyList = new LinkedList<Person>();
  naughtyList->add(p2);

  // Clean up
  delete list1;
  delete list2;

  delete niceList;
  delete naughtyList;

  return 0;
}
