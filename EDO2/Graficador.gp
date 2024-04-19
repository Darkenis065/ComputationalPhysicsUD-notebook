set term png
set xlabel 't(s)'
set ylabel 'v(m/s)'
set output 'GAnalitica.png'
set title 'Velocidad contra tiempo.'
plot 'datos.dat' u 1:2 w l t 'Analitica','datos.dat' u 1:3 w l t 'Taylor','datos.dat' u 1:4 w l t 'Euler','datos.dat' u 1:5 w l t 'Euler mejorado' 