#include <stdio.h>
#include <math.h>

#define X_START  0
#define X_END    20
#define SIGMA    4
#define NUM_PANEL 10


double bell(double, double);
double adaptive_trap(double (*f)(double, double), double, double, double,int*, double);
double trapezoidal(double (*f)(double, double), double, double, double, int);
double error(double, double, double, int);

int main() {
    double result, val, a, b, sigma;
    double tolerance;
    int n;

    val = bell(X_START, SIGMA);
    result = trapezoidal(bell, X_START, X_END, SIGMA, NUM_PANEL);

    printf("Bell Test: %lf\n", val);
    printf("Trapezoidal Test: %lf\n", result);



    while (1) {
        if (sigma != 0) {
            /* initial values */
            n = 1;
            a = 0.0;
            b = 30.0;

            printf("Enter sigma: ");
            scanf("%lf", &sigma);

            if (sigma == 0) break;

            printf("Enter tolerance: ");
            scanf("%lf", &tolerance);

            result = adaptive_trap(bell, a, b, sigma, &n, tolerance);

            printf("For sigma=%lf, used %d panels and got %lf\n", sigma, n, result);
        }
        else break;
    }

    return 0;
}


double adaptive_trap(double (*f)(double, double),
        double a,
        double b,
        double sigma,
        int *n,
        double tol)
{
    double calc_error = tol + 10.0;
    double val, lowval;
    
    lowval = trapezoidal(bell, a, b, sigma, *n);
    while (calc_error > tol) {
        *n = 2 * (*n);
        val = trapezoidal(bell, a, b, sigma, *n);
        calc_error = error(a, b, sigma, *n);
        lowval = val;
    }
    return (val);
}


double trapezoidal(double (*f)(double, double),
        double a,
        double b,
        double sigma,
        int n)
{
    double sum = 0, h = 0;
    int i;

    h = (b-a)/n;
    sum += f(a, sigma) / 2.0;

    for (i=1; i<n; i++) {
        sum += f(a+i*h, sigma);
    }

    sum += f(b, sigma) / 2.0;

    return (sum * h);
}


double bell(double x, double sigma)
{
    return ( (1/sigma) * exp( (-1*x*x)/(sigma*sigma) ) );
}


double error(double a, double b,
        double sigma, int n)
{
    return ( (pow( (b-a), 3 )/(12*n*n)) * (2/(pow(sigma, 3))) );
}
