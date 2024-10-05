#include "chess.h"
#include "figures.h"
#include <stdio.h>
void display()
{
  char** blackSquare= reverse(whiteSquare);
  char** result= repeatH(blackSquare,4);
  interpreter(result);
}

