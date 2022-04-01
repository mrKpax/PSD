#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulo.h"

int isVocal(char c)
{
    if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int isCons(char c)
{
    if (c == 'b' || c == 'B' || c == 'c' || c == 'C' || c == 'd' || c == 'D' || c == 'f' || c == 'F' || c == 'g' || c == 'G' || c == 'h' || c == 'H' || c == 'j' || c == 'J' ||
        c == 'k' || c == 'K' || c == 'l' || c == 'L' || c == 'm' || c == 'M' || c == 'n' || c == 'N' || c == 'o' || c == 'O' || c == 'p' || c == 'P' || c == 'q' || c == 'Q' || c == 'r' || c == 'R' ||
        c == 's' || c == 'S' || c == 't' || c == 'T' || c == 'v' || c == 'V' || c == 'w' || c == 'W' || c == 'x' || c == 'X' || c == 'y' || c == 'Y' || c == 'z' || c == 'Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char **vocali_consonanti(char *stringa)
{
    int cons, voc, i;
    int len = strlen(stringa);
    voc = 0;
    cons = 0;
    char **vocons = xcalloc(2, sizeof(char*));

    for (i=0; i<len; i++)
    {
        if (isVocal(stringa[i]))
        {
            voc++;
        }
        else if (isCons(stringa[i]))
        {
            cons++;   
        }
    }

    vocons[0] = xcalloc(voc, sizeof(char));
    vocons[1] = xcalloc(cons, sizeof(char));

    int j = 0;
    int k = 0;
    for (i=0; i<len; i++)
    {
        if (isVocal(stringa[i]))
        {
            vocons[0][j] = stringa[i];
            j++;
        }
        else if (isCons(stringa[i]))
        {
            vocons[1][k] = stringa[i];
            k++;
        }
    }

    vocons[0][j] = '\0';
    vocons[1][k] = '\0';

    return vocons;
}

int main(int argc, char *argv[])
{
    if (argc<2)
    {
        fprintf(stderr,"errore, elementi insufficienti\n");
        exit(-1);
    }

    char *stringa = argv[1];

    char **vocons = xcalloc(2, sizeof(char*));
    vocons = vocali_consonanti(stringa);

    printf("Vocali: %s\n", vocons[0]);
    printf("Consonanti: %s\n", vocons[1]);
  
    return 1;
}
