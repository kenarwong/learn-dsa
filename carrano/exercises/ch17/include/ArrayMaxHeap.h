/** Array-based implementation of the ADT Heap
 @file ArrayMaxHeap.h */

#ifndef ARRAY_MAX_HEAP
#define ARRAY_MAX_HEAP

#include <iostream>
#include <memory>
#include "HeapInterface.h"
#include "PrecondViolatedExcept.h"
#include <cmath>

template<class ItemType>
class ArrayMaxHeap : public HeapInterface<ItemType>
{
private:
  static const int ROOT_INDEX = 0;        // Helps with readability
  static const int DEFAULT_CAPACITY = 21; // Small default capacity

  std::unique_ptr<ItemType[]> items;      // Unique pointer to array of heap items
  int itemCount;                          // Current count of items in heap
  int maxCount;                           // Maximum capacity of the heap

  /** 
   * Helper functions
   * Depend on array-based implementation
  */

  // Return left child index of node at index
  int getLeftChildIndex(const int nodeIndex) const;

  // Return right child index of node at index
  int getRightChildIndex(const int nodeIndex) const;

  // Return parent index of node at index
  int getParentIndex(const int nodeIndex) const;

  // Check if node at index is a leaf
  bool isLeaf(const int nodeIndex) const;

  // Recursive method reheapify subtree at node index
  // Assumes node at root of subtree requires to be sifted down
  void heapRebuild(const int nodeIndex);

  // Creates a heap from an array
  // Internally calls heapRebuild
  void heapCreate();

public:
  ArrayMaxHeap();
  ArrayMaxHeap(const int arraySize);
  ArrayMaxHeap(const ItemType someArray[], const int arraySize);
  virtual ~ArrayMaxHeap();

  bool isEmpty() const;
  int getNumberOfNodes() const;
  int getHeight() const;
  ItemType peekTop() const;
  bool add(const ItemType& newData);
  bool remove();
  void clear();
};

template <class ItemType>
inline int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
  return nodeIndex*2 + 1;
}

template <class ItemType>
inline int ArrayMaxHeap<ItemType>::getRightChildIndex(const int nodeIndex) const
{
  return nodeIndex*2 + 2;
}

template <class ItemType>
inline int ArrayMaxHeap<ItemType>::getParentIndex(const int nodeIndex) const
{
  if (nodeIndex == 0) {
    throw PrecondViolatedExcept("Root has no parent");
  }
  return (nodeIndex-1)/2;
}

template <class ItemType>
inline bool ArrayMaxHeap<ItemType>::isLeaf(const int nodeIndex) const
{
  int leftIndex = getLeftChildIndex(nodeIndex);
  int rightIndex = getRightChildIndex(nodeIndex);

  // If either child index is greater than or equal to itemCount, then node is a leaf
  return leftIndex >= itemCount && rightIndex >= itemCount;
}

template <class ItemType>
inline void ArrayMaxHeap<ItemType>::heapRebuild(const int nodeIndex)
{
  /** Sifting Down
   * At each node, we check to see if any child is larger than the current node
   * Only performed on subtrees (i.e. not leaves)
   * By definition, in a complete binary tree, at least the left child exists
   * It is possible that a right child does not exist
   * Once largest child is determined, swap parent and child value
   * Do nothing if equal
   */
  if (!isLeaf(nodeIndex)) {
    // Left must exist
    int childIndex = getLeftChildIndex(nodeIndex);
    ItemType child = items[childIndex];

    // Check if right child exists
    int rightChildIndex = getRightChildIndex(nodeIndex);

    // If greater than itemCount, then right child does not exist
    if (rightChildIndex < itemCount) {
      ItemType rightChild = items[rightChildIndex];

      // Determine largest child
      if (rightChild > child) {
        child = rightChild;
        childIndex = rightChildIndex;
      }
    }

    // Swap if child is larger
    if (child > items[nodeIndex]) {
      items[childIndex] = items[nodeIndex];
      items[nodeIndex] = child;

      // Recursive call to next subtree
      heapRebuild(childIndex);
    }
  }
}

template <class ItemType>
inline void ArrayMaxHeap<ItemType>::heapCreate()
{
  // Get start node
  // Only need to heapify internal node subtrees
  int startNodeIndex = maxCount/2 - 1;

  for (int i = startNodeIndex; i >= 0; --i) {
    heapRebuild(i);
  }
}

template <class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap() : itemCount(0),
                                         maxCount(DEFAULT_CAPACITY)
{
  items = std::make_unique<ItemType[]>(DEFAULT_CAPACITY);
}

template <class ItemType>
inline ArrayMaxHeap<ItemType>::ArrayMaxHeap(const int arraySize) : itemCount(0),
                                                                   maxCount(2*arraySize)
{
  items = std::make_unique<ItemType[]>(maxCount);
}

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(
    const ItemType someArray[],
    const int arraySize
  ) : 
  itemCount(arraySize), 
  maxCount(2*arraySize)
{
  items = std::make_unique<ItemType[]>(maxCount);

  // Copy values
  for (int i = 0; i < itemCount; i++) {
    items[i] = someArray[0];
  }

  // Heapify array
  heapCreate();
}

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap() {
  // No need to explicitly delete unique_ptr items as it will be automatically deleted when the destructor is called.
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const {
  return itemCount == 0;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const {
  return itemCount;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const {
  return std::ceil(std::log2(itemCount + 1));
}

template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const {
  if (itemCount == 0) {
    throw PrecondViolatedExcept("Heap is empty");
  }
  //return *items;
  return items[0];
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData) {
  /** Insert value into heap
   * If heap is not full
   * 1) Insert into last array index (itemCount),
   *    which is associated the next valid position in a complete binary tree
   * 2) Perform reheapification, by bubbling up the value
   *    Compare this value with each parent, until value is no longer larger than parent
   */

  if (itemCount < maxCount) {
    // Directly insert into root if empty 
    if (isEmpty()) {
      // Insert into root
      items[0] = newData;
      itemCount++; // Increment count
      return true;
    }

    // insert new node
    int childIndex = itemCount;
    items[childIndex] = newData;

    // Get parent
    int parentIndex = getParentIndex(childIndex);
    ItemType parent = items[parentIndex];

    // Bubble up until data is no longer greater than parent and we haven't passed root
    while (newData > parent) {
      // swap
      items[parentIndex] = newData;
      items[childIndex] = parent;

      // Update parentIndex and childIndex
      childIndex = parentIndex;
      try {
        parentIndex = getParentIndex(childIndex);
        parent = items[parentIndex];
      } catch (PrecondViolatedExcept e) {
        // We have already reached root
        break;
      }
    }

    itemCount++; // Increment count
  } else {
    throw PrecondViolatedExcept("Heap is full");
  }

  // // Print array
  // for (int i = 0; i < itemCount; i++) {
  //   std::cout << items[i] << " ";
  // }
  // std::cout << std::endl;
  
  return true;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove() {
  /** Extract largest value
   * 1) Save largest value, which is at top of heap
   *    Use peekTop(), which will throw an error if array is empty
   * 2) Replace with bottom-most, left-most item, which is at end of array
   * 3) Perform recursive sift down, heapRebuild()
   */
  
  ItemType returnValue = peekTop(); // Checks against empty array

  items[0] = items[itemCount-1];
  heapRebuild(0);
  itemCount--;  // Decrement count

  // // Print array
  // for (int i = 0; i < itemCount; i++) {
  //   std::cout << items[i] << " ";
  // }
  // std::cout << std::endl;
  
  // return returnValue; // Return top value if extracting
  return true;
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::clear() {
  items.reset(new ItemType[maxCount]); // Delete and create a new items array of same array capacity
  itemCount = 0;
}
#endif