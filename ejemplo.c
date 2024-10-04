#include "chess.h"
#include "figures.h"
#include <stdio.h>

void flipV1(char** var1){
	
    for(int i = 0; *(*var1 + i) != 0; i++)
	for(int j = 0; var1[i][j] != '\0'; j++){
		printf("%s", var1[i][j]);
	}

}

int main(){

    flipV1(whiteSquare);	

    return 0;
}
