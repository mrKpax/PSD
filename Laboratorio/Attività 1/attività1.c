#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulo.h"
#define MAX 50

//funzione che trova il carattere minimo in una stringa secondo la tabella ASCII
char minimo(char *s)
{ 
    char min = s[0];
    int len = strlen(s);
    for (int i = 1; i < len; i++)
    {
        if (s[i] < min)
        {
            min = s[i];
        }
    }
    return min;
}

int main()
{
    char *nome, *cognome, minn, minc;

    nome = xcalloc(MAX, sizeof(char));
    cognome = xcalloc(MAX, sizeof(char));

    printf("Inserisci il nome: ");
    scanf("%s", nome);
    nome = xrealloc(nome, strlen(nome)+1);
    
    printf("Inserisci il cognome: ");
    scanf("%s", cognome);
    cognome = xrealloc(cognome, strlen(cognome)+1);

    minn = minimo(nome);
    minc = minimo(cognome);
    printf("Minimo del nome: %c, minimo del cognome: %c\n", minn, minc);

    return 0;
}
