#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int linha, coluna;
    int **mat = NULL; //é um ponteiro para uma estrutura de ponteiros
    int i, j;

    printf ("Digite a largura (linhas) e a altura (colunas) : ");
    scanf ("%d %d", &linha, &coluna);

    mat = (int **)malloc(coluna*sizeof(int*));
    for (i=0; i<coluna; i++)
    {
        mat[i] = (int *)malloc(coluna*sizeof(int));
    }

    srand(time(NULL));
    for (i=0; i<linha; i++)
        for(j=0; j<coluna; j++)
        {
            mat[i][j] = rand()%1000;
        }

    printf ("\n\n Matriz: \n");
    for (i=0; i<linha; i++)
    {
        for(j=0; j<coluna; j++)
        {
            printf("% 3d \t", mat[i][j]);
        }
        printf ("\n");
    }

    for (i=0; i<linha; i++)
    {
        free(mat[i]);
    }
    free(mat);

    return 0;
}