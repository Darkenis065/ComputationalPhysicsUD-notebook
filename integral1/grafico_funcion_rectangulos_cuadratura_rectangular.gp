set term png
set output 'grafico_funcion_rectangulos_cuadratura_rectangular.png'
set xlabel 'x'
set ylabel 'f(x)'
plot 'datos_cuadratura_rectangular.dat' u 1:2 w lp title 'Funcion'
