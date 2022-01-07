/*
 * C program to evaluate a given polynomial by reading its coefficients
 * in an array.
 * P(x) = AnXn + An-1Xn-1 + An-2Xn-2+... +A1X + A0
 *
 * The polynomial can be written as:
 * P(x) = A0 + X(A1 + X(A2 + X(A3 + X(Q4 + X(...X(An-1 + XAn))))
 * and evaluated starting from the inner loop
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

void main()
{
    int array[MAXSIZE];
    int i, num, power;
    float x, polySum;

    printf("Enter the order of the polynomial \n");
    scanf("%d", &num);
    printf("Enter the value of x \n");
    scanf("%f", &x);
    /*  Read the coefficients into an array */
    printf("Enter %d coefficients \n", num + 1);
    for (i = 0; i <= num; i++)
    {
        scanf("%d", &array[i]);
    }
    polySum = array[0];
    for (i = 1; i <= num; i++)
    {
        polySum = polySum * x + array[i];
    }
    power = num;

    printf("Given polynomial is: \n");
    for (i = 0; i <= num; i++)
    {
        if (power < 0)
        {
            break;
        }
        /*  printing proper polynomial function */
        if (array[i] > 0)
            printf(" + ");
        else if (array[i] < 0)
            printf(" - ");
        else
            printf(" ");
        printf("%dx^%d  ", abs(array[i]), power--);
    }
    printf("\n Sum of the polynomial = %6.2f \n", polySum);
}
