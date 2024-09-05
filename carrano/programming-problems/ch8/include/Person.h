#ifndef PERSON_
#define PERSON_

#include "headers.h"
#include "LinkedList.h"

struct Person {
  Person() : name_(""), gifts_(nullptr) {};
  Person(const std::string& name, LinkedList<std::string>* list) : name_(name), gifts_(list) {};

  bool operator==(const Person& p) const {
    return name_ == p.name_;
  }

  bool operator<(const Person& p) const {
    return name_ < p.name_;
  }

  std::string name_;
  LinkedList<std::string>* gifts_;
};

#endif