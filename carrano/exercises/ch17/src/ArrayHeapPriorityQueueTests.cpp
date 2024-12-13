#include "HeapPriorityQueue.h"
#include <cassert>

void generateHeapPriorityQueueRandomEntries(int* array, int numEntries) {
  srand(time(0));

  for (int i = 0; i < numEntries; ++i) {
    int value = rand() % 1000; // Values do not need to be unique
    *(array+i) = value;
  }
}

void ArrayHeapPriorityQueueConstructorTests(bool randomizeValues = false) {
  HeapPriorityQueue<int> queue;
  assert(queue.isEmpty());

  int n = 31;
  int items[n];
  HeapPriorityQueue<int> queueWithItems(n);
  if (randomizeValues) {
    generateHeapPriorityQueueRandomEntries(items, n);
  } else {
    for (int i = 0; i < n; ++i) {
      items[i] = i;
    }
  }

  for (int i = 0; i < n; ++i) {
    queueWithItems.enqueue(items[i]);
  }

  assert(!queueWithItems.isEmpty());

  for (int i = 0; i < n; ++i) {
    queueWithItems.dequeue();
  }

  assert(queueWithItems.isEmpty());

  try {
    queueWithItems.peekFront();
  } catch (PrecondViolatedExcept e) {
    assert(true);
  }
}

void ArrayHeapPriorityQueueQueueTests(bool randomizeValues = false) {
  int n = 4095;
  int items[n];

  HeapPriorityQueue<int> queue(n);
  assert(queue.isEmpty());

  if (randomizeValues) {
    generateHeapPriorityQueueRandomEntries(items, n);
  } else {
    for (int i = 0; i < n; ++i) {
      items[i] = i;
    }
  }

  for (int i = 0; i < n; ++i) {
    int largestValueIndex = 0;
    for (int j = 0; j <= i; ++j) {
      if (items[j] > items[largestValueIndex]) {
        largestValueIndex = j;
      }
    }

    queue.enqueue(items[i]);
    assert(queue.peekFront() == items[largestValueIndex]);
  }

  for (int i = 0; i < n; ++i) {
    int largestValueIndex = 0;
    for (int j = 0; j < n; ++j) {
      if (items[j] > items[largestValueIndex]) {
        largestValueIndex = j;
      }
    }
    assert(queue.peekFront() == items[largestValueIndex]);
    queue.dequeue();

    // Remove largest value from items
    items[largestValueIndex] = -1;
  }

  assert(queue.isEmpty());
}

void ArrayHeapPriorityQueueTests() {
  ArrayHeapPriorityQueueConstructorTests(true);
  ArrayHeapPriorityQueueQueueTests(true);

  std::cout << "ArrayHeapPriorityQueue tests passed" << std::endl;
}