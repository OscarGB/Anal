/**
 *
 * Descripcion: Implementacion de funciones de tiempo
 *
 * Fichero: tiempos.c
 * Autor: Carlos Aguirre Maeso
 * Version: 1.0
 * Fecha: 16-09-2016
 *
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "tiempos.h"
#include "ordenacion.h"
#include "permutaciones.h"

/***************************************************/
/* Funcion: tiempo_medio_ordenacion Fecha:2/10/2016*/
/*                                                 */
/* Rutina que guarda en una escritura PTIEMPO los  */
/* datos necesarios para el análisis temporal      */
/***************************************************/
short tiempo_medio_ordenacion(pfunc_ordena metodo, 
                              int n_perms,
                              int tamanio, 
                              PTIEMPO ptiempo)
{
  int **perms;
  int i; /*ob = operación basica*/
  double suma = 0, sumaob=0;
  clock_t start, end; 
  double time, ob; /*time = tiempo fisico*/

  if(!ptiempo){
    return -1;
  }

  ptiempo->n_perms = n_perms;
  ptiempo->tamanio = tamanio;
  ptiempo->max_ob = 0;
  ptiempo->min_ob = INT_MAX;

  perms = genera_permutaciones(n_perms, tamanio);
  if(!perms){
    return -1;
  }

  for(i = 0; i < n_perms; i++){
    start = clock();
    ob = metodo(perms[i], 0, tamanio - 1);
    end = clock();
    time = (double)(end-start);
    sumaob += ob;
    suma += time;
    if(ob > ptiempo->max_ob){
      ptiempo->max_ob = ob;
    }
    if (ob< ptiempo->min_ob){
      ptiempo->min_ob = ob;
    }
  }
  ptiempo->medio_ob = (double)(sumaob/n_perms);
  ptiempo->tiempo = (double)(suma/n_perms)/CLOCKS_PER_SEC; /*Hemos decidido no dividir entre CLOCKS_PER_SEC para poder hacer una comparación más precisa*/
  for(i = 0; i < n_perms; i++){
    free(perms[i]);
  }
  free(perms);
	return 0;
}

/******************************************************/
/* Funcion: genera_tiempos_ordenacion Fecha: 2/10/2016*/
/*                                                    */
/* Rutina usada para generar todos los tiempos de     */
/* ordenación para su posterior escritura en fichero  */
/******************************************************/
short genera_tiempos_ordenacion(pfunc_ordena metodo, char* fichero, 
                                int num_min, int num_max, 
                                int incr, int n_perms)
{
  int i;
  PTIEMPO tiempo;
  tiempo = (PTIEMPO) malloc (sizeof(TIEMPO));
  remove(fichero);
  for(i = num_min; i <= num_max; i += incr){
    tiempo_medio_ordenacion(metodo, n_perms, i, tiempo);
    guarda_tabla_tiempos(fichero, tiempo, 1);
  }
  free(tiempo);
	return 0;
}

/***************************************************/
/* Funcion: guarda_tabla_tiempos Fecha:02/10/2016  */
/*                                                 */
/* Rutina que escribe en un fichero los datos      */
/* obtenidos                                       */
/***************************************************/
short guarda_tabla_tiempos(char* fichero, PTIEMPO tiempo, int N)
{
  FILE* f = NULL;;
  f = fopen(fichero, "a");
  if(!f){
    return -1;
  }
  fprintf(f, "%-20d%-20.8f%-20.1f%-20d%-20d\n", tiempo->tamanio, tiempo->tiempo, tiempo->medio_ob, tiempo->max_ob, tiempo->min_ob);
	fclose(f);
  return 0;
}


