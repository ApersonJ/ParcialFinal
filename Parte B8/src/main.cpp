#include <iostream>
#include <vector>
#include <cmath>
#include "../include/laplace.h"

using namespace std;

/**
 * @brief Programa principal para resolver la ecuación de Laplace en 2D usando Gauss-Seidel con SOR.
 *
 * El programa:
 * - Define la malla del dominio rectangular.
 * - Solicita al usuario los valores de potencial en los bordes izquierdo, derecho y superior.
 * - Inicializa el arreglo del potencial f.
 * - Aplica las condiciones de frontera.
 * - Ejecuta iteraciones del método Gauss-Seidel con Sobrerrelajación (SOR).
 * - Evalúa la convergencia mediante un error absoluto acumulado.
 * - Guarda la solución final del potencial en un archivo .dat.
 *
 * @return int Código de retorno estándar del sistema (0 = ejecución correcta).
 */
int main() {

    int NX = 51;
    int NY = 51;
    double L = 5.0, H = 5.0;
    double w = 1.85;  // parámetro SOR
    double tol = 1e-6;
    int maxIter = 500000;

    double Vleft = 0.0;
    double Vright = 10.0;
    double Vtop = 5.0; 

    vector<vector<double> > phi(NY, vector<double>(NX, 0.0));

    aplicar_fronteras(phi, NX, NY, L, H, Vleft, Vright, Vtop);

    int iter = 0;
    double error = 1.0;

    while (error > tol && iter < maxIter) {
        error = gauss_seidel_SOR(phi, NX, NY, w);
        iter++;

        if (iter % 5000 == 0)
            cout << "Iteración " << iter << "  Error=" << error << endl;
    }

    cout << "Convergencia alcanzada en " << iter
         << " iteraciones. Error final = " << error << endl;

    guardar(phi, NX, NY, "resultados/listas/potencial.dat");

    return 0;
}

