#ifndef PROBLEM_1_
#define PROBLEM_1_

#include <iostream>
#include <vector>

using namespace std;

template<typename ValueType>
vector<ValueType> intersect_unsorted(const vector<ValueType>& a, const vector<ValueType>& b) {
  // O(nm)
  vector<ValueType> c;

  for (int i = 0; i < a.size(); ++i) {
    if (i == 0 || a[i] != a[i-1]) {
      for (int j = 0; j < b.size(); ++j) {
        if (a[i] == b[j]) {
          c.emplace_back(a[i]);
        }
      }
    }
  }

  return c;
}

template<typename ValueType>
int binary_search(const vector<ValueType>& v, int low, int high, ValueType searchTerm) {
  if (low > high) {
    return -1; // not found
  }

  int mid = low + (high-low)/2;

  if (searchTerm == v[mid]) {
    return mid;
  } else if (searchTerm < v[mid]) {
    return binary_search(v, low, mid-1, searchTerm);
  } else {
    return binary_search(v, mid+1, high, searchTerm);
  }
}

template<typename ValueType>
vector<ValueType> intersect_sorted1(const vector<ValueType>& a, const vector<ValueType>& b) {
  // O(nlogm)
  vector<ValueType> c;
  const vector<ValueType>* small_vec;
  const vector<ValueType>* large_vec;

  if (a.size() < b.size()) {
    small_vec = &a;
    large_vec = &b;
  } else {
    large_vec = &a;
    small_vec = &b;
  }

  int low = 0;
  int high = large_vec->size() - 1;

  for (int i = 0; i < small_vec->size(); ++i) {
    if (i == 0 || (*small_vec)[i] != (*small_vec)[i-1] &&
        binary_search(*large_vec, low, high, (*small_vec)[i]) > 0) {
      c.emplace_back((*small_vec)[i]);
    }
  }

  return c;
}

template<typename ValueType>
vector<ValueType> intersect_sorted2(const vector<ValueType>& a, const vector<ValueType>& b) {
  // O(n+m)
  vector<ValueType> c;

  int i = 0, j = 0;
  while (i < a.size() && j < b.size()) {
    if (i == 0 || (a[i] != a[i-1]) && (a[i] == b[j])) {
      c.emplace_back(a[i]);
      ++i;
      ++j;
    } else if (a[i] < b[i]) {
      ++i;
    } else {
      ++j;
    }
  }

  return c;
}

#endif