#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bst.h"

struct node {
    item value;
    struct node *left;
    struct node *right;
};

item getItem(struct node *N);
void setItem(struct node *N, item el);

item getItem(struct node *N)
{
    if (N==NULL) return NULLITEM;
    return N->value;
}

void setItem(struct node *N, item el)
{
    if (N==NULL) return;
    N->value = el; //correttezza di = dipende dal tipo item
}

BST newBST(void)
{
    return NULL;
}

int emptyBST(BST T)
{
    return T==NULL;
}

int contains(BST T, item elem)
{
    if (T==NULL) return 0;
    if (eq(elem, getItem(T))) return 1;
    if (minore(elem, getItem(T)))
        return (contains(figlioSX(T), elem));
    else
        return (contains(figlioDX(T), elem));
}

BST insert(BST T, item elem)
{
    if (T==NULL) return creaFoglia(elem);
    else if (minore(elem, getItem(T)))
            T->left = insert(T->left, elem);
        else if (minore(getItem(T), elem))
                T->right = insert(T->right, elem);
    return T;
}

BST creaFoglia(item elem)
{
    struct node *N;
    N = malloc(sizeof(struct node));
    if (N==NULL) return NULL;
    setItem(N, elem);
    N->left = NULL;
    N->right = NULL;
    return N;
}

BST deleteNode(BST T, item elem)
{
    if (T==NULL) return T;
    
    if (minore(elem, T->value))
        T->left = deleteNode(T->left, elem);
    else if (minore(T->value, elem))
            T->right = deleteNode(T->right, elem);
    else
    {
        if (T->left==NULL)
        {
            BST *temp = T->right;
            free(T);
            return temp;
        }
        else if (T->right==NULL)
            {
                BST *temp = T->left;
                free(T);
                return temp;
            }
        BST *temp = minValue(T->right);
        T->value = temp->value;
        
        //delete the inorder successor
        T->right = deleteNode(T->right, temp->value);
    }
    return T;
}

BST *minValue(BST node)
{
    BST *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

BST figlioSX(BST T);

BST figlioDX(BST T);
