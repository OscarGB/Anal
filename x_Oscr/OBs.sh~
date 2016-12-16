#!/bin/bash

echo "Escribe el nombre del archivo"
read FILE
echo "Escribe el nombre de la gráfica"
read NAME
echo "Escribe el nombre del fichero de salida"
read SALIDA

gnuplot > $SALIDA.jpg <<EOF

set terminal jpeg
set title "OBs $NAME"
set xlabel "Dimension array"
set ylabel "OBs"
plot "$FILE" using 1:3 with lp title "$NAME media", "$FILE" using 1:4 with lp title "$NAME maximo", "$FILE" using 1:5 with lp title "$NAME minimo"

plot "$FILE" using 1:2 w lp title "Tiempo $NAME"

EOF
