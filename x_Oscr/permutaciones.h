/**
 *
 * Descripcion: Funciones de cabecera para generaciónde permutaciones
 *
 * Fichero: permutaciones.h
 * Autor: Carlos Aguirre 
 * Version: 1.0
 * Fecha: 16-09-2016
 *
 */

#ifndef PERMUTACIONES_H
#define PERMUTACIONES_H

/* constantes */

#ifndef ERR
  #define ERR -1
  #define OK (!(ERR))
#endif
 
int swap(int* a, int* b);
int aleat_num(int inf, int sup);
int* genera_perm(int n);
int** genera_permutaciones(int n_perms, int tamanio);

#endif