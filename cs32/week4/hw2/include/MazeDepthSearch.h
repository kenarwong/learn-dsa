#ifndef MAZE_DEPTH_SEARCH_H
#define MAZE_DEPTH_SEARCH_H

#include "headers.h"
#include <stack>
#include "Coord.h"

class MazeDepthSearch {
public:
  MazeDepthSearch();
  MazeDepthSearch(const bool debug);
  bool pathExists(std::string maze[], int nRows, int nCols, int sr, int sc, int er, int ec);

private:
  std::stack<Coord> m_pathStack;
  bool m_debug = false;

  void clearStack();
};

MazeDepthSearch::MazeDepthSearch()  {
  m_pathStack = std::stack<Coord>();
}

MazeDepthSearch::MazeDepthSearch(const bool debug) : m_debug(debug) {
  m_pathStack = std::stack<Coord>();
}

void MazeDepthSearch::clearStack() {
  while (!m_pathStack.empty()) {
    m_pathStack.pop();
  }
}

bool MazeDepthSearch::pathExists(std::string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
  // Return true if there is a path from (sr,sc) to (er,ec)
  // through the maze; return false otherwise

  // set starting point and destination point
  // push starting point on stack
  m_pathStack.push(Coord(sr, sc));

  // step loop while stack not empty
  while (!m_pathStack.empty()) {
    // current = pop stack // depth search
    Coord current = m_pathStack.top();
    m_pathStack.pop();

    if (m_debug) {
      std::cout << "Checking (" << std::to_string(current.r()) << "," + std::to_string(current.c()) << ")" << std::endl;
    }

    // Check if current square is destination
    if (current.r() == er && current.c() == ec) {
      // if is .. return true
      if (m_debug) {
        std::cout << "Destination reached!" << std::endl;
      }

      // clear stack
      clearStack();

      return true;
    }

    // if not ..
    // Mark visited on maze

    maze[current.r()][current.c()] = 'X';
  
    // check each direction, west, south, east, north
    // if direction has not yet been marked or isn't a wall ...
    // push on stack
    if (maze[current.r()][current.c()-1] != 'X') {
      m_pathStack.push(Coord(current.r(), current.c()-1));
    }
    if (maze[current.r()+1][current.c()] != 'X') {
      m_pathStack.push(Coord(current.r()+1, current.c()));
    }
    if (maze[current.r()][current.c()+1] != 'X') {
      m_pathStack.push(Coord(current.r(), current.c()+1));
    }
    if (maze[current.r()-1][current.c()] != 'X') {
      m_pathStack.push(Coord(current.r()-1, current.c()));
    }

    if (m_debug) {
        // print maze
        for (int i = 0; i < nRows; i++) {
          std::cout << maze[i] << std::endl;
        }
    }
    // end step loop
  }
  
  if (m_debug) {
    std::cout << "No path found." << std::endl;
  }

  // clear stack
  clearStack();
  
  return false;
};

#endif