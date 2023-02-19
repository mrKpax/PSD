#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "pqueue.h"

void heapify(int *a, int numel, int i)
{
    int max = i, sx = 2*i+1, dx = 2*i+2, tmp;
    if (sx < numel && a[sx] > a[max])
    {
        max = sx;
    }
    if (dx < numel && a[dx] > a[max])
    {
        max = dx;
    }
    if (max != i)
    {
        tmp = a[i];
        a[i] = a[max];
        a[max] = tmp;
        heapify(a, numel, max);
    }
}

void crea_heap(int a[], int numel)
{
    int ultimo_genitore = (numel-1)/2;
    for (int i = ultimo_genitore; i >= 0; i--)
    {
        heapify(a, numel, i);
    }
}

key max_PQ(pqueue pq)
{
    return getMax(pq);
}

key min_PQ(pqueue pq)
{
    pqueue tmp = newPQ();
    key curr = getMax(pq), min;
    while (!emptyPQ(pq))
    {
        insert(tmp, curr);
        deleteMax(pq);
        curr = getMax(pq);
    }
    while (!emptyPQ(tmp))
    {
        insert(pq, getMax(tmp));
        deleteMax(tmp);
    }
    free(tmp);
    return curr;
}

void incrementa_chiave(pqueue pq, key k, key new_k)
{
    pqueue tmp = newPQ();
    key curr;
    while (!emptyPQ(pq))
    {
        insert(tmp, getMax(pq));
        deleteMax(pq);
    }
    while (!emptyPQ(tmp))
    {
        curr = getMax(tmp);
        if (curr == k)
        {
            insert(pq, new_k);
        }
        else
        {
            insert(pq, curr);
        }
        deleteMax(tmp);
    }
    free(tmp);
}

int push(pqueue pq, key k)
{
    if (k < getMax(pq))
    {
        return 0;
    }
    insert(pq, k);
    return 1;
}

int pop(pqueue pq)
{
    return deleteMax(pq);
}

pqueue merge(pqueue pq1, pqueue pq2)
{
    pqueue pq3 = newPQ(), tmp = newPQ();
    while (!emptyPQ(pq1))
    {
        insert(pq3, getMax(pq1));
        insert(tmp, getMax(pq1));
        deleteMax(pq1);
    }
    while (!emptyPQ(tmp))
    {
        insert(pq1, getMax(tmp));
        deleteMax(tmp);
    }
    while (!emptyPQ(pq2))
    {
        insert(pq3, getMax(pq2));
        insert(tmp, getMax(pq2));
        deleteMax(pq2);
    }
    while (!emptyPQ(tmp))
    {
        insert(pq2, getMax(tmp));
        deleteMax(tmp);
    }
    free(tmp);
    return pq3;
}

int main(void)
{
    int a[9] = {100,19,36,17,3,25,1,2,7};
    crea_heap(a, 9);
    printf("heapificato: ");
    for (int i = 0; i < 9; i++) printf("%d ", a[i]);

    pqueue pq = input_PQ(a, 9);
    printf("\npq: ");
    output_PQ(pq);

    printf("\nmax: ");
    output_key(max_PQ(pq));
    printf("\nmin: ");
    output_key(min_PQ(pq));

    incrementa_chiave(pq, 19, 43);
    printf("\n\nincrementa chiave: ");
    output_PQ(pq);

    push(pq, 111);
    printf("\npush: ");
    output_PQ(pq);
    pop(pq);
    printf("\npop: ");
    output_PQ(pq);

    int b[7] = {4,5,8,9,11,23,35};
    crea_heap(b, 7);

    pqueue pq2 = input_PQ(b, 7);
    printf("\npq2: ");
    output_PQ(pq2);

    pqueue q3 = merge(pq, pq2);
    printf("\nmerge: ");
    output_PQ(q3);
    
    return 0;
}
