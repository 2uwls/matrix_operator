#include <stdio.h>
#include <stdlib.h>

#define N 4

int print_matrix(int **list);
void free_matrix(int **matrix, int size);
int standard_algorithm(int **A, int **B, int **C);
void divide_and_conquer(int **A, int **B, int **C, int size,int *count);
void add(int **A, int **B, int **C, int size);
void subtract(int **A, int **B, int **C, int size);
void combine(int **C11, int **C12, int **C21, int **C22, int **C, int size);
