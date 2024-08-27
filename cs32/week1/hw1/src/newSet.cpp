//#include "main.h"
//#include "newSet.h"
//#include <cstring>
//
//Set::Set() {
//  m_items = new ItemType[DEFAULT_MAX_ITEMS];
//  std::memset( m_items, 0, sizeof(m_items) );
//  m_num = 0;
//  m_capacity = DEFAULT_MAX_ITEMS;
//}
//
//Set::Set(int capacity) {
//  m_capacity = capacity;
//  m_items = new ItemType[m_capacity];
//  std::memset( m_items, 0, sizeof(m_items) );
//  m_num = 0;
//}
//
////// Copy constructor
////Set::Set(const Set& other) {
////  m_num = other.m_num;
////  m_capacity = other.m_capacity;
////  m_items = new ItemType[m_capacity];
////  for (int i = 0; i < m_num; ++i)
////  {
////    m_items[i] = other.m_items[i];
////  }
////}
////
////// Assignment operator
////Set& Set::operator=(const Set& other) {
////  if (this == &other)
////  {
////    return *this; // Handle self-assignment
////  }
////
////  // Release existing resources
////  delete[] m_items;
////
////  // Allocate new resources and copy data
////  m_num = other.m_num;
////  m_capacity = other.m_capacity;
////  m_items = new ItemType[m_capacity];
////  for (int i = 0; i < m_num; ++i)
////  {
////    m_items[i] = other.m_items[i];
////  }
////
////  return *this;
////}
//
////// Destructor
////// Not working properly
////Set::~Set() {
////  delete[] m_items;
////}
//
//bool Set::empty() const {
//  if (this->size() == 0) {
//    return true;
//  }
//  return false;
//}
//
//int Set::size() const {
//  return m_num;
//}
//
//bool Set::insert(const ItemType& value) {
//  // Insert value into the set if it is not already present.  Return
//  // true if the value is actually inserted.  Leave the set unchanged
//  // and return false if value was not inserted (perhaps because it
//  // was already in the set or because the set has a fixed capacity and
//  // is full).
//
//  // Check if the set is full
//  if (m_num == DEFAULT_MAX_ITEMS) {
//    return false;
//  }
//
//  // Check if the value is already in the set
//  int i, j;
//  int k = m_num; // Default index of insert is the end of the set
//  for (i = 0; i < m_num; i++) {
//
//    if (value <= m_items[i]) {
//        // Check if the value is already in the set
//        if (value == m_items[i]) {
//          return false;
//        }
//
//      k = i; // Set k to the index for insert
//      break;
//    }
//  }
//
//  // Shift the values to the right to make room for the new value
//  for (j = m_num; j > k; j--) {
//    m_items[j] = m_items[j-1];
//  }
//
//  // Insert into the set
//  m_items[k] = value;
//  m_num++;
//
//  return true;
//}
//
//bool Set::erase(const ItemType& value) {
//  // Remove the value from the set if present.  Return true if the
//  // value was removed; otherwise, leave the set unchanged and
//  // return false.
//
//  // Initialize the found flag
//  int found = false;
//  int i, j;
//  for (i = 0; i < m_num; i++) {
//    // Check if the value is in the set
//    if (value == m_items[i]) {
//      found = true;
//    }
//    // If the value has been found, shift the values to the left
//    if (found) {
//      if (i == m_num-1) {
//        m_items[i] = ItemType{}; // Default ItemType
//        break;
//      }
//      m_items[i] = m_items[i+1];
//    }
//  }
//
//  // Decrement the number of items in the set
//  m_num--;
//
//  return found;
//}
//
//bool Set::contains(const ItemType& value) const {
//  for (int i = 0; i < m_num; i++) {
//    if (value == m_items[i]) {
//      return true;
//    }
//  }
//  return false;
//}
//
//bool Set::get(int i, ItemType& value) const {
//  // If 0 <= i < size(), copy into value the item in the set that is
//  // strictly less than exactly i items in the set and return true.
//  // Otherwise, leave value unchanged and return false.
//
//  // Check if i is within the bounds of the set
//  if (i < 0 || i >= m_num) {
//    return false;
//  }
//
//  int j = m_num - 1;
//  value = m_items[(j - i)];
//  return true;
//}
//
//void Set::swap(Set& other) {
//  Set tempSet = other;
//  other = *this;
//  *this = tempSet;
//}