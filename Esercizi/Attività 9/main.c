#include <stdio.h>
#include "list.h"
#include <string.h>

int sizeListRic(list l)
{
    if(isEmpty(l)) return 0;
    
    return 1 + sizeListRic(tailList(l));
}

int quadrato(int n)
{
    if (n<0)
        n *= -1;
    
    if (n == 1) return 1;
    
    return (2 * n-1) + quadrato(n-1);
}

int algEuclide(int n, int m)
{
    if(m==n)
        return m;
    
    if (m > n)
        return algEuclide(m-n, n);
    else
        return algEuclide(m, n-m);
}

int palindroma(char *s)
{
    if (s[0] != s[strlen(s) -1])
        return 0;
    
    s++;
    s[strlen(s)-1] = '\0';
    
    if(strlen(s) <= 1)
        return 1;
    
    palindroma(s);
}

int tartaglia(int r, int c)
{
    if (c == 1) return 1;
    if (r == c) return 1;
    
    return(tartaglia(r-1, c-1) + tartaglia(r-1, c));
}

int main(void)
{
    //primo esercizio
    list l = newList();

    l = addFirst(l, 10);
    l = addFirst(l, 20);
    l = addFirst(l, 30);
    l = addFirst(l, 40);
    l = addFirst(l, 50);
    l = addFirst(l, 100);
    printList(l);

    int count = 0;
    count = sizeListRic(l);
    printf("\nNumero di nodi: %d\n", count);
    
    //secondo esercizio
    int n = -5;
    int quad;
    
    quad = quadrato(n);
    printf("Il quadrato di %d è %d\n", n, quad);
    
    //terzo esercizio
    printf("MCD tra 494 e 130 è: %d\n", algEuclide(494, 130));
    
    //quarto esercizio
    char s[] = "osso";
    
    if(palindroma(s))
        printf("Palindroma\n");
    else
        printf("Non palindroma\n");
    
    //quinto esercizio
    printf("(5,2): %d\n", tartaglia(5, 2));
    
    return 0;
}

