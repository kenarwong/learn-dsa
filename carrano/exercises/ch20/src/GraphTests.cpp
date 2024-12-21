#include "Graph.h"
#include "helpers.h"
#include <cassert>

void GraphConstructorTests() {
  Graph<int> g;
  assert(g.getNumVertices() == 0);
  assert(g.getNumEdges() == 0);

  g.add(0, 1, 9);

  // g.displayAdjacencyList();

  assert(g.getNumVertices() == 2);
  assert(g.getNumEdges() == 1);

  // Adjacency list
  std::map<int, std::list<std::pair<int,int>>> adjacencyList;

  adjacencyList[0] = {std::make_pair(1, 9),std::make_pair(4, 1)};
  adjacencyList[1] = {std::make_pair(0, 9),std::make_pair(2, 8),std::make_pair(4, 6)};
  adjacencyList[2] = {std::make_pair(1, 8),std::make_pair(3, 5),std::make_pair(5, 2)};
  adjacencyList[3] = {std::make_pair(2, 5)};
  adjacencyList[4] = {std::make_pair(0, 1),std::make_pair(1, 6),std::make_pair(5, 7)};
  adjacencyList[5] = {std::make_pair(2, 2),std::make_pair(4, 7)};

  Graph<int> g2 = Graph<int>(adjacencyList, 7);

  // g2.displayAdjacencyList();

  assert(g2.getNumVertices() == 6);
  assert(g2.getNumEdges() == 7);
}

void GraphAddRemoveTests() {
  Graph<int> g;

  g.add(0, 1, 9);
  g.add(1, 2, 8);
  g.add(2, 3, 5);
  g.add(4, 0, 1);
  g.add(4, 1, 6);
  g.add(4, 5, 7);
  g.add(5, 2, 2);
  g.add(4, 3, 1);   // Out of order insertion

  // g.displayAdjacencyList();

  assert(g.getNumVertices() == 6);
  assert(g.getNumEdges() == 8);

  assert(g.getEdgeWeight(0, 1) == 9);
  assert(g.getEdgeWeight(1, 2) == 8);
  assert(g.getEdgeWeight(2, 3) == 5);
  assert(g.getEdgeWeight(4, 0) == 1);
  assert(g.getEdgeWeight(4, 1) == 6);
  assert(g.getEdgeWeight(4, 5) == 7);
  assert(g.getEdgeWeight(5, 2) == 2);

  assert(g.remove(0, 1));
  assert(!g.remove(0, 1));
  assert(g.getEdgeWeight(0, 1) == -1);
  assert(g.getNumEdges() == 7);
  assert(g.getNumVertices() == 6); // Number of vertices should not change

  assert(g.remove(4, 0)); // 0 is now isolated and removed

  assert(g.getEdgeWeight(0, 1) == -1);
  assert(g.getNumVertices() == 5); // Number of vertices should decrease
  assert(g.getNumEdges() == 6);

  assert(g.remove(1, 2));
  assert(g.remove(2, 3));
  assert(g.remove(4, 1));
  assert(g.remove(4, 5));
  assert(g.remove(5, 2));

  // g.displayAdjacencyList();

  assert(g.getNumVertices() == 2);
  assert(g.getNumEdges() == 1);

  assert(g.remove(4, 3));

  assert(g.getNumVertices() == 0);
  assert(g.getNumEdges() == 0);

  // g.displayAdjacencyList();
}

void GraphTraversalTests() {
  // Adjacency list
  std::map<int, std::list<std::pair<int,int>>> adjacencyList;

  adjacencyList[0] = {std::make_pair(1, 9),std::make_pair(4, 1)};
  adjacencyList[1] = {std::make_pair(0, 9),std::make_pair(2, 8),std::make_pair(4, 6)};
  adjacencyList[2] = {std::make_pair(1, 8),std::make_pair(3, 5),std::make_pair(5, 2)};
  adjacencyList[3] = {std::make_pair(2, 5)};
  adjacencyList[4] = {std::make_pair(0, 1),std::make_pair(1, 6),std::make_pair(5, 7)};
  adjacencyList[5] = {std::make_pair(2, 2),std::make_pair(4, 7)};

  Graph<int> g = Graph<int>(adjacencyList, 7);

  std::cout << "Depth-first traversal" << std::endl;
  g.depthFirstTraversal(0,graphTraversalVisit);

  std::cout << "Breadth-first traversal" << std::endl;
  g.breadthFirstTraversal(0,graphTraversalVisit);

}

void GraphTests() {
  GraphConstructorTests();
  GraphAddRemoveTests();
  // GraphTraversalTests();

  std::cout << "All Graph tests complete!" << std::endl;
}