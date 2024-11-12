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

#endif