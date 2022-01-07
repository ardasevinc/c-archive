#include "matrix.h"

#define A(I, J) (*( a + (I) * n + (J) ))
#define B(I, J) (*( b + (I) * p + (J) ))
#define C(I, J) (*( c + (I) * p + (J) ))


void print_vector(double vec[], int n) {
    int i;

    printf("[ ");
    for ( i = 0; i < n; i++ ) {
        printf("%f ", vec[i]);
    }
    printf(" ]\n");
}


/* Could be configured to return a pointer but I didn't want that */
void read_vector(double vec[], int n) {
    int i = 0;

    /* Get entries from a line or lines until an illegal character
     * (like EOF or non-numeric) is encountered */
    while ( i < n && ( scanf("%le", &vec[i]) == 1) ) {
        i++;
    }
    /* Return a pointer to the first element of the vector temp */
}


/* This returns a pointer to a globally allocated memory location
 * We don't want to touch the original vector so we return another answer array */
double * scalar_multiplication(double a[], int nvec, double scalar) {
    int i;
    /* Allocate memory for the answer vector that will be returned */
    double *ans_vec = malloc( sizeof(double) * nvec );

    for ( i = 0; i < nvec; i++ ) {
        ans_vec[i] = a[i] * scalar;
    }
    /* Return a pointer to the first element of the vector */
    return ans_vec;
}


/* Multiply two 3-dimensional vectors */
double * vector_3_product(double a[], double b[], int n) {
    double *ans_vec = malloc( sizeof(double) * n );

    ans_vec[0] = a[1] * b[2] - a[2] * b[1];
    ans_vec[1] = a[2] * b[0] - a[0] * b[2];
    ans_vec[2] = a[0] * b[1] - a[1] * b[0];
    
    return ans_vec;
}


double inner_product(double a[], double b[], int n) {
    int i;
    double sum;

    for ( i = 0; i < n; i++ ) {
        sum += a[i] * b[i]; 
    }
    return sum;
}


void read_matrix(double *a, int m, int n) {
    int i, j;
    for ( i = 0; i < m; i++ ) {
        for ( j = 0; j < n; j++ ) {
            scanf("%le", &(A(i,j)));
        }
    }
}


void print_matrix(double *a, int m, int n) {
    int i, j;

    for ( i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%3.4lf ", A(i,j));
        }
        /* Print a newline before changing cols */
        printf("\n");
        
    }
}


void print_transpose(double *a, int m, int n) {
    int i, j;

    for ( i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%3.4lf ", A(j,i));
        }
        /* Print a newline before changing cols */
        printf("\n");
        
    }
}


void mat_mult(
        double *a,
        double *b,
        double *c,
        int m,
        int n,
        int p
        )
{
    int i, j, k;
    double sum = 0.0;

    for( i = 0; i < m; i++ ) {
        for ( j = 0; j < p; j++ ) {
            sum = 0.0;
            for ( k = 0; k < n; k++) {
                sum += A(i, k) * B(k, j);
            }
            C(i, j) = sum;
        }
    }
}

/* Redefine A, B and C
 * we need A, B and C to be same size
 * which was not the case with the prev macro def */
#undef A 
#undef B
#undef C
#define A(I, J) (*( a + (I) * n + (J) ))
#define B(I, J) (*( b + (I) * n + (J) ))
#define C(I, J) (*( c + (I) * n + (J) ))
void transpose(double *a, double *b, int m, int n) {
    int i, j;

    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < m; j++ ) {
            B(i, j) = A(j, i);
        }
    }
}


void mat_add(
        double *a,
        double *b,
        double *c,
        int m,
        int n
        )
{
    int i, j;
    for ( i = 0; i < m; i++ ) {
        for (j = 0; j < n; j++) {
            C(i, j) = A(i, j) + B(i, j);
        }
    }
}


void mat_scalar(
        double *a,
        double x, /* scalar */
        int m, /* Size info */
        int n
        )
{
    int i, j;

    for ( i = 0; i < m; i++ ) {
        for ( j = 0; j < n; j++ ) {
            A(i, j) = A(i, j) * x;
        }
    }
}
#undef A
#undef B
#undef C
