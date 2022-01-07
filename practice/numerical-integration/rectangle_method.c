#include <stdio.h>
#include <time.h>
#define RUN_COUNT 100

double l_rect(double (*f)(double), double, double, int);
double r_rect(double (*f)(double), double, double, int);
double poly(double);
double l_rect_new(double (*f)(double));
double func(double x);


int main() {
    double a, b, l_rect_sum, r_rect_sum;
    double l_rect_time, r_rect_time;
    int n, i;
    clock_t begin, end;

    l_rect_sum = l_rect_new(func);
    
    printf("%lf\n", l_rect_sum);

    /* printf("Enter a and b\n"); */
    /* scanf("%lf %lf", &a, &b); */

    /* printf("n: "); */
    /* scanf("%d", &n); */
    
    /* begin = clock(); */
    /* for (i=0; i<RUN_COUNT; i++) */
    /*     l_rect_sum += l_rect(poly, a, b, n); */
    /* end = clock(); */

    /* l_rect_sum /= RUN_COUNT; */
    /* l_rect_time = (double)(end-begin) / CLOCKS_PER_SEC; */
    /* l_rect_time /= RUN_COUNT; */

    /* begin = clock(); */
    /* for (i=0; i<RUN_COUNT; i++) */
    /*     r_rect_sum += r_rect(poly, a, b, n); */
    /* end = clock(); */

    /* r_rect_sum /= RUN_COUNT; */
    /* r_rect_time = (double)(end-begin) / CLOCKS_PER_SEC; */
    /* r_rect_time /= RUN_COUNT; */

    /* printf("Left") */

    /* printf("\t Left     Right     Time\n"); */
    /* printf("\t -------  --------  -------\n"); */
    /* printf("\t %4.2lf   %4.2lf    %2.4lf\n", l_rect_sum, r_rect_sum); */


    return 0;
}


double l_rect(double (*f)(double),
        double a,
        double b,
        int n)
{
    double sum, delta;
    int i;

    delta = (b - a) / n;

    sum = 0;
    sum += f(a)*delta;

    for (i=1; i<n; i++)
        sum += f(i*delta)*delta;


    return (sum);
}

double l_rect_new(double (*f)(double)
        )
{
    double sum, delta;
    int i;

    double a = 1.0;
    double b = 3.0;

    /* delta = (b - a) / n; */
    delta = 0.5;

    sum = 0;
    sum += f(a)*delta;

    for (i=1; i<4; i++)
        sum += f(i*delta)*delta;


    return (sum);
}

double l_rect_diff(double (*f)(double),
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


double func(double x)
{
    return (9 - (x*x));
}
