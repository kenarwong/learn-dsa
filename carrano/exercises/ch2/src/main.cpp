#include "headers.h"
#include "exercises.h"

using namespace std;

int main()
{
  // Exercise 3
  cout << "Exercise 3" << endl;
  int array[8] = {1, 2, 4, 8, 16, 32, 64, 128};
  int n = 7;
  cout << "sum up first " << n << " numbers in array" << endl;
  cout << "sum is " << sumUpTo(n,array) << endl;

  // Exercise 4
  cout << "Exercise 4" << endl;
  int start = 1;
  int end = 8;
  cout << "sum all numbers in range from " << start << " to " << end << endl;
  cout << "sum is " << sumRange(start,end) << endl;

  // Exercise 5
  cout << "Exercise 5" << endl;
  string str = "Hello";
  cout << "print string \"" << str << "\" backwards" << endl;
  writeBackward(str);

  // Exercise 6
  cout << "Exercise 6" << endl;
  n = 8;
  cout << "print numbers from " << n << " to 0" << endl;
  printNum(n);

  // Exercise 7
  cout << "Exercise 7" << endl;
  cout << "print numbers from 1 to " << n << endl;
  printNumUp(n);

  // Exercise 8
  cout << "Exercise 8" << endl;
  cout << "sum of squares from integers 1 to " << n << endl;
  cout << "the sum is " << sumOfSquares(n) << endl;

  // Exercise 9
  cout << "Exercise 9" << endl;
  int value = 12345678;
  cout << "write digits of " << value << " backwards" << endl;
  writeDecimalReverse(value);

  // Exercise 10
  cout << "Exercise 10" << endl;
  char c = '*';
  n = 5;
  cout << "print char " << c << " " << n << " times" << endl;
  writeLine(c, n);
  int m = 3;
  cout << "print char " << c << " " << n << " times for " << m << " lines" << endl;
  writeBlock(c,n,m);

  // Exercise 11
  cout << "Exercise 11" << endl;
  cout << "The return value is 2" << endl;
  cout << getValue(1, 7, 7) << endl;
  return 0;
} 