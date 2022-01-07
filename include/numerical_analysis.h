#ifndef NUMERICAL_ANALYSIS_H
#define NUMERICAL_ANALYSIS_H

#include <math.h>
#include <stdio.h>


int find_interval(double (*)(double), double,
                double, double, double*, double*);
double bisect(double (*)(double), double, double, double);
double newton(double (*)(double), double (*)(double),
        double, double, double, int*);
double polycubic(double);
double dpolycubic(double);


#endif
