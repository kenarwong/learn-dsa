#include "Queen.h"
#include "Board.h"
#include "headers.h"

using namespace std;

Queen::Queen() : row(0), col(0) {}

Queen::Queen(int inRow, int inCol) : row(inRow), col(inCol) {}

int Queen::getCol() const {
  return col;
}

int Queen::getRow() const {
  return row;
}

void Queen::nextRow() {
  row++;
}

bool Queen::isUnderAttack() const {
  // 1-based
  int n = boardPtr->getNumQueens();

  // Check all prior queens 
  // n-2 because changing to 0-based and checking all prior queens
  for (int qi = n-2; qi >= 0 ; qi--) {
    const Queen* q = boardPtr->getQueen(qi);

    // check if same row
    if (q->getRow() == this->getRow()) {
      return true;
    }

    // check each diagonal line
    for (int diag = 0; diag < 4; diag++) {
      int i = q->getRow();
      int j = q->getCol();

      // stay within board bounds
      while (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE) {
        switch (diag) {
          case 0: // upper-left
            i--; j--;
            break;
          case 1: // upper-right
            i++; j--;
            break;
          case 2: // lower-left
            i--; j++;
            break;
          case 3: // lower-right
            i++; j++;
            break;
        }

        if (i == this->getRow() && j == this->getCol()) {
          return true;
        }
      }
    }
  }

  return false;
}

const Board* Queen::boardPtr = nullptr;

/** Saves a pointer to the board for all queens. */
void Queen::setBoard(const Board *bPtr) {
  boardPtr = bPtr;
}
