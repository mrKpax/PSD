#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node
{
    btree data;
    struct node *next;
};

struct c_queue
{
    struct node *head;
    struct node *tail;
    int size;
};

queue newQueue(void)
{
    queue q;
    q = malloc(sizeof(struct c_queue));
    if(q == NULL) return NULL;

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    return q;
}

int emptyQueue(queue q)
{
    return q->size == 0;
}

int enqueue(queue q, btree t)
{
    struct node *n;
    n = malloc(sizeof(struct node));
    if(n == NULL) return 0;

    n->data = t;
    n->next = NULL;

    if(q->head == NULL)
    {
        q->head = n;
        q->tail = n;
        (q->size)++;
        return 1;
    }

    q->tail->next = n;
    q->tail = n;

    (q->size)++;

    return 1;
}

btree dequeue(queue q)
{
    if(emptyQueue(q)) return NULL;

    btree val;
    struct node *temp;

    val = q->head->data;

    temp = q->head;
    q->head = q->head->next;
    free(temp);

    if(q->head == NULL)
    {
        q->tail = NULL;
    }

    (q->size)--;

    return val;
}
