set term png
set output 'GraficaNum2.png'
set xlabel 'x (m)'
set ylabel 'y (m)'
x(r,o) = (r)*cos(o)
y(r,o) = (r)*sin(o)
set title 'Elipse simpson'
plot 'Resultados_numericos.dat' u (x($2,$3)):(y($2,$3))