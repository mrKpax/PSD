#include <stdio.h>
#include <stdlib.h>
#include "vettore.h"

int main(int argc, char *argv[])
{
    if (argc != 5)
    [
        printf("Numero di parametri non corretto \n");
    ]
    else
    {
        int n = atoi(argv[1]);
        int *a = xcalloc(n,sizeof(int));

        finput_array(argv[2],a,n);
        ordina_array(a,n);
        foutput_array(argv[4],a,n);

        int *oracle = xcalloc(n,sizeof(int));
        finput_array(argv[3],oracle,n);

        if(confronta_array(a,oracle,n))
        {
            printf("PASS \n");
        }
        else
        {
            printf("FAIL \n");
        }
    }
}
