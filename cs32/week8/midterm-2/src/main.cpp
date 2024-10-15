#include "headers.h"
#include "A.h"
#include "B.h"
#include "solutions.h"

int main()
{
  // Tests for gcd and gc2
  int numOfExecutions = 0;
  std::cout << "gcd(12, 30): " << gcd(12, 30, numOfExecutions) << std::endl;
  std::cout << "numOfExecutions: " << numOfExecutions << std::endl;
  numOfExecutions = 0;
  std::cout << "gcd2(12, 30): " << gcd2(12, 30, numOfExecutions) << std::endl;
  std::cout << "numOfExecutions: " << numOfExecutions << std::endl;

  // Tests for powerOfTwo
  std::cout << "powerOfTwo(3): " << powerOfTwo(3) << std::endl;
  std::cout << "powerOfTwo(4): " << powerOfTwo(4) << std::endl;

  // Tests for A and B
  A *b1 = new B;	
  B *b2 = new B;	
  A *b3 = new B("Apple");	
  b1->message();	
  b2->message();	
  b3->message();	
  delete b1;	
  delete b2;	
  delete b3;	

  // Tests for balanced
  std::string exp1 = "(2 + 4) * 6";                 // balanced
  std::string exp2 = "[(2 + 4) * {15 - 20}]";       // balanced
  std::string exp3 = "({12+30]]";                   // not balanced
  std::string exp4 = "(({{[[<<<_*_>>>]]}}))";       // balanced
  std::string exp5 = "(((( )))))))))))";            // not balanced
  
  std::cout << "checking exp1: " << exp1 << std::endl;
  std::cout << "result: " << (balanced(exp1) ? "balanced" : "not balanced") << std::endl;
  std::cout << "checking exp2: " << exp2 << std::endl;
  std::cout << "result: " << (balanced(exp2) ? "balanced" : "not balanced") << std::endl;
  std::cout << "checking exp3: " << exp3 << std::endl;
  std::cout << "result: " << (balanced(exp3) ? "balanced" : "not balanced") << std::endl;
  std::cout << "checking exp4: " << exp4 << std::endl;
  std::cout << "result: " << (balanced(exp4) ? "balanced" : "not balanced") << std::endl;
  std::cout << "checking exp5: " << exp5 << std::endl;
  std::cout << "result: " << (balanced(exp5) ? "balanced" : "not balanced") << std::endl;

  return 0;
} 