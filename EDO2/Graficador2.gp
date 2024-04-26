set term png
set xlabel 'Pasos'
set ylabel 'Error(%)'
set output 'GError.png'
set title 'Error'
plot [0:50] 'datos.dat' u 1:10 w l t 'Rk4'