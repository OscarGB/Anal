/**
 *
 * Descripcion: Implementacion de funciones de ordenacion 
 *
 * Fichero: ordenacion.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2016
 *
 */


#include "ordenacion.h"

/***************************************************/
/* Funcion: InsertSort    Fecha:                   */
/* Vuestro comentario                              */
/***************************************************/
int InsertSort(int* tabla, int ip, int iu)
{
  	int time = 0;
  	int i, j, aux;

  	for (i = ip + 1; i <= iu; i++) {
  		aux = tabla[i];

  		j = i-1;
  		while (j >= ip && tabla[j] > aux){
  			tabla[j+1] = tabla[j];
  			j--;
  			time++;
  		} 
  		time++;

  		tabla[j+1] = aux;
  	}

	return time;
}

/***************************************************/
/* Funcion: InsertSortInv    Fecha:                   */
/* Vuestro comentario                              */
/***************************************************/
int InsertSortInv(int* tabla, int ip, int iu)
{
  int time = 0;
    int i, j, aux;

    for (i = ip + 1; i <= iu; i++) {
      aux = tabla[i];

      j = i-1;
      while (j >= ip && tabla[j] < aux){
        tabla[j+1] = tabla[j];
        j--;
        time++;
      } 
      time++;

      tabla[j+1] = aux;
    }

  return time;
}

