/**
 *
 * Descripcion: Implementacion de funciones de ordenacion 
 *
 * Fichero: ordenacion.c
 * Autor: Óscar Gómez, Jose Ignacio Gómez
 * Version: 1.0
 * Fecha: 30-09-2016
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ordenacion.h"

/***************************************************/
/* Funcion: InsertSort    Fecha: 30/09/2016        */
/* Función de ordenacion para tablas de menor a    */
/* mayor                                           */
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
/* Funcion: InsertSortInv    Fecha:   30/09/2016   */
/* Función de ordenacion para tablas de mayor a    */
/* menor                                           */
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

/***************************************************/
/* Funcion: Merge    Fecha: 21/10/2016             */
/* Función privada de MergeSort                    */
/*                                                 */
/***************************************************/
int Merge(int* tabla, int ip, int iu, int imedio){
  int* tablaaux = NULL;
  int ob = 0;
  int i,j,k;

  i = ip;
  j = imedio + 1;
  k = 0; /*Primera posición de nuestro array auxiliar*/

  tablaaux = (int *)malloc(sizeof(int) * (iu - ip + 1)); /*Reserva memoria para los elementos necesarios*/
  if(tablaaux == NULL){
    return ERR;
  }

  while(i <= imedio && j <= iu){
    ob++;

    if(tabla[i] < tabla[j]){
      tablaaux[k] = tabla[i];
      i++;
    }
    else{
      tablaaux[k] = tabla[j];
      j++;
    }
    k++;
  }

  if(i > imedio){
    while(j <= iu){
      tablaaux[k] = tabla[j];
      j++;
      k++;
    }   
  }
  else if(j > iu){
    while(i <= imedio){
      tablaaux[k] = tabla[i];
      i++;
      k++;
    }  
  }

  k = 0; /*Primera posición de nuestro array auxiliar*/
  for(i = ip; i <= iu; i++, k++){
    tabla[i] = tablaaux[k];
  }

  free(tablaaux);
  return ob;
} 


/***************************************************/
/* Funcion: MergeSort    Fecha: 21/10/2016         */
/* Función de ordenacion para tablas de menor a    */
/* mayor                                           */
/***************************************************/
int MergeSort(int* tabla, int ip, int iu){
  int ob = 0;
  int aux;
  int m;

  if(tabla == NULL){
    fprintf(stderr, "Tabla vacia\n");
    return ERR;
  }

  if(ip > iu){
    return ERR;
  }
  if(ip == iu){
    return OK;
  }

  m = (ip + iu)/2;

  aux = MergeSort(tabla, ip, m); /*Tabla superior*/
  if(aux == ERR){
    return ERR;
  }

  aux = MergeSort(tabla, m+1, iu); /*Tabla inferior*/
  if(aux == ERR){
    return ERR;
  }

 

  aux = Merge(tabla, ip, iu, m); /*Unión de tablas*/
  if(aux == ERR){
    return ERR;
  }
  ob = ob + aux; /*Contador de operaciones básicas*/

  return ob;
}