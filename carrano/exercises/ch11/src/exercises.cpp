#include "exercises.h"
#include <iostream>
#include "SortClass.h"
#include "SelectionSort.h"


void Exercise8() {
  std::cout << "Exercise 8" << std::endl;
  
  int n = 20;
  SortClass* arr[n];

  for (int i = 0; i < n; i++) {
    arr[i] = new SortClass;
  }

  displayClassKeys<SortClass>(arr, n);
  selectionSort<SortClass>(arr, n);
  displayClassKeys<SortClass>(arr, n);
}

void Exercise9() {
  std::cout << "Exercise 9" << std::endl;
}