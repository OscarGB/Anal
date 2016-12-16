/***********************************************************/
/* Programa: ejercicio1                  Fecha: 16/12/2016 */
/* Autores:Óscar Gómez                                     */
/*                                                         */
/* Programa que escribe en un fichero                      */
/* los tiempos medios del algoritmo de                     */
/* ordenacion por InsertQuickSort                          */
/*                                                         */
/* Entrada: Linea de comandos                              */
/* -num_min: numero minimo de elementos de la tabla        */
/* -num_max: numero minimo de elementos de la tabla        */
/* -incr: incremento\n                                     */
/* -numP: Introduce el numero de permutaciones a promediar */
/* -fichSalida: Nombre del fichero de salida               */
/* Salida: 0 si hubo error                                 */
/* -1 en caso contrario                                    */
/***********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ordenacion.h"
#include "ordenacion_examen.h"
#include "tiempos.h"
#include "glob.h"

int main(int argc, char** argv)
{
  int i = 0, num_min = 0, num_max = 0, incr = 0, n_perms = 0, L = 0;
  char nombre1[256];
  short ret = 0;

  srand(time(NULL));

  if (argc != 13) {
    fprintf(stderr, "Error en los parametros de entrada:\n\n");
    fprintf(stderr, "%s -num_min <int> -num_max <int> -incr <int>\n", argv[0]);
    fprintf(stderr, "\t\t -numP <int> -fichSalida1 <string> -fichSalida2 <string> -fichSalida3 <string>\n");
    fprintf(stderr, "Donde:\n");
    fprintf(stderr, "-num_min: numero minimo de elementos de la tabla\n");
    fprintf(stderr, "-num_max: numero minimo de elementos de la tabla\n");
    fprintf(stderr, "-incr: incremento\n");
    fprintf(stderr, "-numP: Introduce el numero de permutaciones a promediar\n");
		fprintf(stderr, "-L: tipo de InsertQuickSort\n");
    fprintf(stderr, "-fichSalida: Nombre del fichero de salida1\n");
    exit(-1);
  }

  printf("Examen\n");
  printf("Realizada por: Óscar Gómez\n");
  printf("Grupo: 1201 (Pareja 4)\n");

  /* comprueba la linea de comandos */
  for(i = 1; i < argc ; i++) {
    if (strcmp(argv[i], "-num_min") == 0) {
      num_min = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-num_max") == 0) {
      num_max = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-incr") == 0) {
      incr = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-numP") == 0) {
      n_perms = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-fichSalida") == 0) {
      strcpy(nombre1, argv[++i]);
		} else if (strcmp(argv[i], "-L") == 0) {
			L = atoi(argv[++i]);		
    } else{
      fprintf(stderr, "Parametro %s es incorrecto\n", argv[i]);
			exit(-1);
    }
  }

	switch(L){
		case 100:
			ret = genera_tiempos_ordenacion(InsertQuickSort100, nombre1, num_min, num_max,incr, n_perms);
  		if (ret == ERR) { /* ERR_TIME debera ser un numero negativo */
    		printf("Error en la funcion Time_Ordena de tipo 100\n");
    		exit(-1);
  		}
			break;
		case 200:
			ret = genera_tiempos_ordenacion(InsertQuickSort200, nombre1, num_min, num_max,incr, n_perms);
  		if (ret == ERR) { /* ERR_TIME debera ser un numero negativo */
    		printf("Error en la funcion Time_Ordena de tipo 200\n");
    		exit(-1);
  		}
			break;
		case 300:
			ret = genera_tiempos_ordenacion(InsertQuickSort300, nombre1, num_min, num_max,incr, n_perms);
  		if (ret == ERR) { /* ERR_TIME debera ser un numero negativo */
    		printf("Error en la funcion Time_Ordena de tipo 300\n");
    		exit(-1);
  		}
			break;
		case 400:
			ret = genera_tiempos_ordenacion(InsertQuickSort400, nombre1, num_min, num_max,incr, n_perms);
  		if (ret == ERR) { /* ERR_TIME debera ser un numero negativo */
    		printf("Error en la funcion Time_Ordena de tipo 400\n");
    		exit(-1);
  		}
			break;
		default:
			printf("L es inválido, utilice 100, 200, 300 o 400\n");
			exit(-1);
	}

  printf("Salida correcta \n");

  return 0;
}

