#include "chess.h"
#include "figures.h"
#include <stdio.h>
void display()
{
  char** segundaLinea = repeatH(join(whiteSquare, reverse(whiteSquare)), 4);
  char** primeraLinea = repeatH(join(reverse(whiteSquare), whiteSquare), 4);
  
  char** dosLineasUnidas = up(primeraLinea, segundaLinea);
  
  char** tablero=repeatV(dosLineasUnidas,2);
  char** a=superImpose(rook,tablero);
  char** c_torre=superImpose(rook,whiteSquare);
  interpreter(c_torre);
}

