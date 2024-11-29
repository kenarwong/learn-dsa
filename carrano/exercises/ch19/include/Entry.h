//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Listing 18-2.

/** A class of entries to add to an array-based implementation of the ADT dictionary.
 @file Entry.h */

#ifndef ENTRY_
#define ENTRY_

template <class KeyType, class ValueType>
class Entry
{
private:
   KeyType   key;
   ValueType value;
   
protected:
   void setKey(const KeyType& searchKey);
   
public:
   Entry();
   Entry(const KeyType& searchKey, const ValueType& newValue);
   ValueType getValue() const;
   KeyType getKey() const;
   void setValue(const ValueType& newValue);
   bool operator==(const Entry<KeyType, ValueType>& rightHandValue) const;
   bool operator>(const Entry<KeyType, ValueType>& rightHandValue) const;
}; // end Entry

template <class KeyType, class ValueType>
inline void Entry<KeyType, ValueType>::setKey(const KeyType &searchKey)
{
  key = searchKey;
}

template <class KeyType, class ValueType>
inline Entry<KeyType, ValueType>::Entry() : key(KeyType()), value(ValueType())
{
}

template <class KeyType, class ValueType>
inline Entry<KeyType, ValueType>::Entry(const KeyType &searchKey, const ValueType &newValue) : key(searchKey), value(newValue)
{
}

template <class KeyType, class ValueType>
inline ValueType Entry<KeyType, ValueType>::getValue() const
{
  return value;
}

template <class KeyType, class ValueType>
inline KeyType Entry<KeyType, ValueType>::getKey() const
{
  return key;
}

template <class KeyType, class ValueType>
inline void Entry<KeyType, ValueType>::setValue(const ValueType &newValue)
{
  value = newValue;
}

template <class KeyType, class ValueType>
inline bool Entry<KeyType, ValueType>::operator==(const Entry<KeyType, ValueType> &rightHandValue) const
{
  return key == rightHandValue.getKey();
}

template <class KeyType, class ValueType>
inline bool Entry<KeyType, ValueType>::operator>(const Entry<KeyType, ValueType> &rightHandValue) const
{
  return key > rightHandValue.getKey();
}

// #include "Entry.cpp"
#endif