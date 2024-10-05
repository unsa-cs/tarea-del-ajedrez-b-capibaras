#include "chess.h"
#include "figures.h"
#include <stdio.h>
void display()
{
  char** result = repeatH(join(reverse(whiteSquare), whiteSquare), 4);
  interpreter(result);
}

