set term png
set output 'grafico_integral_vs_regla_de_simpson.png'
set xlabel 'N'
set ylabel 'Integral'
set logscale x
plot 'resultados_regla_de_simpson.dat' u 1:2 w l title 'Integral aproximada', '' u 1:3 w l title 'Valor exacto'
