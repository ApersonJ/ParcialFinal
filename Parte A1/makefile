# ===== Makefile  =====
.PHONY: all build run doc clean

all: run doc            # o solo 'run' si no quiere depender de LaTeX

build:
	mkdir -p bin results scripts documents
	g++ src/main.cpp src/simular.cpp -Iinclude -o bin/DampedOscilator

run: build
	cd bin && ./DampedOscilator

doc:
	
	pdflatex -interaction=nonstopmode -output-directory=documents ../documents/teoria.tex

clean:
	rm -f bin/DampedOscilator results/* scripts/*.gp documents/*.aux documents/*.log documents/*.pdf
