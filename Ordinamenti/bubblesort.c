#include <stdio.h>
#define MAX 5

void swap(int *a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int a[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (a[i] > a[j])
            {
                swap(&a[i], &a[j]);
            }
        }
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
    bubble_sort(a,MAX);
    output_array(a,MAX);
}
