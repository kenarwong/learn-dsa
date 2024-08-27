#include "main.h"
#include "Set.h"
#include "testSet.h"
#include <cassert>

int main()
{
  Set ss;
  assert(ss.empty());

  ss.insert("lavash");
  ss.insert("roti");
  ss.insert("chapati");
  ss.insert("injera");
  ss.insert("roti");
  ss.insert("matzo");
  ss.insert("injera");
  assert(ss.size() == 5);  // duplicate "roti" and "injera" were not added

  std::string x;
  ss.get(0, x);
  assert(x == "roti"); // "roti" is less than exactly 0 items in ss
  ss.get(4, x);
  assert(x == "chapati"); // "chapati" is less than exactly 4 items in ss
  ss.get(2, x);
  assert(x == "lavash"); // "lavash" is less than exactly 2 items in ss

  ss = Set();
  ss.insert("dosa");
  assert(!ss.contains(""));
  ss.insert("laobing");
  ss.insert("");
  ss.insert("focaccia");
  assert(ss.contains(""));
  ss.erase("dosa");
  assert(ss.size() == 3  &&  ss.contains("focaccia")  &&  ss.contains("laobing")  &&
             ss.contains(""));
  std::string v;
  assert(ss.get(0, v)  &&  v == "laobing");
  assert(ss.get(1, v)  &&  v == "focaccia");
  assert(ss.get(2, v)  &&  v == "");

  Set ss1;
  ss1.insert("tortilla");
  Set ss2;
  ss2.insert("matzo");
  ss2.insert("pita");
  ss1.swap(ss2);
  assert(ss1.size() == 2  &&  ss1.contains("matzo")  &&  ss1.contains("pita")  &&
         ss2.size() == 1  &&  ss2.contains("tortilla"));

  // string tests
  test();
  
  return 0;
}