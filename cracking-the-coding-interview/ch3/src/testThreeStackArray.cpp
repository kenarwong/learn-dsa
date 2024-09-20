#include "headers.h"
#include "helpers.h"
#include "testThreeStackArray.h"
#include "ThreeStackArray.h"
#include <iostream>
#include <cassert>

using namespace std;

void testThreeStackArray() {
  int capacity = randInt(10, 100);
  ThreeStackArray<int> stackArray(capacity); 

  // Test pushing to all stacks simultaneously
  stackArray.push(0, 10);
  stackArray.push(0, 20);
  stackArray.push(1, 30);
  stackArray.push(1, 40);
  stackArray.push(2, 50);
  stackArray.push(2, 60);

  // Test popping from all stacks stack simultaneously
  assert(stackArray.peek(0) == 20);
  assert(stackArray.pop(0));
  assert(stackArray.peek(1) == 40);
  assert(stackArray.pop(1));
  assert(stackArray.peek(2) == 60);
  assert(stackArray.pop(2));
  assert(stackArray.peek(0) == 10);
  assert(stackArray.pop(0));
  assert(stackArray.isEmpty(0));
  assert(stackArray.peek(1) == 30);
  assert(stackArray.pop(1));
  assert(stackArray.isEmpty(1));
  assert(stackArray.peek(2) == 50);
  assert(stackArray.pop(2));
  assert(stackArray.isEmpty(2));

  // Test underflow condition
  assert(!stackArray.pop(0));

  // Test for peek underflow condition
  try
  {
    stackArray.peek(0);
  }
  catch (const std::exception &e)
  {
    cout << "Exception caught: " << e.what() << endl;
  }

  // Test overflow condition
  for (int stack = 0; stack < 3; ++stack)
  {
    for (int i = 0; i < capacity; ++i)
    {
      stackArray.push(stack, i);
    }

    assert(stackArray.peek(stack) == capacity - 1);
    assert(!stackArray.push(stack, capacity));
  }

  cout << "All tests passed!" << endl;
}