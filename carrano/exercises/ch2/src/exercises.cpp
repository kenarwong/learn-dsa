#include "exercises.h"
#include "headers.h"
#include "helpers.h"

int sumUpToRecursion(const int n, int array[]) {
  if (n == 0) {
    return array[0];
  } else {
    return array[n] + sumUpToRecursion(n-1,array);
  }
}

int sumUpTo(const int n, int array[]) {

  if (n > 0) {
    // Change 1-based n to 0-based
    return sumUpToRecursion(n-1, array);
  }

  return -1;
}

int sumRangeRecursion(int start, int end) {
  if (start == end) {
    return end;
  }

  return start + sumRangeRecursion(start+1, end);
}

int sumRange(int start, int end) {
  if (start < end) {
    return sumRangeRecursion(start, end);
  }

  return -1;
}

void writeBackwardRecursion(const char* c, int n) {
  if (n == 1) {
    std::cout << *c;
    return;
  }

  writeBackwardRecursion(c+1, n-1);
  std::cout << c[0];

}

void writeBackward(const std::string str) {
  if (!iswhitespace(str)) {
    writeBackwardRecursion(str.c_str(), str.size());
    std::cout << std::endl;
  }
}

void printNum(int n) {
  if (n == 0) {
    std::cout << "Done." << std::endl;
    return;
  }
  std::cout << n << std::endl;
  printNum(n - 1);
}

void printNumUp(int n) {
  if (n == 0) {
    return;
  }

  printNumUp(n-1);
  std::cout << n << std::endl;
}

int sumOfSquaresRecursion(int n) {
  if (n == 1) {
    return 1;
  }

  return n*n + sumOfSquares(n-1);
}

int sumOfSquares(int n) {
  if (n > 0) {
    return sumOfSquaresRecursion(n);
  }

  return 0;
}

void writeDecimalReverse(int n) {
  if (n == 0) {
    std::cout << std::endl;
    return;
  }

  // mod by 10 to get 1s place
  int r = n % 10;
  std::cout << r;

  // divide by 10, truncates decimal
  writeDecimalReverse(n/10);
}

void writeLine(char c, int n) {
  if (n == 0) {
    std::cout << std::endl;
    return;
  }
  std::cout << c;
  writeLine(c, n-1);
}

void writeBlock(char c, int n, int m) {
  if (m == 0) {
    return;
  }
  writeLine(c, n);
  writeBlock(c, n, m-1);
}

int getValue(int a, int b, int n)
{
  int returnValue = 0;
  std::cout << "Enter: a = " << a << " b = " << b << std::endl;
  int c = (a + b) / 2;
  if (c * c <= n)
    returnValue = c;
  else
    returnValue = getValue(a, c - 1, n);
  std::cout << "Leave: a = " << a << " b = " << b << std::endl;
  return returnValue;
}