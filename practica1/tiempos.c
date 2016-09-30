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

#include "tiempos.h"
#include "ordenacion.h"
#include "permutaciones.h"

/***************************************************/
/* Funcion: tiempo_medio_ordenacion Fecha:         */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/
short tiempo_medio_ordenacion(pfunc_ordena metodo, 
                              int n_perms,
                              int tamanio, 
                              PTIEMPO ptiempo)
{
  int **perms;
  int i, time, suma = 0;

  if(!ptiempo){
    return -1
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
    time = metodo(perms[i], 0, tamanio - 1);
    suma += time;
    if(time > ptiempo->max_ob){
      ptiempo->max_ob = time;
    }
    if (time < ptiempo->min_ob){
      ptiempo->min_ob = time;
    }
  }

  ptiempo->medio_ob = (float)(suma/n_perms);

	return 0;
}

/***************************************************/
/* Funcion: genera_tiempos_ordenacion Fecha:       */
/*                                                 */
/* Vuestra documentacion                           */
/***************************************************/
short genera_tiempos_ordenacion(pfunc_ordena metodo, char* fichero, 
                                int num_min, int num_max, 
                                int incr, int n_perms)
{
  /* vuestro codigo */
	return 0;
}

/***************************************************/
/* Funcion: guarda_tabla_tiempos Fecha:            */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/
short guarda_tabla_tiempos(char* fichero, PTIEMPO tiempo, int N)
{
  /* vuestro codigo */
	return 0;
}


