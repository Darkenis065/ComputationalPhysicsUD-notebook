set term png
set xlabel 'x'
set ylabel 'f(x)'
set output 'Analitica_vs_Taylor.png'
plot 'Resultados_EDO.dat' u 1:2 w p pt 4 ps 2 title 'Solucion numerica', '' u 1:3 w l lw 5 title 'Solucion Analitica'
