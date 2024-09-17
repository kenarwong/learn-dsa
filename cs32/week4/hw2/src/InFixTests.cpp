#include "headers.h"
#include "Map.h"
#include "InFixTests.h"
#include "InFixCalculator.h"
#include <cassert>

void InFixTests()
{
  char vars[] = {'a', 'e', 'i', 'o', 'u', 'y', '#'};
  int vals[] = {3, -9, 6, 2, 4, 1};
  Map m;
  for (int k = 0; vars[k] != '#'; k++)
    m.insert(vars[k], vals[k]);
  std::string pf;
  int answer;

  InFixCalculator calc;

  assert(calc.evaluate("a+ e", m, pf, answer) == 0 &&
         pf == "ae+" && answer == -6);
  answer = 999;
  assert(calc.evaluate("", m, pf, answer) == 1 && answer == 999);
  assert(calc.evaluate("a+", m, pf, answer) == 1 && answer == 999);
  assert(calc.evaluate("a i", m, pf, answer) == 1 && answer == 999);
  assert(calc.evaluate("ai", m, pf, answer) == 1 && answer == 999);
  assert(calc.evaluate("()", m, pf, answer) == 1 && answer == 999);
  assert(calc.evaluate("()o", m, pf, answer) == 1 && answer == 999);
  assert(calc.evaluate("y(o+u)", m, pf, answer) == 1 && answer == 999);
  assert(calc.evaluate("y(*o)", m, pf, answer) == 1 && answer == 999);
  assert(calc.evaluate("a+E", m, pf, answer) == 1 && answer == 999);
  assert(calc.evaluate("(a+(i-o)", m, pf, answer) == 1 && answer == 999);
  // unary operators not allowed:
  assert(calc.evaluate("-a", m, pf, answer) == 1 && answer == 999);
  assert(calc.evaluate("a*b", m, pf, answer) == 2 &&
         pf == "ab*" && answer == 999);
  assert(calc.evaluate("y +o *(   a-u)  ", m, pf, answer) == 0 &&
         pf == "yoau-*+" && answer == -1);
  answer = 999;
  assert(calc.evaluate("o/(y-y)", m, pf, answer) == 3 &&
         pf == "oyy-/" && answer == 999);
  assert(calc.evaluate(" a  ", m, pf, answer) == 0 &&
         pf == "a" && answer == 3);
  assert(calc.evaluate("((a))", m, pf, answer) == 0 &&
         pf == "a" && answer == 3);
  std::cout << "Passed all tests" << std::endl;
}