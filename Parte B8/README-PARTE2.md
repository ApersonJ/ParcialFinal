# Simulación Numérica de la Ecuación de Laplace en 2D

Este proyecto implementa la resolución numérica de la **ecuación de Laplace bidimensional** en un dominio rectangular. El potencial eléctrico se calcula imponiendo diversas condiciones de frontera, usando el método de **diferencias finitas** y el esquema iterativo **Gauss–Seidel con sobre–relajación (SOR)** para acelerar la convergencia.

La simulación produce un archivo con la distribución del potencial, que puede ser graficado posteriormente para visualizar mapas de potencial, superficies 3D o líneas equipotenciales.

---

## 📁 Contenido del Proyecto

- **src/main.cpp**: gestiona el flujo principal, inicialización de parámetros e iteración SOR.
- **src/laplace.cpp**: contiene la implementación del método de Gauss–Seidel SOR, la aplicación de condiciones de frontera y la escritura de datos.
- **include/laplace.h**: declaración de las funciones utilizadas en la simulación.
- **scripts/graficar.gp**: script de Gnuplot para generar gráficos del potencial y del campo eléctrico.
- **resultados/**: carpeta donde se almacenan:
  - matrices de potencial (`.dat`)
  - gráficos generados (`.png`)
- **documents/teoria.tex**: documento en LaTeX con la teoría física, formulación matemática y metodología numérica de la ecuación de Laplace.
- **Makefile**: automatiza la compilación, ejecución y generación de gráficos.

---

## 🧮 Ecuación Diferencial del Sistema

La ecuación de Laplace en dos dimensiones está dada por:

\[
\nabla^2 \phi(x,y) = 0
\]

donde:

- \( \phi(x,y) \): potencial electrostático  
- \( \nabla^2 \): operador Laplaciano bidimensional  

En electrostática, esta ecuación describe regiones **sin carga** (\(\rho = 0\)).  
El potencial depende exclusivamente de las **condiciones de frontera**, lo que hace del problema un sistema estrictamente determinista.

### Discretización

Para una malla uniforme:

\[
\phi_{i,j} = \frac{1}{4} \left(
\phi_{i+1,j} + \phi_{i-1,j} +
\phi_{i,j+1} + \phi_{i,j-1}
\right)
\]

lo que corresponde al promedio de los cuatro vecinos (discretización estándar).

---

## ⚙️ Método Numérico Utilizado

Para resolver la ecuación discretizada se utiliza el **método iterativo de Gauss–Seidel**, mejorado con **sobre–relajación (SOR)**:

\[
\phi^{(k+1)}_{i,j} =
(1-\omega)\phi^{(k)}_{i,j}
+ \omega \cdot \phi^\text{nuevo}_{i,j}
\]

donde:

- \( \omega \) es el parámetro SOR (\(1 < \omega < 2\)),
- \( \phi^\text{nuevo}_{i,j} \) es el promedio de vecinos.

Este esquema reduce drásticamente el número de iteraciones necesarias para converger.

---

## ▶️ Cómo Compilar y Ejecutar

El proyecto incluye un **Makefile** que automatiza compilación, ejecución y graficado.


### Compilar + ejecutar la simulación + generar gráficos:

En la terminal:

```bash
make
