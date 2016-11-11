/***********************************************************/
/* Programa: ejercicio5                  Fecha: 08/10/2016 */
/* Autores:Óscar Gómez, Jose Ignacio Gómez                 */
/*                                                         */
/* Programa que escribe en un fichero                      */
/* los tiempos medios del algoritmo de                     */
/* ordenacion por Seleccion                                */
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
#include "tiempos.h"
#include "glob.h"

int main(int argc, char** argv)
{
  int i, num_min, num_max, incr, n_perms;
  char nombre1[256], nombre2[256], nombre3[256];
  short ret;

  srand(time(NULL));

  if (argc != 15) {
    fprintf(stderr, "Error en los parametros de entrada:\n\n");
    fprintf(stderr, "%s -num_min <int> -num_max <int> -incr <int>\n", argv[0]);
    fprintf(stderr, "\t\t -numP <int> -fichSalida1 <string> -fichSalida2 <string> -fichSalida3 <string>\n");
    fprintf(stderr, "Donde:\n");
    fprintf(stderr, "-num_min: numero minimo de elementos de la tabla\n");
    fprintf(stderr, "-num_max: numero minimo de elementos de la tabla\n");
    fprintf(stderr, "-incr: incremento\n");
    fprintf(stderr, "-numP: Introduce el numero de permutaciones a promediar\n");
    fprintf(stderr, "-fichSalida1: Nombre del fichero de salida1\n");
    fprintf(stderr, "-fichSalida2: Nombre del fichero de salida2\n");
    fprintf(stderr, "-fichSalida3: Nombre del fichero de salida3\n");
    exit(-1);
  }

  printf("Practica numero 2, apartado 5\n");
  printf("Realizada por: Jose Ignacio Gómez, Óscar Gómez\n");
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
    } else if (strcmp(argv[i], "-fichSalida1") == 0) {
      strcpy(nombre1, argv[++i]);
    } else if (strcmp(argv[i], "-fichSalida2") == 0){
      strcpy(nombre2, argv[++i]);
    } else if (strcmp(argv[i], "-fichSalida3") == 0){
      strcpy(nombre3, argv[++i]);
    } else{
      fprintf(stderr, "Parametro %s es incorrecto\n", argv[i]);
    }
  }

  /* calculamos los tiempos con tipo 1*/
  ret = genera_tiempos_ordenacion(QuickSortIni, nombre1, num_min, num_max,incr, n_perms);
  if (ret == ERR) { /* ERR_TIME debera ser un numero negativo */
    printf("Error en la funcion Time_Ordena de tipo 1\n");
    exit(-1);
  }

  /* calculamos los tiempos con tipo 2*/
  ret = genera_tiempos_ordenacion(QuickSortAvg, nombre2, num_min, num_max,incr, n_perms);
  if (ret == ERR) { /* ERR_TIME debera ser un numero negativo */
    printf("Error en la funcion Time_Ordena de tipo 2\n");
    exit(-1);
  }

  /* calculamos los tiempos con tipo 2*/
  ret = genera_tiempos_ordenacion(QuickSortStat, nombre3, num_min, num_max,incr, n_perms);
  if (ret == ERR) { /* ERR_TIME debera ser un numero negativo */
    printf("Error en la funcion Time_Ordena de tipo 3\n");
    exit(-1);
  }

  printf("Salida correcta \n");

  return 0;
}

