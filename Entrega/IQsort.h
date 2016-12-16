#ifndef IQSORT_H
#define IQSORT_H

#include <stdio.h>

#ifndef ERR
  #define ERR -1
  #define OK (!(ERR))
#endif


/* definiciones de tipos */
typedef int (* pfunc_ordena)(int*, int, int, int);

int QuickSortIni(int* tabla, int ip, int iu, int L);
int InsertQuickSort(int* tabla, int ip, int iu, int L);
int InsertQuickSort100(int* tabla, int ip, int iu);
int InsertQuickSort200(int* tabla, int ip, int iu);
int InsertQuickSort300(int* tabla, int ip, int iu);
int InsertQuickSort400(int* tabla, int ip, int iu);

#endif

