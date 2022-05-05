#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

struct node {
    item value;
    struct node *next;
}

list newList(void)
{
    return NULL;
}

int emptyList(list l)
{
    return l == NULL;
}

list consList(item val, list l) //utilizzo tipico L = consList(val, list L);
{
    struct node *nuovo;
    nuovo = xmalloc(sizeof(struct node));

    nuovo->value = val;
    nuovo->next = l;
    l = nuovo;

    return l;
}

list tailList(list l) //utilizzo tipico L = tailList(L);
{
    list temp;
    if (l != NULL)
    {
        temp = l->next;
    }
    else
    {
        temp = NULL;
    }
    return temp;
}

item getFirst(list l)
{
    item e;
    if (l != NULL)
    {
        e = l->value;
    }
    else
    {
        e = NULLITEM;
    }
    return e;
}
