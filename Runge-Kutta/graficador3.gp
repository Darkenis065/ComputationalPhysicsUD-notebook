set term png
set output 'Grafica3.png'
set xlabel 'x'
set ylabel 'y'
set title 'EDO3'
plot 'datos3.dat' u 1:2 w l t 'RK4', 'datos3.dat' u 1:3 w l t 'Analitica'