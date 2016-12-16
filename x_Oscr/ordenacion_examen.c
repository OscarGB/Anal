/**
 *
 * Descripcion: Implementacion de funciones de ordenacion durante el examen 
 *
 * Fichero: ordenacion_examen.c
 * Autor: Óscar Gómez, Jose Ignacio Gómez
 * Version: 1.0
 * Fecha: 30-09-2016
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ordenacion.h"
#include "ordenacion_examen.h"
#include "permutaciones.h"

/***************************************************/
/* Funcion: Partir_examen   Fecha: 04/11/2016      */
/* Función privada de QuickSort                    */
/*                                                 */
/***************************************************/
int Partir_examen(int* tabla, int ip, int iu,int *pos){
  int contador = 0;
  int k, i;
   
	*pos = ip;
  k = tabla[*pos];
  swap(&tabla[ip], &tabla[*pos]);
  *pos = ip;
  for(i = ip + 1; i<= iu; i++){
    if(tabla[i] < k){
      (*(pos))++;
      swap(&tabla[i], &tabla[*pos]);
    }
    contador++;
  }
  swap(&tabla[ip], &tabla[*pos]);
  return contador;
}

/***************************************************/
/* Funcion: InsertQuickSort  Fecha: 16/12/2016     */
/* Función de ordenacion para tablas de menor a    */
/* mayor                                           */
/***************************************************/
int InsertQuickSort(int* tabla, int ip, int iu, int L){
  int m;
  int contador = 0;
  if(ip > iu){
    return ERR;
  }
  if(ip == iu){
    return OK;
  }
	if((iu - ip) > L){
		contador += Partir_examen(tabla, ip, iu, &m);
		if(ip < (m - 1)){
			contador += InsertQuickSort(tabla, ip, m-1, L);
		}
		if((m + 1) < iu){
			contador += InsertQuickSort(tabla, m+1, iu, L);
		}
	}
	else {
		contador += InsertSort(tabla, ip, iu);
	}
  return contador;
}

/***************************************************/
/* Funcion: InsertQuickSort100 Fecha: 16/12/2016   */
/* Función de ordenacion para tablas de menor a    */
/* mayor                                           */
/***************************************************/
int InsertQuickSort100(int* tabla, int ip, int iu){
	return InsertQuickSort(tabla, ip, iu, 100);
}

/***************************************************/
/* Funcion: InsertQuickSort200 Fecha: 16/12/2016   */
/* Función de ordenacion para tablas de menor a    */
/* mayor                                           */
/***************************************************/
int InsertQuickSort200(int* tabla, int ip, int iu){
	return InsertQuickSort(tabla, ip, iu, 200);
}

/***************************************************/
/* Funcion: InsertQuickSort300 Fecha: 16/12/2016   */
/* Función de ordenacion para tablas de menor a    */
/* mayor                                           */
/***************************************************/
int InsertQuickSort300(int* tabla, int ip, int iu){
	return InsertQuickSort(tabla, ip, iu, 300);
}

/***************************************************/
/* Funcion: InsertQuickSort400 Fecha: 16/12/2016   */
/* Función de ordenacion para tablas de menor a    */
/* mayor                                           */
/***************************************************/
int InsertQuickSort400(int* tabla, int ip, int iu){
	return InsertQuickSort(tabla, ip, iu, 400);
}
