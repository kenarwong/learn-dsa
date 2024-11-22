#ifndef HELPERS_H
#define HELPERS_H

#include "headers.h"

template <typename T>
void displayArray(T* a, size_t n) {
  for (size_t i = 0; i < n; i++) {
    std::cout << *(a+i) << " ";
  }

  std::cout << std::endl;
}

template <typename T>
int binarySearch(const T* a, T searchTerm, int start, int end) {
  if (end < start)  {
    return -1;
  }

  int mid = start + (end - start)/2;
  T midTerm = *(a+mid);

  if (searchTerm == midTerm) {
    return mid;
  } else if (searchTerm < midTerm) {
    return binarySearch(a, searchTerm, start, mid-1);
  } else {
    return binarySearch(a, searchTerm, mid+1, end);
  }

  return -1;
}

#endif