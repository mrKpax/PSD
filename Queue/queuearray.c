#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"
#define MAXQUEUE 100 //dimensione massima

struct c_queue {
  item *vet;
  int size; //dimensione della coda
  int head, tail;
};

queue newQueue(void)
{
  struct c_queue *q = xmalloc(sizeof(struct c_queue));
  
  q->vet = malloc(MAXQUEUE * sizeof(item));
  if (q->vet==NULL)
  {
    free (q);
    return NULL;
  }
  
  q->size = 0; //dimensione massima
  q->head = 0;
  q->tail = 0;
  return q;
}

int emptyQueue(queue q)
{
  if (q==NULL) return -1;
  
  return (q->size == 0);
}

int enqueue(item val, queue q)
{
  if(q==NULL) return -1;
  
  if (q->size == MAXQUEUE-1) //coda piena
    return 0;
  (q->size)++;
  q->vet[q->tail] = val; //inserisco in coda
  q->tail = (q->tail + 1) % MAXQUEUE;
  return 1;
}

item dequeue(queue q)
{
  if(q == NULL || q->size == 0) return NULLITEM;
  
  item result = q->vet[q->head]; //item da restituire
  q->head = (q->head + 1) % MAXQUEUE; //operatore % per gestione circolare
  return result;
}
