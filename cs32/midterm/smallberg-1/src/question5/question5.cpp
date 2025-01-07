#include "question5.h"
#include <iostream>
#include <cassert>

void TestWallet() {
  Wallet w1(0);
  assert(w1.value() == 0);
  assert(w1.isEmpty() == true);

  Wallet w2(10);
  assert(w2.value() == 10);
  assert(w2.isEmpty() == false);
  w2.deposit(5);
  assert(w2.value() == 15);
  w2.deposit(-5);
  assert(w2.value() == 15);
  w2.deposit(0);
  assert(w2.value() == 15);
  w2.deposit(10);
  assert(w2.value() == 25);
  w2.deposit(-10);
  assert(w2.value() == 25);
  w2.deposit(0);
  assert(w2.value() == 25);
  w2.deposit(-10);
  assert(w2.value() == 25);
  assert(w2.isEmpty() == false);
}

void TestUKWallet() {
  UKWallet w1(0);
  assert(w1.value() == 0);
  assert(w1.isEmpty() == true);

  UKWallet w2(2);
  assert(w1.value() == 0);
  assert(w1.isEmpty() == true);

  w2.deposit(5);
  assert(w2.value() == 5);
  assert(w2.isEmpty() == false);
  w2.deposit(10);
  assert(w2.value() == 15);
}

int main()
{
  std::cout << "Question 5" << std::endl;
  TestWallet();
  TestUKWallet();

  return 0;
}
