set term png
set output 'Grafica5.png'
set xlabel 'x'
set ylabel 'y'
set title 'EDO5'
plot 'datos5.dat' u 1:2 w l t 'RK5', 'datos5.dat' u 1:3 w l t 'Analitica'