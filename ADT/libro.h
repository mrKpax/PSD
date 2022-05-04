typedef struct lib{
    char autore[26];
    char titolo[53];
    char editore[26];
    int anno;
} libro;

libro creaLibro(char *aut, char *tit, char *ed, int an);
char *autore(libro l);
char *titolo(libro l);
char *editore(libro l);
int anno(libro l);
