#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

struct node {
  item value;
  struct node *next;
};

struct c_queue {
  struct node *head, *tail;
  int numel;
};

queue newQueue(void)
{
  struct c_queue *q;
  q = xmalloc(sizeof(struct c_queue));
  
  q->numel = 0;
  q->head = NULL;
  q->tail = NULL;
  return q;
}

int emptyQueue(queue q)
{
  if (q==NULL)
    return -1;
  return q->numel == 0;
}

int enqueue(item val, queue q)
{
  if (q==NULL)
    return -1;
  
  struct node *nuovo;
  nuovo = xmalloc(sizeof(struct node));
  
  nuovo->value = val;
  nuovo->next = NULL;
  
  if(q->head==NULL)
    q->head = nuovo; //caso cosa vuota
  else
    q->tail->next = nuovo; //caso coda non vuota
  
  q->tail = nuovo; //tail punta al nuovo nodo
  (q->numel)++; //incrementare il numero di elementi
  return 1;
}

item dequeue(queue q)
{
  if (q==NULL) return NULLITEM;
  if (q->numel==0) return NULLITEM; //coda vuota
  
  item result = q->head->value; //item da restituire
  struct node *temp = q->head; //nodo da rimuovere
  q->head = q->head->next; //q->head avanza
  free(temp); //libera memoria nodo da rimuovere
  
  if(q->head==NULL) //se la coda conteneva un solo elemento
    q->tail = NULL;
  
  (q->numel)--;
  return result;
}
