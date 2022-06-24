#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"
#define MAXPQ 50

struct c_PQ {
    int vet[MAXPQ];
    int numel;
}

static void scendi(PQueue q);
static void sali(PQueue q);

PQueue newPQ(void)
{
    PQueue q;
    q = malloc(sizeof(struct c_PQ));
    if (q==NULL) return NULL;
    q->numel = 0;
    return q;
}

int emptyPQ(PQueue q)
{
    if (!q) return 1;
    return q->numel==0;
}

int getMax(PQueue q)
{
    return q->vet[1];
    //non verifica la precondizione, la coda non può essere vuota
}

int deleteMax(PQueue q)
{
    if (!q || q->numel==0) return 0; //coda vuota
    
    q->vet[1] = q->vet[q->numel]; //sposto l'ultimo elemento in posizione 1
    q->numel--;
    
    scendi(q); //riaggiusto lo heap scendendo
    
    return 1;
}

static void scendi (PQueue q)
{
    int temp, n=q->numel, i=1, pos;
    
    while(1)
    {
        if (2*i+1 <= n) //il nodo corrente ha 2 figli
            pos = (q->vet[i*2] > q->vet[i*2+1]) ? i*2 : i*2+1;
        
        else if (2*i <= n) //il nodo corrente ha 1 figlio
                pos = 2*i;
            else break; //il nodo corrente non ha figli
        
        if (q->vet[pos] > q->vet[i]) //scambio le chiavi e proseguo
        {
            temp = q->vet[i];
            q->vet[i] = q->vet[pos];
            q->vet[pos] = temp;
            i = pos;
        }
        else
            break; //non ci sono più scambi da fare
    }
}

int insert(PQueue q, int key)
{
    if (!q || q->numel==MAXPQ) return 0; //coda piena
    
    q->numel++;
    q->vet[q->numel] = key; //inserisci in ultima posizione
    
    sali(q); //aggiusta lo heap risalendo
    
    return 1;
}

static void sali(PQueue q)
{
    int temp, pos=q->numel, i=pos/2;
    
    while(pos>1)
    {
        if (q->vet[pos] > q->vet[i])
        {
            temp = q->vet[i];
            q->vet[i] = q->vet[pos];
            q->vet[pos] = temp;
            pos = i;
            i = pos/2;
        }
        else
            break;
    }
}
