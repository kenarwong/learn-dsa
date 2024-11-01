#include "exercises.h"
#include <cstdlib>
#include <iostream>

int generateRandomNumber(const int& n) {
  // generate random number from -n to n
  return rand() % (2 * n + 1) - n;
}

void displayNumbers(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << std::endl;
}

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int item = arr[i]; // item to replace

    // shift all items right
    int j = i; // next empty spot
    while (j > 0 && arr[j-1] > item) { 
      arr[j] = arr[j-1]; // shift right
      j--;
    }

    // Add at current index
    arr[j] = item;
  }
}

void partition(int arr[], int n) {
  int i = 0; 
  int neg = 0;              // everything before neg is < 0
  while (i < n) { 
    int item = arr[i];
    if (arr[i] < 0) {
      arr[i] = arr[neg];
      arr[neg] = item;
      neg++;
    }
    i++;
  }

  // displayNumbers(arr, n);

  int j = n-1;
  int pos = n-1;            // everything after pos is > 0
  while (j >= neg) { 
    int item = arr[j];
    if (arr[j] > 0) {
      arr[j] = arr[pos];
      arr[pos] = item;
      pos--;
    }
    j--;
  }

  // displayNumbers(arr, n);
}

void Exercise10() {
  const int MAX_RANGE = 100;
  int n = 20;
  int numbers[n];

  std::cout << "O(n^2) sort" << std::endl;

  for (int i = 0; i < n; i++) {
    int randomNumber = generateRandomNumber(MAX_RANGE);
    numbers[i] = randomNumber;
  }
  displayNumbers(numbers, n);

  // O(n^2)
  insertionSort(numbers,n);
  displayNumbers(numbers, n);

  std::cout << "O(n) partition" << std::endl;

  for (int i = 0; i < n; i++) {
    int randomNumber = generateRandomNumber(MAX_RANGE);
    numbers[i] = randomNumber;
  }
  displayNumbers(numbers, n);

  // O(n)
  partition(numbers,n);
  displayNumbers(numbers, n);

  std::cout << "O(n^2) sort test with zeros" << std::endl;

  // Test with 0s
  int test[] = {0, 1, 0, -4, 2, 0, 3, -5, 0, 4, 0, 5, 0, -1, 0, -2, 0, -3, 0, 0};
  displayNumbers(test, n);
  insertionSort(test, 20);
  displayNumbers(test, n);

  std::cout << "O(n) partition test with zeros" << std::endl;

  // Test with 0s
  int test2[] = {0, 1, 0, -4, 2, 6, 3, -5, 0, 4, 0, 5, 0, -1, 0, -2, 0, -3, 0, 0};
  displayNumbers(test2, n);
  partition(test2, 20);
  displayNumbers(test2, n);
}