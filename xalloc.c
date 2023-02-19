#include <stdlib.h>
#include <stdio.h>

void *xcalloc(size_t n, size_t size)
{
    void *result;
    if ((result = calloc(n, size)) == NULL)
    {
        fprintf(stderr, "Errore calloc\n");
        exit(-1);
    }
    return result;
}
void *xrealloc(void *p, size_t nbytes)
{
    void *result;
    if ((result = realloc(p, nbytes)) == NULL)
    {
        fprintf(stderr, "Errore realloc\n");
        exit(-1);
    }
    return result;
}

void *xmalloc(size_t nbytes)
{
    void *result;
    if ((result = malloc(nbytes)) == NULL)
    {
        fprintf(stderr, "Errore malloc\n");
        exit(-1);
    }
    return result;
}
