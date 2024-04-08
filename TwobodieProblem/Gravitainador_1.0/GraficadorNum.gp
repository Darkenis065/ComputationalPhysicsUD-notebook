set term png
set output 'GraficaNum.png'
set xlabel 'x (m)'
set ylabel 'y (m)'
x(r,o) = (r)*cos(o)
y(r,o) = (r)*sin(o)
set title 'Elipse trapecios'
plot 'Resultados_numericos.dat' u (x($2,$4)):(y($2,$4))