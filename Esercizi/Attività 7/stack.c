#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

struct c_stack
{
    struct node *head;
    int size;
};

struct node
{
    struct node *next;
    item value;
};

stack newStack(void)
{
    stack s = malloc(sizeof(struct c_stack));
    if (s == NULL) return NULL;
    
    s->head = NULL;
    s->size = 0;
    
    return s;
}

int emptyStack(stack s)
{
    return (s->size == 0);
}

int push(stack s, item it)
{
    struct node *new;
    new = malloc(sizeof(struct node));
    if (new == NULL) return 0;
    
    new->value = it;
    new->next = s->head;
    s->head = new;
    
    (s->size)++;
    
    return 1;
}

int pop(stack s)
{
    struct node *temp;
    
    if(emptyStack(s)) return 0;
    
    temp = s->head;
    s->head = s->head->next;
    free(temp);
    
    (s->size)--;
    
    return 1;
}

item top(stack s)
{
    if (emptyStack(s)) return NULLITEM;
    
    return s->head->value;
}

stack reverseStack(stack s)
{
    struct node *head = s->head;
    stack rev;
    item val;
    
    rev = newStack();
    
    while(head != NULL)
    {
        val = head->value;
        push(rev, val);
        head = head->next;
    }
    
    return rev;
}

void printStack(stack s)
{
    struct node *head = s->head;
    int i = 0;

    while(head != NULL)
    {
        printItem(head->value);
        printf("  ");
        head = head->next;
        i++;
    }
}

void freeStack(stack s)
{
    struct node *temp;
    
    while(s->head != NULL)
    {
        temp = s->head;
        s->head = s->head->next;
        free(temp);
    }
    
    free(s);
}

//stack merge(stack s1, stack s2);

//stack deleteItems(stack s, item it);
