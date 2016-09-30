/**
 *
 * Descripcion: Implementacion de funciones de generacion de permutaciones
 *
 * Fichero: permutaciones.c
 * Autores: Óscar Gómez, Jose Ignacio Gómez
 * Version: 1.0
 * Fecha: 23-09-2016
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "permutaciones.h"

/*Funciones privadas*/

/***************************************************/
/* Funcion: swap	    Fecha: 23/09/2016          */
/* Autores: Óscar Gómez, Jose Ignacio Gómez        */
/*                                                 */
/* Rutina que intercambia el contenido de dos      */
/* posiciones de un Array                          */
/*                         						   */
/* Entrada:                                        */
/* int n: Numero de elementos de la permutación    */
/*                                                 */
/* Salida:                                         */
/* int *: puntero a un array de enteros            */
/* que contiene a la permutacion                   */
/* o NULL en caso de error                         */
/***************************************************/

int swap(int* a, int* b){
	int aux;

	if(!a || !b){
		return ERR;
	}

	aux = *(a);
	*(a) = *(b);
	*(b) = aux;

	return OK;
}

/***************************************************/
/* Funcion: aleat_num Fecha: 23/09/2016            */
/* Autores: Óscar Gómez, Jose Ignacio Gómez        */
/*                                                 */
/* Rutina que genera un numero aleatorio           */
/* entre dos numeros dados                         */
/*                                                 */
/* Entrada:                                        */
/* int inf: limite inferior                        */
/* int sup: limite superior                        */
/* Salida:                                         */
/* int: numero aleatorio                           */
/***************************************************/
int aleat_num(int inf, int sup){
	float random;

	if(inf < 0 || sup < 0 || sup < inf){
		fprintf(stderr, "Error en la entrada de argumentos a aleat_num");
		return -1; /*ERROR*/
	}

	random = rand();
	random /= RAND_MAX;
	random *= (sup-inf+1);
	random += inf;
	if(random > sup){
		random = sup;
	}
	return (int)random;
}

/***************************************************/
/* Funcion: genera_perm Fecha: 23/09/2016          */
/* Autores: Óscar Gómez, Jose Ignacio Gómez        */
/*                                                 */
/* Rutina que genera una permutacion aleatoria     */
/*                                                 */
/* Entrada:                                        */
/* int n: Numero de elementos de la permutación    */
/*                                                 */
/* Salida:                                         */
/* int *: puntero a un array de enteros            */
/* que contiene a la permutacion                   */
/* o NULL en caso de error                         */
/***************************************************/
int* genera_perm(int n){
	int i, random, aux;
	int* perm = NULL;;

	if(n<1){
		fprintf(stderr, "Error de entrada de argumentos de genera_perm");
		return NULL;
	}

	perm = (int *)malloc(n * sizeof(int));
	if(!perm){
		return NULL;
	}

	for(i = 0; i < n; i++){
		perm[i] = i;
	}

	for(i = 0; i < n-1; i++){ /*Llegamos hasta n-1 porque la última posición
							del array solo se puede permutar consigo misma*/
		random= aleat_num(i+1, n-1);
		if(swap(&(perm[i]), &(perm[random])) == ERR){
			fprintf(stderr, "PENEEEEE");
			free(perm);
			return NULL;
		}
	}

	return perm;
}

/***************************************************/
/* Funcion: genera_permutaciones Fecha:            */
/* Autores: Óscar Gómez, Jose Ignacio Gómez        */
/*                                                 */
/* Funcion que genera n_perms permutaciones        */
/* aleatorias de tamanio elementos                 */
/*                                                 */
/* Entrada:                                        */
/* int n_perms: Numero de permutaciones            */
/* int tamanio: Numero de elementos de cada        */
/* permutacion                                     */
/* Salida:                                         */
/* int**: Array de punteros a enteros              */
/* que apuntan a cada una de las                   */
/* permutaciones                                   */
/* NULL en caso de error                           */
/***************************************************/
int** genera_permutaciones(int n_perms, int tamanio)
{
/* vuestro codigo */
	return NULL;
}
