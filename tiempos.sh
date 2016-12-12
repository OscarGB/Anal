#!/bin/bash

echo "Escribe el nombre del archivo"
read FILE
echo "Escribe el nombre de la gráfica"
read NAME
echo "Escribe el nombre del fichero de salida"
read SALIDA

gnuplot > $SALIDA.jpg <<EOF

set terminal jpeg
set title "Tiempo $NAME"
set xlabel "Dimension array"
set ylabel "Tiempo"
plot "$FILE" using 1:2 w lp title "Tiempo $NAME"

EOF
