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

int sizeList(list l)
{
    int n = 0;
    while (!emptyList(l)) //finchè non raggiungiamo la fine della lista, visita totale
    {
        n++; //il primo elemento contribuisce al conteggio
        l = tailList(l); //visita degli elementi successivi
    }
    return n;
}

int posItem(list l, item val)
{
    int pos = 0;
    int found = 0;

    while (!emptyList(l) && !found)
    {
        if (eq(getFirst(l), val))
        {
            found = 1;
        }
        else
        {
            pos++;
            l = tailList(l);
        }
    }

    if (!found)
    {
        pos = -1;
    }

    return pos;
}

/* VERSIONE RICORSIVA di posItem
int posItem(list l, item val)
{
    if emptyList(l) return -1;
    if (eq(getFirst(l), val)) return 0;
    else
    {
        int ris = posItem(tailList(l), val);
        if (ris == -1)
            return -1;
        else
            return 1 + ris;
    }
} */

getItem(list l, int pos)
{
    item e;
    int i = 0;

    while (i<pos && !emptyList(l)) //scorriamo la lista fino a pos (se esiste)
    {
        i++;
        l = tailList(l);
    }

    if (!emptyList(l)) //se la lista ha almeno pos+1 elementi
        e = getFirst(l); //elemento di posizione pos
    else
        e = NULLITEM;

    return e;
}

list reverseList(list l) //utilizzo tipico lst2 = reverseList(lst1)
{
    list rev;
    item val;

    rev = newList();

    while (!emptyList(l)) //visita totale
    {
        val = getFirst(l);
        rev = consList(val, rev);
        l = tailList(l);
    }
    return rev;
}

outputList(list l)
{
    int i = 0;
    item val;

    while(!emptyList(l)) //visita totale
    {
        val = getFirst(l);
        printf("Elemento di posizione %d: ",i);
        output_item(val);
        printf("\n");
        l = tailList(l);
        i++;
    }
}

/* VERSIONE RICORSIVA di outpuList
void outputLis(list l)
{
    out_List(l, 0);
}

void out_List(list l, int i)
{
    if (emptyList(l)) return;
    
    val = getFirst(l);
    printf("Elemento di posizione %d: ",i);
    output_item(val);
    printf("\n");
    out_List(tailList(l), i+1);
} */

list inputList(int n)
{
    item val;
    list l = newList();

    for(int i=0; i<n; i++)
    {
        printf("Elemento di posizione %d: ", i);
        input_item(&val);
        l = consList(val, l);
    }

    return reverseList(l); //poichè alla fine del ciclo l contiene la lista al contrario
}
