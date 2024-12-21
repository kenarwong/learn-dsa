#include "helpers.h"

void Exercise2() {
  std::cout << "Exercise 2" << std::endl;

  // Adjacency matrix
  bool adjacencyMatrix[9][9] = {
  //      P      Q      R      S      T      W      X      Y      Z
    { false, false,  true, false, false,  true, false, false, false }, // P
    { false, false, false, false, false, false,  true, false, false }, // Q
    { false, false, false, false, false, false,  true, false, false }, // R
    { false, false, false, false,  true, false, false, false, false }, // S
    { false, false, false, false, false,  true, false, false, false }, // T
    { false, false, false,  true, false, false, false,  true, false }, // W
    { false, false, false, false, false, false, false, false, false }, // X
    { false, false,  true, false, false, false, false, false,  true }, // Y
    { false, false, false, false, false, false, false, false, false }  // Z
  };

  std::cout << "Figure 20-6b: Adjacency Matrix" << std::endl;
  printNonWeightedMatrix(adjacencyMatrix);
  std::cout << std::endl;

  // Adjacency list
  std::map<char, std::list<char>> adjacencyList;

  adjacencyList['P'] = {'R','W'};
  adjacencyList['Q'] = {'X'};
  adjacencyList['R'] = {'X'};
  adjacencyList['S'] = {'T'};
  adjacencyList['T'] = {'W'};
  adjacencyList['W'] = {'S','Y'};
  adjacencyList['X'] = {};
  adjacencyList['Y'] = {'R','Z'};
  adjacencyList['Z'] = {};

  std::cout << "Figure 20-8b: Adjacency list" << std::endl;
  printMapList(adjacencyList);
  std::cout << std::endl;
}