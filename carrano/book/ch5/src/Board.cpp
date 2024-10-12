#include "Board.h"
#include "headers.h"

using namespace std;

int Board::indexToColumn(int index) {
  return (index + startColumn) % BOARD_SIZE;
}

bool Board::isQueen(int inRow, int inCol) const {
  for (Queen *queenPtr : queens) {
    if (queenPtr->getRow() == inRow && queenPtr->getCol() == inCol) {
      return true;
    }
  }

  return false;
}

bool Board::placeQueens(Queen *queenPtr) {
  // Base case
  if(getNumQueens() == BOARD_SIZE) {
    return true;
  }

  // try to set a queen
  setQueen(queenPtr);

  // check all rows
  int row = 0;
  while(row < BOARD_SIZE) {
    // check if valid
    if (!queenPtr->isUnderAttack()) {
      // if valid attempt next recursiion

      // calculate next column
      // need to get next column (+1), which is 0-based
      // getNumOfQueens() returns size with is 1-based
      int col = indexToColumn(getNumQueens()); 

      // calculate empty row
      // use 0 for now

      // try recursive call for next queen
      if(placeQueens(new Queen(0, col))) {
        return true;
      }
    }

    //move to next row
    queenPtr->nextRow();

    row++;
  }

  // If all rows were exhausted
  removeQueen();

  // Backtrack
  return false;
}

void Board::removeQueen() {
  queens.pop_back();
}

void Board::setQueen(Queen *queenPtr) {
  queens.push_back(queenPtr);
}

Board::Board() {
  queens.clear();
}

Board::~Board() {
  for (Queen *queenPtr : queens) {
    delete queenPtr;
  }
}

void Board::clear() {
  queens.clear();
}

void Board::display() const {
  for (int n = 0; n < BOARD_SIZE; n++) {
    for (int m = 0; m < BOARD_SIZE; m++) {
      if (isQueen(n, m)) {
        cout << "Q ";
      } else {
        cout << ". ";
      }
    }
    cout << endl;
  }
}

void Board::doEightQueens() {
  clear();

  int firstRow = rand() % BOARD_SIZE;
  int firstCol = rand() % BOARD_SIZE;
  startColumn = firstCol;

  // Place first queen
  placeQueens(new Queen(firstRow, firstCol));
}

int Board::getNumQueens() const {
  return queens.size();
}

const Queen *Board::getQueen(int index) const {
  return queens[index];
}