#include "chess.h"
#include "figures.h"
#include <stdio.h>
#include <cstdlib>
void display()
{
  
  char** segundaLinea = repeatH(join(whiteSquare, reverse(whiteSquare)), 4);
  char** primeraLinea = repeatH(join(reverse(whiteSquare), whiteSquare), 4);
  
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

  char** c_torreN = superImpose(reverse(rook), whiteSquare);
  char** c_caballoN = superImpose(reverse(knight), blackSquare);
  char** c_alfilN = superImpose(reverse(bishop), whiteSquare);
  char** c_damaN = superImpose(reverse(queen), blackSquare);
  char** c_reyN = superImpose(reverse(king), whiteSquare);
  char** c_alfil2N = superImpose(reverse(bishop), blackSquare);
  char** c_caballo2N = superImpose(reverse(knight), whiteSquare);
  char** c_torre2N = superImpose(reverse(rook), blackSquare);

  char** torreCaballo = join(c_torre, c_caballo);
  char** alfilDama = join(c_alfil, c_dama);
  char** reyAlfil2 = join(c_rey, c_alfil2);
  char** caballo2Torre2 = join(c_caballo2, c_torre2);

  char** torreCaballoN = join(c_torreN, c_caballoN);
  char** alfilDamaN = join(c_alfilN, c_damaN);
  char** reyAlfil2N = join(c_reyN, c_alfil2N);
  char** caballo2Torre2N = join(c_caballo2N, c_torre2N);

  char** medioEquipoB1 = join(torreCaballo, alfilDama);
  char** medioEquipoB2 = join(reyAlfil2, caballo2Torre2);

  char** medioEquipoN1 = join(torreCaballoN, alfilDamaN);
  char** medioEquipoN2 = join(reyAlfil2N, caballo2Torre2N);

  char** equipoBlanco = join(medioEquipoB1, medioEquipoB2);
  char** equipoNegro = join(medioEquipoN1, medioEquipoN2);
  //
  char** result1B = superImpose(pawn, whiteSquare);
  char** result2B = superImpose(pawn, blackSquare);

  char** result1N = superImpose(reverse(pawn), blackSquare);
  char** result2N = superImpose(reverse(pawn), whiteSquare);

  char** filapeones = repeatH(join(result1B, result2B), 4);
  char** filapeonesN = repeatH(join(result1N, result2N), 4);
  
  char** equipoBlancoCompleto = up(equipoBlanco, filapeones);
  char** equipoNegroCompleto = up(filapeonesN, equipoNegro);
  
  char** lineasunidas = up(primeraLinea,segundaLinea);
  char** lineasunidas2 = up(lineasunidas, lineasunidas);
  char** resultado = up(equipoBlancoCompleto,lineasunidas2);
  char** resultadoFinal = up(resultado, equipoNegroCompleto);

  interpreter(resultadoFinal);
  
  int i=0;
  while (equipoBlancoCompleto [i] != 0)
  {
    free(equipoBlancoCompleto [i]);
    i++;
  }
  free(equipoBlancoCompleto);
}

