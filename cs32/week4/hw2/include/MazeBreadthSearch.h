#ifndef MAZE_BREADTH_SEARCH_H
#define MAZE_BREADTH_SEARCH_H

#include "headers.h"
#include <queue>
#include "Coord.h"

class MazeBreadthSearch {
public:
  MazeBreadthSearch();
  MazeBreadthSearch(const bool debug);
  bool pathExists(std::string maze[], int nRows, int nCols, int sr, int sc, int er, int ec);

private:
  std::queue<Coord> m_pathQueue;
  bool m_debug = false;

  void clearQueue();
};

MazeBreadthSearch::MazeBreadthSearch()  {
  m_pathQueue = std::queue<Coord>();
}

MazeBreadthSearch::MazeBreadthSearch(const bool debug) : m_debug(debug) {
  m_pathQueue = std::queue<Coord>();
}

void MazeBreadthSearch::clearQueue() {
  while (!m_pathQueue.empty()) {
    m_pathQueue.pop();
  }
}

bool MazeBreadthSearch::pathExists(std::string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
  // Return true if there is a path from (sr,sc) to (er,ec)
  // through the maze; return false otherwise

  // set starting point and destination point
  // push starting point on queue
  m_pathQueue.push(Coord(sr, sc));

  // step loop while queue not empty
  while (!m_pathQueue.empty()) {
    // current = pop queue // breadth search
    Coord current = m_pathQueue.front();
    m_pathQueue.pop();

    if (m_debug) {
      std::cout << "Checking (" << std::to_string(current.r()) << "," + std::to_string(current.c()) << ")" << std::endl;
    }

    // Check if current square is destination
    if (current.r() == er && current.c() == ec) {
      // if is .. return true
      if (m_debug) {
        std::cout << "Destination reached!" << std::endl;
      }

      // clear queue
      clearQueue();

      return true;
    }

    // if not ..
    // Mark visited on maze

    maze[current.r()][current.c()] = 'X';
  
    // check each direction, west, south, east, north
    // if direction has not yet been marked or isn't a wall ...
    // push on queue
    if (maze[current.r()][current.c()-1] != 'X') {
      m_pathQueue.push(Coord(current.r(), current.c()-1));
    }
    if (maze[current.r()+1][current.c()] != 'X') {
      m_pathQueue.push(Coord(current.r()+1, current.c()));
    }
    if (maze[current.r()][current.c()+1] != 'X') {
      m_pathQueue.push(Coord(current.r(), current.c()+1));
    }
    if (maze[current.r()-1][current.c()] != 'X') {
      m_pathQueue.push(Coord(current.r()-1, current.c()));
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

  // clear queue
  clearQueue();
  
  return false;
};

#endif