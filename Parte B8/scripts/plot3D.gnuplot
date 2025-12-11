set term pngcairo
set output "resultados/graficas/potencial3D.png"
set xlabel "x"
set ylabel "y"
set zlabel "ϕ(x,y)"
set title "Superficie del potencial"
set hidden3d
splot "resultados/listas/potencial.dat" matrix with lines
