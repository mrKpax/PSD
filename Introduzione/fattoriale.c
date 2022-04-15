#include <stdio.h>

int fattoriale(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n*fattoriale(n-1);
    }
}

int main(void)
{
    int n, fatt;
    printf("Inserisci n: ");
    scanf("%d", &n); // n > 1
  
    fatt = fattoriale(n);
    printf("il fattoriale di %d è %d\n", n, fatt);
  
    return 0;
}
