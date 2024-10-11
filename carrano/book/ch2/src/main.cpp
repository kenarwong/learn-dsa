#include "headers.h"
#include "functions.h"

using namespace std;

int main()
{

  // sum up to a number
  cout << "sumUpTo" << endl;

  int n = 5;
  cout << "sumUpTo(" << n << ") = " << sumUpTo(n) << endl;

  n = -1;
  cout << "sumUpTo(" << n << ") = " << sumUpTo(n) << endl;

  // print string backwards
  string str = "Hello";
  cout << "printStringBackwards(" << str << ")" << endl;
  printStringBackwards(str);

  str = "cat";
  cout << "printStringBackwards(" << str << ")" << endl;
  printStringBackwards(str);

  // count down
  n = 5;
  cout << "countDown(" << n << ")" << endl;
  countDown(n);

  n = 0;
  cout << "countDown(" << n << ")" << endl;
  countDown(n);

  n = -1;
  cout << "countDown(" << n << ")" << endl;
  countDown(n);

  // print an array backwards
  char anArray[] = {'a', 'b', 'c', 'd', 'e'};
  cout << "writeArrayBackwards(anArray)" << endl;
  writeArrayBackwards(anArray, 5);

  // binary search
  string searchArray[] = {"dog","face","library","person","world"};
  string value = "person";
  cout << "binarySearch(searchArray, value)" << endl;
  int result = binarySearch(searchArray, 5, value);
  if (result == -1) {
    cout << "The search term \"" << value << "\" wasn't found." << endl;
  } else {
    cout << "The position of search term \"" << value << "\" is " << result << "." << endl;
  }

  // kth smallest
  int k = 26;
  //int testArray[5] = {1,2,3,4,5};
  //cout << "The " << k << "th smallest value is " << kSmall(k, testArray, 5) << endl;

  // Array of 30 values in random order, one-based
  int testArray[30] = {15, 3, 22, 7, 1, 30, 12, 25, 9, 18, 5, 27, 14, 2, 21, 6, 29, 11, 24, 8, 17, 4, 26, 13, 20, 10, 23, 19, 28, 16};
  result = kSmall(k, testArray, 30);

  cout << "kSmall(" << k << ", testArray, 30)" << endl;
  cout << "The " << k << "th smallest value is " << result << endl;

  // Towers of Hanoi
  int numberOfDisks = 6;
  TowersOfHanoi(numberOfDisks);
  
  return 0;
} // end main