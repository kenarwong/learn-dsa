#ifndef SORT_CLASS_H
#define SORT_CLASS_H

#include <cstdlib>
#include <iostream>

const int MAX_SORT_KEY_VALUE = 100;

class SortClass {
  public:
    SortClass();
    int getSortKey() const;

    bool operator>(const SortClass& other) const { 
      return this->sortKey > other.getSortKey();
    }

    bool operator>=(const SortClass& other) const { 
      return this->sortKey >= other.getSortKey();
    }
  
  private:
    const int sortKey;
};

inline SortClass::SortClass() : sortKey(rand() % (MAX_SORT_KEY_VALUE + 1)) {
}

inline int SortClass::getSortKey() const {
  return sortKey;
}


#endif