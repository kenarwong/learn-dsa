#ifndef EXERCISE_LINKED_BAG_H
#define EXERCISE_LINKED_BAG_H

#include "LinkedBag.h"
#include "Node.h"

template<class ItemType>
class ExerciseLinkedBag: public LinkedBag<ItemType>
{
public:
   ExerciseLinkedBag();
   //ExerciseLinkedBag(const LinkedBag<ItemType>& aBag);
   //virtual ~ExerciseLinkedBag();

   int getCurrentSize() const override;
   bool addToRear(const ItemType& newEntry);

private:
    //Node<ItemType>* headPtr; // Pointer to first node
    //Node<ItemType>* tailPtr; // Pointer to last node
    //int itemCount; // Current count of bag items
};


// Explicit instantiation because we are separating the interface from the implementation
// C++ can't handle generic classes at runtime
template class ExerciseLinkedBag<std::string>;

#endif