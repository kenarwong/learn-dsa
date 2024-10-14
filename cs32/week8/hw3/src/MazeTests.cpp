#include "headers.h"
#include "maze.h"

void MazeTests() {
  std::cout << "Depth search" << std::endl;

  std::string maze[10] = {
      "XXXXXXXXXX",
      "X.X..X...X",
      "X....XXX.X",
      "X.XXXX.X.X",
      "X......XXX",
      "X.XX.X...X",
      "X.X..X.X.X",
      "X.X.XXXX.X",
      "X.X...X..X",
      "XXXXXXXXXX"
  };


  if (pathExists(maze, 10,10, 4,6, 1,1)) {
    std::cout << "Solvable!" << std::endl;
  } else {
    std::cout << "Out of luck!" << std::endl;
  }
  
  // First 12
  // (4,6)
  // (5,6)
  // (5,7)
  // (5,8)
  // (6,8)
  // (7,8)
  // (8,8)
  // (8,7)
  // (6,6)
  // (4,5)
  // (4,4)
  // (5,4)
}