#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"

struct node
{
    item value;
    struct node *left;
    struct node *right;
};

item getItem(struct node *N)
{
    if (N == NULL) return NULLITEM;
    
    return N->value;
}

void setItem(struct node *N, item el)
{
    if (N == NULL) return;
    
    N->value = el;
}

btree newBtree(void)
{
    return NULL;
}

int emptyBtree(btree T)
{
    return T == NULL;
}

struct node *getRoot(btree T)
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
    if (T != NULL)
        return T->left;
    else
        return NULL;
}

btree figlioDX(btree T)
{
    if (T != NULL)
        return T->right;
    else
        return NULL;
}

void output_Btree(btree T, int liv)
{
    if (getRoot(T) == NULL)
        return;
    else
    {
        output_Btree(getRoot(T)->right, liv+1);
        for (int i=0; i<liv; i++)
        {
            printf("  ");
        }
        printf("%d\n", getRoot(T)->value);
        output_Btree(getRoot(T)->left, liv+1);
    }
}
