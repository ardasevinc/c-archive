#include <stdio.h>
#include <time.h>

double poly(double);
double trap(double (*f)(double), double, double, int);

int main() {
    double a, b;
    double result;
    double time_spent;
    int n;
    clock_t begin, end;

    printf("Enter a and b\n");
    scanf("%lf %lf", &a, &b);

    printf("n=");
    scanf("%d", &n);

    begin = clock();
    result = trap(poly, a, b, n);
    end = clock();
    printf("Result = %lf\n", result);

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent: %lf seconds\n", time_spent);

    return 0;
}


double poly(double x) {
    return (x*x -4);
}


double trap(double (*f)(double),
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
