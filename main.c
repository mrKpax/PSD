#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xalloc.h"
#define MAX 30

char* merge(char *nome, char *cognome)
{
    char *result;
    int len;
    len = (strlen(nome) + strlen(cognome));
    result = xcalloc(len+1, sizeof(char));
    
    strcpy(result, nome);
    strcat(result, cognome);
    
    return result;
}

char* incastona(char *nome, char *cognome)
{
    //verifica quale stringa sia più lunga (in caso di parità si considera il nome)
    char *longer, *shorter;
    if(strlen(nome) >= strlen(cognome))
    {
        longer = xcalloc(strlen(nome)+1, sizeof(char));
        shorter = xcalloc(strlen(cognome)+1, sizeof(char));
        strcpy(longer, nome);
        strcpy(shorter, cognome);
    }
    else if (strlen(nome) < strlen(cognome))
    {
            longer = xcalloc(strlen(cognome)+1, sizeof(char));
            shorter = xcalloc(strlen(nome)+1, sizeof(char));
            strcpy(longer, cognome);
            strcpy(shorter, nome);
    }
    
    //fase di incastonamento
    int i, j=0, llen, slen;
    llen = strlen(longer);
    slen = strlen(shorter);
    for (i = (llen-slen)/2; i<(llen+slen)/2; i++)
    {
        longer[i] = shorter[j];
        j++;
    }
    return longer;
}

void inverti(char **matrice)
{
    char *temp;
    temp = xcalloc(strlen(matrice[0])+1, sizeof(char));
    strcpy(temp, matrice[0]);
    
    strcpy(matrice[0], matrice[1]);
    strcpy(matrice[1], temp);
    free(temp);
}

void crea (char **matrice)
{
    int len;
    len = strlen(matrice[0]);
    matrice[2] = xcalloc(7, sizeof(char));
    
    strncat(matrice[2], matrice[1], 3);
    strcat(matrice[2], matrice[0]+(len-3));
    
    printf("Collage: %s\n", matrice[2]);
}

void ordina(char *s)
{
    int len = strlen(s);
    char temp;
    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if (s[i] > s[j])
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main(void)
{
    char *nome, *cognome;
    nome = xcalloc(MAX, sizeof(char));
    cognome = xcalloc(MAX, sizeof(char));
    
    printf("Inserisci il nome: ");
    scanf("%s", nome);
    nome = xrealloc(nome, strlen(nome)+1);
    
    printf("Inserisci il cognome: ");
    scanf("%s", cognome);
    cognome = xrealloc(cognome, strlen(cognome)+1);
    
    char *concat;
    concat = merge(nome, cognome);
    printf("Risultato concatenazione: %s\n", concat);
    
    char *sandwich;
    sandwich = incastona(nome, cognome);
    printf("Risultato incastonamento: %s\n", sandwich);
    
    char *nomecognome[2];
    nomecognome[0] = nome;
    nomecognome[1] = cognome;
    inverti(nomecognome);
    printf("Matrice invertita: %s %s\n", nomecognome[0], nomecognome[1]);
    
    crea(nomecognome);
    
    ordina(nome);
    ordina(cognome);
    printf("Nome ordinato: %s\n", nome);
    printf("Cognome ordinato: %s\n", cognome);
    
    return 1;
}
