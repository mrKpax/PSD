#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

int numero_punti(char *file_name)
{
    int n = 0;
    FILE *sp;
    float x, y;

    sp = fopen(file_name, "r");
    if (sp != NULL)
    {
        while(fscanf(sp, "%f%f", &x, &y) == 2)
        {
            n++;
        }
        fclose(sp);
    }
    return n;
}

void carica_punti(char *file_name, punto a[], int n)
{
    int i = 0;
    FILE *sp;
    float x, y;

    sp = fopen(file_name, "r");
    if (sp == NULL)
    {
        printf("Errore in apertura del file %s \n", file_name);
    }

    while(fscanf(sp, "%f%f", &x, &y) == 2)
    {
        a[i] = creaPunto(x, y);
        i++;
    }

    fclose(sp);
}

int coppie_vicine(punto a[], int n, float d)
{
    int i, j, m;
    m = 0;
    for (i=0; i<n-1; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if (distanza(a[i], a[j]) < d)
            {
                m++;
            }
        }
    }
    return m;
}

int main(int argc, char *argv[])
{
    float d;
    int n, m;
    punto *a; //array di punti
    d = atof(argv[2]);

    if(argc<3)
    {
        printf("Numero di parametri non corretto \n");
        exit(-1);
    }

    //passo 2
    n = numero_punti(argv[1]);
    if (n == 0)
    {
        printf("Nessun punto caricato dal file %s \n", argv[1]);
        exit(-1);
    }

    //passo 3
    a = malloc(n * sizeof(punto));
    carica_punti(argv[1], a, n);

    //passo 4
    m = coppie_vicine(a, n, d);

    //passo 5
    printf("Numero di coppie di punti nel file %s ", argv[1]);
    printf("con distanza minore di %f: %d \n", d, m);
    return 0;
}
