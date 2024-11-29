//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Listing 18-4.

/** A binary search tree implementation of the ADT dictionary
 that organizes its entries in sorted search-key order.
 Search keys in the dictionary are unique.
 @file TreeDictionary.h */
 
#ifndef TREE_DICTIONARY_
#define TREE_DICTIONARY_

#include "DictionaryInterface.h"
#include "BinarySearchTree.h"
#include "Entry.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"
#include <functional>

template <class KeyType, class ValueType>
class TreeDictionary : public DictionaryInterface<KeyType, ValueType>
{
private:
   // Binary search tree of dictionary entries
   BinarySearchTree<Entry<KeyType, ValueType> > entryTree;
   
public:
  TreeDictionary();
  TreeDictionary(const TreeDictionary<KeyType, ValueType>& dictionary);
  virtual ~TreeDictionary();
   
  // The declarations of the public methods appear here and are the
  // same as given in Listing 18-3 for the class ArrayDictionary.
  bool isEmpty() const;
  int getNumberOfEntries() const;

  bool add(const KeyType& searchKey, const ValueType& newValue);
  bool remove(const KeyType& searchKey);
  void clear();

  ValueType getValue(const KeyType& searchKey) const;
  bool contains(const KeyType& searchKey) const;

  /** Traverses the entries in this dictionary in sorted search-key order
   and calls a given client function once for the value in each entry. */
  void traverse(void visit(ValueType&)) const;
}; // end TreeDictionary

template <class KeyType, class ValueType>
TreeDictionary<KeyType, ValueType>::TreeDictionary() : entryTree() {}

template <class KeyType, class ValueType>
TreeDictionary<KeyType, ValueType>::TreeDictionary(const TreeDictionary<KeyType, ValueType>& dictionary) : entryTree(dictionary.entryTree) {}

template <class KeyType, class ValueType>
TreeDictionary<KeyType, ValueType>::~TreeDictionary() {
  clear();
}

template <class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::isEmpty() const {
  return entryTree.isEmpty();
}

template <class KeyType, class ValueType>
int TreeDictionary<KeyType, ValueType>::getNumberOfEntries() const {
  return entryTree.getNumberOfNodes();
}

template <class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::add(const KeyType& searchKey,
                                             const ValueType& newValue)
{
   Entry<KeyType, ValueType> newEntry(searchKey, newValue);
   
   // Enforce precondition: Ensure distinct search keys
   if (!entryTree.contains(newEntry))
   {
      // Add new entry and return boolean result
      return entryTree.add(Entry<KeyType, ValueType>(searchKey, newValue));
   }
   else
   {
      auto message = "Attempt to add an entry whose search key exists in dictionary.";
      throw(PrecondViolatedExcept(message)); // Exit the method
   }  // end if
}  // end add

template <class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::remove(const KeyType& searchKey) {
  Entry<KeyType, ValueType> entryToRemove(searchKey, ValueType());
  return entryTree.remove(entryToRemove);
}

template <class KeyType, class ValueType>
void TreeDictionary<KeyType, ValueType>::clear() {
  entryTree.clear();
}

template <class KeyType, class ValueType>
ValueType TreeDictionary<KeyType, ValueType>::getValue(const KeyType& searchKey) const {
  Entry<KeyType, ValueType> entryToFind(searchKey, ValueType());
  Entry<KeyType, ValueType> foundEntry = entryTree.getEntry(entryToFind);
  return foundEntry.getValue();
}

template <class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::contains(const KeyType& searchKey) const {
  Entry<KeyType, ValueType> entryToFind(searchKey, ValueType());
  return entryTree.contains(entryToFind);
}

template <class KeyType, class ValueType>
void TreeDictionary<KeyType, ValueType>::traverse(void visit(ValueType&)) const {
  std::function<void(std::shared_ptr<BinaryNode<Entry<KeyType, ValueType>>>)> visitEntry = [visit](std::shared_ptr<BinaryNode<Entry<KeyType, ValueType>>> ptr) {
    ValueType value = ptr->getItem().getValue();
    visit(value);
  };
  entryTree.inorderTraverse(visitEntry);
}

//#include "TreeDictionary.cpp"
#endif