set term png
set output 'Grafica2.png'
set xlabel 'x'
set ylabel 'y'
set title 'EDO1'
plot 'datos2.dat' u 1:2 w l t 'RK42', 'datos2.dat' u 1:3 w l t 'Analitica'