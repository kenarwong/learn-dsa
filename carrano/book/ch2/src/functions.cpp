#include "functions.h"
#include "headers.h"
#include "helpers.h"

int sumUpToRecursion(const int n) {
  if (n == 0) {
    return 0;
  } else {
    return n + sumUpToRecursion(n-1);
  }
}

/** Computes the sum of the integers from 1 through n.
  @pre n > 0.
  @post None.
  @param n A positive integer.
  @return The sum 1 + 2 + . . . + n. */
int sumUpTo(const int n) {

  if (n > 0) {
    return sumUpToRecursion(n);
  }

  return 0;
}

void printStringBackwardsRecursion(const char* c, int n) {
  //if (c[0] != '\0') {
  if (n != 0) {
    printStringBackwardsRecursion(c + 1, n - 1);
    std::cout << c[0];
  }
}

/** Writes a character string backward.
  @pre The string s to write backward.
  @post None.
  @param s The string to write backward. */
void printStringBackwards(std::string s) {

  int n = s.length();
  printStringBackwardsRecursion(s.c_str(), n);
  std::cout << std::endl;
}

void countDownRecursion(int n) {
  if (n == 0) {
    std::cout << "Blast Off!" << std::endl;
  } else {
    std::cout << n << std::endl;
    countDownRecursion(n - 1);
  }
}

void countDown(int n) {
  if (n > 0) {
    countDownRecursion(n);
  }
}

/** Writes the characters in an array backward.
  @pre The array anArray contains size characters, where size >= 0.
  @post None.
  @param anArray The array to write backward.
  @param first The index of the first character in the array.
  @param last The index of the last character in the array. */
void writeArrayBackwardsRecursion(const char anArray[], int first, int last) {
  if(first > last)  {
    return;
  } else {
    writeArrayBackwardsRecursion(anArray, first + 1, last);
    std::cout << anArray[first] << std::endl;
  }
}

void writeArrayBackwards(const char anArray[], int size) {
  if(size > 0) {
    writeArrayBackwardsRecursion(anArray, 0, size - 1);
  }
}

/** Searches for a string in an array
  @pre The sorted array searchArray contains string entries, where size > 0
  @pre The value must be a valid string
  @post None.
  @param anArray The array to search.
  @param value The value of the item to be searched.
  @return If the value is not a valid string, then return 1
  @return The position of the string in the array, or -1 if the string does not exist */
int binarySearchRecursion(const std::string *searchArray, std::string value, int start, int end) {
  // Base case
  // If value is not found, then both recursive calls will end up with start greater than end
  if (start > end) {
    return -1;
  }

  // middle item 
  // add to start to get absolute position
  int mid = start + (end - start) / 2; // floor
  std::string midItem = searchArray[mid];
  
  int cmp = value.compare(midItem);
  if (cmp == 0) {
    // If middle item
    return mid; // return position of middle item
  } else if (cmp < 0) {
    // first half
    return binarySearchRecursion(searchArray, value, start,  mid - 1);
  } else {
    // second half
    return binarySearchRecursion(searchArray, value, mid + 1, end);
  }
}

int binarySearch(const std::string *searchArray, size_t length, std::string value) {
  if (value.size() == 0 || iswhitespace(value)) {
    return 1;
  }

  return binarySearchRecursion(searchArray, value, 0, length - 1);
}

int kSmallRecursion(int k, int *anArray, int first, int last) {
  // choose last as pivotIndex
  // choose value as pivot value
  int pivotIndex = last;
  int p = anArray[pivotIndex];

  // partition
  int i = first, r = first;
  while (i < last) {
    if (anArray[i] < p) {
      std::swap(anArray[i], anArray[r]);
      r++;
    }
    i++;
  }
  // Update pivotIndex
  std::swap(anArray[r], anArray[pivotIndex]);
  pivotIndex = r;

  for (auto it = anArray + first; it != anArray + last + 1; ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  // pivotIndex is 0-based
  // kth smallest is 1-based
  // Will add 1, since kth smallest means 1-based
  // Subtract first to make absolute
  int comparingIndex = pivotIndex - first + 1;
  
  if (k == comparingIndex) {
    // Successfully partitioned k number of elements left of p
    return p;
  } else if (k < comparingIndex) {
    // If k is smaller, than look in first partition 
    return kSmallRecursion(k, anArray, first, pivotIndex - 1);
  } else {
    // If k is larger, than look in second partition 
    // Shift k accordingly, so that the next comparison 
    // doesn't take into account all of the other smaller values already discarded
    return kSmallRecursion(k - comparingIndex, anArray, pivotIndex + 1, last);
  }
}

int kSmall(int k, int *anArray, size_t length) {
  if (k <= 0 || k > length) {
    return -1;
  }

  return kSmallRecursion(k, anArray, 0, length - 1);
}