/* Implements Gauss-Jordan without using partial pivoting */
#include <stdio.h>
#include "/home/ardasevinc/programming/C/practice/vector-matrix/matrix.h"

void simple_gauss(
        double *a,      /* coefficient matrix A's first element */
        double b[],     /* Right-hand side vector */
        double *work,   /* Working matrix that has A and b in it */
        double x[],     /* solutions vector */
        int n
        );


int main() {
    int temp, n;

    printf("Enter the dimensions of your square coefficients matrix A\n");
    scanf("%d %d", &temp, &n);
    while (temp != n) {
        printf("I said SQUARE matrix.\n");
        scanf("%d %d", &temp, &n);
    }

    double A[n][n];
    double b[n];
    double work[n][n+1];
    double x[n];

    printf("-----------------------------------------\n");
    printf("Input %d elements for mat A\n", n*n);
    read_matrix(&A[0][0], n, n);
    printf("\n");
    print_matrix(&A[0][0], n, n);

    printf("Input %d elements for vector b\n", n);
    read_vector(b, n);
    print_vector(b, n);
    printf("-----------------------------------------\n");

    /* Actually try to solve the thing */
    simple_gauss(
            &A[0][0],
            b,
            &work[0][0],
            x,
            n
            );
    printf("-----------------------------------------\n");
    print_matrix(&work[0][0], n, n+1);
    printf("-----------------------------------------\n");
    print_vector(x, n);
    return 0;
}

#define A(I,J) (*(a + (I)*n + (J)))
#define WORK(I,J) (*(work + (I)*(n+1) + (J)))

void simple_gauss(
        double *a,      /* coefficient matrix A's first element */
        double b[],     /* Right-hand side vector */
        double *work,   /* Working matrix that has A and b in it */
        double x[],     /* solutions vector */
        int n           /* n equations */
        )
{
    double m;
    int i, j, k;

    /* Set up the working matrix */
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            WORK(i,j) = A(i,j);
        }
        WORK(i,n) = b[i];
    }

    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            if ( j != i ) {
                m = WORK(j,i) / WORK(i,i);
                /* >=n because the working matrix has n+1 columns */
                for ( k = i; k <= n; k++ ) {
                    WORK(j,k) -= m*WORK(i,k);
                }
            }
        }
    }

    for ( i = 0; i < n; i++) {
        x[i] = WORK(i,n) / WORK(i,i);
    }
}
#undef A
#undef WORK
