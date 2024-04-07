set xlabel 'x'
set ylabel 'f(x)'
set term png
set output 'Funcion.png'
plot 'Datos_EDO.dat' u 1:2 w p pt 4 ps 2 title 'f(x)'
