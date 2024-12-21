#include "helpers.h"

void Exercise3() {
  std::cout << "Exercise 3" << std::endl;

  // Adjacency matrix
  bool adjacencyMatrix[6][6] = {
  //      a      b      c      d      e      f
    { false,  true,  true, false, false, false }, // a
    {  true, false,  true, false, false, false }, // b
    {  true,  true, false,  true,  true,  true }, // c
    { false, false,  true, false, false,  true }, // d
    { false, false,  true, false, false, false }, // e
    { false, false,  true,  true, false, false }  // f
  };

  std::cout << "Figure 20-35: Adjacency Matrix" << std::endl;
  printNonWeightedMatrix(adjacencyMatrix);
  std::cout << std::endl;

  // Adjacency list
  std::map<char, std::list<char>> adjacencyList;

  adjacencyList['a'] = {'b','c'};
  adjacencyList['b'] = {'a','c'};
  adjacencyList['c'] = {'a','b','d','e','f'};
  adjacencyList['d'] = {'c','f'};
  adjacencyList['e'] = {'c'};
  adjacencyList['f'] = {'c','d'};

  std::cout << "Figure 20-35: Adjacency list" << std::endl;
  printMapList(adjacencyList);
  std::cout << std::endl;
}