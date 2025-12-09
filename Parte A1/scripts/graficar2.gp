set terminal pngcairo size 800,600
set output '../results/graficas/SINacoplar_x(t).png'
set title 'Posicion x vs Tiempo (Sin Acoplar)'
set xlabel 'Tiempo (s)'
set ylabel 'x (m)'
set grid
plot '../results/listas/oscillator2.dat' index 0 every ::1 using 1:2 with lines lw 2 lc rgb 'blue' title 'x1(t)', \
 '../results/listas/oscillator2.dat' index 0 every ::1 using 1:3 with lines lw 2 lc rgb 'red' title 'x2(t)'

#grafico de v(t)

set terminal pngcairo size 800,600
set output '../results/graficas/SINacoplador_v(t).png'
set title 'Velocidad vs Tiempo (Sin Acoplar)'
set xlabel 'Tiempo (s)'
set ylabel 'v (m/s)'
set grid
plot '../results/listas/oscillator2.dat' index 0 every ::1 using 1:4 with lines lw 2 lc rgb 'blue' title 'v1(t)', \
 '../results/listas/oscillator2.dat' index 0 every ::1 using 1:5 with lines lw 2 lc rgb 'red' title 'v2(t)'

#grafico de momento contra x

set terminal pngcairo size 800,600
set output '../results/graficas/SINacoplador_p(x).png'
set title 'p(x)'
set xlabel 'x (m)'
set ylabel 'p (kg(m/s))'
set grid
plot '../results/listas/oscillator2.dat' index 0 every ::1 using 2:6 with lines lw 2 lc rgb 'blue' title 'p1(x1)', \
 '../results/listas/oscillator2.dat' index 0 every ::1 using 3:7 with lines lw 2 lc rgb 'red' title 'p2(x2)'