/**
 *
 * Descripcion: Implementacion funciones para busqueda 
 *
 * Fichero: busqueda.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 11-11-2016
 *
 */

#include "busqueda.h"
#include "permutaciones.h"

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/**
 *  Funciones de geracion de claves
 *
 *  Descripcion: Recibe el numero de claves que hay que generar
 *               en el parametro n_claves. Las claves generadas
 *               iran de 1 a max. Las claves se devuelven en 
 *               el parametro claves que se debe reservar externamente
 *               a la funcion.
 */
  
/**
 *  Funcion: generador_claves_uniforme
 *               Esta fucnion genera todas las claves de 1 a max de forma 
 *               secuencial. Si n_claves==max entonces se generan cada clave
 *               una unica vez.
 */
void generador_claves_uniforme(int *claves, int n_claves, int max)
{
  int i;

  for(i = 0; i < n_claves; i++) claves[i] = 1 + (i % max);

  return;
}

/**
 *  Funcion: generador_claves_potencial
 *               Esta funcion genera siguiendo una distribucion aproximadamente
 *               potencial. Siendo los valores mas pequenos mucho mas probables
 *               que los mas grandes. El valor 1 tiene una probabilidad del 50%,
 *               el dos del 17%, el tres el 9%, etc.
 */
void generador_claves_potencial(int *claves, int n_claves, int max)
{
  int i;

  for(i = 0; i < n_claves; i++) {
    claves[i] = (1+max) / (1 + max*((double)rand()/RAND_MAX));
  }

  return;
}

/***************************************************/
/* Funcion: ini_diccionario      Fecha:18/11/2016  */
/*                                                 */
/* Rutina que inicia un diccionario, con los       */
/* correspondientes valores por defecto            */
/***************************************************/
PDICC ini_diccionario (int tamanio, char orden)
{
	PDICC dic = NULL;
	int i;

	dic = (PDICC)malloc(sizeof(DICC));
	
	if(!dic){
		return NULL;
	}

	dic->tamanio = tamanio;
	dic->n_datos = 0;
	dic->orden = orden;
	dic->tabla = NULL;
	dic->tabla = (int *)malloc(sizeof(int) * tamanio);
	if(!dic->tabla){
		free(dic);
		return NULL;
	}

	for(i=0; i < tamanio; i++){
		dic->tabla[i] = 0;
	}

	return dic;
}

/***************************************************/
/* Funcion: libera_diccionario   Fecha:18/11/2016  */
/*                                                 */
/* Rutina que libera un diccionario.               */
/*                                                 */
/***************************************************/
void libera_diccionario(PDICC pdicc)
{
	if(!pdicc){
		return;
	}
	free(pdicc->tabla);
	free(pdicc);
	return;
}

/***************************************************/
/* Funcion: inserta_diccionario  Fecha:18/11/2016  */
/*                                                 */
/* Rutina que inserta en un diccionario, depende   */
/* de si el diccionario esta ordenado.             */
/***************************************************/
int inserta_diccionario(PDICC pdicc, int clave)
{
	int j;

	if(!pdicc || pdicc->n_datos == pdicc->tamanio){
		return -1;
	}
	if(pdicc->orden == NO_ORDENADO){
		pdicc->tabla[pdicc->n_datos] = clave;
		pdicc->n_datos++;
		return 0;
	}else{
		j = pdicc->n_datos - 1;

		while(j >= 0 && pdicc->tabla[j] > clave){
			pdicc->tabla[j+1] = pdicc->tabla[j];
			j--;
		}

		pdicc->tabla[j+1] = clave;
		pdicc->n_datos++;
		return 0;
	}

}

/***************************************************/
/* Funcion: insercion_masiva_diccionario           */
/* Fecha:18/11/2016                                */
/* Rutina que inserta varios datos en un           */
/* diccionario.                                    */
/***************************************************/
int insercion_masiva_diccionario (PDICC pdicc,int *claves, int n_claves)
{
	int i;
	int res;

	if(!pdicc || !claves || n_claves < 1){
		return -1;
	}
	for(i = 0; i < n_claves; i++){
		res = inserta_diccionario(pdicc, claves[i]);
		if(res != 0){
			return -1;
		}
	}
	return 0;
}

/***************************************************/
/* Funcion: busca_diccionario    Fecha:18/11/2016  */
/*                                                 */
/* Rutina que busca en un diccionario, depende     */
/* de la función de búsqueda introducida.          */
/***************************************************/
int busca_diccionario(PDICC pdicc, int clave, int *ppos, pfunc_busqueda metodo)
{
	if(!pdicc || !ppos){
		return -1;
	}
	return metodo(pdicc->tabla, 0, pdicc->n_datos - 1, clave, ppos);
}

/***************************************************/
/* Funcion: imprime_diccionario  Fecha:18/11/2016  */
/*                                                 */
/* Rutina que imprime un diccionario.              */
/*                                                 */
/***************************************************/
void imprime_diccionario(PDICC pdicc)
{
	int i;
	if(!pdicc){
		return;
	}
	printf("Imprimiendo diccionario:\n");
	for(i = 0; i < pdicc->n_datos; i++){
		printf("\t%d\n", pdicc->tabla[i]);
	}
	return;
}

/* Funciones de busqueda del TAD Diccionario */

/***************************************************/
/* Funcion: bbin                 Fecha:18/11/2016  */
/*                                                 */
/* Rutina que busca binariamente en una tabla una  */
/* clave dada.                                     */
/***************************************************/
int bbin(int *tabla,int P,int U,int clave,int *ppos)
{
	int medio;
	int obs = 0;
    while(P <= U){
      	medio = ((U - P)/2) + P;
      	obs++;
      	if(tabla[medio] == clave){
      		*ppos = medio;
      		return obs;
      	}

      	else if(clave < tabla[medio]){ 
      		U = medio - 1;
      	}
      	else{
      		P = medio + 1;
      	}
    }
    return NO_ENCONTRADO;
}

/***************************************************/
/* Funcion: blin                 Fecha:18/11/2016  */
/*                                                 */
/* Rutina que busca linealmente en una tabla una   */
/* clave dada.                                     */
/***************************************************/
int blin(int *tabla,int P,int U,int clave,int *ppos)
{
	int i, flag = 0;
	int obs = 0;

    for(i = P; i <= U; i++){
        obs++;
        if(clave == tabla[i]) {
            *ppos = i;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
    	*ppos = NO_ENCONTRADO;
    }
    return obs;
}

/***************************************************/
/* Funcion: blin_auto            Fecha:18/11/2016  */
/*                                                 */
/* Rutina que busca linealmente en una tabla una   */
/* clave dada, reordena la tabla según se usa.     */
/***************************************************/
int blin_auto(int *tabla,int P,int U,int clave,int *ppos)
{
	int i, flag = 0;
	int obs = 0;

    for(i = P; i <= U; i++){
        obs++;
        if(clave == tabla[i]) {
        	if(i != 0){
            	*ppos = i-1;
        	}
        	else{
        		*ppos = i;
        	}
            flag = 1;
            if(i > 0){
            	swap(&tabla[i], &tabla[i-1]);
            }
            break;
        }
    }
    if(flag == 0){
    	*ppos = NO_ENCONTRADO;
    }
    return obs;
}


