#include "chess.h"
#include "figures.h"
#include <stdio.h>
void display()
{
  char** primeraLinea = repeatH(join(whiteSquare, reverse(whiteSquare)), 4);
  char** segundaLinea = repeatH(join(reverse(whiteSquare), whiteSquare), 4);
  
  char** dosLineasUnidas = up(primeraLinea, segundaLinea);

  char** tablero=repeatV(dosLineasUnidas,4);
  interpreter(tablero);
}

