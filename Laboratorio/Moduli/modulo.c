#include <stdio.h>
#include <stdlib.h>
#include "modulo.h"

void *xmalloc(size_t nbytes)
{
    void *p;
    p = malloc(nbytes);
    if (p == NULL)
    {
        fprintf(stderr, "allocazione fallita, uscita...\n");
        exit(-1);
    }
    return p;
}

void *xcalloc(size_t nelements, size_t elementsize)
{
    void *p;
    p = calloc(nelements, elementsize);
    if (p == NULL)
    {
        fprintf(stderr, "allocazione fallita, uscita...\n");
        exit(-1);
    }
    return p;
}

void *xrealloc(void *p, size_t size)
{
    void *result;
    result = realloc(p, size);
    if (result == NULL)
    {
        fprintf(stderr, "riallocazione fallita, uscita...\n");
        exit(-1);
    }
    return result;
}
