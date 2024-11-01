#include "exercises.h"
#include <iostream>
#include <cstdlib>
#include "SortClass.h"
#include "SelectionSort.h"
#include "RecursiveSorts.h"


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

  int n = 20;
  int range = 100;
  int arr[n];

  std::cout << "Recursive Selection Sort" << std::endl;

  for(int i = 0; i < n; i++) {
    arr[i] = rand() % range + 1;
  }

  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  selectionSortRecursive(arr, n);

  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Recursive Insertion Sort" << std::endl;

  for(int i = 0; i < n; i++) {
   arr[i] = rand() % range + 1;
  }

  for(int i = 0; i < n; i++) {
   std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  insertionSortRecursive(arr, n);

  for(int i = 0; i < n; i++) {
   std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Recursive Bubble Sort" << std::endl;

  for(int i = 0; i < n; i++) {
    arr[i] = rand() % range + 1;
  }

  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  bubbleSortRecursive(arr, n);

  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

}