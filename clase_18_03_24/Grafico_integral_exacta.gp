set term png
set output 'integral_exacta.png'
set xlabel 'N'
set ylabel 'Integral'
set logscale x
set title 'Integral exacta'
plot 'Resultados.dat' u 1:3 w l
