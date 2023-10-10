#include "matrix_mul.h"

int print_matrix(int **list)
{
    int i,j;
    for(i=0; i<N; i++)
    {
        for(j=0;j<N;j++)
            printf("%d ",list[i][j]);
        printf("\n");
    }
    return 0;
}

void free_matrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int standard_algorithm(int **A, int **B, int **C)
{
    int i, j, k;
    int count=0;

    for (i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            C[i][j]=0;
            for (k=0; k<N; k++)
            {
                C[i][j]+=A[i][k]*B[k][j];
                count++;
            }
     
        }
    }
  
    print_matrix(C);
    printf("counting : %d\n", count);

    return 0;

}



void divide_and_conquer(int **A, int **B, int **C, int size,int *count);
void add(int **A, int **B, int **C, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void subtract(int **A, int **B, int **C, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void combine(int **C11, int **C12, int **C21, int **C22, int **C, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + size] = C12[i][j];
            C[i + size][j] = C21[i][j];
            C[i + size][j + size] = C22[i][j];
        }
    }
}

void divide_and_conquer(int **A, int **B, int **C, int size,int *count)
{

    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        (*count)++;
        return;
    }

    int half_size = size / 2;

    int **A11 = (int **)malloc(sizeof(int *) * half_size);
    int **A12 = (int **)malloc(sizeof(int *) * half_size);
    int **A21 = (int **)malloc(sizeof(int *) * half_size);
    int **A22 = (int **)malloc(sizeof(int *) * half_size);

    int **B11 = (int **)malloc(sizeof(int *) * half_size);
    int **B12 = (int **)malloc(sizeof(int *) * half_size);
    int **B21 = (int **)malloc(sizeof(int *) * half_size);
    int **B22 = (int **)malloc(sizeof(int *) * half_size);

    int **C11 = (int **)malloc(sizeof(int *) * half_size);
    int **C12 = (int **)malloc(sizeof(int *) * half_size);
    int **C21 = (int **)malloc(sizeof(int *) * half_size);
    int **C22 = (int **)malloc(sizeof(int *) * half_size);

    int **P1 = (int **)malloc(sizeof(int *) * half_size);
    int **P2 = (int **)malloc(sizeof(int *) * half_size);
    int **P3 = (int **)malloc(sizeof(int *) * half_size);
    int **P4 = (int **)malloc(sizeof(int *) * half_size);
    int **P5 = (int **)malloc(sizeof(int *) * half_size);
    int **P6 = (int **)malloc(sizeof(int *) * half_size);
    int **P7 = (int **)malloc(sizeof(int *) * half_size);

    int **temp1 = (int **)malloc(sizeof(int *) * half_size);
    int **temp2 = (int **)malloc(sizeof(int *) * half_size);

    for (int i = 0; i < half_size; i++)
    {
        A11[i] = (int *)malloc(sizeof(int) * half_size);
        A12[i] = (int *)malloc(sizeof(int) * half_size);
        A21[i] = (int *)malloc(sizeof(int) * half_size);
        A22[i] = (int *)malloc(sizeof(int) * half_size);

        B11[i] = (int *)malloc(sizeof(int) * half_size);
        B12[i] = (int *)malloc(sizeof(int) * half_size);
        B21[i] = (int *)malloc(sizeof(int) * half_size);
        B22[i] = (int *)malloc(sizeof(int) * half_size);

        C11[i] = (int *)malloc(sizeof(int) * half_size);
        C12[i] = (int *)malloc(sizeof(int) * half_size);
        C21[i] = (int *)malloc(sizeof(int) * half_size);
        C22[i] = (int *)malloc(sizeof(int) * half_size);

        P1[i] = (int *)malloc(sizeof(int) * half_size);
        P2[i] = (int *)malloc(sizeof(int) * half_size);
        P3[i] = (int *)malloc(sizeof(int) * half_size);
        P4[i] = (int *)malloc(sizeof(int) * half_size);
        P5[i] = (int *)malloc(sizeof(int) * half_size);
        P6[i] = (int *)malloc(sizeof(int) * half_size);
        P7[i] = (int *)malloc(sizeof(int) * half_size);

        temp1[i] = (int *)malloc(sizeof(int) * half_size);
        temp2[i] = (int *)malloc(sizeof(int) * half_size);
    }

    for (int i = 0; i < half_size; i++)
    {
        for (int j = 0; j < half_size; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half_size];
            A21[i][j] = A[i + half_size][j];
            A22[i][j] = A[i + half_size][j + half_size];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half_size];
            B21[i][j] = B[i + half_size][j];
            B22[i][j] = B[i + half_size][j + half_size];
        }
    }


    add(A11, A22, temp1, half_size);
    add(B11, B22, temp2, half_size);
    divide_and_conquer(temp1, temp2, P1, half_size,count);

    add(A21, A22, temp1, half_size);
    divide_and_conquer(temp1, B11, P2, half_size,count);

    subtract(B12, B22, temp1, half_size);
    divide_and_conquer(A11, temp1, P3, half_size,count);

    subtract(B21, B11, temp1, half_size);
    divide_and_conquer(A22, temp1, P4, half_size,count);

    add(A11, A12, temp1, half_size);
    divide_and_conquer(temp1, B22, P5, half_size,count);

    subtract(A21, A11, temp1, half_size);
    add(B11, B12, temp2, half_size);
    divide_and_conquer(temp1, temp2, P6, half_size,count);

    subtract(A12, A22, temp1, half_size);
    add(B21, B22, temp2, half_size);
    divide_and_conquer(temp1, temp2, P7, half_size,count);

    add(P1, P4, temp1, half_size);
    subtract(temp1, P5, temp2, half_size);
    add(temp2, P7, C11, half_size);
    add(P3, P5, C12, half_size);
    add(P2, P4, C21, half_size);
    add(P1, P3, temp1, half_size);
    subtract(temp1, P2, temp2, half_size);
    add(temp2, P6, C22, half_size);

    combine(C11, C12, C21, C22, C, half_size);

    free_matrix(A11, half_size);
    free_matrix(A12, half_size);
    free_matrix(A21, half_size);
    free_matrix(A22, half_size);

    free_matrix(B11, half_size);
    free_matrix(B12, half_size);
    free_matrix(B21, half_size);
    free_matrix(B22, half_size);

    free_matrix(C11, half_size);
    free_matrix(C12, half_size);
    free_matrix(C21, half_size);
    free_matrix(C22, half_size);

    free_matrix(P1, half_size);
    free_matrix(P2, half_size);
    free_matrix(P3, half_size);
    free_matrix(P4, half_size);
    free_matrix(P5, half_size);
    free_matrix(P6, half_size);
    free_matrix(P7, half_size);

    free_matrix(temp1, half_size);
    free_matrix(temp2, half_size);

    printf("Partial matrix\n");
    print_matrix(C);
    

}