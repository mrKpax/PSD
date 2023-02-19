#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"

void ricercavecchio(libro biblioteca[], int n)
{
    libro vecchio = biblioteca[0];
    for (int i=1; i<n; i++)
    {
        if(anno(biblioteca[i]) < anno(vecchio))
        {
            vecchio = biblioteca[i];
        }
    }
    printf("\nLibro più vecchio: \n");
    stampa(vecchio);
    printf("\n");
}

void ricercaeconomico(libro biblioteca[], int n)
{
    libro economico = biblioteca[0];
    for (int i=1; i<n; i++)
    {
        if(prezzo(biblioteca[i]) < prezzo(economico))
        {
            economico = biblioteca[i];
        }
    }
    printf("\nLibro più economico: \n");
    stampa(economico);
    printf("\n");
}

void librieditore(libro biblioteca[], int n)
{
    char target[50];
    printf("\nDi quale editore vuoi cercare i libri? ");
    scanf("%s", target);

    printf("\nEcco i libri di %s: \n", target);
    for (int i=0; i<n; i++)
    {
        if((strcmp(editore(biblioteca[i]), target)) == 0)
        {
            stampa(biblioteca[i]);
            printf("\n");
        }
    }
}

void scontoanno(libro biblioteca[], int n)
{
    int year;
    float perc;
    printf("\nQual è l'anno dei libri da scontare? ");
    scanf("%d", &year);
    printf("Qual è la percentuale dello sconto? ");
    scanf("%f", &perc);

    for(int i=0; i<n; i++)
    {
        if((anno(biblioteca[i])) == year )
        {
            sconto(biblioteca[i], perc);
        }
    }
}

float differenza(libro l1, libro l2)
{
    float diff;
    diff = prezzo(l1) - prezzo(l2);

    return diff;
}

void prezzosimile (libro biblioteca[], int n)
{
    libro l1;
    libro l2;
    float diffmin = 100000;

    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if( ((differenza(biblioteca[i], biblioteca[j])) < diffmin) && ((differenza(biblioteca[i], biblioteca[j])) > 0))
            {
                  diffmin = differenza(biblioteca[i], biblioteca[j]);
                  l1 = biblioteca[i];
                  l2 = biblioteca[j];
            }
        }
    }

    printf("\nI libri con differenza di prezzo minima (%f), sono:\n", diffmin);
    stampa(l1);
    printf("\n");
    stampa(l2);
    printf("\n");
}

void costoanno(libro biblioteca[], int n)
{
    int year;
    float sum = 0;

    printf("\nQual è l'anno di cui vuoi sommare il costo dei libri? ");
    scanf("%d", &year);

    for (int i=0; i<n; i++)
    {
        if( (anno(biblioteca[i])) == year )
        {
            sum = sum + prezzo(biblioteca[i]);
        }
    }

    printf("\nLa somma dei prezzi dei libri dell'anno %d è: %f\n", year, sum);
}

int main(void)
{
    char tit[50], aut[50], ed[50];
    float prezzo;
    int anno;
    int n, op;
    libro *biblioteca;

    printf("Quanti libri vuoi inserire? ");
    scanf("%d", &n);
    biblioteca = malloc(sizeof(libro)*n);

    for (int i=0; i<n; i++)
    {
        printf("Titolo libro %d: ", i+1);
        scanf("%s", tit);
        printf("Autore libro %d: ", i+1);
        scanf("%s", aut);
        printf("Editore libro %d: ", i+1);
        scanf("%s", ed);
        printf("Prezzo libro %d: ", i+1);
        scanf("%f", &prezzo);
        printf("Anno libro %d: ", i+1);
        scanf("%d", &anno);
        biblioteca[i] = creaLibro(tit, aut, ed, prezzo, anno);
        printf("\n");
    }

    while(op != 0)
    {
        printf("\n");
        printf("0) Esci dal programma.\n");
        printf("1) Ricerca del libro più vecchio.\n");
        printf("2) Ricerca del libro meno costoso.\n");
        printf("3) Ricerca di tutti i libri di un editore.\n");
        printf("4) Applica sconto ai libri di un certo anno.\n");
        printf("5) Trova libri con differenza di prezzo minore.\n");
        printf("6) Calcola costo totale dei libri di un certo anno.\n");
        printf("Quale operazione vuoi eseguire? ");
        scanf("%d", &op);

        switch(op)
        {
            case 0:
                break;

            case 1:
                ricercavecchio(biblioteca, n);
                break;

            case 2:
                ricercaeconomico(biblioteca, n);
                break;

            case 3:
                librieditore(biblioteca, n);
                break;

            case 4:
                scontoanno(biblioteca, n);
                break;

            case 5:
                prezzosimile(biblioteca, n);
                break;

            case 6:
                costoanno(biblioteca, n);
                break;

            default:
                break;
        }

    }

    return 0;
}
