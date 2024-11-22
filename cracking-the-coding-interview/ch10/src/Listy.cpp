#include "Listy.h"
#include "headers.h"
#include "helpers.h"

Listy::Listy() {
  size = rand() % LISTY_MAX_SIZE;
  arr = new int[size];

  for (int i = 0; i < size; i++) {
    *(arr+i) = rand() % LISTY_MAX_RANGE + 1;
  }
}

Listy::~Listy() {
  delete[] arr;
}

void Listy::display() const {
  displayArray(arr, size);
}

int Listy::returnRandomElement() const {
  int i = rand() % size;
  return arr[i];
}

int Listy::elementAt(int i) const {
  if (i < size) {
    return arr[i];
  }
  return -1;
}
