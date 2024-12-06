#ifndef _HASHED_ENTRY
#define _HASHED_ENTRY

#include "Entry.h"
#include <iostream>
#include <memory>

template<class KeyType, class ValueType>
class HashedEntry : public Entry<KeyType, ValueType>
{
private:
  std::shared_ptr<HashedEntry<KeyType, ValueType>> nextPtr;
   
public:
  HashedEntry();
  HashedEntry(KeyType searchKey, ValueType newValue);
  HashedEntry(KeyType searchKey, ValueType newValue,
              std::shared_ptr<HashedEntry<KeyType, ValueType>> nextEntryPtr);
  virtual ~HashedEntry();
              
  void setNext(std::shared_ptr<HashedEntry<KeyType, ValueType>> nextEntryPtr);
  auto getNext() const;
}; // end HashedEntry

template <class KeyType, class ValueType>
inline void HashedEntry<KeyType, ValueType>::setNext(std::shared_ptr<HashedEntry<KeyType, ValueType>> nextEntryPtr)
{
  nextPtr = nextEntryPtr;
}

template <class KeyType, class ValueType>
inline auto HashedEntry<KeyType, ValueType>::getNext() const
{
  return nextPtr;
}

template <class KeyType, class ValueType>
inline HashedEntry<KeyType, ValueType>::HashedEntry()
{
  this->setKey(KeyType());
  this->setValue(ValueType());
  setNext(nullptr);
}

template <class KeyType, class ValueType>
inline HashedEntry<KeyType, ValueType>::HashedEntry(KeyType searchKey, ValueType newValue)
{
  this->setKey(searchKey);
  this->setValue(newValue);
  setNext(nullptr);
}

template <class KeyType, class ValueType>
inline HashedEntry<KeyType, ValueType>::HashedEntry(KeyType searchKey, ValueType newValue,
               std::shared_ptr<HashedEntry<KeyType, ValueType>> nextEntryPtr) : nextPtr(nextEntryPtr)
{
  this->setKey(searchKey);
  this->setValue(newValue);
}

template <class KeyType, class ValueType>
inline HashedEntry<KeyType, ValueType>::~HashedEntry()
{
  // std::cout << "HashedEntry with key " << this->getKey() << " destroyed" << std::endl;
}

// #include "HashedEntry.cpp"
#endif