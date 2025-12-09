
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>

void pedirDatos(double &x1, double &x2, double &t, double &v1, double &v2, double &m1, double &m2,
                 double &k, double &kc, double &c, double &d, double &dt);
void funcion(double x1, double x2, double v1, double v2, double m1, double m2, 
            double k, double kc, double c, double d, 
            double &dx1dt, double &dx2dt, double &dv1dt, double &dv2dt);
void rungeKutta4(double &x1, double &x2, double &v1, double &v2, double &m1, double &m2,
                 double &k, double &kc, double &c, double &d, double &dt);
void guardarDatos(const std::string &archivo, double x1, double x2, double t, double v1, double v2,
                     double m1, double m2, double k,  double kc, double c, double d, double dt, double tmax);

#endif
