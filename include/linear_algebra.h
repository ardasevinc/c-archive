#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H
#include <stdio.h>
#include <math.h>


int gauss_jordan(
        double *a, /* Coefficients matrix A */
        double b[], /* Right-hand side vector */
        double *work, /* Working matrix A and b are combined*/
        double x[], /* Solution vector */
        int n, /* number of equations */
        double tol /* tolerance dependent on the value of pivot element */
        );
#endif
