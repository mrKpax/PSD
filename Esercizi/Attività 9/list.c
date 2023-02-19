#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node
{
    struct node *next;
    item data;
};

list newList(void)
{
    return NULL;
}

int isEmpty(list l)
{
    return l == NULL;
}

list addFirst(list l, item it)
{
    struct node* new;

    new = malloc(sizeof(struct node));
    if(new == NULL) return NULL;

    new->data = it;

    if(l == NULL) {
        new->next = NULL;
        l = new;
        return l;
    }

    new->next = l;
    l = new;

    return l;
}
void printList(list l)
{
    if(isEmpty(l)) return;

    int i = 0;

    while(!isEmpty(l)) {
        printf("Element %d\n", i++);
        printItem(l->data);
        l = l->next;
        putchar('\n');
    }
}

list tailList(list l) {
    if(l == NULL) return NULL;

    return l->next;
}

//Non ricorsiva
int sizeList(list l) {
    if(l == NULL) return 0;

    int i = 0;

    l = l->next;
    
    while(l != NULL) {
       l = l->next;
        i++;
    }
    
    return i;
}

int sizeListRec(list l) {
    if(l == NULL) return 0;

    l= l->next;

    return 1 + sizeListRec(l);
}
