#include "exercises.h"
#include "headers.h"
#include "helpers.h"
#include "Listy.h"


void Exercise1() {
  int MAX_INT_VALUE = 64;
  std::cout << "Exercise 1" << std::endl;

  int a = 20;
  int b = 15;

  int A[a+b];

  for (int i = 0; i < a; i++){ 
    A[i] = rand() % (MAX_INT_VALUE + 1);
  }

  std::sort(A, A+a);

  displayArray(A, a);

  int B[b];

  for (int i = 0; i < b; i++){ 
    B[i] = rand() % (MAX_INT_VALUE + 1);
  }

  std::sort(B, B+b);

  displayArray(B, b);

  // Merge
  int c = a+b;
  int C[c];
  int i = 0, j = 0, k = 0;
  while (k < c) {
    if (A[i] < B[j] && i < a) {
      C[k++] = A[i++];
    } else {
      C[k++] = B[j++];
    }
  }

  displayArray(C, c);
}

void Exercise2() {
  std::cout << "Exercise 2" << std::endl;

  int n = 17;
  std::string anagrams[n] = {"bad", "dab", "abc", "cab", "fart", "frat", "raft", "bast", "bats", "stab", "tabs", "feel", "flee", "leap", "pale", "peal", "plea" };
  random_shuffle(anagrams, anagrams+n);

  displayArray(anagrams, n);

  std::map<char, int> anagramChars[n];
  std::map<std::string, std::string*> anagramGroups;
  std::map<std::string, int> anagramGroupCounters;

  for (int i = 0; i < n; i++) {
    std::string anagram = anagrams[i];
    std::map<char, int> m = anagramChars[i];

    // chars and counts
    for (int j = 0; j < anagram.size(); j++) {
      m[anagram[j]]++;
    }

    // compose a key of chars and counts
    std::string key;
    int k = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
      // std::cout << it->first << ": " << it->second << " ";
      key.push_back(it->first);
      // char c = char(it->second);
      key.append(std::to_string(it->second));

    }
    // std::cout << std::endl;

    // get current count for this key
    int count = anagramGroupCounters[key];
    // if count is 0, initiate new arr1ay of size n
    if (count == 0) {
      anagramGroups[key] = new std::string[n];
    }
    // insert into grouped arr1ay using count index
    anagramGroups[key][count] = anagram;
    // increment count
    anagramGroupCounters[key]++;
  }

  std::string anagramsGrouped[n];
  int i = 0;
  for (auto it = anagramGroups.begin(); it != anagramGroups.end(); it++) {
    std::string key = it->first;
    int count = anagramGroupCounters[key];
    for (int j = 0; j < count; j++) {
      anagramsGrouped[i++] = it->second[j];
    }

    delete[] it->second;
  }

  displayArray(anagramsGrouped,n);
}

void Exercise3() {
  std::cout << "Exercise 3" << std::endl;

  int n = 12;
  int arr1[n] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
  displayArray(arr1,n);

  int i = 0;
  int val = *(arr1);
  while (val <= *(arr1+i) && i < n) {
    i++;
  }

  std::cout << *(arr1+i) << std::endl;

  int arr2[n];
  int k = 0;
  for (int j = i; j < n; j++) {
    *(arr2+k) = *(arr1+j);
    k++;
  }
  for (int j = 0; j < i; j++) {
    *(arr2+k) = *(arr1+j);
    k++;
  }

  displayArray(arr2,n);

  int searchTerm = 5;
  int searchIndex = binarySearch(arr2,searchTerm,0,n);
  if (searchIndex < 0) {
    std::cout << searchIndex << std::endl;
  } else {
    std::cout << i+searchIndex << std::endl;
  }
}

void Exercise4() {
  std::cout << "Exercise 4" << std::endl;

  Listy* l = new Listy();
  l->display();

  // // Testing elementAt
  // int index = 0;
  // int val = l->elementAt(index);
  // std::cout << val << std::endl;

  // index = 20;
  // val = l->elementAt(index);
  // std::cout << val << std::endl;

  int stop = false;
  int i = 0; 
  int x = l->returnRandomElement(); // Get a random element to search for
  while (!stop) {
    int val = l->elementAt(i);
    if (val > 0) {
      if (val == x) {
        std::cout << "Element " << x << " occurs at position " << i << std::endl;
        stop = true;
      }
      i++;
    } else {
      stop = true;
    }
  }

  delete l;
}

void Exercise5() {
  std::cout << "Exercise 5" << std::endl;

  std::string sparseArray[] = {"at","","","","ball","","","car","","","dad","",""};
  std::string searchTerm = "ball";

}