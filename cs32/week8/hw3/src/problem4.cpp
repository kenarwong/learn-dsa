#include "headers.h"

// Return the number of ways that all n2 elements of a2 appear in
// the n1 element array a1 in the same order (though not necessarily
// consecutively).  The empty sequence (i.e. one where n2 is 0)
// appears in a sequence of length n1 in 1 way, even if n1 is 0.
// For example, if a1 is the 7 element array
//        10 50 40 20 50 40 30
// then for this value of a2     the function must return
//        10 20 40                        1
//        10 40 30                        2
//        20 10 40                        0
//        50 40 30                        3
int countContains(const double a1[], int n1, const double a2[], int n2)
{
  if (n1 == 0 && n2 != 0) {
    return 0; // a1 exhausted, but a2 check not completed
  }

  if (n2 == 0) {
    return 1; // a2 check completed
  }

  if (a1[n1-1] == a2[n2-1]) {
    // branch of match

    int count = 0;

    // Depth search
    // confirm if valid combination
    count = countContains(a1,n1-1,a2,n2-1); // advance both

    // if count = 0, depth search not found, do not continue
    // still need to continue breadth search
    if (count == 0) {
      return 0;
    }

    // Breadth search
    // if count == 1
    // if the number of search terms left in a1 is greater than or equal to search terms in n2
    // need to continue searching for alternate combinations of this match
    // if n1-1 >= n2, continue 
    if (n1-1 >= n2) {
      // advance only n1, and add to count
      count += countContains(a1,n1-1,a2,n2); 
    }

    return count;
  } else {
    // match not found, but advance until another one is found
    return countContains(a1,n1-1,a2,n2); // advance only n1
  }
}

// Exchange two doubles
void exchange(double &x, double &y)
{
  double t = x;
  x = y;
  y = t;
}
// Rearrange the elements of the array so that all the elements
// whose value is > separator come before all the other elements,
// and all the elements whose value is < separator come after all
// the other elements.  Upon return, firstNotGreater is set to the
// index of the first element in the rearranged array that is
// <= separator, or n if there is no such element, and firstLess is
// set to the index of the first element that is < separator, or n
// if there is no such element.
// In other words, upon return from the function, the array is a
// permutation of its original value such that
//   * for 0 <= i < firstNotGreater, a[i] > separator
//   * for firstNotGreater <= i < firstLess, a[i] == separator
//   * for firstLess <= i < n, a[i] < separator
// All the elements > separator end up in no particular order.
// All the elements < separator end up in no particular order.
void separate(double a[], int n, double separator,
              int &firstNotGreater, int &firstLess)
{
  if (n < 0)
    n = 0;

  // It will always be the case that just before evaluating the loop
  // condition:
  //  firstNotGreater <= firstUnknown and firstUnknown <= firstLess
  //  Every element earlier than position firstNotGreater is > separator
  //  Every element from position firstNotGreater to firstUnknown-1 is
  //    == separator
  //  Every element from firstUnknown to firstLess-1 is not known yet
  //  Every element at position firstLess or later is < separator

  firstNotGreater = 0;
  firstLess = n;
  int firstUnknown = 0;
  while (firstUnknown < firstLess)
  {
    if (a[firstUnknown] < separator)
    {
      firstLess--;
      exchange(a[firstUnknown], a[firstLess]);
    }
    else
    {
      if (a[firstUnknown] > separator)
      {
        exchange(a[firstNotGreater], a[firstUnknown]);
        firstNotGreater++;
      }
      firstUnknown++;
    }
  }
}

// |GGGGAEEEEB----CLLLLL|
// G = greater
// A = firstNotGreater (could be equal)
// E = Equal
// B = firstUnknown (always unknown)
// - = not yet checked
// C = firstLess (always less, excluding pre-loop)
// L = less

// Rearrange the elements of the array so that
// a[0] >= a[1] >= a[2] >= ... >= a[n-2] >= a[n-1]
// If n <= 1, do nothing.
void order(double a[], int n)
{
  if (n <= 1) {
    return;
  }

  int firstNotGreater = 0; // 0-based
  int firstLess = n; // 1-based
  double separator = a[0];
  separate(a, n, separator, firstNotGreater, firstLess);

  //for(auto i = 0; i < n; i++) {
  //  std::cout << a[i] << " ";
  //}
  //std::cout << std::endl;

  // order each section using firstNotGreater and firstLess as separator indices
  order(a,firstNotGreater); // Everything greater
  //order(a + firstNotGreater,firstLess); // Everything equal, don't need to sort
  order(a + firstLess,n - firstLess); // Everything less

  return; // This is not always correct.
}

void testCountContains() {
  double a1[] = {10, 50, 40, 20, 50, 40, 30};
  double a2_1[] = {10, 20, 40};
  double a2_2[] = {10, 40, 30};
  double a2_3[] = {20, 10, 40};
  double a2_4[] = {50, 40, 30};

  assert(countContains(a1, 7, a2_1, 3) == 1);
  assert(countContains(a1, 7, a2_2, 3) == 2);
  assert(countContains(a1, 7, a2_3, 3) == 0);
  assert(countContains(a1, 7, a2_4, 3) == 3);

  std::cout << "All countContains tests passed!" << std::endl;
}

void testOrder() {
  double a1[] = {10, 50, 40, 20, 50, 40, 30};
  double expected1[] = {50, 50, 40, 40, 30, 20, 10};

  order(a1, 7);
  for (int i = 0; i < 7; ++i) {
    assert(a1[i] == expected1[i]);
  }

  double a2[] = {1, 2, 3, 4, 5};
  double expected2[] = {5, 4, 3, 2, 1};

  order(a2, 5);
  for (int i = 0; i < 5; ++i) {
    assert(a2[i] == expected2[i]);
  }

  std::cout << "All order tests passed!" << std::endl;
}

// You will not receive full credit if for nonnegative `n2` and `n1 >= n2`, 
// the `countContains` function causes operations like these to be called more than 
// `factorial(n1+1) / (factorial(n2)*factorial(n1+1-n2))` times.
int countContainsWithExecutionCounter(const double a1[], int n1, const double a2[], int n2, int& executions)
{
  executions++;

  if (n1 == 0 && n2 != 0) {
    return 0; // a1 exhausted, but a2 check not completed
  }

  if (n2 == 0) {
    return 1; // a2 check completed
  }

  if (a1[n1-1] == a2[n2-1]) {
    // branch of match

    int count = 0;

    // Depth search
    // confirm if valid combination
    count = countContainsWithExecutionCounter(a1,n1-1,a2,n2-1,executions); // advance both

    // if count = 0, depth search not found, do not continue
    // still need to continue breadth search
    if (count == 0) {
      return 0;
    }

    // Breadth search
    // if count == 1
    // if the number of search terms left in a1 is greater than or equal to search terms in n2
    // need to continue searching for alternate combinations of this match
    // if n1-1 >= n2, continue 
    if (n1-1 >= n2) {
      // advance only n1, and add to count
      count += countContainsWithExecutionCounter(a1,n1-1,a2,n2,executions); 
    }

    return count;
  } else {
    // match not found, but advance until another one is found
    return countContainsWithExecutionCounter(a1,n1-1,a2,n2,executions); // advance only n1
  }
}

void testCountContainsEfficiency() {
  double a1[] = {10, 50, 40, 20, 50, 40, 30};
  double a2[] = {10, 20, 40};

  int expectedCalls = 35; // factorial(8) / (factorial(3) * factorial(5))
  int actualCalls = 0;
  countContainsWithExecutionCounter(a1,7,a2,3,actualCalls);

  assert(actualCalls <= expectedCalls);

  std::cout << "Efficiency test for countContains passed!" << std::endl;
}

void Problem4() {
  testCountContains();
  testOrder();
  testCountContainsEfficiency();
}