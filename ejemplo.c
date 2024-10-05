#include "chess.h"
#include "figures.h"
#include <stdio.h>
void display()
{
  char** result = repeatH(join(reverse(whiteSquare), whiteSquare), 4);
  char** tablero=repeatV(result,8);
  interpreter(tablero);
}

