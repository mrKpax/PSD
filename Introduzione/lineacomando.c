#include <stdio.h>
#include <stdlib.h>
#include "vettore.h"
#include "utile.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Numero di elementi da ordinare insufficienti\n");
    }
    else
    {
        int n = atoi(argv[1]);
        int *a = xcalloc(n,sizeof(int));

        input_array(a,n);
        ordina_array(a,n);
        output_array(a,n);
    }
}
