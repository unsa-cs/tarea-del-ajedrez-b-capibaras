#include "chess.h"
#include "figures.h"
#include <stdio.h>
void display()
{
  char** blackSquare = reverse(whiteSquare);
  char** result = repeatH(join(whiteSquare, blackSquare), 4);
  interpreter(result);
}

