#include <stdio.h>
#define MAX 100

void input_array(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("Elemento di posizione %d: ", i);
        scanf("%d", &a[i]);
    }
}

int minimo_i(int a[], int i, int n)
{
    int min, pmin, j;
    min = a[i];
    pmin = i;
    for (j=i+1; j<n; j++)
    {
        if (a[j] < min)
        {
            min = a[j];
            pmin = j;
        }
    }
    return (pmin);
}

void scambia(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void ordina_array(int a[], int n)
{
    int i, p;
    for (i=0; i<n-1; i++)
    {
        p = minimo_i(a,i,n);
        scambia(&a[i],&a[p]);
    }
}

void output_array(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("Elemento di posizione %d: %d \n", i, a[i]);
    }
}

int main()
{
    int a[MAX], n;
    printf("Inserisci il numero di elementi da ordinare: ");
    scanf("%d", &n);

    if (n<=0)
    {
        fprintf(stderr, "Numero di elementi non valido \n");
    }
    else if (n > MAX)
    {
        printf("Il numero massimo di elementi è MAX \n");
    }
    else
    {
        input_array(a,n);
        ordina_array(a,n);
        output_array(a,n);
    }

    return 0;
}
