/* LAB 02 of EE204, 2020
 * Arda Sevinç, 260206019 */
#include <stdio.h>

void print_vector(double vec[], int n);
void read_vector(double vec[], int n);
void read_matrix(double *a, int m, int n);
void print_matrix(double *a, int m, int n);
double det3(double *a);
double det4(double *b);
void calc_minor(double *mat, double *min);


#define N 4
int main() {
    int m, n, sel;

    double matA[N][N];
    double b[N];

    printf("\tChoose operation mode\n");
    printf("\t 1: I/O\n");
    printf("\t 2: 3x3 Determinant\n");
    printf("Selection: ");
    
    scanf("%d", &sel);

    switch(sel) {
        case 1: {
                    printf("> Input %d elements for coefficient matrix A\n", N*N);
                    read_matrix(&matA[0][0], N, N);
                    
                    printf("------------------------\n");
                    print_matrix(&matA[0][0], N, N);
                    printf("------------------------\n");
                    
                    printf("> Input %d elements for right-hand side vector b\n", N);
                    read_vector(b, N);

                    printf("------------------------\n");
                    print_vector(b, N);
                    printf("------------------------\n");
                }
        case 2: {
                    double mat1[3][3];

                    printf("> Input %d elements for determinant calculation\n", 3*3);
                    read_matrix(&mat1[0][0], 3, 3);

                    printf("------------------------\n");
                    print_matrix(&mat1[0][0], 3, 3);
                    printf("------------------------\n");

                    double determinant = det3(&mat1[0][0]);

                    printf("\t Determinant=%4.4le\n", determinant);
                    break;
                }
    }
    printf("Press enter to exit...");
    getchar();
    return 0;
}
#undef N

void print_vector(double vec[], int n) {
    int i;

    printf("[ ");
    for ( i = 0; i < n; i++ ) {
        printf("%f ", vec[i]);
    }
    printf(" ]\n");
}


void read_vector(double vec[], int n) {
    int i = 0;

    /* Get entries from a line or lines until an illegal character
     * (like EOF or non-numeric) is encountered */
    while ( i < n && ( scanf("%le", &vec[i]) == 1) ) {
        i++;
    }
    /* Return a pointer to the first element of the vector temp */
}

#define A(I, J) (*( a + (I) * n + (J) ))
#define B(I, J) (*( b + (I) * p + (J) ))

void read_matrix(double *a, int m, int n) {
    int i, j;
    for ( i = 0; i < m; i++ ) {
        for (j = 0; j < n; j++) {
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


double det3(double *a) {
    double first, second, third, sum;
    int n = 3;

    first = A(0,0) * ( A(1,1)*A(2,2) - A(1,2)*A(2,1) );
    second = -A(0,1) * ( A(1,0)*A(2,2) - A(1,2)*A(2,0) );
    third = A(0,2) * ( A(1,0)*A(2,1) - A(1,1)*A(2,0) );

    sum = first + second + third;
    return sum;
}


/* double det4(double *b) { */
/*     /1* Size p as shown in the macro for B *1/ */
/*     int i, p = 4; */
/*     double sum = 0, det3; */

/*     for (i=0; i<p; i++) { */
/*         if (i % 2 == 0) { */
/*             sum += det3() */
/*         } */
/*     } */
/* } */

#define Mat(I,J) (*( mat + (I)*4 + J ))
#define Min(I,J) (*( min + (I)*4 + J ))
void calc_minor(double *mat, double *min) {
    double b[4][4];
    int m, n, i, j, c, q, p;
    for (q = 0; q < 4; q++) {
        for (p = 0; p < 4; p++) {
            m = 0;
            n = 0;
            for (i = 0; i < 4; i++) {
                    for (j=0; j<4; j++) {
                        if (i != q && j != p) {
                            b[m][n] = Mat(i,j);
                        }
                        if (n < 2) {
                            n++;
                        }
                        else {
                            n = 0;
                            m++;
                        }
                    }
        Min(q,p) = det3(&b[0][0]);
            }
        }
    }
}
#undef A
#undef B
#undef Mat
#undef Min
