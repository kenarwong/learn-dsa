#ifndef A_H
#define A_H

#include "headers.h"
using namespace std;

class A
{
public:
  A() : m_msg("Apple") {}
  A(string msg) : m_msg(msg) {}
  virtual ~A() { 
    //std::cout << "A destructor" << std::endl;
    message();
  }
  //void message() const {
  virtual void message() const {
    cout << m_msg << endl;
  }

private:
  string m_msg;
};

#endif