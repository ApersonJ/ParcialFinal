
# Proyecto: Oscilador Armónico Amortiguado (Lineal)

Este proyecto implementa la simulación numérica de un **oscilador armónico amortiguado lineal**, donde la fuerza de amortiguamiento es proporcional a la velocidad, y la restauradora proporcional al desplazamiento. El sistema se resuelve mediante un método numérico RK y los resultados se visualizan mediante gráficos.

---

##  Contenido del Proyecto

* `src/main.cpp`: gestiona la interacción con el usuario y el flujo principal del programa.
* `src/simular.cpp`: contiene la implementación del método de integración numérica RK y la escritura de los datos de salida.
* `include/funciones.h`: declaración de los prototipos de funciones utilizadas.
* `scripts/graficar.gp`: script de Gnuplot para la generación de gráficos de resultados.
* `results/`: carpeta donde se almacenan los archivos de datos (`.dat`) de la simulación y las imágenes gráficas (`.png`).
* `documents/teoria.tex`: documento en LaTeX donde se explica la teoría del oscilador amortiguado lineal.
* `Makefile`: automatiza la compilación del programa, la ejecución de la simulación y la generación de gráficos.

---

##  Ecuación Diferencial del Sistema

Para un sistema masa–resorte con amortiguamiento lineal, la ecuación de movimiento es:
[
m , \ddot x + b , \dot x + k, x = 0
]
donde:

* **m**: masa del oscilador
* **k**: constante del resorte
* **b**: coeficiente de amortiguamiento (proporcional a la velocidad)

Esta se puede reescribir como:
[
\ddot x + \frac{b}{m},\dot x + \frac{k}{m},x = 0
]
La ecuación es lineal de segundo orden homogénea. 

Dependiendo del valor de (b^2 - 4mk), el sistema puede estar:

* Sobreamortiguado
* Críticamente amortiguado
* Subamortiguado (oscila con amplitud decreciente) 

---

##  Cómo Compilar y Ejecutar

El proyecto incluye un `Makefile` que automatiza los pasos de compilación, ejecución y graficado.

### Compilar y ejecutar la simulación + generación de gráficos:

En la terminal de Linux, simplemente escribe:

```
make
```

Esto realizará: compilación del código fuente, ejecución de la simulación, y generación de los gráficos (usando `scripts/graficar.gp`) que se almacenarán en la carpeta `results/`.

---

##  Resultados Generados

Tras la ejecución, obtendrás los siguientes archivos en la carpeta `results/`:

* `oscillator.dat` (o nombre similar) → datos numéricos de la simulación (tiempo, desplazamiento, velocidad, etc).
* `XvsTiempo.png` → gráfico de la posición vs tiempo.
* `VelvsTiempo.png` → gráfico de la velocidad vs tiempo.
* `Fase.png` → diagrama de fase (velocidad vs desplazamiento).
  Estos archivos te permiten visualizar cómo el sistema decae, cómo cambia la amplitud con el tiempo, y ver la trayectoria en el espacio de fase.

---

##  Dependencias

Asegúrate de tener instalados los siguientes programas en tu sistema:

* **g++** (o cualquier compilador de C++)
* **Make** (para automatizar construcción)
* **Gnuplot** (o alternativa de graficado)
* **LaTeX** (opcional, solo si deseas compilar el documento en `documents/teoria.tex`)

