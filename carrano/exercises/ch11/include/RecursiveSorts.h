int findLargestIndex(int arr[], int n) {
  int largestIndex = 0;
  for (int i = 0; i < n; i++){
    if (arr[i] > arr[largestIndex]) {
      largestIndex = i;
    }
  }

  return largestIndex;
}

void selectionSortRecursive(int arr[], int n) {
  if(n < 2) {
    return;
  }

  int largestIndex = findLargestIndex(arr, n);

  int temp = arr[n-1];
  arr[n-1] = arr[largestIndex];
  arr[largestIndex] = temp;

  selectionSortRecursive(arr, n-1);

}

void insertionSortInnerRecursive(int arr[], int n, int item) { 
  if (n < 1 || item > arr[n-1]) {
    arr[n] = item;
    return;
  }

  arr[n] = arr[n-1];
  insertionSortInnerRecursive(arr, n-1, item);
}

void insertionSortRecursive(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    insertionSortInnerRecursive(arr, i, arr[i]);
  }
}

bool bubbleSortPassRecursive(int arr[], int n, bool swapped) { 
  if (n < 2) {
    return swapped;
  }

  if (arr[0] > arr[1]) {
    int tmp = arr[1];
    arr[1] = arr[0];
    arr[0] = tmp;

    swapped = true;
  } 

  return bubbleSortPassRecursive(arr+1, n-1, swapped);
}

void bubbleSortRecursive(int arr[], int n) { 
  if (n < 2) {
    return;
  }

  int swapped = bubbleSortPassRecursive(arr, n, false);
  if (!swapped) { 
    return;
  }

  bubbleSortRecursive(arr, n-1);
}