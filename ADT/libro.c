#include "libro.h"

libro creaLibro(char *aut, char *tit, char *ed, int an)
{
    libro l;
    strcpy(l.autore, aut);
    strcpy(l.titolo, tit);
    strcpy(l.editore, ed);
    l.anno = an;
    return l;
}

char *autore(libro L)
{
    char *aut;
    aut = calloc(26, sizeof(char));
    strcpy(aut, L.autore);
    return aut;
}

char *titolo(libro L)
{
    char *tit;
    tit = calloc(26, sizeof(char));
    strcpy(tit, L.titolo);
    return tit;
}

char *editore(libro L)
{
    char *ed;
    ed = calloc(26, sizeof(char));
    strcpy(ed, L.editore);
    return ed;
}

int anno(libro L)
{
    return L.anno;
}
