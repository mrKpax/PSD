#include "libro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lib
{
    char titolo[50];
    char autore[50];
    char editore[50];
    float prezzo;
    int anno;
};

libro creaLibro(char *tit, char *aut, char *ed, float prez, int an)
{
    libro l = malloc(sizeof(struct lib));
    
    strcpy(l->titolo, tit);
    strcpy(l->autore, aut);
    strcpy(l->editore, ed);
    l->prezzo = prez;
    l->anno = an;
    
    return l;
}

char *autore(libro l)
{
    char *s;
    s = malloc(sizeof(char) * strlen(l->autore));
    strcpy(s, l->autore);
    return s;
}

char *titolo(libro l)
{
    char *s;
    s = malloc(sizeof(char) * strlen(l->titolo));
    strcpy(s, l->titolo);
    return s;
}

char *editore(libro l)
{
    char *s;
    s = malloc(sizeof(char) * strlen(l->editore));
    strcpy(s, l->editore);
    return s;
}

float prezzo(libro l)
{
    return l->prezzo;
}

int anno(libro l)
{
    return l->anno;
}

void sconto(libro l, float perc)
{
    float risparmio = ((l->prezzo)/100)*perc;
    float result = l->prezzo - risparmio;
    
    l->prezzo = result;
}

void modanno(libro l, int n)
{
    l->anno = n;
}

void stampa(libro l)
{
    printf("Titolo: %s\n", l->titolo);
    printf("Autore: %s\n", l->autore);
    printf("Editore: %s\n", l->editore);
    printf("Prezzo: %f\n", l->prezzo);
    printf("Anno: %d\n", l->anno);
}
