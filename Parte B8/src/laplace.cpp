#include <iostream>
#include <fstream>
#include <cmath>
#include "../include/laplace.h"

using namespace std;

/**
 * @brief Aplica las condiciones de frontera al potencial eléctrico f(x,y).
 *
 * Asigna valores fijos en los cuatro bordes del dominio:
 * - Borde izquierdo: f = Vleft
 * - Borde derecho: f = Vright
 * - Borde superior: f = Vtop
 * - Borde inferior: f(x,0) = cosh(x)
 *
 * @param phi Matriz 2D del potencial eléctrico.
 * @param NX Número de nodos en la dirección x.
 * @param NY Número de nodos en la dirección y.
 * @param L Longitud del dominio en x.
 * @param H Altura del dominio en y.
 * @param Vleft Valor del potencial en el borde izquierdo.
 * @param Vright Valor del potencial en el borde derecho.
 * @param Vtop Valor del potencial en el borde superior.
 */
void aplicar_fronteras(vector<vector<double> > &phi, int NX, int NY,
                       double L, double H,
                       double Vleft, double Vright, double Vtop)
{
    double dx = L / (NX - 1);

    // Borde izquierdo x=0
    for (int j = 0; j < NY; j++)
        phi[j][0] = Vleft;

    // Borde derecho x=L
    for (int j = 0; j < NY; j++)
        phi[j][NX - 1] = Vright;

    // Borde superior y=H
    for (int i = 0; i < NX; i++)
        phi[NY - 1][i] = Vtop;

    // Borde inferior: f(x,0)=cosh(x)
    for (int i = 0; i < NX; i++) {
        double x = i * dx;
        phi[0][i] = cosh(x);
    }
}

/**
 * @brief Realiza una iteración del método Gauss-Seidel con SOR.
 *
 * Actualiza el potencial f en los nodos interiores usando Gauss-Seidel,
 * mejorado con un factor de sobrerrelajación (SOR).
 *
 * @param phi Matriz del potencial eléctrico.
 * @param NX Número de nodos en x.
 * @param NY Número de nodos en y.
 * @param w Factor de sobrerrelajación (1 < w < 2 recomendado).
 *
 * @return double Suma del cambio absoluto en todos los nodos, usada como error.
 */
double gauss_seidel_SOR(vector<vector<double>> &phi,
                        int NX, int NY,
                        double w)
{
    double error = 0.0;
    double phi_old;

    for (int j = 1; j < NY - 1; j++) {
        for (int i = 1; i < NX - 1; i++) {
            phi_old = phi[j][i];

            double newphi = 0.25 * (phi[j+1][i] + phi[j-1][i]
                                  + phi[j][i+1] + phi[j][i-1]);

            phi[j][i] = (1 - w) * phi_old + w * newphi;

            error += fabs(phi[j][i] - phi_old);
        }
    }

    return error;
}

/**
 * @brief Guarda la matriz del potencial eléctrico f en un archivo de texto.
 *
 * El archivo se guarda como una malla rectangular con valores separados por espacio.
 *
 * @param phi Matriz del potencial.
 * @param NX Número de nodos en x.
 * @param NY Número de nodos en y.
 * @param filename Nombre del archivo de salida.
 */
void guardar(const vector<vector<double>> &phi,
             int NX, int NY, const string &filename)
{
    ofstream file(filename);

    for (int j = 0; j < NY; j++) {
        for (int i = 0; i < NX; i++) {
            file << phi[j][i];
            if (i < NX - 1) file << " ";
        }
        file << "\n";
    }
}

