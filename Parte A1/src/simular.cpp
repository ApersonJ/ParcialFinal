
#include "../include/funciones.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

void pedirDatos(double &x1, double &x2, double &t, double &v1, double &v2, double &m1, double &m2,
                 double &k, double &kc, double &c, double &d, double &dt) {

    cout << "Ingrese los datos para el sistema masa resorte 1." << endl;
    cout << "Ingrese el valor inicial de x1 (m): ";
    cin >> x1;
    cout << "Ingrese el valor inicial de v1  (m/s): ";
    cin >> v1;
    cout << "Ingrese el valor de la masa  1 (Kg): ";
    cin >> m1;
    cout << endl;

    cout << "Ingrese los datos para el sistema masa resorte 2." << endl;
    cout << "Ingrese el valor inicial de x2 (m): ";
    cin >> x2;
    cout << "Ingrese el valor inicial de v2  (m/s): ";
    cin >> v2;
    cout << "Ingrese el valor de la masa 2 (Kg): ";
    cin >> m2;
    cout << endl;

    cout << "Ingrese el valor de k (N/m): ";
    cin >> k;
    cout << "Ingrese el valor de kc (N/m): ";
    cin >> kc;
    cout << "Ingrese el valor del coeficiente de amortiguamiento lineal c: ";
    cin >> c;
    cout << "Ingrese el valor del coeficiente de amortiguamiento cuadratico d (Kg/m): ";
    cin >> d;
    cout << "Ingrese el valor del tiempo inicial: ";
    cin >> t;  
    cout << "Ingrese el paso de integracion dt: ";
    cin >> dt;
}

void funcion(double x1, double x2, double v1, double v2, double m1, double m2, 
            double k, double kc, double c, double d, 
            double &dx1dt, double &dx2dt, double &dv1dt, double &dv2dt) {
    dx1dt = v1; 
    dv1dt = (-k/m1) * x1 - (c/m1) * v1 - (d/m1) * v1 * fabs(v1) - (kc/m1) * (x1 - x2); 

    dx2dt = v2; 
    dv2dt = (-k/m2) * x2 - (c/m2) * v2 - (d/m2) * v2 * fabs(v2) - (kc/m2) * (x2 - x1);

}

void rungeKutta4(double &x1, double &x2, double &v1, double &v2, double &m1, double &m2,
                 double &k, double &kc, double &c, double &d, double &dt) {
    double dx11, dv11, dx21, dv21;
    double dx12, dv12, dx22, dv22;
    double dx13, dv13, dx23, dv23;
    double dx14, dv14, dx24, dv24;

    funcion(x1, x2, v1, v2, m1 , m2, 
            k, kc, c, d, dx11, dx21, dv11, dv21);

    funcion(x1 + 0.5 * dt * dx11, x2 + 0.5 * dt *dx21, 
            v1 + 0.5 * dt * dv11, v2 + 0.5 * dt *dv21, m1, m2, k, kc, c, d, dx12, dx22, dv12, dv22); 

    funcion(x1 + 0.5 * dt * dx12, x2 + 0.5 * dt *dx22, 
            v1 + 0.5 * dt * dv12, v2 + 0.5 * dt *dv22, m1, m2, k, kc, c, d, dx13, dx23, dv13, dv23);

    funcion(x1 + dt * dx13, x2 + dt *dx23, 
            v1 + dt * dv13, v2 + dt *dv23, m1, m2, k, kc, c, d, dx14, dx24, dv14, dv24); 


    x1 += dt * (dx11 + 2 * dx12 + 2 * dx13 + dx14) / 6.0;
    v1 += dt * (dv11 + 2 * dv12 + 2 * dv13 + dv14) / 6.0;
    x2 += dt * (dx21 + 2 * dx22 + 2 * dx23 + dx24) / 6.0;
    v2 += dt * (dv21 + 2 * dv22 + 2 * dv23 + dv24) / 6.0;
}

void guardarDatos(const string &archivo, double x1, double x2, double t0, double v1, double v2,
                     double m1, double m2, double k,  double kc, double c, double d, double dt, double tmax) {
    system("mkdir -p ../results/listas"); 

    ofstream file(archivo);
    file << fixed << setprecision(6);
    file << setw(10) << "t" << setw(15) << "x1" << setw(15) << "x2" << setw(15) << 
            "v1" << setw(15) << "v2" << setw(15) << "p1" << setw(15) << "p2" <<endl;

                                
    double p1 = m1 * v1;
    double p2 = m2 * v2; 

    /// Bucle de integración temporal.
    for ( double t = t0 ; t <= tmax; t += dt) {
        file << setw(10) << t << setw(15) << x1 << setw(15) << x2 << setw(15) << 
            v1 << setw(15) << v2 << setw(15) << p1 << setw(15) << p2 <<endl;
        rungeKutta4(x1, x2, v1, v2, m1, m2, k, kc, c, d, dt);
        
        p1 = m1 * v1;
        p2 = m2 * v2;
    }

    file.close(); ///< Cierra el archivo de salida.
    cout << "Datos guardados en: " << archivo << endl;

    system ("gnuplot ../scripts/graficar.gp");
    system ("gnuplot ../scripts/graficar2.gp");
}