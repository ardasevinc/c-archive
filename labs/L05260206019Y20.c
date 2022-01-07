#include <stdio.h>
#include <math.h>

double g(double, double);
double y(double);
void euler(double, double, double (*g)(double, double), double, double);
void midpoint(double, double, double (*g)(double, double), double, double);
void range_kutta_4(double, double, double (*g)(double, double), double, double);
void call_the_functions(double, double, double(*g)(double, double),
        double (*y)(double), double, double);


int main() {
    double x0, y0, xlast, step;

    printf("Enter x0 y0 xlast step\n");
    scanf("%lf %lf %lf %lf", &x0, &y0, &xlast, &step);

    printf("y(0.2)=%lf \t g(0.2, 0.8)=%lf\n",
            y(0.2), g(0.2, 0.8));

    printf("------------------\n");
    
    /* euler(x0, y0, g, step, xlast); */
    /* midpoint(x0, y0, g, step, xlast); */
    /* range_kutta_4(x0, y0, g, step, xlast); */
    call_the_functions(x0, y0, g, y, step, xlast);
    return 0;
}


double y(double x)
{
    return ( exp( (pow(x, 4)/4.0) - (0.1*x) )  );
}


double g(double x, double y)
{
    return ( (y*pow(x,3)) - (0.1*y) );
}


void euler(double x0, double y0, double (*g)(double, double),
        double step, double xlast)
{
    int i;
    printf("\t\t\t x \t\t euler\n");

    for (i = 0; x0<=xlast; x0 += step, i++) {
        printf("step %2d:\t %15.6lf %15.6lf\n", i, x0, y0);
        y0 += step*g(x0, y0);
    }
}


void midpoint(double x0, double y0, double (*g)(double, double),
        double step, double xlast)
{
    int i;
    double temp;
    printf("\t\t\t x \t\t midpoint\n");

    for (i = 0; x0<=xlast; x0 += step, i++ ) {
        printf("step %2d:\t %15.6lf %15.6lf\n", i, x0, y0);
        temp = step*g(x0,y0);
        y0 += step*g(x0 + step/2, y0+temp/2);
    }
}


void range_kutta_4(double x0, double y0, double (*g)(double, double),
        double step, double xlast)
{
    int i;
    double ta, tb, tc, td;

    printf("\t\t\t x \t\t RK4\n");

    for (i = 0; x0<=xlast; x0 += step, i++) {
        printf("step %2d:\t %15.6f %15.6f\n", i, x0, y0);
        ta = step * g(x0, y0);
        tb = step * g(x0+step/2.0, y0+ta/2.0);
        tc = step * g(x0+step/2.0, y0+tb/2.0);
        td = step * g(x0+step, y0+tc);

        y0 += (ta + 2.0*tb + 2.0*tc + td) / 6.0;
    }
}


void call_the_functions(double x0, double y0, double (*g)(double, double),
        double (*y)(double),
        double step, double xlast)
{
    int i;
    double ta, tb, tc, td, temp;
    double y_euler, y_midpoint, y_rk4, y_ref;

    y_euler = y_midpoint = y_rk4 = y_ref = y0;
    temp = 0;

    printf("\t\t\t x \t\t euler\t     midpoint\t\t RK4 \t reference\n");
    for (i=0; x0<=xlast; x0 += step, i++) {
        printf("step %2d:\t %14.6f %14.6lf %14.6lf %14.6lf %14.6lf\n",
                i, x0, y_euler, y_midpoint, y_rk4, y_ref);

        y_euler += step * g(x0, y_euler);

        temp = step * g(x0, y_midpoint);
        y_midpoint += step * g(x0+step/2.0, y_midpoint+temp/2.0);

        ta = step * g(x0, y_rk4);
        tb = step * g(x0+step/2.0, y_rk4+ta/2.0);
        tc = step * g(x0+step/2.0, y_rk4+tb/2.0);
        td = step * g(x0+step, y_rk4+tc);
        y_rk4 += (ta + 2.0*tb + 2.0*tc + td) / 6.0;

        y_ref = y(x0);
    }
    y_ref = y(x0);
    printf("step %2d:\t %14.6f %14.6lf %14.6lf %14.6lf %14.6lf\n",
            i, x0, y_euler, y_midpoint, y_rk4, y_ref);
}
