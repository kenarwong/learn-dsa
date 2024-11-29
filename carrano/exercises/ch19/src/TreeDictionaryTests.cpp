#include <iostream>
#include <string>
#include "TreeDictionary.h"
#include <cassert>
#include <vector>
#include <functional>
#include <cstdlib>
#include <ctime>

std::vector<std::string> generateRandomEntries(TreeDictionary<std::string, int>& dict, int numEntries) {
  srand(time(0));
  std::vector<std::string> keys;
  for (int i = 0; i < numEntries; ++i) {
    // loop until unique key is generated
    std::string key = "key" + std::to_string(rand() % 1000);
    while (dict.contains(key)) {
      key = "key" + std::to_string(rand() % 1000);
    }

    keys.push_back(key);

    int value = rand() % 1000;
    dict.add(key, value);
  }

  return keys;
}

void testAddAndRemove() {
  TreeDictionary<std::string, int> dict;
  std::vector<std::string> keys = generateRandomEntries(dict, 20);

  // Test if all entries are added
  assert(dict.getNumberOfEntries() == 20);

  // Test if all keys are present
  for (const std::string& key : keys) {
    assert(dict.contains(key));
  }

  // Test if all keys are removed
  for (const std::string& key : keys) {
    dict.remove(key);
    assert(!dict.contains(key));
  }

  // Test if the number of entries is correct after removal
  assert(dict.getNumberOfEntries() == 0);
}

void testTraversal() {
  TreeDictionary<std::string, int> dict;

  std::vector<std::pair<std::string, int>> entries;
  for (int i = 0; i < 10; ++i) {
    std::string key = "key" + std::to_string(i);
    int value = i * 10;
    entries.emplace_back(key, value);
    dict.add(key, value);
  }

  auto visit = [](int& value) {
    std::cout << "Value: " << value << std::endl;
  };

  dict.traverse(visit);
}

int TreeDictionaryTests() {
  testAddAndRemove();
  testTraversal();

  std::cout << "All tests passed!" << std::endl;
  return 0;
}