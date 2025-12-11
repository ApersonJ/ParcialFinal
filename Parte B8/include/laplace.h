#ifndef LAPLACE_H
#define LAPLACE_H

#include <vector>
using namespace std;

/**
 * @brief Aplica condiciones de frontera para el caso 8:
 *        Tres bordes constantes y borde inferior ϕ(x,0)=cosh(x).
 */
void aplicar_fronteras(vector<vector<double>> &phi, int NX, int NY,
                       double L, double H,
                       double Vleft, double Vright, double Vtop);

/**
 * @brief Ejecuta Gauss–Seidel con sobre–relajación.
 */
double gauss_seidel_SOR(vector<vector<double>> &phi,
                        int NX, int NY,
                        double w);

/**
 * @brief Guarda la malla en un archivo.
 */
void guardar(const vector<vector<double>> &phi,
             int NX, int NY,
             const string &filename);

#endif
