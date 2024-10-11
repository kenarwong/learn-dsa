#include "headers.h"

void printInstruction(char src, char dest) {
  std::cout << "Move top disk from pole " << src << " to " << dest << std::endl;
}

void solveTowers(int n, char src, char dest, char spare, int& moveCount) {
  if (n == 1) {
    printInstruction(src, dest);
    moveCount++;
    return;
  }

  solveTowers(n-1,src,spare,dest, moveCount);  // Swap destination and spare
  solveTowers(1,src,dest,spare, moveCount);    // Execute base case
  solveTowers(n-1,spare,dest,src, moveCount);  // Reverse step 1 

}

void TowersOfHanoi(int numberOfDisks) {
  std::cout << "Towers of Hanoi" << std::endl;

  std::cout << "Using " << numberOfDisks << " disks" << std::endl;

  int moveCount = 0;
  solveTowers(numberOfDisks,'A','B','C', moveCount);
  
  std::cout << "Solved using " << moveCount << " moves!" << std::endl;
}