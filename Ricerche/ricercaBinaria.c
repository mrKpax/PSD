int ricercabin(int a[], int n, int elem)
{
    int h = 0; //estremo inferiore dell'intervallo in cui ricercare
    int k = n-1; //estremo superiore dell'intervallo in cui ricercare
    int p; //posizione dell'elemento se trovato
    int trovato = 0; //inizialmente elemento non trovato

    while (h<=k && !trovato)
    {
        p = (h+k)/2; //posizione centrale
        if (a[p] == elem)
        {
            trovato = 1; //permette di uscire dal ciclo
        }
        else if (a[p] > elem)
        {
            k = p-1; //la ricerca continua nella prima metà
        }
        else
        {
            h = p+1; //la ricerca continua nella seconda metà
        }
    }

    return (trovato? p : -1);
}
