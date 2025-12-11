#include <iostream>
#include <fstream>
#include <cmath>
#include "../include/laplace.h"

using namespace std;

void aplicar_fronteras(vector<vector<double>> &phi, int NX, int NY,
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

    // Borde inferior (punto 8): φ(x,0)=cosh(x)
    for (int i = 0; i < NX; i++) {
        double x = i * dx;
        phi[0][i] = cosh(x);
    }
}

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
