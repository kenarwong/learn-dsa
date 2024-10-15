#ifndef B_H
#define B_H

#include "headers.h"
#include "A.h"

class B : public A
{
public:
  B() : A("Orange") {}
  B(string msg) : A(msg), m_a(msg) {}
  //virtual ~B() { 
  //  std::cout << "B destructor" << std::endl;
  //  message();
  //}
  void message() const {
    m_a.message();
  }

private:
  A m_a;
};

#endif