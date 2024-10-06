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

  char** ude4[2];
  
  /*
  while(p<2)
  {
    ude4[p]=join(*(uniones),*(uniones+1));
    *uniones+=2;
    p++; 
  }*/
  
  char** mitad1 = join(uniones[1],uniones[2]);

  char** result1 = superImpose(pawn, whiteSquare);
  char** result2 = superImpose(pawn, blackSquare);
  char** filapeones = repeatH(join(result1, result2), 4);
  
  /*
  char** equipoBlanco = up(unionFinal, filapeones);
  char** lineasunidas = up(primeraLinea,segundaLinea);*/
  //char** resultado = up(equipoBlanco,lineasunidas);
  interpreter(mitad1);
  
  int i=0;
  while (mitad1[i]!=0)
  {
    free(mitad1[i]);
    i++;
  }
  free(mitad1);
}

