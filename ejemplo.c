#include "chess.h"
#include "figures.h"
#include <stdio.h>
#include <cstdlib>
void display()
{
  char** segundaLinea = repeatH(join(whiteSquare, reverse(whiteSquare)), 4);
  char** primeraLinea = repeatH(join(reverse(whiteSquare), whiteSquare), 4);
  
  char** dosLineasUnidas = up(primeraLinea, segundaLinea);
  
  char** tablero=repeatV(dosLineasUnidas,2);

  char** blackSquare=reverse(whiteSquare);

  //
  char** c_torre=superImpose(reverse(rook),blackSquare);
  char** c_caballo=superImpose(reverse(knight),whiteSquare);
  char** c_alfil = superImpose(reverse(bishop), blackSquare);
  char** c_dama = superImpose(reverse(queen), whiteSquare);
  char** c_rey = superImpose(reverse(king), blackSquare);
  char** c_alfil2 = superImpose(reverse(bishop), whiteSquare);
  char** c_caballo2 = superImpose(reverse(knight),blackSquare);
  char** c_torre2=superImpose(reverse(rook),whiteSquare);
  //
  char** unirAlfilDama = join(c_alfil, c_dama);
  char** unidos=join(c_torre,c_caballo);
  char** unirReyAlfil=join(c_rey,c_alfil2);
  char** unirCaballo2Torre2=join(c_caballo2,c_torre2);
  char** unidos2 = join(unidos, unirAlfilDama);
  char** unidos3=join(unirReyAlfil,unirCaballo2Torre2);
  char** unionFinal=join(unidos2, unidos3);
  interpreter(unionFinal);
  
  int i=0;
  while (unionFinal[i]!=0)
  {
    free(unionFinal[i]);
    i++;
  }
  free(unionFinal);
}

