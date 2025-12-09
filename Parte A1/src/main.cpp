#include "../include/funciones.h"
using namespace std;


int main() {
    double x1, x2, t, v1, v2, m1, m2, k, kc, c, d, l, dt; 
    double tmax = 20.0;          

    pedirDatos(x1, x2, t, v1, v2, m1, m2, k, kc, c, d, dt); 
    double x1i = x1, x2i = x2, v1i = v1, v2i = v2, ti = t; 
    
    guardarDatos("../results/listas/oscillator1.dat", x1, x2, t, v1, v2, m1, m2, 
                    k, kc, c, d, dt, tmax);

    guardarDatos("../results/listas/oscillator2.dat", x1i, x2i, ti, v1i, v2i, m1, m2, 
                    k, 0, c, d, dt, tmax);                       //kc = 0, para sin acoplamiento                   

    return 0;
}