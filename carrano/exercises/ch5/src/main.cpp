#include "headers.h"
#include "exercises.h"

using namespace std;

int main()
{
  // Exercise 1
  cout << "Exercise 1" << endl;
  string pal = "abcdeba";
  //string pal = "abcdcba";
  cout << "string \"" << pal << "\" is" << (isPal(pal) ? " " : " not ") << "a palindrome" << endl;

  string AnBn = "AABB";
  //string AnBn = "AAAABBBB";
  cout << "string \"" << AnBn << "\" is" << (isAnBn(AnBn) ? " " : " not ") << "AnBn" << endl;

  //string endPre = "*/abcd";

  return 0;
} 