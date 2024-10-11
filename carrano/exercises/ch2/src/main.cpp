#include "headers.h"
#include "exercises.h"

using namespace std;

int main()
{
  // Exercise 3
  cout << "Exercise 3" << endl;
  int array3[8] = {1, 2, 4, 8, 16, 32, 64, 128};
  int n = 7;
  cout << "sum up first " << n << " numbers in array" << endl;
  cout << "sum is " << sumUpTo(n,array3) << endl;

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

  // Exercise 12
  cout << "Exercise 12" << endl;
  cout << "The return value is 5" << endl;
  cout << mystery(30) << endl;

  // Exercise 13
  cout << "Exercise 13" << endl;
  n = 100;
  cout << "the octal value of decimal " << n << " is ";
  displayAsOctal(n);
  cout << endl;

  // Exercise 14
  cout << "Exercise 14" << endl;
  cout << "The value of f(8) is " << f(8) << endl;
  cout << "placed check to not be odd and greater than 3" << endl;
  cout << "The value of f(3) is " << f(3) << endl;

  // Exercise 15
  cout << "Exercise 15" << endl;
  int x1 = 5, y1 = 3;
  int x2 = 5, y2 = 3;
  cout << "recurseByValue will retain the values of its local environment" << endl;
  recurseByValue(x1,y1);
  cout << "recurseByReference will reflect changes in all recursive calls" << endl;
  recurseByReference(x2,y2);

  // Exercise 16
  cout << "Exercise 16" << endl;
  int array16[] = {1,5,9,12,15,21,29,31};
  int search1 = 5;
  cout << "binarySearch for value " << search1 << " returns position " << binarySearch(array16, search1, 8) << endl;
  int search2 = 13;
  cout << "binarySearch for value " << search2 << " returns position " << binarySearch(array16, search2, 8) << endl;
  int search3 = 16;
  cout << "binarySearch for value " << search3 << " returns position " << binarySearch(array16, search3, 8) << endl;

  return 0;
} 