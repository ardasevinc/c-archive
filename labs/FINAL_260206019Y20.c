/* EE204 LAB FINAL WORK
 * Author: Arda Sevinç
*/
#include <stdio.h>
#include <math.h>

/* Uncomment below if your compiler
 * doesn't define M_PI in math.h */
/* #define M_PI acos(-1.0) */
#define ARR_MAX 50
#define INTERVAL 0.05
#define STEP 0.0001
#define TEST1 0.0
#define TEST2 2.2


double f(double);
void print_array(double *);
int is_root_present(double *);
void find_lower_boundaries(double *, double, double);
/* double trisection(double (*f)(double), double, double, double); */
double bisection(double (*f)(double), double, double, double);
void find_roots(double (*f)(double), double *,
            double *, double);
double left_rect(double (*f)(double), double,
        double, double);
void record_integrals(double *, double *, double,
        double, double);


int main()
{
    int i;
    double lower_boundaries[ARR_MAX] = {0};
    double roots[ARR_MAX] = {0};
    double integrals[ARR_MAX] = {0};
    double root_test, xstart, xend;
    double tri_test;
    double l_rect;
    double int_test;

    printf("f(0) = %lf\tf(2.2) = %lf\n", 
            f(TEST1), f(TEST2));

    /* printf("Enter array elements\n"); */

    /* for (i=0; i<ARR_MAX; i++) { */
    /*     scanf("%lf", &test_arr[i]); */
    /* } */

    /* print_array(test_arr); */
    /* printf("\n"); */

    /* root_test = 1.95; */
    /* printf("root(1.95, 2.00) = %d\n", is_root_present(&root_test)); */
    /* root_test = 2.05; */
    /* printf("root(2.05, 2.10) = %d\n", is_root_present(&root_test)); */
    /* root_test = 3.75; */
    /* printf("root(3.75, 3.80) = %d\n", is_root_present(&root_test)); */

    printf("Enter lower and upper boundaries\n");
    scanf("%lf %lf", &xstart, &xend);
    /* printf("For (%lf, %lf) boundaries are \n", xstart, xend); */

    find_lower_boundaries(lower_boundaries, xstart, xend);

    /* print_array(lower_boundaries); */

    /* tri_test = bisection(f, 2.45, 2.5, 0.00001); */
    /* printf("tri(f, 2.45, 2.5, 1e-10) = %lf\n", tri_test); */
    /* tri_test = bisection(f, 1.95, 2.0, 0.00001); */
    /* printf("tri(f, 1.95, 2.0, 1e-10) = %lf\n", tri_test); */

    find_roots(f, lower_boundaries, roots, 0.00001);

    /* print_array(roots); */

    /* l_rect = left_rect(f, 1.4588, 1.9677, 0.00001); */
    /* printf("l_rect1 = %lf\n", l_rect); */
    /* l_rect = left_rect(f, 2.8056, 3.1824, 0.00001); */
    /* printf("l_rect2 = %lf\n", l_rect); */

    record_integrals(roots, integrals,
            0.0, 2.20, 0.00001);
    print_array(integrals);
    /* record_integrals(roots, integrals, */
    /*         2.0, 3.60, 0.00001); */
    
    return 0;
}


double f(double x)
{
    return ( sin((M_PI/2.0)*x*x) + 0.2 );
}


/* Print array contents until a 0
 * is encountered */
void print_array(double *input_arr)
{
    int i;
    for (i=0; i<ARR_MAX; i++) {
        if (input_arr[i] == 0) break;
        else
            printf("%lf ", input_arr[i]);
    }
    printf("\n");

}


/* interval length is always $INTERVAL
 * we only need lower boundary */
int is_root_present(double *xleft)
{
    double xright, xend;
    xend = *xleft + INTERVAL;
    xright = *xleft + STEP;

    while ( *xleft < xend && f(*xleft) * f(xright) > 0.0) {
        *xleft = xright;
        xright += STEP;
        if (xright > xend) xright = xend;
    }
    
    if ( f(*xleft) * f(xright) > 0.0) {
        return 0;
    }
    return 1;
}


void find_lower_boundaries(double *arr,
        double xstart,
        double xend)
{
    int i, result;
    double xleft, xright;

    xleft = xstart;
    xright = xleft + INTERVAL;
    i = 0;
    while (xleft < xend) {
        result = is_root_present(&xleft);

        if (result) {
            arr[i] = xleft;
            i++;
        }

        xleft = xright;
        xright += INTERVAL;
        if (xright > xend) xright = xend;
    }
}


/* double trisection(double (*f)(double), */
/*         double xstart, */
/*         double xend, */
/*         double epsilon) */
/* { */
/*     double step, y1, y2; */



/*     step = fabs(xstart - xend) / 3.0; */
/*     y2 = y1 + step; */
/*     for (y1=(xend-xstart)/3.0; fabs(y2-y1)>epsilon; y1=(xend-xstart)/3.0) { */
/*         step = fabs(xstart - xend) / 3.0; */
/*         y2 = y1 + step; */
/*         /1* leftmost interval *1/ */
/*         if (f(xstart)*f(y1) <= 0.0) { */
/*             xend = y1; */
/*         } */
/*         /1* middle interval *1/ */
/*         else if (f(y1) * f(y2) <= 0.0) { */
/*             xstart = y1; */
/*             xend = y2; */
/*         } */
/*         /1* rightmost interval *1/ */
/*         else { */
/*             xstart = y2; */
/*             xend = y2 + step; */
/*         } */
/*     } */
/*     return (y1); */
/* } */


double bisection(double (*f)(double),
        double xstart,
        double xend,
        double epsilon)
{
    double y;

    for (y=(xstart+xend)/2.0; fabs(xstart-y)>epsilon; y=(xstart+xend)/2.0) {
        if ( f(xstart) * f(y) <= 0.0 )
            xend = y;
        else
            xstart = y;
    }
    
    return (y);
}


void find_roots(double (*f)(double),
        double * lower_boundaries,
        double * roots,
        double epsilon)
{
    int i;

    for (i=0; i<ARR_MAX; i++) {
        if (lower_boundaries[i] == 0) break;
        else {
            roots[i] = bisection(f, lower_boundaries[i],
                    lower_boundaries[i]+INTERVAL, epsilon);
        }

    }
}


double left_rect(double (*f)(double),
        double x1,
        double x2,
        double step)
{

    double sum;
    int i, n;

    sum = 0;
    while (x1 < x2) {
        sum += f(x1)*step;
        x1 += step;
    }

    /* n = fabs(x2-x1)/step; */
    /* sum = 0; */
    /* for (i=1; i<=n; i++) */
    /*     sum += f(i*step)*step; */

    return (sum);
}


void record_integrals(double *roots,
        double *integrals,
        double a,
        double b,
        double step)
{
    int i;
    double temp;

    i = 0;
    while (roots[i] != 0) {
        if (a <= b) {
            temp = left_rect(f, a, roots[i], 0.00001);
            a = roots[i];
            integrals[i] = temp;
            i++;
        }
        else break;
    }
    /* calculate the rightmost interval */
    integrals[i] = left_rect(f, roots[i-1], b, 0.00001);
}
