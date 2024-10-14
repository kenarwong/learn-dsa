#include "headers.h"
#include "maze.h"

bool pathExists(std::string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
  std::cout << "(" << sr << "," << sc << ")" << std::endl;;

  // if dest, return true
  if (sr == er && sc == ec) {
    return true;
  }

  // mark current location
  maze[sr][sc] = 'X';

  // check each direction
  // if ".", then recursive call
  if (maze[sr][sc + 1] == '.')
  {
    bool exists = pathExists(maze, nRows, nCols, sr, sc + 1, er, ec);

    // if path found stop checking
    if (exists)
    {
      return true;
    }
  }

  // if ".", then recursive call
  if (maze[sr + 1][sc] == '.')
  {
    bool exists = pathExists(maze, nRows, nCols, sr + 1, sc, er, ec);

    // if path found stop checking
    if (exists)
    {
      return true;
    }
  }

  // if ".", then recursive call
  if (maze[sr][sc - 1] == '.')
  {
    bool exists = pathExists(maze, nRows, nCols, sr, sc - 1, er, ec);

    // if path found stop checking
    if (exists)
    {
      return true;
    }
  }

  // if ".", then recursive call
  if (maze[sr - 1][sc] == '.')
  {
    bool exists = pathExists(maze, nRows, nCols, sr - 1, sc, er, ec);

    // if path found stop checking
    if (exists)
    {
      return true;
    }
  }

  // No more paths to check
  return false;
}

void Problem3() {
  std::cout << "Problem 3" << std::endl;

  MazeTests();
}
