#include "chess.h"
#include "figures.h"
#include <stdio.h>
void display(){
  char** result= repeatH(whiteSquare,4);
  interpreter(result);
}

