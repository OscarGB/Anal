#!/bin/bash

gnuplot > Obs.jpg <<EOF

set terminal jpeg
set title "Comparacion OBs"
set xlabel "Dimension array"
set ylabel "OBs"
plot "iq100.log" using 1:3 with lp title "IQS100 media", "iq200.log" using 1:3 with lp title "IQS200 media", "iq300.log" using 1:3 with lp title "IQS300 media", "iq400.log" using 1:3 with lp title "IQS400 media", "qs.log" using 1:3 with lp title "QS media"

EOF
