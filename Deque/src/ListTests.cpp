/**
 * @file ListTests.cpp
 * This file contains unit tests for the LinkedList class.
 * 
 * The tests include:
 * - Testing the default constructor of the LinkedList class.
 * - Testing the add, remove, contains, and clear methods of the LinkedList class.
 */

#include "LinkedList.h"
#include "headers.h"
#include <cassert>

/**
 * Tests the default constructor of the LinkedList class.
 * 
 * This test ensures that a newly created LinkedList is empty and has a size of 0.
 */
void testListConstructor() {
  LinkedList<int> list;
  assert(list.isEmpty());
  assert(list.size() == 0);
}

/**
 * Tests the add, remove, contains, and clear methods of the LinkedList class.
 * 
 * This test performs the following checks:
 * - Adds elements to the list and verifies the size.
 * - Checks if the list contains specific elements.
 * - Removes elements from the list and verifies the size and contents.
 * - Clears the list and verifies it is empty.
 */
void testListAddRemove()
{
  LinkedList<std::string> list;

  int size = 5;
  std::string items[size] = {"one", "two", "three", "four", "five"};
  for (int i = 0; i < size; i++)
  {
     list.addBack(items[i]);
  } 

  assert(list.size() == size);

  assert(list.contains("one"));
  assert(list.contains("two"));
  assert(list.contains("three"));
  assert(list.contains("four"));
  assert(list.contains("five"));
  assert(!list.contains("six"));
  
  assert(list.removeBack());
  assert(list.size() == 4);
  assert(!list.contains("five"));

  list.addFront("zero");
  assert(list.size() == 5);
  assert(list.contains("zero"));

  assert(list.removeFront());
  assert(list.size() == 4);
  assert(!list.contains("zero"));

  list.clear();
  assert(list.isEmpty());
  assert(list.size() == 0);
} 

/**
 * Runs all the tests for the LinkedList class.
 * 
 * This function calls the individual test functions
 */
void ListTests()
{
  testListConstructor();
  testListAddRemove();
  std::cout << "--- All List tests passed ---" << std::endl;
}