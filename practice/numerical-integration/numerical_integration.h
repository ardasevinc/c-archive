#ifndef NUMERICAL_INTEGRATION_H
#define NUMERICAL_INTEGRATION_H

#include <stdio.h>


double l_rect(double (*f)(double), double, double, int);
double r_rect(double (*f)(double), double, double, int);
double poly(double);
double trap(double (*f)(double), double, double, int);
double trap_improved(double (*f)(double), double, double, int);

#endif
