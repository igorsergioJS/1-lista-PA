#include "gc.h"
#include <gc/gc.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void OldMalloc()
{
    int j,i, *x, n = 250;

    x = malloc(n * sizeof(int));

    for(i=0;i<n;i++)
    {
        x[i] = rand() % 100;
    }

    free(x);
}

void GCmalloc()
{
    int j,i, *x, n = 250;

    x = GC_malloc(n * sizeof(int));

    for(i=0;i<n;i++)
    {
        x[i] = rand() % 100;
    }


}


int main()
{
    clock_t t; // Variável para armazenar tempo;
    clock_t k;

    t = clock(); //Armazena tempo antes da chamada da funcão
    OldMalloc();
    t = clock() - t; // Tempo final - Tempo inicial;
    printf("\nTempo de execucao do malloc: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
    printf(" milissegundos.");

    k = clock(); // Variável para armazenar tempo;
    GCmalloc();
    k = clock() - k; //Armazena tempo antes da chamada da funcão
    printf("\nTempo de execucao do GC_malloc: %lf", ((double)k)/((CLOCKS_PER_SEC/1000))); //conversão para double
    printf(" milissegundos.");



    return 0;
}
