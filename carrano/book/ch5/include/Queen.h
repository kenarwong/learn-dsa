#ifndef QUEEN_H
#define QUEEN_H

class Board; // Forward declaration of Board class

/** The Queen class. */
class Queen
{
public:
  /** Places a queen in upper-left corner of board. */
  Queen();

  /** Places a queen in supplied location. */
  Queen(int inRow, int inCol);

  /** @return Column number. */
  int getCol() const;

  /** @return Row number. */
  int getRow() const;

  /** Moves queen to next row. */
  void nextRow();

  /** Sees whether the queen is under attack by another queen.
  @return True if another queen is in the same row or the same
  diagonal; otherwise, returns false. */
  bool isUnderAttack() const;

  /** Saves a pointer to the board for all queens. */
  static void setBoard(const Board *bPtr);

private:
  int row; // Row (or prospective row) of queen if it is on the board
  int col; // Column (or prospective column) of queen if it is on the board
  // All queens share the same board
  static const Board *boardPtr;
}; // end Queen

#endif