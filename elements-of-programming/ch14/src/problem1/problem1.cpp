#include "problem1.h"
#include <iostream>
#include <cassert>

void TestUnsorted() {
  std::vector<int> a = {1, 2, 3, 4, 5};
  std::vector<int> b = {3, 4, 5, 6, 7};
  std::vector<int> c = intersect_unsorted(a, b);
  for (int i = 0; i < c.size(); i++) {
    std::cout << c[i] << " ";
  }
  std::cout << std::endl;

  assert(c.size() == 3);
  assert(c[0] == 3);
  assert(c[1] == 4);
  assert(c[2] == 5);
}

void TestSorted1() {
  std::vector<int> a = {11, 12, 13};
  std::vector<int> b = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  std::vector<int> c = intersect_sorted1(a, b);
  for (int i = 0; i < c.size(); i++) {
    std::cout << c[i] << " ";
  }
  std::cout << std::endl;

  assert(c.size() == 3);
  assert(c[0] == 11);
  assert(c[1] == 12);
  assert(c[2] == 13);
}

void TestSorted2() {
  std::vector<int> a = {1, 1, 2, 3, 3, 4, 5, 5};
  std::vector<int> b = {3, 4, 5, 6, 7};
  std::vector<int> c = intersect_unsorted(a, b);
  for (int i = 0; i < c.size(); i++) {
    std::cout << c[i] << " ";
  }
  std::cout << std::endl;

  assert(c.size() == 3);
  assert(c[0] == 3);
  assert(c[1] == 4);
  assert(c[2] == 5);
}

int main()
{
  std::cout << "Problem 1" << std::endl;
  TestUnsorted();
  TestSorted1();
  TestSorted2();

  return 0;
}