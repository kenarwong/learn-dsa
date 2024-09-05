#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedList: public ListInterface<ItemType>
{
public:
   LinkedList();
   LinkedList(const LinkedList<ItemType>& aList);
   virtual ~LinkedList();
   int getCurrentSize() const override;
   bool isEmpty() const override;
   bool add(const ItemType& newEntry) override;
   bool remove(const ItemType& anEntry) override;
   void clear() override;
   int getFrequencyOf(const ItemType& anEntry) const override;
   bool contains(const ItemType& anEntry) const override;
   std::vector<ItemType> toVector() const override;

private:
    Node<ItemType>* headPtr; // Pointer to first node
    Node<ItemType>* tailPtr; // Pointer to last node
    int itemCount; // Current count of list items

    Node<ItemType>* getPointerTo(const ItemType& target, Node<ItemType>* curPtr) const;
    void fillVector(std::vector<ItemType>& listContents, Node<ItemType>* curPtr) const;

    void clear(Node<ItemType>* curPtr);
};

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0) {
}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& otherList) {
  itemCount = otherList.itemCount;
  Node<ItemType>* origChainPtr = otherList.headPtr; // Points to nodes in original chain

  if (origChainPtr == nullptr) {
    headPtr = nullptr; // Original list is empty
    tailPtr = nullptr; // Original list is empty
  } else {
    // Set headPtr
    // Copy first node
    headPtr = new Node<ItemType>();
    headPtr->setItem(origChainPtr->getItem());

    // Copy remaining nodes
    Node<ItemType>* chainPtr = headPtr; // Points to next node in new chain
    origChainPtr = origChainPtr->getNext(); 

    // Loop through old chain
    while (origChainPtr != nullptr) {
      // Get next item from original chain
      ItemType nextItem = origChainPtr->getItem();

      // Create a new node containing the next item
      Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

      // Link new node to end of new chain
      chainPtr->setNext(newNodePtr);

      // Advance pointer to new next node
      chainPtr = chainPtr->getNext();

      // Advance original-chain pointer
      origChainPtr = origChainPtr->getNext();
    }

    chainPtr->setNext(nullptr); // Flag end of chain
    tailPtr = chainPtr; // Set as tailPtr
  }
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList() {
  clear();
}

template<class ItemType>
int LinkedList<ItemType>::getCurrentSize() const {
  return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
  return itemCount == 0;
}

template<class ItemType>
bool LinkedList<ItemType>::add(const ItemType& newEntry) {
  Node<ItemType>* q = nullptr;
  Node<ItemType>* p = headPtr;

  while (p != nullptr) {
    if (newEntry == p->getItem()) {
      return false;
    }

    if (newEntry < p->getItem()) {
      break;
    }

    q = p;
    p = p->getNext();
  }

  Node<ItemType>* newNodePtr = new Node<ItemType>();
  newNodePtr->setItem(newEntry);
  newNodePtr->setNext(p);
  newNodePtr->setPrev(q);

  if (q != nullptr) {
    q->setNext(newNodePtr);
  } else {
    headPtr = newNodePtr; 
  }

  if (p != nullptr) {
    p->setPrev(newNodePtr);
  } else {
    tailPtr = newNodePtr; 
  }

  itemCount++;

  return true;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(const ItemType& anEntry) {
  //Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
  Node<ItemType>* nodeToDeletePtr = getPointerTo(anEntry, headPtr);

  bool canRemoveItem = !isEmpty() && (nodeToDeletePtr != nullptr);
  if (canRemoveItem) {
    Node<ItemType>* prev = nodeToDeletePtr->getPrev();
    Node<ItemType>* next = nodeToDeletePtr->getNext();

    if (prev != nullptr) {
      prev->setNext(next);
    } else {
      headPtr = next;
    }

    if (next != nullptr) {
      next->setPrev(prev);
    } else {
      tailPtr = prev;
    }

    // Return node to system
    nodeToDeletePtr->setNext(nullptr);
    nodeToDeletePtr->setPrev(nullptr);
    delete nodeToDeletePtr;
    nodeToDeletePtr = nullptr;

    itemCount--;
  }

  return canRemoveItem;
}

template<class ItemType>
void LinkedList<ItemType>::clear() {
  clear(headPtr);
  headPtr = nullptr;
  itemCount = 0;
}

template<class ItemType>
void LinkedList<ItemType>::clear(Node<ItemType>* curPtr) {
  if (curPtr != nullptr) {
    Node<ItemType>* nodeToDeletePtr = curPtr;
    curPtr = curPtr->getNext();
    clear(curPtr);

    delete nodeToDeletePtr;
    curPtr = nullptr;
    itemCount--;
  }
  //while (headPtr != nullptr) {
  //  headPtr = headPtr->getNext();

  //  // Return node to system
  //  nodeToDeletePtr->setNext(nullptr);
  //  delete nodeToDeletePtr;

  //  nodeToDeletePtr = headPtr;
  //}

  //itemCount = 0;
}

template<class ItemType>
int LinkedList<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
  int frequency = 0;
  int counter = 0;
  Node<ItemType>* curPtr = headPtr;
  while ((curPtr != nullptr) && (counter < itemCount)) {
    if (anEntry == curPtr->getItem()) {
      frequency++;
    }

    counter++;
    curPtr = curPtr->getNext();
  }

  return frequency;
}

template<class ItemType>
bool LinkedList<ItemType>::contains(const ItemType& anEntry) const {
  // return getPointerTo(anEntry) != nullptr;
  return getPointerTo(anEntry, headPtr) != nullptr;
}

template<class ItemType>
std::vector<ItemType> LinkedList<ItemType>::toVector() const {
  std::vector<ItemType> listContents;
  Node<ItemType>* curPtr = tailPtr;
  //int counter = 0;
  //while ((curPtr != nullptr) && (counter < itemCount)) {
  //  listContents.push_back(curPtr->getItem());
  //  curPtr = curPtr->getNext();
  //  counter++;
  //}

  fillVector(listContents, curPtr);

  return listContents;
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getPointerTo(const ItemType& target, Node<ItemType>* curPtr) const {

  Node<ItemType>* result = nullptr;
  if (curPtr != nullptr) {
    if (target == curPtr->getItem()) {
      result = curPtr;
    } else {
      curPtr = curPtr->getNext();
      result = getPointerTo(target, curPtr);
    }
  }

  return result;

  //int counter = 0;
  //Node<ItemType>* curPtr = headPtr;

  //while((curPtr != nullptr) && (counter < itemCount)) {
  //  if (target == curPtr->getItem()) {
  //    return curPtr;
  //  }

  //  counter++;
  //  curPtr = curPtr->getNext();
  //}

  //return curPtr;
}

template<class ItemType>
void LinkedList<ItemType>::fillVector(std::vector<ItemType>& listContents, Node<ItemType>* curPtr) const {
  if (curPtr != nullptr) {
    fillVector(listContents, curPtr->getPrev());
    listContents.push_back(curPtr->getItem());
  }
}

//// Explicit instantiation because we are separating the interface from the implementation
//// C++ can't handle generic classes at runtime
//template class LinkedList<std::string>;
//template class LinkedList<Person>;

//// Alternative to explicit instantiation
//#include "LinkedList.cpp"
#endif