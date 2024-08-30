#ifndef EXERCISE_LINKED_BAG_H
#define EXERCISE_LINKED_BAG_H

#include "LinkedBag.h"
#include "Node.h"

template<class ItemType>
class ExerciseLinkedBag: public LinkedBag<ItemType>
{
public:
  ExerciseLinkedBag();
  ExerciseLinkedBag(const ItemType* arr, size_t size);
  //ExerciseLinkedBag(const LinkedBag<ItemType>& aBag);
  //virtual ~ExerciseLinkedBag();

  bool addToRear(const ItemType& newEntry);

  int getCurrentSizeIteratively() const;
  int getCurrentSizeRecursively() const;

  int getFrequencyOf(const ItemType& anEntry) const override;

  bool removeRandomEntry();

private:
  //Node<ItemType>* headPtr; // Pointer to first node
  //Node<ItemType>* tailPtr; // Pointer to last node
  //int itemCount; // Current count of bag items

  int getCurrentSizeRecursively(int count, Node<ItemType>* curPtr) const;
  int getFrequencyOf(int count, const ItemType& anEntry, Node<ItemType>* curPtr) const;
};


// Explicit instantiation because we are separating the interface from the implementation
// C++ can't handle generic classes at runtime
template class ExerciseLinkedBag<std::string>;

#endif