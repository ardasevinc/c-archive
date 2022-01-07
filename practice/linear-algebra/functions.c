#include "/home/ardasevinc/programming/C/include/linear_algebra.h"

#define TRUE 1
#define FALSE 0

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
