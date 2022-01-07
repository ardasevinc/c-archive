/* Solution of L01 of EE 204
 * Author: Arda Sevinç - 260206019
 * Written on a unix-based operating system on 2020-05-18 */
#include <stdio.h>

/* *a, *b, *c and *t are all pointers to the 
 * first element of a matrix(multidimensional array) */
void read_matrix(int *a, int m, int n);
void print_matrix(int *a, int m, int n);

void mat_mult(
        int *a,
        int *b,
        int *c,
        int m,
        int n,
        int p
        );

void mat_transpose(int *a, int *t, int m, int n);

void mat_add(
        int *a,
        int *b,
        int *c,
        int m,
        int n
        );

int main() {
    int m, n, sel;

    /* User is asked to input the dimension for the first matrix */
    printf("Enter the dimensions of your matrix seperated by a whitespace (m n)\n");
    scanf("%d %d", &m, &n);
    printf("\nYou entered a dimension of %d X %d\n", m, n);

    /* We define the first matrix since we have its size */
    int matA[m][n];

    printf("-------------------OPTIONS------------------------\n");
    printf("1.    Matrix addition\n");
    printf("2.    Matrix multiplication\n");
    printf("3.    Transpose\n");
    printf("--------------------------------------------------\n");

    printf("Your selection = ");
    scanf("%d", &sel);
    printf("You selected %d\n", sel);
    printf("--------------------------------------------------\n");

    /* Switch case is used to reduce clutter */
    switch(sel) {
        /* I used curly brackets because of matrix definitions below.
         * C doesn't allow local-scoped variables otherwise */

        /* Addition */
        case 1: {
                    /* These are local variables, valid in only case 1*/
                    int m_user, n_user;
                    int matB[m][n];
                    int matC[m][n];

                    printf("Enter the dimensions for the second matrix B\n");
                    scanf("%d %d", &m_user, &n_user);
                    /* printf("I got %d and %d\n", m_user, n_user); */

                    while (m_user != m || n_user != n) {
                        printf("\nIllegal matrix size for second matrix B\n");
                        printf("Enter the size again\n");
                        scanf("%d %d", &m_user, &n_user);
                        /* printf("I got %d and %d", m_user, n_user); */
                    }

                    printf("Input %d values for the first matrix A\n", m*n);
                    read_matrix(&matA[0][0], m, n);
                    printf("------------------------------------\n");
                    printf("Input %d values for the second matrix B\n", m*n);
                    read_matrix(&matB[0][0], m, n);
                    printf("------------------------------------\n");

                    print_matrix(&matA[0][0], m, n);
                    printf("\n + \n\n");
                    print_matrix(&matB[0][0], m, n);
                    printf("\n = \n\n");

                    /* Perform the addition */
                    mat_add(
                            &matA[0][0],
                            &matB[0][0],
                            &matC[0][0],
                            m,
                            n
                           );

                    printf("--------------RESULTS----------------\n");
                    print_matrix(&matC[0][0], m, n);
                    break;
                }
        /* Multiplication */
        case 2: {
                    /* n_user is defined to compare the expected n to the number
                     * that user entered
                     * It uses the fact that in matrix multiplication
                     * dimensions should be
                     * (m x n) * (n x p) = (m x p) */
                    int n_user, p;
                    printf("Enter the dimensions of second matrix B\n");
                    scanf("%d %d", &n_user, &p);

                    /* We only need to compare n because p is free to choose */
                    while (n_user != n) {
                        printf("\nIllegal matrix dimension!\n");
                        printf("Enter the size for matrix B again\n");
                        scanf("%d %d", &n_user, &p);
                    }
                    /* Define the needed matrices immediately since we have the dimensions */
                    int matB[n][p];
                    int matC[m][p];
                    printf("Input %d values for the first matrix A\n", m*n);
                    read_matrix(&matA[0][0], m, n);
                    printf("------------------------------------\n");
                    printf("Input %d values for the second matrix B\n", n*p);
                    read_matrix(&matB[0][0], n, p);
                    printf("------------------------------------\n");

                    print_matrix(&matA[0][0], m, n);
                    printf("\n X \n\n");
                    print_matrix(&matB[0][0], n, p);
                    printf("\n = \n\n");

                    /* Perform the multiplication */
                    mat_mult(
                            &matA[0][0],
                            &matB[0][0],
                            &matC[0][0],
                            m,
                            n,
                            p
                            );
                    printf("--------------RESULTS----------------\n");
                    print_matrix(&matC[0][0], m, p);
                    break;
                }

        case 3: {
                    int mat_T[n][m];

                    printf("Input %d values\n", m*n);
                    read_matrix(&matA[0][0], m, n);

                    mat_transpose(
                            &matA[0][0],
                            &mat_T[0][0],
                            m,
                            n
                            );
                    printf("--------------RESULTS----------------\n");
                    print_matrix(&mat_T[0][0], n, m);
                    break;

                }

        default:
                printf("Illegal selection!\n");
    }

    return 0;
}

/* Define macros for pointer arithmetic */
#define A(I, J) (*( a + (I) * n + (J) ))
#define B(I, J) (*( b + (I) * p + (J) ))
#define C(I, J) (*( c + (I) * p + (J) ))
void read_matrix(int *a, int m, int n) {
    int i, j;
    for ( i = 0; i < m; i++ ) {
        for ( j = 0; j < n; j++ ) {
            scanf("%d", &(A(i,j)));
        }
    }
}


void print_matrix(int *a, int m, int n) {
    int i, j;

    for ( i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (j == 0)
                printf("[ ");
            /* Calculate offset using pointer arithmetic to roam the matrix */
            printf("%d ", A(i,j));
            if (j == n - 1)
                printf(" ]");
        }
        /* Print a newline before changing cols */
        printf("\n");
        
    }
}


void mat_mult(
        int *a,
        int *b,
        int *c,
        int m,
        int n,
        int p
        )
{
    int i, j, k;
    int sum = 0;

    for( i = 0; i < m; i++ ) {
        for ( j = 0; j < p; j++ ) {
            sum = 0;
            for ( k = 0; k < n; k++) {
                sum += A(i, k) * B(k, j);
            }
            C(i, j) = sum;
        }
    }
}

/* I needed to redefine because the matrix sizes 
 * changed in these functions below */
#undef A 
#undef B
#undef C
#define A(I, J) (*( a + (I) * n + (J) ))
#define B(I, J) (*( b + (I) * n + (J) ))
#define C(I, J) (*( c + (I) * n + (J) ))
#define T(I, J) (*( t + (I) * n + (J) ))
void mat_transpose(int *a, int *t, int m, int n) {
    int i, j;

    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < m; j++ ) {
            T(i, j) = A(j, i);
        }
    }
}


void mat_add(
        int *a,
        int *b,
        int *c,
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
#undef A
#undef B
#undef C
#undef T
