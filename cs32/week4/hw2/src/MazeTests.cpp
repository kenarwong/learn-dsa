#include "headers.h"
#include "MazeDepthSearch.h"
#include "MazeBreadthSearch.h"
#include "MazeTests.h"

void MazeTests() {
  std::cout << "Depth search" << std::endl;

  std::string maze1[10] = {
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

  //MazeDepthSearch mds(true);
  MazeDepthSearch mds(false);

  if (mds.pathExists(maze1, 10,10, 4,6, 1,1)) {
    std::cout << "Solvable!" << std::endl;
  } else {
    std::cout << "Out of luck!" << std::endl;
  }

// First 12
// (4,6)
// (3,6)
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

  std::cout << "Breadth search" << std::endl;

  std::string maze2[10] = {
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

  //MazeBreadthSearch mbs(true);
  MazeBreadthSearch mbs(false);

  if (mbs.pathExists(maze2, 10,10, 4,6, 1,1)) {
    std::cout << "Solvable!" << std::endl;
  } else {
    std::cout << "Out of luck!" << std::endl;
  }
  
  // First 12
  // (4,6)
  // (4,5)
  // (5,6)
  // (3,6)
  // (4,4)
  // (6,6)
  // (5,7)
  // (4,3)
  // (5,4)
  // (5,8)
  // (4,2)
  // (6,4)
}