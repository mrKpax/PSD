#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"
#include "queue.h"

btree input_Btree(int *a, int i, int n)
{
    if (i >= n) return NULL;
    
    return consBtree(a[i], input_Btree(a, 2*i+1, n), input_Btree(a, 2*i+2, n));
}

btree file_input_btree(char *fname, int *size)
{
    int i, quant = 0;
    int *a;
    FILE *fp = fopen(fname, "r");
    if (fp == NULL) exit(-1);
    
    while (fscanf(fp, "%d\n", &i) == 1)
        quant++;
    
    fclose(fp);
    a = malloc(quant * sizeof(int));
    fp = fopen(fname, "r");
    if (fp == NULL) exit(-1);
    
    for(i = 0; i < quant; i++)
    {
        fscanf(fp, "%d\n", &a[i]);
    }
    fclose(fp);
    
    *size = quant;
    btree T = input_Btree(a, 0, *size);
    return T;
}

int contaFoglie(btree T)
{
    if(emptyBtree(T)) return 0;
    
    if(emptyBtree(figlioSX(T)) && emptyBtree(figlioDX(T)))
        return 1;
    
    return contaFoglie(figlioSX(T)) + contaFoglie(figlioDX(T));
}

btree speculare(btree T)
{
    if (emptyBtree(T)) return NULL;
    
    return consBtree(getItem(getRoot(T)), speculare(figlioDX(T)), speculare(figlioSX(T)));
}

int massimo(btree T)
{
    item max, sx, dx;
    
    if(emptyBtree(T)) return -99999;
    
    max = getItem(getRoot(T));
    sx = massimo(figlioSX(T));
    dx = massimo(figlioDX(T));
    
    if(max < sx)
        max = sx;
    
    if(max < dx)
        max = dx;
    
    return max;
}

int minimo(btree T)
{
    item min, sx, dx;
    
    if(emptyBtree(T)) return 99999;
    
    min = getItem(getRoot(T));
    sx = minimo(figlioSX(T));
    dx = minimo(figlioDX(T));
    
    if(min > sx)
        min = sx;
    
    if(min > dx)
        min = dx;
    
    return min;
}

int uguaglianza(btree T, btree T2)
{
    if (emptyBtree(T) && emptyBtree(T2))
        return 1;
    
    if(getItem(getRoot(T)) != getItem(getRoot(T2)))
        return 0;
    
    if(uguaglianza(figlioSX(T), figlioSX(T2)) && uguaglianza(figlioDX(T), figlioDX(T2)))
        return 1;
    
    return 0;
}

/*
btree arrayToBtree(btree t, item *a, int i, int size)
{
    if (i>=size) return t;
    
    t = consBtree(a[i], arrayToBtree(figlioSX(t), a, 2*i+1, size), arrayToBtree(figlioDX(t), a, 2*i+2, size));
    
    return t;
}

int contaNodi(btree t)
{
    if (t == NULL) return 0;
    
    return 1 + contaNodi(figlioSX(t)) + contaNodi(figlioDX(t));
}

btree aggiungiNodo(btree t, item nodo)
{
    queue q = newQueue();
    btree temp;
    btree nuovo = newBtree();
    
    int size = contaNodi(t);
    item arr[size];
    
    enqueue(q, t);
    
    int i=0;
    
    while(!emptyQueue(q) && i<size)
    {
        temp = dequeue(q);
        
        arr[i] = getItem(temp);
        printItem(arr[i]);
        i++;
        
        enqueue(q, figlioSX(temp));
        enqueue(q, figlioDX(temp));
    }
    
    for(int j=0; j<size; j++)
    {
        if(arr[j] == NULLITEM)
        {
            arr[j] = nodo;
            break;
        }
    }
    
    for(int k=0; k<size; k++)
    {
        printItem(arr[k]);
    }
    
    arrayToBtree(nuovo, arr, 0, size);
    
    return nuovo;
}
*/
 
int main(void)
{
    int numel, numel2, foglie, min, max, eq;
    
    btree T;
    T = newBtree();
    T = file_input_btree("input.txt", &numel);
    printf("\nAlbero:\n");
    output_Btree(T, 0);
    
    btree T2;
    T2 = newBtree();
    T2 = file_input_btree("input2.txt", &numel2);
    printf("\nAlbero 2:\n");
    output_Btree(T2, 0);
    
    foglie = contaFoglie(T);
    printf("\nNumero di foglie: %d\n", foglie);
    
    
    T = speculare(T);
    printf("\nAlbero speculare:\n");
    output_Btree(T, 0);
    
    min = minimo(T);
    max = massimo(T);
    printf("\nMassimo: %d \nMinimo: %d\n", max, min);
    
    
    eq = uguaglianza(T, T2);
    if (eq == 1) printf("\nAlberi uguali\n");
    else printf("\nAlberi diversi\n");
    
    
    /*
    item arr[5] = {1, 2, 3, 4, 5};
    btree nuovo = newBtree();
    nuovo = arrayToBtree(nuovo, arr, 0, 5);
    printf("\nDopo l'aggiunta:\n");
    nuovo = aggiungiNodo(nuovo, 6);
    */
     
    printf("\n");
    
    return 0;
}
