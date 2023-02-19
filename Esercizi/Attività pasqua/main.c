#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list cloneList(list l)
{
    if(l == NULL) return NULL;
    
    list clone = newList();
    item val;

    while(!emptyList(l))
    {
        val = getFirst(l);
        clone = addFirst(clone, val);
        l = tailList(l);
    }
    
    l = reverseList(l);
    clone = reverseList(clone);
    
    return clone;
}

void containsList(list l, int x)
{
    if(l == NULL) return;
    
    int i = 0, trovato = 0;
    list temp = newList();
    temp = cloneList(l);
    
    while(!emptyList(temp) && !trovato)
    {
        if(getFirst(temp) == x)
        {
            printf("\nL'elemento %d è presente in posizione %d\n", x, i+1);
            trovato = 1;
        }
        else
        {
            temp = tailList(temp);
            i++;
        }
    }
    
    if(!trovato) printf("\n55 non presente\n");
    
    return;
}

list switchCoppie(list l)
{
    if(l == NULL) return NULL;
    
    list temp = newList();
    temp = cloneList(l);
    item it1, it2;
    
    list res = newList();
    
    for(int i=0; i<sizeList(l)-1; i += 2)
    {
        it1 = getItem(temp, i);
        it2 = getItem(temp, i+1);
        
        res = addFirst(res, it2);
        res = addFirst(res, it1);
    }
    
    res = reverseList(res);
    
    return res;
}

list eliminaCentro(list l)
{
    int size = sizeList(l);
    list temp =  newList();
    int i = 0;
    int centro = size/2;
    
    while (i < size)
    {
        if(i != centro)
        {
            temp = addFirst(temp, getFirst(l));
            l = tailList(l);
            i++;
        }
        else
        {
            l = tailList(l);
            i++;
        }
    }
    
    temp = reverseList(temp);
    
    return temp;
}

int main(void)
{
    list l = newList();
    int n, x;
    
    printf("Quanti elementi vuoi inserire nella lista? ");
    scanf("%d", &n);
    
    for (int i=0; i<n; i++)
    {
        inputItem(&x);
        l = addFirst(l, x);
    }
    
    l = reverseList(l);
    printf("\nLista:\n");
    outputList(l);
    
    containsList(l, 55);
    
    list source = newList();
    source = cloneList(l);
    int pos = posItem(source, 25);
    if (pos >=0)
        printf("\nL'elemento 25 è presente in posizione %d\n", pos+1);
    else
        printf("\n25 non presente\n");
    
    list coppie = newList();
    coppie = cloneList(l);
    coppie = switchCoppie(coppie);
    printf("\nLista con switch di coppie:\n");
    outputList(coppie);
    
    l = eliminaCentro(l);
    printf("\nLista con centro eliminato:\n");
    outputList(l);
    
    return 0;
}
