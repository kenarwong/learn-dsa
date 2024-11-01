#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

template <class T>
int findLargestIndex(T* arr[], int n) {
  int largestIndex = 0;
  for (int i = 0; i < n; i++) {
    if (*(arr[i]) > *(arr[largestIndex])) {
      largestIndex = i;
    }
  }

  return largestIndex;
}

template <class T>
void selectionSort(T* arr[], int n) {
  for (int i = 0; i < n; i++) { 
    int index = findLargestIndex(arr+i, n-i);
    int largestIndex = index+i;

    T* temp = arr[i];
    arr[i] = arr[largestIndex];
    arr[largestIndex] = temp;
  }
}

template <class T>
void displayClassKeys(T* arr[], int n) {
  for (int i = 0; i < n; i++) { 
    std::cout << arr[i]->getSortKey() << " ";
  }

  std::cout << std::endl;
}

#endif