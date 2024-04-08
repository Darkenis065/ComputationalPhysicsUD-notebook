set term png
set output 'GraficaA.png'
set xlabel 'x (UA)'
set ylabel 'y (UA)'
x(r,o) = (r)*cos(o)
y(r,o) = (r)*sin(o)
set title 'Elipse Analitica'
plot 'Resultados_numericos.dat' u (x($5,$6)):(y($5,$6))