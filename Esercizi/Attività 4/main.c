#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

void input(punto p[], int n)
{
    float x, y;
    for(int i=0; i<n; i++)
    {
        printf("Ascissa punto %d: ", i+1);
        scanf("%f", &x);
        printf("Ordinata punto %d: ", i+1);
        scanf("%f", &y);
        p[i] = creaPunto(x, y);
    }
}

int distanzamin(punto p[], int n, float d)
{
    int coppie = 0;
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if(distanza(p[i], p[j]) < d)
            {
                coppie++;
            }
        }
    }
    return coppie;
}

int distanzamax(punto p[], punto pmax[], int n)
{
    float dmax = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (distanza(p[i], p[j]) > dmax)
            {
                dmax = distanza(p[i], p[j]);
                pmax[0] = p[i];
                pmax[1] = p[j];
            }
        }
    }
    return dmax;
}

int main(void)
{
    int n = 0, m = 0, op;
    float d;
    punto *p;
    punto pmax[2];
    
    printf("Coppie di punti da inserire: ");
    scanf("%d", &n);
    p = malloc(sizeof(punto)*n);
    input(p, n);
    
    printf("1) Cerca coppie di punti a distanza minore di una immessa.\n");
    printf("2) Cerca i due punti a distanza massima.\n");
    printf("Quale operazione vuoi eseguire? ");
    scanf("%d", &op);
    
    switch(op)
    {
        case 1:
            printf("Inserire distanza massima: ");
            scanf("%f", &d);
            m = distanzamin(p, n, d);
            printf("Le coppie di punti a distanza minore di %f sono %d\n", d, m);
            break;
            
        case 2:
            d = distanzamax(p, pmax, n);
            printf("I punti a distanza massima (%f) sono: \n", d);
            stampa(pmax[0]);
            stampa(pmax[1]);
            break;
        
        default:
            break;
    }
    
    return 0;
}
