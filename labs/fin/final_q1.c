/* Arda Sevinç - 260206019 */
#include <stdio.h>
#include <math.h>

#define TRUE 1


double ellipse(double, double, double, double,
        double, double);


int main()
{
    double x, y, h, k;
    double a, b;

    a = 30.0;
    b = 15.0;
    h = k = 0.0;

    for (x=0.0, y=0.0; (fabs(x)<=60) && (fabs(y)<=30); x+=0.1, y+=0.1) {
        if ( round(ellipse(x,y,h,k,a,b)) == TRUE )
            printf("\\");
    }
    return 0;
}


double ellipse(double x, double y, double h,
        double k, double a, double b)
{
    return ( (pow((x-h),2) / (a*a)) + 
            ( pow((y-k),2) / (b*b) ));
}

/* I don't think it is justifiable
 * to do this instead of using graphics.h
 */
