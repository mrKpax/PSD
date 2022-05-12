#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"
#define STARTSIZE 50 //dimensione iniziale stack
#define ADDSIZE 20 //dimensione da aggiungere se pieno

struct c_stack {
    item *vet;
    int size; //serve a mantenere la dimensione corrente
    int top;   
}

stack newStack(void)
{
    stack s = xmalloc(sizeof(struct c_stack));
    s->vet = xmalloc(STARTSIZE * sizeof(item));

    s->size = STARTSIZE;
    s->top = 0;
    return s;
}

int emptyStack(stack s)
{
    return s->top == 0;
}

int push(item val, stack s)
{
    if(s->top == s->size) //necessario il resizing dello stack
    {
        item *tmp == xrealloc(s->vet, (s->size + ADDSIZE) * sizeof(item));
        s->vet = tmp;
        s->size += ADDSIZE;
    }

    s->vet[s->top] = val;
    (s->top)++;
    return 1;
}

int pop(stack s)
{
    if (s->top == 0)
    {
        return 0;
    }
    (s->top)--;
    return 1;
}

item top(stack s)
{
    item e;
    if (s->top > 0)
    {
        e = s->vet[s->top];
    }
    else
    {
        e = NULLITEM;
    }
    return e;
}
