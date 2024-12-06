#include <iostream>
#include <string>
#include "HashedEntry.h"
#include "HashedDictionary.h"
#include <cassert>
#include <vector>
#include <map>
#include <functional>
#include <cstdlib>
#include <ctime>

std::map<std::string,int> generateHashedDictionaryRandomEntries(HashedDictionary<std::string, int>& dict, int numEntries) {
  srand(time(0));
  std::map<std::string,int> pairs;

  for (int i = 0; i < numEntries; ++i) {
    // loop until unique key is generated
    std::string key = "key" + std::to_string(rand() % 1000);
    while(pairs.find(key) != pairs.end()) {
      key = "key" + std::to_string(rand() % 1000);
    }

    int value = rand() % 1000;
    dict.add(key, value);

    pairs.insert({key, value});
  }

  return pairs;
}

void testHashedDictionaryConstructors(bool randomizeValues = false) {
  HashedDictionary<std::string, int> dict;
  assert(dict.isEmpty() == true);
  assert(dict.getNumberOfEntries() == 0);

  int n = 10;
  HashedDictionary<std::string, int> dict2(n);
  assert(dict2.isEmpty() == true);
  assert(dict2.getNumberOfEntries() == 0);
  
  if (randomizeValues) {
    generateHashedDictionaryRandomEntries(dict2, n);
  } else {
    for (int i = 0; i < n; ++i) {
      std::string key = "key" + std::to_string(i);
      int value = i * n;
      dict2.add(key, value);
    }
  }

  assert(dict2.isEmpty() == false);
  assert(dict2.getNumberOfEntries() == n);

  HashedDictionary<std::string, int> dict3(dict2);
  assert(dict3.isEmpty() == false);
  assert(dict3.getNumberOfEntries() == n);
}

void testHashedDictionaryAddAndRemove(bool randomizeValues = false) {
  HashedDictionary<std::string, int> dict;
  assert(dict.isEmpty() == true);
  assert(dict.getNumberOfEntries() == 0);

  int n = 10;
  std::map<std::string,int> pairs;
  if (randomizeValues) {
    pairs = generateHashedDictionaryRandomEntries(dict, n);
  } else {
    for (int i = 0; i < n; ++i) {
      std::string key = "key" + std::to_string(i);
      int value = i * n;
      dict.add(key, value);
      pairs.insert({key, value});
    }
  }

  assert(dict.isEmpty() == false);
  assert(dict.getNumberOfEntries() == n);

  for(auto const& [key, value] : pairs) {
    assert(dict.contains(key) == true);
    assert(dict.getValue(key) == value);
  }

  for(auto const& [key, value] : pairs) {
    dict.remove(key);
    assert(dict.contains(key) == false);
  }

  assert(dict.isEmpty() == true);
  assert(dict.getNumberOfEntries() == 0);
}

void testHashedDictionaryTraversal(bool randomizeValues = false) {
  HashedDictionary<std::string, int> dict;
  assert(dict.isEmpty() == true);
  assert(dict.getNumberOfEntries() == 0);

  int n = 10;
  std::map<std::string,int> pairs;
  if (randomizeValues) {
    pairs = generateHashedDictionaryRandomEntries(dict, n);
  } else {
    for (int i = 0; i < n; ++i) {
      std::string key = "key" + std::to_string(i);
      int value = i * n;
      dict.add(key, value);
      pairs.insert({key, value});
    }
  }

  assert(dict.isEmpty() == false);
  assert(dict.getNumberOfEntries() == n);

  std::vector<int> values;
  std::function<void(std::shared_ptr<HashedEntry<std::string, int>>)> visit = [&values](std::shared_ptr<HashedEntry<std::string, int>> ptr) {
    auto value = ptr->getValue();
    values.push_back(value);
  };

  dict.traverse(visit);

  assert(values.size() == n);

  for(auto const& [key, value] : pairs) {
    assert(std::find(values.begin(), values.end(), value) != values.end());
  }
}

void testHashedDictionaryHighLoad(bool randomizeValues = false) {
  // Load factor = 10
  int n = 100;
  int s = 10;

  HashedDictionary<std::string, int> dict(s);
  assert(dict.isEmpty() == true);
  assert(dict.getNumberOfEntries() == 0);

  std::map<std::string,int> pairs;
  if (randomizeValues) {
    pairs = generateHashedDictionaryRandomEntries(dict, n);
  } else {
    for (int i = 0; i < n; ++i) {
      std::string key = "key" + std::to_string(i);
      int value = i * n;
      dict.add(key, value);
      pairs.insert({key, value});
    }
  }

  assert(dict.isEmpty() == false);
  assert(dict.getNumberOfEntries() == n);

  for(auto const& [key, value] : pairs) {
    assert(dict.contains(key) == true);
    assert(dict.getValue(key) == value);
  }

  std::vector<int> values;
  std::function<void(std::shared_ptr<HashedEntry<std::string, int>>)> visit = [&values](std::shared_ptr<HashedEntry<std::string, int>> ptr) {
    auto value = ptr->getValue();
    values.push_back(value);
  };

  dict.traverse(visit);

  assert(values.size() == n);

  for(auto const& [key, value] : pairs) {
    assert(std::find(values.begin(), values.end(), value) != values.end());
  }

  for(auto const& [key, value] : pairs) {
    dict.remove(key);
    assert(dict.contains(key) == false);
  }

  assert(dict.isEmpty() == true);
  assert(dict.getNumberOfEntries() == 0);
}

int HashedDictionaryTests()
{
  testHashedDictionaryConstructors(true);
  testHashedDictionaryAddAndRemove(true);
  testHashedDictionaryTraversal(true);
  testHashedDictionaryHighLoad(true);

  std::cout << "All Hashed Dictionary tests passed!" << std::endl;
  return 0;
}