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

int search(int first, int last, int n)
{
  int returnValue = 0;
  std::cout << "Enter: first = " << first << " last = " << last << std::endl;
  int mid = (first + last) / 2;
  if ((mid * mid <= n) && (n < (mid + 1) * (mid + 1)))
    returnValue = mid;
  else if (mid * mid > n)
    returnValue = search(first, mid - 1, n);
  else
    returnValue = search(mid + 1, last, n);
  std::cout << "Leave: first = " << first << " last = " << last << std::endl;
  return returnValue;
} // end search

int mystery(int n)
{
  return search(1, n, n);
} // end mystery

void displayAsOctal(int n) {
  if (n == 0) {
    return;
  }

  displayAsOctal(n / 8);

  // Most-significant digit is displayed last
  std::cout << n % 8;
}

/** @pre n >= 0. */
int f(int n)
{
  if (n % 2 == 1 && n >= 3) {
    return 0;
  }

  std::cout << "Function entered with n = " << n << std::endl;
  switch (n)
  {
    case 0: case 1: case 2:
      return n + 1;
    default:
      return f(n-2) * f(n-4);
  } // end switch
}

void recurseByValue(int x, int y)
{
  if (y > 0)
  {
    x++;
    y = y - 1;
    std::cout << x << " " << y << std::endl;
    recurseByValue(x, y);
    std::cout << x << " " << y << std::endl;
  } // end if
}

void recurseByReference(int& x, int y)
{
  if (y > 0)
  {
    x++;
    y = y - 1;
    std::cout << x << " " << y << std::endl;
    recurseByReference(x, y);
    std::cout << x << " " << y << std::endl;
  } // end if
}

int binarySearchRecursion(int array[], int search, int first, int last) {
  if (first > last) {
    return -1;
  }

  int mid = first + (last - first)/2;
  int midTerm = array[mid];

  if (search == midTerm) {
    return mid;
  } else if (search < midTerm) {
    return binarySearchRecursion(array, search, first, mid-1);
  } else {
    return binarySearchRecursion(array, search, mid+1, last);
  }
}

int binarySearch(int array[], int search, int n) {
  if (n > 0) {
    return binarySearchRecursion(array, search, 0, n-1);
  }
  
  return -1;
}