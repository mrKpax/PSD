#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "item.h"
#include "bst.h"
#include "queue.h"

Btree input_Btree(int *a, int i, int numel)
{
    if (i >= numel)
    {
        return NULL;
    }
    return consBtree(a[i], input_Btree(a, 2*i+1, numel), input_Btree(a, 2*i+2, numel));
}

int isBST(Btree T)
{
    if (emptyBtree(T))
    {
        return 1;
    }
    int maxSX = max_Btree(figlioSX(T));
    int minDX = min_Btree(figlioDX(T));
    int root = getItem(getRoot(T));
    if (maxSX > root || minDX < root)
    {
        return 0;
    }
    if (isBST(figlioSX(T)) && isBST(figlioDX(T)))
    {
        return 1;
    }
    return 0;
}

BST input_BST(int *a, int numel)
{
    BST T = newBST();
    for (int i = 0; i < numel; i++)
    {
        T = insert(T, a[i]);
    }
    return T;
}

void output_intervallo(BST T, int A, int B)
{
    if (emptyBST(T))
    {
        return;
    }
    int x = getItem(getRoot(T));
    if (A < x)
    {
        output_intervallo(figlioSX(T), A, B);
    }
    if (A <= x && x <= B)
    {
        output_item(x);
        printf(" ");
    }
    if (x < B)
    {
        output_intervallo(figlioDX(T), A, B);
    }
}

queue altezzak(BST T, queue q, int k, int liv)
{
    if (emptyBST(T))
    {
        return NULL;
    }
    if (k == liv)
    {
        enqueue(getItem(getRoot(T)), q);
        return q;
    }
    else if (k > liv)
    {
        altezzak(figlioSX(T), q, k, liv+1);
        altezzak(figlioDX(T), q, k, liv+1);
    }
    return NULL;
}

int conta_nodi(BST T)
{
    if (emptyBST(T))
    {
        return 0;
    }
    return 1 + conta_nodi(figlioSX(T)) + conta_nodi(figlioDX(T));
}

int mediano(BST T, item U)
{
    if (contains(T, U))
    {
        int root = getItem(getRoot(T));
        if (root == U)
        {
            return conta_nodi(figlioSX(T)) == conta_nodi(figlioDX(T));
        }
        else if (U < root)
        {
            mediano(figlioSX(T), U);
        }
        else if (root < U)
        {
            mediano(figlioDX(T), U);
        }
    }
    return 0;
}

int main(void)
{
    int v;
    int a[7] = {10,6,18,4,8,15,21};
    
    Btree T;
    T = newBtree();
    T = input_Btree(a, 0, 7);
    printf("albero: \n");
    output_Btree(T, 0);
    
    v = isBST(T);
    printf("\nè di ricerca? %d\n", v);
    
    BST TB;
    TB = input_BST(a, 7);
    output_BST(TB, 0);
    
    printf("\nI nodi compresi tra 5 e 16 sono: ");
    output_intervallo(TB, 5, 16);
    
    queue nodik = newQueue();
    altezzak(TB, nodik, 2, 0);
    printf("\nnodi ad altezza k = 2: ");
    output_queue(nodik);
    
}
