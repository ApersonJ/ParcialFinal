# ===== Makefile  =====
.PHONY: all build run doc clean

all: run doc            # o solo 'run' si no quiere depender de LaTeX

build:
	mkdir -p bin resultados scripts documents
	g++ src/main.cpp src/laplace.cpp -Iinclude -o bin/DampedOscilatorB

run: build
	cd bin && ./DampedOscilatorB

doc:
	
	pdflatex -interaction=nonstopmode -output-directory=documents ../documents/teoria.tex

clean:
	rm -f bin/DampedOscilatorB resultados/* scripts/*.gp documents/*.aux documents/*.log documents/*.pdf