#!/bin/bash

gnuplot > tiempos.jpg <<EOF

set terminal jpeg
set title "Comparacion Tiempos"
set xlabel "Dimension array"
set ylabel "Tiempo"
plot "iq100.log" using 1:2 w lp title "Tiempo IQS100", "iq200.log" using 1:2 w lp title "Tiempo IQS200", "iq300.log" using 1:2 w lp title "Tiempo IQS300", "iq400.log" using 1:2 w lp title "Tiempo IQS400",  "qs.log" using 1:2 w lp title "Tiempo QS"

EOF
