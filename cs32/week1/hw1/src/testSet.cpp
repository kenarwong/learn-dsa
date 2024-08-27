#include "testSet.h"
using namespace std;

int test()
{
  Set s;
  assert(s.empty());
  ItemType x = "arepa";
  assert(!s.get(42, x) && x == "arepa"); // x unchanged by get failure
  s.insert("chapati");
  assert(s.size() == 1);
  assert(s.get(0, x) && x == "chapati");
  cout << "Passed all tests" << endl;

  return 0;
}