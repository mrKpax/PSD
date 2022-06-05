int ricercaord(int a[], int n, int elem)
{
    int i = 0;
    int trovato = 0;

    while (i<n && !trovato) //visita finalizzata
    {
        if (a[i] >= elem)
        {
            trovato = 1;
            else i++;
        }
    }

    if (i==n) //raggiunta fine array senza trovare elem
    {
        i = -1;
    }
    else if (a[i] > elem) //elem non può essere più trovato
    {
        i = -1;
    }

    return i;
}
