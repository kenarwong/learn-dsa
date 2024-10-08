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
  // Only one item left
  if (start == end) {
    // if value matches the single item return this position, else -1
    return searchArray[start] == value ? start : -1;
  }

  // middle item (relative to start)
  int mid = (end - start) / 2; // floor
  std::string midItem = searchArray[start + mid];
  
  int cmp = value.compare(midItem);
  if (cmp == 0) {
    // If middle item
    return start + mid; // return position of middle item
  } else if (cmp < 0) {
    // first half
    return binarySearchRecursion(searchArray, value, start, start + mid - 1);
  } else {
    // second half
    return binarySearchRecursion(searchArray, value, start + mid + 1, end);
  }
}

int binarySearch(const std::string *searchArray, size_t length, std::string value) {
  if (value.size() == 0 || iswhitespace(value)) {
    return 1;
  }

  return binarySearchRecursion(searchArray, value, 0, length - 1);
}