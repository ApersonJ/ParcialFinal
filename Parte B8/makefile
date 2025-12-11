CXX=g++
CXXFLAGS=-O2 -std=c++11

all: run graficas

run:
	$(CXX) src/*.cpp -o laplace
	./laplace

graficas:
	bash scripts/generar_graficas.sh

clean:
	rm -f laplace
	rm -f resultados/listas/*.dat
	rm -f resultados/graficas/*.png
