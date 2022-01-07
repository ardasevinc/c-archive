#include <stdio.h>
#include <time.h>

#define RUN_COUNT 100

double poly(double);
double simpsons(double (*f)(double), double, double, int);


int main() {
    double a, b, sum;
    int n, i;
    clock_t begin, end;
    double time_spent;

    printf("Enter a and b\n");
    scanf("%lf %lf", &a, &b);

    printf("Enter n: ");
    scanf("%d", &n);

    sum = 0;

    begin = clock();
    for (i=0; i<RUN_COUNT; i++)
        sum += simpsons(poly, a, b, n);
    end = clock();

    sum /= RUN_COUNT;

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    time_spent /= RUN_COUNT;

    printf("Result: %lf\n", sum);
    printf("Time spent: %lf\n", time_spent);

    return 0;
}


double poly(double x) {
    return (x*x-4);
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
