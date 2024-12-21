#ifndef GRAPH_H
#define GRAPH_H

#include "GraphInterface.h"
#include "helpers.h"
#include <map>
#include <list>
#include <set>
#include <stack>
#include <queue>

template<class LabelType>
class Graph : public GraphInterface<LabelType> {
  private:
    std::map<LabelType, std::list<std::pair<LabelType, int>>> adjacencyList;
    int numVertices;
    int numEdges;

  public:
    Graph();
    Graph(const std::map<LabelType, std::list<std::pair<LabelType, int>>>& adjacencyList, int numBidirectionalEdgesnumEdges);
    ~Graph();

    int getNumVertices() const override;
    int getNumEdges() const override;
    bool add(LabelType start, LabelType end, int edgeWeight) override;
    bool remove(LabelType start, LabelType end) override;
    int getEdgeWeight(LabelType start, LabelType end) const override;
    void depthFirstTraversal(LabelType start, void visit(LabelType&)) override;
    void breadthFirstTraversal(LabelType start, void visit(LabelType&)) override;

    void displayAdjacencyList() const; // for debugging
};

template <class LabelType>
inline void Graph<LabelType>::displayAdjacencyList() const
{
  printMapListPair(adjacencyList);
}

template <class LabelType>
inline Graph<LabelType>::Graph() : numVertices(0), numEdges(0) { }

template<class LabelType>
inline Graph<LabelType>::Graph(const std::map<LabelType, std::list<std::pair<LabelType, int>>>& adjacencyList, int numBidirectionalEdgesnumEdges)
  : adjacencyList(adjacencyList), numVertices(adjacencyList.size()), numEdges(numBidirectionalEdgesnumEdges) {
}

template<class LabelType>
inline Graph<LabelType>::~Graph() {
}

template<class LabelType>
inline int Graph<LabelType>::getNumVertices() const {
  return numVertices;
}

template<class LabelType>
inline int Graph<LabelType>::getNumEdges() const {
  return numEdges;
}

template <class LabelType>
inline bool Graph<LabelType>::add(LabelType start, LabelType end, int edgeWeight)
{
  // find first vertex v
  auto v = adjacencyList.find(start); // O(logn)
  if (v != adjacencyList.end()) {

    std::list<std::pair<LabelType, int>>* list = &((*v).second); // list of adjacent vertices 

    // check if v->u already exists
    bool uFound = false;
    bool insertAtIterator = false;
    typename std::list<std::pair<LabelType, int>>::iterator it;
    for (it = list->begin(); it != list->end(); ++it) {

      if ((*it).first >= end) {
        // v->u already exists
        if ((*it).first == end) {
          (*it).second = edgeWeight; // update edgeWeight
          uFound = true;
        } else {
          // insert new edge here
          insertAtIterator = true;
          break;
        }
      }
    }

    // if not found, insert at position it
    if (!uFound) {
      if (insertAtIterator) {
        list->insert(it, std::make_pair(end, edgeWeight)); // insert in place
      } else {
        list->push_back(std::make_pair(end, edgeWeight)); // insert at end
      }

      ++numEdges;
    }
  } else {

    // vertex doesn't exist
    std::list<std::pair<LabelType, int>> list = {std::make_pair(end, edgeWeight)}; // create list with edge to end
    adjacencyList.insert(std::make_pair(start, list)); // insert into map, O(1)

    numVertices++;
    numEdges++;
  }

  // undirected graph, requires bidrectional edges
  // find second vertex u
  auto u = adjacencyList.find(end);
  if (u != adjacencyList.end()) {

    std::list<std::pair<LabelType, int>>* list = &((*u).second); // list of adjacent vertices 

    // check if u->v already exists
    bool vFound = false;
    bool insertAtIterator = false;
    typename std::list<std::pair<LabelType, int>>::iterator it;
    for (it = list->begin(); it != list->end(); ++it) {

      if ((*it).first >= start) {
        // v->u already exists
        if ((*it).first == start) {
          (*it).second = edgeWeight; // update edgeWeight
          vFound = true;
        } else {
          // insert new edge here
          insertAtIterator = true;
          break;
        }
      }
    }

    // if not found, insert at position it
    if (!vFound) {
      if (insertAtIterator) {
        list->insert(it, std::make_pair(start, edgeWeight)); // insert in place
      } else {
        list->push_back(std::make_pair(start, edgeWeight)); // insert at end
      }
      // ++numEdges; // do not need to increment edges (already performed above)
    }
  } else {

    // vertex doesn't exist 
    std::list<std::pair<LabelType, int>> list = {std::make_pair(start, edgeWeight)}; // create list with edge to start
    adjacencyList.insert(std::make_pair(end, list)); // insert into map, O(1)

    numVertices++;
    // ++numEdges; // do not need to increment edges (already performed above)
  }

  return true; // an edge is always created
}


template <class LabelType>
inline bool Graph<LabelType>::remove(LabelType start, LabelType end)
{
  bool edgeRemoved = false;

  // find both vertices 
  auto v = adjacencyList.find(start); // O(logn)
  auto u = adjacencyList.find(end); // O(logn)

  // remove edges from lists
  if (v != adjacencyList.end() && u != adjacencyList.end()) {
    
    bool vEdgeFound = false;
    bool uEdgeFound = false;
    
    std::list<std::pair<LabelType, int>>* vlist = &((*v).second); // list of adjacent vertices 
    typename std::list<std::pair<LabelType, int>>::iterator it;
    for (it = vlist->begin(); it != vlist->end(); ++it) {
        if ((*it).first == end) {
          vEdgeFound = true;
          break;
        }
    }

    if (vEdgeFound) {
      vlist->erase(it);
    }

    std::list<std::pair<LabelType, int>>* ulist = &((*u).second); // list of adjacent vertices 
    for (it = ulist->begin(); it != ulist->end(); ++it) {
        if ((*it).first == start) {
          uEdgeFound = true;
          break;
        }
    }

    if (uEdgeFound) {
      ulist->erase(it);
    }

    // only decrement edge count and return if bidirectional edge was found and removed from both vertices' lists
    // possible due to data manipulation error that they don't both exist
    // in this case, it will still remove both, but will not report a success or decrement number of edges count
    // because presumably there was a more serious problem upstream
    if (vEdgeFound && uEdgeFound) {
      numEdges--;
      edgeRemoved = true;

      // check if vertices are now isolated
      if (vlist->size() == 0) {
        adjacencyList.erase(v);
        numVertices--;
      }
      if(ulist->size() == 0) {
        adjacencyList.erase(u);
        numVertices--;
      }
    }
  }

  return edgeRemoved;
}

template <class LabelType>
inline int Graph<LabelType>::getEdgeWeight(LabelType start, LabelType end) const
{
  auto v = adjacencyList.find(start);
  if (v != adjacencyList.end()) {

    std::list<std::pair<LabelType, int>> list = (*v).second; // list of adjacent vertices 
    for (auto it = list.begin(); it != list.end(); ++it) {

      if ((*it).first == end) {
        return (*it).second;
      }

    }
    return -1;

  } else {
    return -1;
  }
}

template <class LabelType>
inline void Graph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&))
{
  std::stack<LabelType> s;
  std::set<LabelType> visited;

  s.push(start);
  visited.insert(start);

  while(!s.empty()) {
    LabelType current = s.top();
    s.pop();
    visit(current);

    auto list = adjacencyList.find(current);
    for (auto& pair : list->second) {
      if(visited.find(pair.first) == visited.end()) {
        s.push(pair.first);
        visited.insert(pair.first); // Pre-visit to prevent future searches from pushing same to stack
      }
    }

  }
}

template <class LabelType>
inline void Graph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&))
{
  std::queue<LabelType> q;
  std::set<LabelType> visited;

  q.push(start);
  visited.insert(start);

  while(!q.empty()) {
    LabelType current = q.front();
    q.pop();
    visit(current);

    auto list = adjacencyList.find(current);
    for (auto& pair : list->second) {
      if(visited.find(pair.first) == visited.end()) {
        q.push(pair.first);
        visited.insert(pair.first); // Pre-visit to prevent future searches from pushing same to stack
      }
    }

  }
}

#endif