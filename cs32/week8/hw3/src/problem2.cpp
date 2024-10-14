#include "headers.h"

using namespace std;

bool somePredicate(double x) {
  return x < 0;
}

// Return true if the somePredicate function returns false for at
// least one of the array elements, false otherwise.
bool anyFalse(const double a[], int n)
{
  if (n == 0)
  {
    return false;
  }

  return !somePredicate(a[n-1]) || anyFalse(a, n-1);
}

// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const double a[], int n)
{
    if (n == 0) {
      return 0;
    }
    return (somePredicate(a[n-1]) ? 0 : 1) + countFalse(a, n-1);
}

// Return the subscript of the first element in the array for which
// the somePredicate function returns true.  If there is no such
// element, return -1.
int firstTrueRecursion(const double a[], int index, int n)
{
    if (index == n) {
      return -1;
    }

    if(somePredicate(a[index])) {
      return index;
    } else {
      return firstTrueRecursion(a, index+1, n);
    }
}

// helper function to start from 0 to count up, rather than count down
// looking for first, so counting up is more efficient
int firstTrue(const double a[], int n){
  if (n <= 0) {
    return -1;
  }

  return firstTrueRecursion(a, 0, n);
}

// Return the subscript of the largest element in the array (i.e.,
// return the smallest subscript m such that a[m] >= a[k] for all
// k such that k >= 0 and k < n).  If there is no such subscript,
// return -1.
int locateMax(const double a[], int n)
{
    if (n == 1) {
      return 0;
    }

    int maxIndex = locateMax(a, n-1);
    return (a[n-1] > a[maxIndex] ? n-1 : maxIndex);
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not contain
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    10 50 40 20 50 40 30
// then the function should return true if a2 is
//    50 20 30
// or
//    50 40 40
// and it should return false if a2 is
//    50 30 20
// or
//    10 20 20
bool contains(const double a1[], int n1, const double a2[], int n2)
{
  if (n1 == 0 && n2 != 0) {
    return false; // a1 exhausted, but a2 check not completed
  }

  if (n2 == 0) {
    return true; // a2 check completed
  }

  if (a1[n1-1] == a2[n2-1]) {
    return contains(a1,n1-1,a2,n2-1); // advance both
  } else {
    return contains(a1,n1-1,a2,n2); // advance only n1
  }
}

void test_anyFalse() {
  double arr1[] = {1.0, 2.0, 3.0};
  double arr2[] = {-1.0, -2.0, -3.0};
  double arr3[] = {1.0, -2.0, 3.0};

  assert(anyFalse(arr1, 3) == true);
  assert(anyFalse(arr2, 3) == false);
  assert(anyFalse(arr3, 3) == true);
}

void test_countFalse() {
  double arr1[] = {1.0, 2.0, 3.0};
  double arr2[] = {-1.0, -2.0, -3.0};
  double arr3[] = {1.0, -2.0, 3.0};

  assert(countFalse(arr1, 3) == 3);
  assert(countFalse(arr2, 3) == 0);
  assert(countFalse(arr3, 3) == 2);
}

void test_firstTrue() {
  double arr1[] = {1.0, 2.0, 3.0};
  double arr2[] = {-1.0, -2.0, -3.0};
  double arr3[] = {1.0, -2.0, 3.0};

  assert(firstTrue(arr1, 3) == -1);
  assert(firstTrue(arr2, 3) == 0);
  assert(firstTrue(arr3, 3) == 1);
}

void test_locateMax() {
  double arr1[] = {1.0, 2.0, 3.0};
  double arr2[] = {3.0, 2.0, 1.0};
  double arr3[] = {1.0, 3.0, 2.0};

  assert(locateMax(arr1, 3) == 2);
  assert(locateMax(arr2, 3) == 0);
  assert(locateMax(arr3, 3) == 1);
}

void test_contains() {
  double arr1[] = {10, 50, 40, 20, 50, 40, 30};
  double arr2[] = {50, 20, 30};
  double arr3[] = {50, 40, 40};
  double arr4[] = {50, 30, 20};
  double arr5[] = {10, 20, 20};

  assert(contains(arr1, 7, arr2, 3) == true);
  assert(contains(arr1, 7, arr3, 3) == true);
  assert(contains(arr1, 7, arr4, 3) == false);
  assert(contains(arr1, 7, arr5, 3) == false);
}

void Problem2() {
  cout << "Problem 2" << endl;

  test_anyFalse();
  test_countFalse();
  test_firstTrue();
  test_locateMax();
  test_contains();

  std::cout << "All tests passed!" << std::endl;
}