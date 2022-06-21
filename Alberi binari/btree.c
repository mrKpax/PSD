#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"

struct node{
    item value;
    struct node *left;
    struct node *right;
};

item getItem(node *N);
void setItem(node *N, item el);

item getItem(node *N)
{
    if (N==NULL) return NULLITEM;
    return N->value;
}

void setItem(node *N, item el)
{
    if (N==NULL) return;
    N->value = el; //la correttezza di = dipende dal tipo item
}

btree newBtree(void)
{
    return NULL;
}

int emptyBtree(btree T)
{
    return T==NULL;
}

node *getRoot(btree T)
{
    return T;
}

btree consBtree(item val, btree sx, btree dx)
{
    struct node *nuovo;
    nuovo = malloc(sizeof(struct node));
    if (nuovo != NULL)
    {
        setItem(nuovo, val);
        nuovo->left = sx;
        nuovo->right = dx;
    }
    return nuovo;
}

btree figlioSX(btree T)
{
    if (T!=NULL)
        return T->left;
    else
        return NULL;
}

btree figlioDX(btree T)
{
    if (T!=NULL)
        return T->right;
    else
        return NULL;
}
