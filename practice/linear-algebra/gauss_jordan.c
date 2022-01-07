/* Gauss-Jordan elimination with partial pivoting */
#include <stdio.h>
#include <math.h>
#include "/home/ardasevinc/programming/C/include/matrix.h"

#define TRUE 1
#define FALSE 0


int gauss_jordan(
        double *a, /* Coefficients matrix A */
        double b[], /* Right-hand side vector */
        double *work, /* Working matrix A and b are combined*/
        double x[], /* Solution vector */
        int n, /* number of equations */
        double tol /* tolerance dependent on the value of pivot element */
        );


int main() {
    int n;
    double tol;

    printf("> How many equations?\n");
    scanf("%d", &n);

    double A[n][n];
    double b[n];
    double x[n];
    double work[n][n+1];

    printf("> Input %d coefficients\n", n*n);
    read_matrix(&A[0][0], n, n);
    printf("\n\n");
    print_matrix(&A[0][0], n, n);

    printf("\n\n> Input %d right-hand side elements\n", n);
    read_vector(b, n);
    printf("\n\n");
    print_vector(b, n);

    printf("tolerance=");
    scanf("%le", &tol);

    /* Try to solve the thing */
    int result = gauss_jordan(
            &A[0][0],
            b,
            &work[0][0],
            x,
            n,
            tol
            );

    if (result) {
        printf("\n> Successfully solved the system\n");
        print_vector(x, n);
    }
    else {
        printf("\n> What the hell did ya gave me? This is unsolvable with that tolerance!\n");
    }
}


#define A(I,J) (*(a + (I)*n +(J)))
#define WORK(I,J) (*(work + (I)*(n+1) + (J)))

int gauss_jordan(
        double *a, /* Coefficients matrix A */
        double b[], /* Right-hand side vector */
        double *work, /* Working matrix A and b are combined*/
        double x[], /* Solution vector */
        int n, /* number of equations */
        double tol /* tolerance dependent on the value of pivot element */
        )
{
    double m, max, temp;
    int i, j, k, swap;

    /* Set up working matrix */
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            WORK(i,j) = A(i,j);
        }
        WORK(i,n) = b[i];
    }

    /* Loop through the rows of the working matrix */
    for (i=0; i<n; i++) {
        max = -1.0;
        for (k = i; k<n; k++) {
            if (fabs(WORK(k,i)) > max) {
                max = fabs(WORK(k,i));
                swap = k;
            }
        }
        /* compare pivot with tolerance */
        if (max <= tol)
            return FALSE;

        /* swap rows */
        if (swap != i) {
            for (k = i; k<=n; k++) {
                temp = WORK(i,k);
                WORK(i,k) = WORK(swap,k);
                WORK(swap,k) = temp;
            }
        }

        /* perform elimination for the guests */
        for(j=0; j<n; j++) {
            if (j != i) {
                m = WORK(j,i)/WORK(i,i);
                for (k=i; k<=n; k++) {
                    WORK(j,k) -= m*WORK(i,k);
                }
            }
        }
    }
    for (i=0; i<n; i++) {
        x[i] = WORK(i,n)/WORK(i,i);
    }
    return TRUE;
}
#undef A
#undef WORK
