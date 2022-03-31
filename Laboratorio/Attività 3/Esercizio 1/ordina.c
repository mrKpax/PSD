#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "modulo.h"

void swap(int *a, int *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int a[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[i]>a[j])
            {
                swap(&a[i], &a[j]);
            }
        }
    }
}

void output(int *a, int len)
{
    for (int i=0; i<len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int len = argc-1;
    int *a = xmalloc(len * sizeof(int));

    for(int i=0; i<len; i++)
    {
        a[i] = atoi(argv[i+1]);
    }

    bubble(a,len);
    output(a,len);
  
    return 1;
}
