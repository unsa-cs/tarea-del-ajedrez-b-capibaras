#include "chess.h"
#include "figures.h"
#include <stdio.h>
#include <cstdlib>
void display()
{
  
  char** segundaLinea = repeatH(join(whiteSquare, reverse(whiteSquare)), 4);
  char** primeraLinea = repeatH(join(reverse(whiteSquare), whiteSquare), 4);
  /*
  char** dosLineasUnidas = up(primeraLinea, segundaLinea);
  
  char** tablero=repeatV(dosLineasUnidas,2);
  */
  char** blackSquare=reverse(whiteSquare);
  //
  char** c_torre=superImpose(rook,blackSquare);
  char** c_caballo=superImpose(knight,whiteSquare);
  char** c_alfil = superImpose(bishop, blackSquare);
  char** c_dama = superImpose(queen, whiteSquare);
  char** c_rey = superImpose(king, blackSquare);
  char** c_alfil2 = superImpose(bishop, whiteSquare);
  char** c_caballo2 = superImpose(knight,blackSquare);
  char** c_torre2=superImpose(rook,whiteSquare);
  //
  char** fic_cas[8]={c_torre,c_caballo,c_alfil,c_dama,c_rey,c_alfil2,c_caballo2,c_torre2};
  char** uniones[4];
  int p=0;
  while(p<4)
  {
    uniones[p]=join(*(fic_cas),*(fic_cas+1));
    *fic_cas+=2;
    p++;
  }
  char** unirAlfilDama = join(c_alfil, c_dama);
  char** unidos=join(c_torre,c_caballo);
  char** unirReyAlfil=join(c_rey,c_alfil2);
  char** unirCaballo2Torre2=join(c_caballo2,c_torre2);
  char** unidos2 = join(unidos, unirAlfilDama);
  char** unidos3=join(unirReyAlfil,unirCaballo2Torre2);
  char** unionFinal=join(unidos2, unidos3);
  
  char** result1 = superImpose(pawn, whiteSquare);
  char** result2 = superImpose(pawn, blackSquare);
  char** filapeones = repeatH(join(result1, result2), 4);

  char** equipoBlanco = up(unionFinal, filapeones);
  char** lineasunidas = up(primeraLinea,segundaLinea);
  char** resultado = up(equipoBlanco,lineasunidas);
  interpreter(uniones[0]);
  
  int i=0;
  while (unionFinal[i]!=0)
  {
    free(unionFinal[i]);
    i++;
  }
  free(unionFinal);
}

