#include <stdio.h>
#include <math.h>

double bell(double, double);
double test_trapezoidal(double (*bell)(double, double), double, double, double, int);

int main() {
    double result, a, b, sigma;
    int i, n;
    
    a = 0;
    b = 20;
    sigma = 4;
    n = 10;

    result = test_trapezoidal(bell, a, b, sigma, n);

    printf("Result: %lf\n", result);

    for (i=0; i<10; i++)
        printf("%lf\n", bell(i, sigma));

    return 0;
}


double bell(double x, double sigma)
{
    return ( (1/sigma) * exp( (-1*x*x)/(sigma*sigma) ) );
}



double test_trapezoidal(double (*bell)(double, double),
        double a,
        double b,
        double sigma,
        int n)
{
    double sum, h;
    int i;

    h = 0;
    h = (b-a)/n;

    sum = 0;
    sum += bell(a, sigma) / 2.0;

    for (i=1; i<n; i++) {
        sum += bell(a+i*h, sigma);
    }

    sum += bell(b, sigma) / 2.0;

    return (sum * h);
}
