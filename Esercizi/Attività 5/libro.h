typedef struct lib *libro;

libro creaLibro(char *tit, char *aut, char *ed, float prez, int an);
char *autore(libro l);
char *titolo(libro l);
char *editore(libro l);
float prezzo(libro l);
int anno(libro l);
void sconto(libro l, float perc);
void stampa(libro l);
