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
#include "permutaciones.h"

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
  ob += aux;

  aux = MergeSort(tabla, m+1, iu); /*Tabla inferior*/
  if(aux == ERR){
    return ERR;
  }

  ob += aux;

 

  aux = Merge(tabla, ip, iu, m); /*Unión de tablas*/
  if(aux == ERR){
    return ERR;
  }

  ob += aux; /*Contador de operaciones básicas*/

  return ob;
}


/***************************************************/
/* Funcion: Medio    Fecha: 04/11/2016             */
/* Función privada de QuickSort                    */
/*                                                 */
/***************************************************/
int Medio(int *tabla, int ip, int iu,int *pos){
  *pos = ip;
  return 0;
}


/***************************************************/
/* Funcion: MedioAvg Fecha: 04/11/2016             */
/* Función privada de QuickSort                    */
/*                                                 */
/***************************************************/
int MedioAvg(int *tabla, int ip, int iu, int *pos){
  *pos = (int)(ip + iu) / 2;
  return 0;
}

/***************************************************/
/* Funcion: MedioStat Fecha: 04/11/2016            */
/* Función privada de QuickSort                    */
/*                                                 */
/***************************************************/
int MedioStat(int *tabla, int ip, int iu, int *pos){
  int medio;
  medio = (int)(ip + iu) / 2;

  if(tabla[ip] > tabla[medio]){
    if(tabla[ip] > tabla[iu]){
      if(tabla[medio] > tabla[iu]){
        *pos = medio;
        return 3; /*Por las comparaciones*/
      }
      else{
        *pos = iu;
        return 3; /*Por las comparaciones*/
      }
    }
    else{
      *pos = ip;
      return 2; /*Por las comparaciones*/
    }
  }
  else{
    if(tabla[ip] < tabla[iu]){
      if(tabla[medio] < tabla[iu]){
        *pos = medio;
        return 3; /*Por las comparaciones*/
      }
      else{
        *pos = iu;
        return 3; /*Por las comparaciones*/
      }
    }
    else{
      *pos = ip;
      return 2; /*Por las comparaciones*/
    }
  }
}

/***************************************************/
/* Funcion: Partir   Fecha: 04/11/2016             */
/* Función privada de QuickSort                    */
/*                                                 */
/***************************************************/
int Partir(int* tabla, int ip, int iu,int *pos, int tipo){
  int contador = 0;
  int k, i;
  if(tipo == 1){
    contador += Medio(tabla, ip, iu, pos);
  }
  else if(tipo == 2){
    contador += MedioAvg(tabla, ip, iu, pos);
  }
  else if(tipo == 3){
    contador += MedioStat(tabla, ip, iu, pos);
  }
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
/* Funcion: QuickSort    Fecha: 04/11/2016         */
/* Función de ordenacion para tablas de menor a    */
/* mayor                                           */
/***************************************************/
int QuickSortIni(int* tabla, int ip, int iu){
  int m;
  int contador = 0;
  if(ip > iu){
    return ERR;
  }
  if(ip == iu){
    return OK;
  }

  contador += Partir(tabla, ip, iu, &m, 1);
  if(ip < (m - 1)){
    contador += QuickSortIni(tabla, ip, m-1);
  }
  if((m + 1) < iu){
    contador += QuickSortIni(tabla, m+1, iu);
  }
  return contador;
}

/***************************************************/
/* Funcion: QuickSortAvg Fecha: 04/11/2016         */
/* Función de ordenacion para tablas de menor a    */
/* mayor                                           */
/***************************************************/
int QuickSortAvg(int* tabla, int ip, int iu){
  int m;
  int contador = 0;
  if(ip > iu){
    return ERR;
  }
  if(ip == iu){
    return OK;
  }

  contador += Partir(tabla, ip, iu, &m, 2);
  if(ip < (m - 1)){
    contador += QuickSortAvg(tabla, ip, m-1);
  }
  if((m + 1) < iu){
    contador += QuickSortAvg(tabla, m+1, iu);
  }
  return contador;
}

/***************************************************/
/* Funcion: QuickSortStat  Fecha: 04/11/2016       */
/* Función de ordenacion para tablas de menor a    */
/* mayor                                           */
/***************************************************/
int QuickSortStat(int* tabla, int ip, int iu){
  int m;
  int contador = 0;
  if(ip > iu){
    return ERR;
  }
  if(ip == iu){
    return OK;
  }

  contador += Partir(tabla, ip, iu, &m, 3);
  if(ip < (m - 1)){
    contador += QuickSortStat(tabla, ip, m-1);
  }
  if((m + 1) < iu){
    contador += QuickSortStat(tabla, m+1, iu);
  }
  return contador;
}

