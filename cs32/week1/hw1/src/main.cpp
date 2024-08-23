#include "main.h"
#include "Set.h"
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

  //std::cout << ss.size() << std::endl;

  return 0;
}