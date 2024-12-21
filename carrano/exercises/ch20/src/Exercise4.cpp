#include "helpers.h"
#include "Graph.h"
#include <cassert>

void Exercise4() {
  std::cout << "Exercise 4" << std::endl;

  // Figure 20-33
  // Adjacency list
  std::map<int, std::list<std::pair<int,int>>> adjacencyList;

  adjacencyList[0] = {std::make_pair(1, 9),std::make_pair(4, 1)};
  adjacencyList[1] = {std::make_pair(0, 9),std::make_pair(2, 8),std::make_pair(4, 6)};
  adjacencyList[2] = {std::make_pair(1, 8),std::make_pair(3, 5),std::make_pair(5, 2)};
  adjacencyList[3] = {std::make_pair(2, 5)};
  adjacencyList[4] = {std::make_pair(0, 1),std::make_pair(1, 6),std::make_pair(5, 7)};
  adjacencyList[5] = {std::make_pair(2, 2),std::make_pair(4, 7)};

  Graph<int> g = Graph<int>(adjacencyList, 7);

  std::cout << "Figure 20-33: Depth-first traversal" << std::endl;
  g.depthFirstTraversal(0,graphTraversalVisit);
  std::cout << std::endl;

  std::cout << "Figure 20-33: Breadth-first traversal" << std::endl;
  g.breadthFirstTraversal(0,graphTraversalVisit);
  std::cout << std::endl;
  
  // Figure 20-36
  Graph<char> g2;
  g2.add('a','d',6);
  g2.add('a','c',4);
  g2.add('a','b',2);
  g2.add('b','c',5);
  g2.add('d','c',1);
  g2.add('d','h',4);
  g2.add('c','e',2);
  g2.add('e','f',1);
  g2.add('f','d',3);
  g2.add('i','e',3);
  g2.add('e','g',5);
  g2.add('g','f',4);

  assert(g2.getNumVertices() == 9);
  assert(g2.getNumEdges() == 12);

  std::cout << "Figure 20-36: Depth-first traversal" << std::endl;
  g2.depthFirstTraversal('a',graphTraversalVisit);
  std::cout << std::endl;

  std::cout << "Figure 20-36: Breadth-first traversal" << std::endl;
  g2.breadthFirstTraversal('a',graphTraversalVisit);
  std::cout << std::endl;

}