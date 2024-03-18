set term png
set output 'Grafica_integral_aproximada.png'
set xlabel 'N'
set ylabel 'Integral'
set logscale x
set title 'Integral aproximada'
plot 'Resultados.dat' u 1:2 w l
