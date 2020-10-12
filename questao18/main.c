#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int MultMat(int **A, int **B, int **C, int nlA, int ncA, int ncB) //Funcão responsável pela multiplicacão das matrizes A e B;
{
    int i,j,k,aux=0;

    for(i=0;i<nlA;i++)
    {
        for(j=0;j<ncB;j++)
        {
            C[i][j] = 0;

            for(k=0;k<ncA;k++)
            {
                aux = aux + (A[i][k]*B[k][j]);
            }

            C[i][j] = aux;
            aux = 0;
        }
    }
}


int main(){

    int **A,**B,**C,i,j,x,y,x1,y1,x2,y2,x3,y3,x4,y4, nlA, ncA,ncB;


    printf("Insira o número de linhas da matriz A: \n");
    scanf("%d",&nlA);
    printf("Insira o número de colunas da matriz A: \n"); // Igual ao número de linhas da matriz B;
    scanf("%d",&ncA);
    printf("Insira o número de colunas da matriz B: \n");
    scanf("%d",&ncB);

    // Aloca os blocos auxiliares;

    A = malloc(nlA * sizeof(int*));
    B = malloc(ncA * sizeof(int*));
    C = malloc(nlA * sizeof(int*));

    // Aloca linhas;

    A[0] = malloc(nlA*ncA* sizeof(int));
    B[0] = malloc(ncA*ncB* sizeof(int));
    C[0] = malloc(nlA*ncB* sizeof(int));

    for(i=1; i<nlA;i++) // Fixa os ponteiros para aqueles que possuem número de linhas da matriz A;
    {
        A[i] = A[i-1]+ncA;
        C[i] = C[i-1]+ncB;
    }

    for(j=1;j<ncA;j++)
    {
        B[j] = B[j-1]+ncB; // Fixa os ponteiros para aqueles que possuem número de linhas da matriz B;
    }


    // Recebe os elementos da matriz A e B;

    printf("\nInsira os elementos da matriz A: \n");

    for(x=0;x<nlA;x++)
    {
        for(y=0;y<ncA;y++)
        {
            scanf("%d",&A[x][y]);
        }
    }

    printf("\nInsira os elementos da matriz B: \n");

    for(x1=0;x1<ncA;x1++)
    {
        for(y1=0;y1<ncB;y1++)
        {
            scanf("%d",&B[x1][y1]);
        }
    }



    MultMat(A,B,C,nlA,ncA,ncB);

    // Imprime as matrizes A, B e C;

    printf("\nMatriz A: \n\n");
    for(x2=0;x2 <nlA;x2++)
    {
        for(y2=0;y2<ncA;y2++)
        {
            printf("%d ", A[x2][y2]);
        }
        printf("\n");
    }

    printf("\nMatriz B: \n\n");
    for(x3=0;x3 <ncA;x3++)
    {
        for(y3=0;y3<ncB;y3++)
        {
            printf("%d ", B[x3][y3]);
        }
        printf("\n");
    }

    printf("\nMatriz C: \n\n");
    for(x4=0;x4 <nlA;x4++)
    {
        for(y4=0;y4<ncB;y4++)
        {
            printf("%d ", C[x4][y4]);
        }
        printf("\n");
    }

    return 0;
}
