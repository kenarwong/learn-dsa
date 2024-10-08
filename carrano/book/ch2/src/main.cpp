#include "headers.h"
#include "functions.h"

using namespace std;

int main()
{
  cout << "sumUpTo" << endl;

  int n = 5;
  cout << "sumUpTo(" << n << ") = " << sumUpTo(n) << endl;

  n = -1;
  cout << "sumUpTo(" << n << ") = " << sumUpTo(n) << endl;

  string str = "Hello";
  cout << "printStringBackwards(" << str << ")" << endl;
  printStringBackwards(str);

  str = "cat";
  cout << "printStringBackwards(" << str << ")" << endl;
  printStringBackwards(str);

  n = 5;
  cout << "countDown(" << n << ")" << endl;
  countDown(n);

  n = 0;
  cout << "countDown(" << n << ")" << endl;
  countDown(n);

  n = -1;
  cout << "countDown(" << n << ")" << endl;
  countDown(n);

  char anArray[] = {'a', 'b', 'c', 'd', 'e'};
  cout << "writeArrayBackwards(anArray)" << endl;
  writeArrayBackwards(anArray, 5);

  string searchArray[] = {"dog","face","library","person","world"};
  string value = "world";
  cout << "binarySearch(searchArray, value)" << endl;
  int result = binarySearch(searchArray, 5, value);
  if (result == -1) {
    cout << "The search term \"" << value << "\" wasn't found." << endl;
  } else {
    cout << "The position of search term \"" << value << "\" is " << result << "." << endl;
  }
  
  return 0;
} // end main