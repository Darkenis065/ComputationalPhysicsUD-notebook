set term png
set output 'Grafica1.png'
set xlabel 'x'
set ylabel 'y'
set title 'EDO1'
plot 'datos1.dat' u 1:2 w l t 'RK4', 'datos1.dat' u 1:3 w l t 'Analitica'