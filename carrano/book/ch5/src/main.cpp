#include "headers.h"
#include "Board.h"
#include "Queen.h"

using namespace std;

int main()
{
  srand(time(NULL));

  Board b = Board();
  Queen::setBoard(&b);

  b.doEightQueens();
  b.display();
  
  return 0;
} // end main