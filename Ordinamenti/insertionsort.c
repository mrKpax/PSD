#include <stdio.h>
#define MAX 5

void insertion_sort(int a[], int n)
{
    for (int i=1; i<n; i++)
    {
        int elem = a[i];
        int j = i-1;
        while(j >= 0 && elem < a[j])
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = elem;
    }
}

void output_array(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("Elemento di posizione %d: %d \n", i, a[i]);
    }
}

int main(void)
{
    int a[MAX] = {5,4,3,2,1};
    insertion_sort(a,MAX);
    output_array(a,MAX);
}
