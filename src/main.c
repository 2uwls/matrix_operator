#include <stdio.h>
#include <stdlib.h>
#include "matrix_mul.h"
#include "fill_random_num.h"

#define N 4

int main ()
{
    int **A=(int**)malloc(sizeof(int *)*N);
    int **B=(int**)malloc(sizeof(int *)*N);
    int **C=(int**)malloc(sizeof(int *)*N);
    for(int t=0; t<N; t++)
    {
        A[t]=(int *)malloc(sizeof(int)*N);
        B[t]=(int *)malloc(sizeof(int)*N);
        C[t]=(int *)malloc(sizeof(int)*N);
    }

    fill_random_num(A,B);
    printf("Matrix A\n");
    print_matrix(A);
    printf("Matrix B\n");
    print_matrix(B);
    printf("Matrix C\n");
    printf("standard_algorithm\n");
    standard_algorithm(A,B,C);
    printf("\n");
    int count=0;
    printf("divide_and_conquer\n");
    divide_and_conquer(A, B, C, N,&count);
    printf("counting: %d",count);
    printf("\n");

    free_matrix(A, N);
    free_matrix(B, N);
    free_matrix(C, N);
    return 0;
}