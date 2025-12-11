set term pngcairo
set output "resultados/graficas/potencial2D.png"
set xlabel "x"
set ylabel "y"
set title "Mapa de color del potencial"
set pm3d map
splot "resultados/listas/potencial.dat" matrix
