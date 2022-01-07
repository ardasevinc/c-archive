/* Arda Sevinç - 260206019
 * Written on a linux operating system
 * for LAB 03 of EE204 */
#include <stdio.h>
#include <math.h>

double T(double R);
double R(double T);
double bisect(
        double (*f)(double x),
        double r1,
        double r2,
        double target,
        double epsilon
        );
double T_to_C(double kelvin);
double C_to_T(double celsius);


int count = 0;

int main() {
    double t1, t2, t3, t4;
    double r_test1 = 5e3;
    double r_test2 = 25e3;
    double R;

    printf("Enter 4 temp values\n");
    scanf("%lf %lf %lf %lf", &t1, &t2, &t3, &t4);

    printf("Got %lf %lf %lf %lf\n\n", t1, t2, t3, t4);

    double test1 = T_to_C( T(r_test1) );
    double test2 = T_to_C( T(r_test2) );

    printf("test1 = %lf\n", test1);
    printf("test2 = %lf\n", test2);

    R = bisect(T, 100, 100e3, C_to_T(t1), 0.01);
    printf("\nHere is R for T = %lf:  %lf\n", t1, R);
    printf("%d iterations\n", count);
    count = 0;

    R = bisect(T, 100, 100e3, C_to_T(t2), 0.01);
    printf("Here is R for T = %lf:  %lf\n", t2, R);
    printf("%d iterations\n", count);
    count = 0;

    R = bisect(T, 100, 100e3, C_to_T(t3), 0.01);
    printf("Here is R for T = %lf:  %lf\n", t3, R);
    printf("%d iterations\n", count);
    count = 0;

    R = bisect(T, 100, 100e3, C_to_T(t4), 0.01);
    printf("Here is R for T = %lf:  %lf\n", t4, R);
    printf("%d iterations\n", count);
    count = 0;

    return 0;
}


double bisect(
        double (*f)(double x),
        double r1, /* start of interval */
        double r2, /* end of interval */
        double target,
        double epsilon /* tolerance */
        )
{
    double R;

    for (R = (r1+r2)/2.0; fabs(f(r1) - f(R)) > epsilon; R = (r1+r2)/2.0) {
        if (fabs( f(r1) - target ) <= fabs( f(r1) - f(R))) {
            r2 = R;
            count++;
        }
        else {
            r1 = R;
            count++;
        }
    }
    return r1;
}


double T(double R) {
    return (1 / (1.1292e-3 + (2.3410e-4 * log(R)) + (8.7754e-8 * pow( log(R), 3 ))));
}


double T_to_C(double kelvin) {
    return (kelvin - 273.15);
}


double C_to_T(double celsius) {
    return (celsius + 273.15);
}
