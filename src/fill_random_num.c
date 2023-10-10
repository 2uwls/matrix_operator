#include "stddef.h"
#include "fill_random_num.h"
#define N 4

void fill_random_num(int **A, int **B)
{
    int i, j;
    srand(time(NULL));
    for (i=0; i<N; i++)
    {
        for (j=0;j<N; j++)
            A[i][j]=rand()%1000;
    }
    for(i=0;i<N;i++)
    {
        for (j=0; j<N; j++)
            B[i][j]=rand()%1000;
    }

}