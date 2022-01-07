#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>
void read_matrix(double *a, int m, int n);
void print_matrix(double *a, int m, int n);
void print_transpose(double *a, int m, int n);
void transpose(double *a, double *b, int m, int n);

void mat_mult(
        double *a,
        double *b,
        double *c,
        int m,
        int n,
        int p
        );

void mat_scalar(
        double *a,
        double x, 
        int m, 
        int n
        );

void mat_add(
        double *a,
        double *b,
        double *c,
        int m,
        int n
        );

void read_vector(double vec[], int n);
void print_vector(double vec[], int n);

double inner_product(double a[], double b[], int n);
double * vector_3_product(double a[], double b[], int n);
double * scalar_multiplication(double a[], int nvec, double scalar);
#endif
