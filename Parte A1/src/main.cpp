#include "../include/funciones.h"
using namespace std;

/**
 * @brief Función principal del programa.
 *
 * Ejecuta la simulación de un sistema de dos masas acopladas y también
 * el caso sin acoplamiento (kc = 0). Primero solicita los datos al usuario,
 * luego realiza la integración numérica y guarda los resultados en archivos.
 *
 * @return int Código de retorno estándar del programa (0 = éxito).
 */
int main() {
    double x1, x2, t, v1, v2, m1, m2, k, kc, c, d, l, dt; 
    double tmax = 20.0;          

    pedirDatos(x1, x2, t, v1, v2, m1, m2, k, kc, c, d, dt); 
    double x1i = x1, x2i = x2, v1i = v1, v2i = v2, ti = t; 
    
    guardarDatos("../results/listas/oscillator1.dat", x1, x2, t, v1, v2, m1, m2, 
                    k, kc, c, d, dt, tmax);

    guardarDatos("../results/listas/oscillator2.dat", x1i, x2i, ti, v1i, v2i, m1, m2, 
                    k, 0, c, d, dt, tmax);                       ///< kc = 0, simulación sin acoplamiento                   

    return 0;
}

