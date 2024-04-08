set term png
set output 'grafico_funcion_rectangulos_regla_trapezoidal.png'
set xlabel 'x'
set ylabel 'f(x)'
set logscale x
plot 'datos_regla_trapezoidal.dat' w l title 'Funcion', '' w boxes title 'Rectangulos'
