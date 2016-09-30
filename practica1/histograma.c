#include <stdio.h>
#include <stdlib.h>
#include "permutaciones.h"

#define TAMANIO 10000
#define NUMEROS 20

int main(){
	FILE *f = NULL;
	int tabla[NUMEROS];
	int i;

	for(i=0; i<NUMEROS; i++){
		tabla[i] = 0;
	}

	for(i=0; i<TAMANIO; i++){
		tabla[aleat_num(1, NUMEROS) - 1]++;
	}

	f = fopen("histograma.txt", "w");
	if(!f){
		return -1;
	}

	for(i=0; i<NUMEROS; i++){
		fprintf(f, "%d \t %d\n",i+1, tabla[i]);
	}
	fclose(f);

	return 0;

}