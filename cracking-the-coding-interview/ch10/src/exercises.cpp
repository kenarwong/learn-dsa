#include "exercises.h"
#include "headers.h"
#include "helpers.h"

const int MAX_INT_VALUE = 255;

void Exercise1() {
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
    // if count is 0, initiate new array of size n
    if (count == 0) {
      anagramGroups[key] = new std::string[n];
    }
    // insert into grouped array using count index
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
