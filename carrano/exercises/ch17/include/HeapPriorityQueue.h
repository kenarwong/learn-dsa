/** ADT priority queue: Heap-based implementation.
 @file HeapPriorityQueue.h */

#ifndef HEAP_PRIORITY_QUEUE_
#define HEAP_PRIORITY_QUEUE_

#include "ArrayMaxHeap.h"
#include "QueueInterface.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class HeapPriorityQueue : public QueueInterface<ItemType>,
                          private ArrayMaxHeap<ItemType>
{
public:
   HeapPriorityQueue();
   HeapPriorityQueue(int size);
   bool isEmpty() const;
   bool enqueue(const ItemType& newEntry);
   bool dequeue();
   
   /** @pre  The priority queue is not empty. */
   ItemType peekFront() const;
}; // end HeapPriorityQueue

template <class ItemType>
inline HeapPriorityQueue<ItemType>::HeapPriorityQueue()
{
  ArrayMaxHeap<ItemType>();
}

template <class ItemType>
inline HeapPriorityQueue<ItemType>::HeapPriorityQueue(int size) : ArrayMaxHeap<ItemType>(size)
{
}

template <class ItemType>
inline bool HeapPriorityQueue<ItemType>::isEmpty() const
{
  return ArrayMaxHeap<ItemType>::isEmpty();
}

template <class ItemType>
inline bool HeapPriorityQueue<ItemType>::enqueue(const ItemType &newEntry)
{
  return ArrayMaxHeap<ItemType>::add(newEntry);
}

template <class ItemType>
inline bool HeapPriorityQueue<ItemType>::dequeue()
{
  return ArrayMaxHeap<ItemType>::remove();
}

template <class ItemType>
inline ItemType HeapPriorityQueue<ItemType>::peekFront() const
{
  try {
    return ArrayMaxHeap<ItemType>::peekTop();
  } catch (PrecondViolatedExcept e) {
    throw PrecondViolatedExcept("Attempted peek into an empty priority queue.");
  }
}

#endif