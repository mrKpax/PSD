#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

void input_punti(punto a[], int n)
{
    float x,y;
    for (int i=0; i<n; i++)
    {
        printf("Ascissa punto %d: ",i);
        scanf("%f", &x);
        printf("Ordinata punto %d: ",i);
        scanf("%f", &y);

        a[i] = creaPunto(x,y);
    }
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

int main()
{
    float d;
    int n, m;
    punto *a;

    //passo 1
    printf("Numero di punti da caricare: ");
    scanf("%d", &n); 

    //passo 2
    a = malloc(n * sizeof(punto));

    //passo 3
    input_punti(a,n);

    //passo 4
    printf("Inserisci distanza: ");
    scanf("%f", &d);

    //passo 5
    m = coppie_vicine(a, n, d);
    printf("Numero di coppie di punti con distanza ");

    //passo 6
    printf("minore di %f: %d \n", d, m);
    return 0;
}
