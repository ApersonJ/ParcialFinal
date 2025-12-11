# ParcialFinal. Sistema Acoplado No Lineal con Amortiguamiento Cuadrático

Este proyecto implementa la simulación numérica de un sistema físico compuesto por dos masas acopladas mediante resortes, sujetas a amortiguamiento lineal y cuadrático. El sistema presenta no linealidades esenciales en el amortiguamiento y se resuelve mediante el método de Runge-Kutta de cuarto orden. Los resultados se visualizan mediante gráficos que muestran la dinámica temporal y el espacio de fase del sistema.

## Descripción Física del Sistema
El sistema modela dos masas puntuales conectadas individualmente a puntos fijos mediante resortes lineales (constante `k`), y acopladas entre sí mediante un resorte adicional (constante `kc`). Cada masa experimenta:
- **Amortiguamiento lineal**: Fuerza proporcional a la velocidad (`-c·v`).
- **Amortiguamiento cuadrático**: Fuerza no lineal proporcional al cuadrado de la velocidad (`-d·|v|·v`).

Esta combinación de características produce un sistema dinámico no lineal con comportamientos complejos e interesantes desde el punto de vista físico y matemático.

## Contenido del Proyecto
- `src/main.cpp`: gestiona la interacción con el usuario y el flujo principal del programa.
- `src/simular.cpp`: contiene la implementación del método de integración numérica RK y la escritura de los datos de salida.
- `include/funciones.h`: declaración de prototipos de funciones.
- `scripts/graficar.gp`: script de Gnuplot para generar gráficos.
- `results/`: almacena archivos de datos `.dat` y gráficos `.png`.
- `documents/teoria.tex`: documento en LaTeX con la teoría.
- `Makefile`: automatiza compilación, simulación y graficado.

## Ecuaciones Diferenciales del Sistema
### Masas individuales (sin acoplamiento)
\[\dot{x}_i = v_i, \quad \dot{v}_i = -\frac{k}{m_i}x_i - \frac{c}{m_i}v_i - \frac{d}{m_i}|v_i|v_i \]

### Sistema acoplado completo
\[
\begin{aligned}
\dot{x}_1 &= v_1 \\
\dot{v}_1 &= -\frac{k}{m_1}x_1 - \frac{c}{m_1}v_1 - \frac{d}{m_1}|v_1|v_1 - \frac{k_c}{m_1}(x_1 - x_2) \\
\dot{x}_2 &= v_2 \\
\dot{v}_2 &= -\frac{k}{m_2}x_2 - \frac{c}{m_2}v_2 - \frac{d}{m_2}|v_2|v_2 - \frac{k_c}{m_2}(x_2 - x_1)
\end{aligned}
\]

### Parámetros
- **m1, m2**: masas (kg)
- **k**: constante elástica (N/m)
- **kc**: constante de acoplamiento (N/m)
- **c**: amortiguamiento lineal (Ns/m)
- **d**: amortiguamiento cuadrático (Ns²/m²)
- **x1, x2**: posiciones iniciales (m)
- **v1, v2**: velocidades iniciales (m/s)
- **dt**: paso temporal (s)
- **tmax**: tiempo total (s)

## Método Numérico
### Runge-Kutta de cuarto orden (RK4)
Elegido por:
1. **Precisión**: error local O(Δt⁵) y global O(Δt⁴).
2. **Estabilidad**: adecuado para sistemas no rígidos.
3. **Eficiencia**: buen balance entre costo y exactitud.

## Compilación y Ejecución
En la terminal de Linux:
```bash
make
```

## Resultados Generados
En la carpeta `results/` se generan:
- `oscillator.dat`: datos numéricos (tiempo, posición, velocidad, etc.).
- `XvsTiempo.png`: posición vs tiempo.
- `VelvsTiempo.png`: velocidad vs tiempo.
- `Fase.png`: diagrama de fase.

Estos gráficos permiten visualizar la disipación, la variación de amplitud y la trayectoria en el espacio de fase.

## Dependencias
Asegúrate de tener instalado:
- `g++`
- `make`
- `gnuplot`
- LaTeX (opcional, para compilar `documents/teoria.tex`)

