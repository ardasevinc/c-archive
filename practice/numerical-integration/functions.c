#include "./numerical_integration.h"


double l_rect(double (*f)(double),
        double a,
        double b,
        int n)
{
    double sum, delta;
    int i;

    delta = (b-a) / n;
    
    sum = 0;
    
    for (i=0; i<n; i++)
        sum += f(a + i*delta)*delta;
    
    return (sum);
}


double r_rect(double (*f)(double),
        double a,
        double b,
        int n)
{
    double sum, delta;
    int i;

    delta = (b-a)/n;

    sum = 0;

    for (i=1; i<=n; i++)
        sum += f(i*delta)*delta;

    return (sum);
}


double poly(double x) {
    return (x*x - 4);
}


double simpsons(double (*f)(double),
        double a,
        double b,
        int n)
{
    double answer, h;
    double x;
    int i;

    answer = f(a);
    h = (b-a)/n;

    for (i=1; i<=n; i++) {
        x = a+i*h;
        answer += 4*f(x-h/2) + 2*f(x);
    }
    answer -= f(b);
    return (h*answer/6);
}


double trap(double (*f)(double),
        double a,
        double b,
        int n)
{
    double sum, h;
    int i;

    sum = 0;
    h = (b-a)/n;

    for (i=0; i<n; i++)
        sum += (f(a+i*h) + f(a+(i+1)*h)) * h/2;
    
    return (sum);
}


double trap_improved(double (*f)(double),
        double a,
        double b,
        int n)
{
    int i;
    double sum, h;

    sum = 0;
    h = (b-a)/n;

    sum += f(a) / 2;

    for (i=1; i<n; i++)
        sum += f(a+i*h);

    sum += f(b) / 2;

    return (sum*h);
}
