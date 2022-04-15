struct Libro
{
    char autore[26];
    char titolo [53];
    char editore [26];
    int anno;
}

typedef struct Libro *libro;

libro creaLibro (char *A, char *T, char *E, int anno)
{
    libro L;
    L = xmalloc(sizeof(struct Libro));
    
    strcpy(L->autore,A);
    strcpy(L->titolo,T);
    strcpy(L->editore,E);
    L->anno = anno;

    return L;
}

char *autore(libro L)
{
    char *aut;
    aut = xcalloc(26, sizeof(char));

    strcpy(aut,L->autore);

    return aut;
}

char *titolo(libro L)
{
    char *tit;
    tit = xcalloc(53, sizeof(char));

    strcpy(tit,L->titolo);

    return tit;
}

char *editore(libro L)
{
    char *ed;
    ed = xcalloc(26, sizeof(char));

    strcpy(ed,L->editore);

    return ed;
}

int anno(libro L)
{
    return L->anno;
}
