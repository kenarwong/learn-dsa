#ifndef _HASHED_DICTIONARY
#define _HASHED_DICTIONARY

#include "DictionaryInterface.h"
#include "HashedEntry.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"
#include <vector>
#include <list>
#include <unordered_map>
#include <functional>

template <class KeyType, class ValueType>
class HashedDictionary : public DictionaryInterface<KeyType, ValueType>
{
private:
  static const int DEFAULT_TABLE_SIZE = 101;
  int itemCount;
  int hashTableSize;
  std::vector<std::shared_ptr<HashedEntry<KeyType,ValueType>>> entryVector;
  std::list<std::shared_ptr<HashedEntry<KeyType,ValueType>>> entryList;

  // Retrieve a hash index for a searchKey
  int getHashIndex(const KeyType& searchKey) const;

public:
  HashedDictionary();
  HashedDictionary(int hashTableSize);
  HashedDictionary(const HashedDictionary<KeyType, ValueType>& dictionary);
  virtual ~HashedDictionary();

  bool isEmpty() const;
  int getNumberOfEntries() const;

  bool add(const KeyType& searchKey, const ValueType& newValue);
  bool remove(const KeyType& searchKey);
  void clear();

  ValueType getValue(const KeyType& searchKey) const;
  bool contains(const KeyType& searchKey) const;

  /** Traverses the entries in this dictionary and calls a given client function once for the value in each entry.
   NOT in sorted order. 
   Adding traversal to hash table means maintaining a separate linked list (entryList).
   This greatly simplifies and speeds up (in low load cases) traversal.
   However, the maintainence of the linked list adds overhead to add and remove operations.
   Add operation will still be O(1), but removal will be O(n) because we need to find the entry in the linked list.
   Normally, removaal would only be 1 + load factor / 2 (e.g. average number of entries in a chain), 
   but now we must traverse the linked list as well.
  */
  void traverse(void visit(ValueType&)) const;
  void traverse(std::function<void(std::shared_ptr<HashedEntry<KeyType,ValueType>>)> visit) const;
};

template <class KeyType, class ValueType>
int HashedDictionary<KeyType, ValueType>::getHashIndex(const KeyType &searchKey) const
{
  // We are creating a hash function type called hashFunction that hashes
  // a search key. First we create an unordered_map object for our KeyType
  // and ValueType.
  std::unordered_map<KeyType, ValueType> mapper;

  // Then we invoke the method hash_function to return the hash function
  // for the KeyType and assign it to 'hashFunction'.
  typename std::unordered_map<KeyType, ValueType>::hasher hashFunction = mapper.hash_function();

  // Need static_cast because hashFunction returns an unsigned long.
  return static_cast<int>(hashFunction(searchKey) % hashTableSize);
} // end getHashIndex

template <class KeyType, class ValueType>
HashedDictionary<KeyType, ValueType>::HashedDictionary() : itemCount(0), hashTableSize(DEFAULT_TABLE_SIZE) {
  entryVector = std::vector<std::shared_ptr<HashedEntry<KeyType,ValueType>>>(DEFAULT_TABLE_SIZE, nullptr);
}

template <class KeyType, class ValueType>
inline HashedDictionary<KeyType, ValueType>::HashedDictionary(int hashTableSize) : itemCount(0), hashTableSize(hashTableSize)
{
  entryVector = std::vector<std::shared_ptr<HashedEntry<KeyType,ValueType>>>(hashTableSize, nullptr);
}

template <class KeyType, class ValueType>
HashedDictionary<KeyType, ValueType>::HashedDictionary(const HashedDictionary<KeyType, ValueType>& dictionary) : itemCount(dictionary.itemCount), hashTableSize(dictionary.hashTableSize), entryVector(dictionary.entryVector), entryList(dictionary.entryList) {}

template <class KeyType, class ValueType>
HashedDictionary<KeyType, ValueType>::~HashedDictionary() {
  clear();
}

template <class KeyType, class ValueType>
inline bool HashedDictionary<KeyType, ValueType>::isEmpty() const
{
  return itemCount == 0;
}

template <class KeyType, class ValueType>
inline int HashedDictionary<KeyType, ValueType>::getNumberOfEntries() const
{
  return itemCount;
}

template <class KeyType, class ValueType>
inline bool HashedDictionary<KeyType, ValueType>::add(const KeyType &searchKey, const ValueType &newValue)
{
  auto newEntryPtr = std::make_shared<HashedEntry<KeyType, ValueType>>(searchKey, newValue);
  int hashValue = getHashIndex(searchKey);

  auto chainHead = entryVector[hashValue];

  // Set old head as next for this value
  if (chainHead != nullptr)
  {
    newEntryPtr->setNext(chainHead);
  }
  entryVector[hashValue] = newEntryPtr; // Set this entry has new chain head

  entryList.push_back(newEntryPtr); // O(1)
  itemCount++;

  return true;
}

template <class KeyType, class ValueType>
inline bool HashedDictionary<KeyType, ValueType>::remove(const KeyType &searchKey)
{
  int hashValue = getHashIndex(searchKey);
  auto chainHead = entryVector[hashValue];

  if (chainHead != nullptr)
  {
    auto prev = chainHead;
    auto cur = chainHead->getNext();

    // If searched key is first node
    if (prev->getKey() == searchKey) {
      entryVector[hashValue] = cur;
    
      entryList.remove(prev); // O(n)
      itemCount--;
      return true;
    }

    // Traverse chain
    while (cur != nullptr) {
      if (cur->getKey() == searchKey) {
        prev->setNext(cur->getNext()); // Relink

        entryList.remove(cur); // O(n)
        itemCount--;
        return true;
      }

      prev = cur;
      cur = cur->getNext();
    }
  }

  return false;
}

template <class KeyType, class ValueType>
inline void HashedDictionary<KeyType, ValueType>::clear()
{
  entryVector.clear();
  entryList.clear();
  itemCount = 0;
}

template <class KeyType, class ValueType>
inline ValueType HashedDictionary<KeyType, ValueType>::getValue(const KeyType &searchKey) const
{
  int hashValue = getHashIndex(searchKey);
  auto chainHead = entryVector[hashValue];

  auto ptr = chainHead;

  // Traverse chain
  while (ptr != nullptr)
  {
    if (ptr->getKey() == searchKey)
    {
      return ptr->getValue();
    }

    ptr = ptr->getNext();
  }

  throw NotFoundException("Item not found in tree");
}

template <class KeyType, class ValueType>
inline bool HashedDictionary<KeyType, ValueType>::contains(const KeyType &searchKey) const
{
  try {
    getValue(searchKey);
    return true;
  } catch (NotFoundException &e) {
    return false;
  }
}

template <class KeyType, class ValueType>
inline void HashedDictionary<KeyType, ValueType>::traverse(void visit(ValueType &)) const
{
  std::function<void(std::shared_ptr<HashedEntry<KeyType, ValueType>>)> visitEntry = [visit](std::shared_ptr<HashedEntry<KeyType, ValueType>> ptr) {
    ValueType value = ptr->getValue();
    visit(value);
  };

  for (auto it = entryList.begin(); it != entryList.end(); ++it ) {
    ValueType value = (*it)->getValue();
    visit(value);
  }
}

template <class KeyType, class ValueType>
inline void HashedDictionary<KeyType, ValueType>::traverse(std::function<void(std::shared_ptr<HashedEntry<KeyType, ValueType>>)> visit) const
{
  for (auto it = entryList.begin(); it != entryList.end(); ++it ) {
    visit(*it);
  }
}

#endif