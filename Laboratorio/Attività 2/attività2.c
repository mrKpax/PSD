#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "modulo.h"
#define MAX 50

void readLine(char *s, int len)
{
    fgets(s, len, stdin);
    int newlen = strlen(s);

    if (s[newlen-1] == '\n')
    {
        s[newlen-1] = '\0';
    }
}

char *readString(int len)
{
    char *s = xmalloc(len);
    readLine(s,len);
    int newlen = strlen(s);

    char *s1 = xmalloc(newlen);
    strcpy(s1,s);
    free(s);
    return s1;
}

char **crea_matrice()
{
    char **nomecognome;
    
    nomecognome = xmalloc(2);

    for (int i=0; i<2; i++)
    {
        nomecognome[i] = readString(MAX);
    }

    return nomecognome;
}

char *merge(char *nome, char *cognome)
{
    void *result, *s1, *s2;
    int len = strlen(nome) + strlen(cognome);
    
    s1 = xmalloc(strlen(nome) * sizeof(char));
    s2 = xmalloc(strlen(cognome) * sizeof(char));
    result = xmalloc(len * sizeof(char));
    
    strcpy(s1, nome);
    strcpy(s2, cognome);
    strcpy(result, strcat(s1,s2));
    
    free(s1);
    free(s2);
    return result;
}

char *incastona(char *longer, char *shorter)
{
    char *result;
    int len = strlen(longer);
    result = xmalloc(len * sizeof(char));
    
    int n1 = (strlen(longer) - strlen(shorter))/2; //posizione di partenza
    int n2 = (strlen(longer) + strlen(shorter))/2;  //tetto massimo
    
    int i, j;
    for (i=0, j=0; i<=len; i++)
    {
        if(i<n1)
        {
            result[i] = longer[i];
        }
        else
        {
            if(i>=n1 && i<n2)
            {
                result[i] = shorter[j++];
            }
            else
            {
                result[i] = longer[i];
            }
        }
    } 
    return result;
}

void inverti(char **matrice)
{
    char temp[strlen(matrice[0])+1];
    strcpy(temp, matrice[0]);

    matrice[0] = xrealloc(matrice[0],strlen(matrice[1])+1);
    strcpy(matrice[0],matrice[1]);

    matrice[1] = xrealloc(matrice[1],strlen(temp)+1);
    strcpy(matrice[1],temp);

    printf("\nPrima stringa: %s\n", matrice[0]);
    printf("Seconda stringa: %s\n", matrice[1]);
}

void crea(char **matrice)
{   
    matrice[2] = xcalloc(7,1); 

    strncat(matrice[2], matrice[1], 3);

    int len = strlen(matrice[0]);
    strcat(matrice[2], matrice[0] + (len-3));

    matrice[2][6] = '\0';

    printf("\nStringa concatenata: %s\n", matrice[2]);
}

void swap(char matrice[], int i, int j)
{
    char temp;
    temp = matrice[i];
    matrice[i] = matrice[j];
    matrice[j] = temp;
}

int shift(char matrice[], int n)
{
    int scambi = 0;
    for (int i=0; i<n-1; i++)
    {
        if(matrice[i] > matrice[i+1])
        {
            swap(matrice, i, i+1);
            scambi = 1;
        }
    }
    return scambi;
}

void bubble(char matrice[], int n)
{
    while(shift(matrice,n));
}

void ordina(char **matrice)
{
    for (int i=0; i<2; i++)
    {
        bubble(matrice[i], strlen(matrice[i]));
    }

    printf("\nNome: %s\n", matrice[1]);
    printf("Cognome: %s\n", matrice[0]);
}

int main()
{
    char *nome, *cognome, *nomecognome[2];

    nome = xcalloc(MAX, sizeof(char));
    cognome = xcalloc(MAX, sizeof(char));

    printf("Inserisci il nome: ");
    scanf("%s", nome);
    nome = xrealloc(nome, strlen(nome)+1);

    printf("Inserisci il cognome: ");
    scanf("%s", cognome);
    cognome = xrealloc(cognome, strlen(cognome)+1);

    nomecognome[0] = nome;
    nomecognome[1] = cognome;
    
    
    printf("\nStringa merge: %s\n", merge(nome,cognome));

    if (strlen(nome) >= strlen(cognome))
    {
        printf("\nStringa incastonata: %s\n", incastona(nome, cognome));
    }
    else if (strlen(nome) < strlen(cognome))
            {
                printf("\nStringa incastonata: %s\n", incastona(cognome, nome));
            }
    
    inverti(nomecognome);
    crea(nomecognome);
    ordina(nomecognome);
    
    return 0;
}
