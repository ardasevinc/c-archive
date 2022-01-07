#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double fnorm(int*, int, int);


int main()
{
    int nrows, ncols;
    int i;
    int *a;
    double sum;


    printf("Enter rows x columns: ");
    scanf("%d %d", &nrows, &ncols);

    a = malloc(sizeof(int) * nrows * ncols);

    if (a == NULL)
        exit(12);

    printf("Enter %d elements\n", nrows*ncols);
    for (i=0; i<(nrows*ncols); i++) {
        scanf("%d", &a[i]);
    }

    sum = fnorm(a, nrows, ncols);

    printf("result=%lf\n", sum);

    return 0;
}


double fnorm(int *a, int nrows, int ncols)
{
    /* Eq to get index of a(ij)
     * (i*ncol) - j - 1
     */
    
    int m, n;
    double sum = 0.0;

    for (m=1; m<=nrows; m++) {
        for (n=1; n<=ncols; n++) {
            sum += pow( a[(m*ncols)-n-1], 2 );
        }
    }
    return (sum);
}
