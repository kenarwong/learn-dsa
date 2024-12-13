#include "ArrayMaxHeap.h"
#include <cassert>

void generateArrayMaxHeapRandomEntries(int* array, int numEntries) {
  srand(time(0));

  for (int i = 0; i < numEntries; ++i) {
    int value = rand() % 1000; // Values do not need to be unique
    *(array+i) = value;
  }
}

void ArrayMaxHeapConstructorTests(bool randomizeValues = false) {
  ArrayMaxHeap<int> heap;
  assert(heap.isEmpty());
  assert(heap.getHeight() == 0);

  int n = 31;
  int height = 5; // ceil(log2(31 + 1))
  int items[n];
  if (randomizeValues) {
    generateArrayMaxHeapRandomEntries(items, n);
  } else {
    for (int i = 0; i < n; ++i) {
      items[i] = i;
    }
  }

  ArrayMaxHeap<int> heapWithItems(items, n);
  assert(!heapWithItems.isEmpty());
  assert(heapWithItems.getNumberOfNodes() == n);
  assert(heapWithItems.getHeight() == height);

  n = 127;
  height = 7; // ceil(log2(127 + 1))
  int items2[n];
  if (randomizeValues) {
    generateArrayMaxHeapRandomEntries(items2, n);
  } else {
    for (int i = 0; i < n; ++i) {
      items2[i] = i;
    }
  }

  ArrayMaxHeap<int> heapWithSize(n);
  for (int i = 0; i < n; ++i) {
    heapWithSize.add(items2[i]);
  }
  assert(!heapWithSize.isEmpty());
  assert(heapWithSize.getNumberOfNodes() == n);
  assert(heapWithSize.getHeight() == height);
}

void ArrayMaxHeapAddRemoveTests() {
  ArrayMaxHeap<int> heap;
  assert(heap.isEmpty());
  assert(heap.getHeight() == 0);

  assert(heap.add(10));
  assert(!heap.isEmpty());
  assert(heap.getNumberOfNodes() == 1);
  assert(heap.getHeight() == 1);
  assert(heap.peekTop() == 10);

  assert(heap.add(20));
  assert(!heap.isEmpty());
  assert(heap.getNumberOfNodes() == 2);
  assert(heap.getHeight() == 2);
  assert(heap.peekTop() == 20);

  assert(heap.add(5));
  assert(!heap.isEmpty());
  assert(heap.getNumberOfNodes() == 3);
  assert(heap.getHeight() == 2);
  assert(heap.peekTop() == 20);

  assert(heap.add(15));
  assert(!heap.isEmpty());
  assert(heap.getNumberOfNodes() == 4);
  assert(heap.getHeight() == 3);
  assert(heap.peekTop() == 20);

  assert(heap.add(25));
  assert(!heap.isEmpty());
  assert(heap.getNumberOfNodes() == 5);
  assert(heap.getHeight() == 3);
  assert(heap.peekTop() == 25);

  assert(heap.add(30));
  assert(!heap.isEmpty());
  assert(heap.getNumberOfNodes() == 6);
  assert(heap.getHeight() == 3);
  assert(heap.peekTop() == 30);

  assert(heap.add(35));
  assert(!heap.isEmpty());
  assert(heap.getNumberOfNodes() == 7);
  assert(heap.getHeight() == 3);
  assert(heap.peekTop() == 35);

  assert(heap.add(40));
  assert(!heap.isEmpty());
  assert(heap.getNumberOfNodes() == 8);
  assert(heap.getHeight() == 4);
  assert(heap.peekTop() == 40);

  assert(heap.add(45));
  assert(!heap.isEmpty());
  assert(heap.getNumberOfNodes() == 9);
  assert(heap.getHeight() == 4);
  assert(heap.peekTop() == 45);

  assert(heap.add(50));
  assert(!heap.isEmpty());
  assert(heap.getNumberOfNodes() == 10);
  assert(heap.getHeight() == 4);
  assert(heap.peekTop() == 50);

  assert(heap.add(55));
  assert(!heap.isEmpty());
  assert(heap.getNumberOfNodes() == 11);
  assert(heap.getHeight() == 4);
  assert(heap.peekTop() == 55);

  heap.clear();
  assert(heap.isEmpty());
  assert(heap.getHeight() == 0);
  try {
    heap.peekTop();
  } catch (PrecondViolatedExcept e) {
    assert(true);
  }
}

void ArrayMaxHeapTests() {
  ArrayMaxHeapConstructorTests(true);
  ArrayMaxHeapAddRemoveTests();

  std::cout << "ArrayMaxHeap tests passed" << std::endl;
}