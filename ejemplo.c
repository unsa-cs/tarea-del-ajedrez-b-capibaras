#include "chess.h"
#include "figures.h"
#include <stdio.h>
void display()
{
  char** segundaLinea = repeatH(join(whiteSquare, reverse(whiteSquare)), 4);
  char** primeraLinea = repeatH(join(reverse(whiteSquare), whiteSquare), 4);
  
  char** dosLineasUnidas = up(primeraLinea, segundaLinea);
  
  char** tablero=repeatV(dosLineasUnidas,2);

  char** blackSquare=reverse(whiteSquare);

  //
  char** c_torre=superImpose(rook,blackSquare);
  char** c_caballo=superImpose(knight,whiteSquare);
  char** c_alfil = superImpose(bishop, blackSquare);
  char** c_dama = superImpose(queen, whiteSquare);
  char** c_rey = superImpose(king, blackSquare);

  //
  char** unirAlfilDama = join(c_alfil, c_dama);
  char** unidos=join(c_torre,c_caballo);

  char** unionFinal = join(unidos, unirAlfilDama);
  interpreter(unionFinal);
}

