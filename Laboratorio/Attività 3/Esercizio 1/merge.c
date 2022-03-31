#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulo.h"

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

int main(int argc, char* argv[])
{
    if (argc<3)
    {
        fprintf(stderr, "parametri insufficienti\n");
        exit(-1);
    }

    char *nome = argv[1];
    char *cognome = argv[2];

    printf("Il merge di nome e cognome è: %s\n", merge(nome,cognome));

    return 1;
}
