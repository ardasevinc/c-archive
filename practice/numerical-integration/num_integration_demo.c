#include <stdio.h>
#include <time.h>
#include "./numerical_integration.h"

int main() {
    double a, b, result;
    int i, n, count;

    printf("Enter a and b\n");
    scanf("%lf %lf", &a, &b);

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter trial count: ");
    scanf("%d", &count);

    printf("-------------------\n");
    printf("1: Left Rectangle\n");
    printf("2: Right Rectangle\n");
    printf("3: Bad Trapezoidal\n");
    printf("4: Good Trapezoidal\n");
    printf("5: Simpson's Rule\n");

    result = 0;
    
    begin = clock();
    for (i=0; i<count; i++) {
        result += l_rect(poly, a, b, n);
    }
    end = clock();

    result /= count;
}


void integration_tester(
        double (*f)(double),
        double a,
        double b,
        double results[5],
        int n,
        int count,
        int choice
        )
{
    clock_t begin, end;
    double time_spent, sum;
    int i;

    sum = 0;
    switch(choice) {
        case 1:
            {
                begin = clock();
                for (i=0; i<n; i++)
                    sum += l_rect(poly, a, b, n);
                end = clock();
                sum /= n;
            }
    }
}
