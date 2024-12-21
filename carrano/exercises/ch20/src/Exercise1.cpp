#include "helpers.h"

void Exercise1() {
  std::cout << "Exercise 1" << std::endl;

  // Adjacency matrix
  uint adjacencyMatrix1[6][6] = {
  //         0         1         2         3         4         5
    {        0,        9,  INT_MAX,  INT_MAX,        1,  INT_MAX }, // 0
    {        9,        0,        8,  INT_MAX,        6,  INT_MAX }, // 1
    {  INT_MAX,        8,        0,        5,  INT_MAX,        2 }, // 2
    {  INT_MAX,  INT_MAX,        5,        0,  INT_MAX,  INT_MAX }, // 3
    {        1,        6,  INT_MAX,  INT_MAX,        0,        7 }, // 4
    {  INT_MAX,  INT_MAX,        2,  INT_MAX,        7,        0 }  // 5
  };

  std::cout << "1a) Figure 20-33: Adjacency Matrix" << std::endl;
  printWeightMatrix(adjacencyMatrix1);
  std::cout << std::endl;

  // Adjacency list
  std::map<int, std::list<std::pair<int,int>>> adjacencyList1;

  adjacencyList1[0] = {std::make_pair(1, 9),std::make_pair(4, 1)};
  adjacencyList1[1] = {std::make_pair(0, 9),std::make_pair(2, 8),std::make_pair(4, 6)};
  adjacencyList1[2] = {std::make_pair(1, 8),std::make_pair(3, 5),std::make_pair(5, 2)};
  adjacencyList1[3] = {std::make_pair(2, 5)};
  adjacencyList1[4] = {std::make_pair(0, 1),std::make_pair(1, 6),std::make_pair(5, 7)};
  adjacencyList1[5] = {std::make_pair(2, 2),std::make_pair(4, 7)};

  std::cout << "1a) Figure 20-33: Adjacency List" << std::endl;
  printMapListPair(adjacencyList1);
  std::cout << std::endl;

  // Adjacency matrix
  bool adjacencyMatrix2[9][9] = {
  //      a      b      c      d      e      f      g      h      i
    { false,  true,  true, false, false, false, false, false, false }, // a
    { false, false, false,  true, false, false, false,  true, false }, // b
    { false, false, false,  true,  true, false, false, false, false }, // c
    { false, false, false, false, false, false, false,  true, false }, // d
    { false, false, false, false, false, false,  true, false, false }, // e
    { false, false, false, false, false, false,  true, false,  true }, // f
    { false, false,  true, false, false, false, false, false, false }, // g
    { false, false, false, false, false, false,  true, false, false }, // h
    { false, false,  true, false, false, false, false, false, false }  // i
  };

  std::cout << "2a) Figure 20-34: Adjacency Matrix" << std::endl;
  printNonWeightedMatrix(adjacencyMatrix2);
  std::cout << std::endl;

  // Adjacency list
  std::map<char, std::list<char>> adjacencyList2;

  adjacencyList2['a'] = {'b','c'};
  adjacencyList2['b'] = {'d','h'};
  adjacencyList2['c'] = {'d','e'};
  adjacencyList2['d'] = {'h'};
  adjacencyList2['e'] = {'g'};
  adjacencyList2['f'] = {'g','i'};
  adjacencyList2['g'] = {'c'};
  adjacencyList2['h'] = {'g'};
  adjacencyList2['i'] = {'c'};

  std::cout << "1a) Figure 20-34: Adjacency List" << std::endl;
  printMapList(adjacencyList2);
  std::cout << std::endl;
}