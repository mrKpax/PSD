#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "punto.h"

int creaPunti(queue q)
{
    punto p;
    int i = 0;
    float x, y;
    char s;
    
    do
    {
        printf("\nInserisci ascissa %d: ", i); scanf("%f", &x);
        printf("Inserisci ordinata %d: ", i); scanf("%f", &y);
        
        p = creaPunto(x, y);
        if (p == NULL) return 0;
        
        i++;
        enqueue(q, p);
        
        printf("Inserire altri punti? (s/n): ");
        getchar();
        s = getchar();
        printf("\n!");
    } while(s != 'n');
    
    return 1;
}

int getQuadrante(punto p)
{
    if (p == NULL) return 0;
    
    float x, y;
    
    x = getAscissa(p);
    y = getOrdinata(p);
    
    if(x >= 0 && y >= 0) return 1;
    if(x >= 0 && y < 0) return 2;
    if(x < 0 && y < 0) return 3;
    if(x < 0 && y >= 0) return 4;
    
    return -1;
}

int sottoCode(queue q, queue q1, queue q2, queue q3, queue q4)
{
    if (q == NULL) return 0;
    
    int quadrante;
    punto p;
    
    while(!emptyQueue(q))
    {
        p = dequeue(q);
        if(p == NULL) return 0;
        
        quadrante = getQuadrante(p);
        
        switch(quadrante)
        {
            case 1:
                enqueue(q1, p);
                break;
            case 2:
                enqueue(q2, p);
                break;
            case 3:
                enqueue(q3, p);
                break;
            case 4:
                enqueue(q4, p);
                break;
        }
    }
    
    freeQueue(q);
    return 1;
}

int spezzata(queue q)
{
    queue temp = newQueue();
    punto p1, p2;
    float somma = 0;
    
    p1=dequeue(q);
    enqueue(temp, p1);
    
    while(!emptyQueue(q))
    {
        p2 = dequeue(q);
        enqueue(temp, p2);
        
        somma = somma + distanza(p1, p2);
        
        p1 = p2;
    }
    
    while(!emptyQueue(temp))
    {
        enqueue(q, dequeue(temp));
    }
    
    freeQueue(temp);
    
    return somma;
}

queue concatena(queue q2, queue q1)
{
    queue new = newQueue();
    
    //concatenazione avviene anche se esiste una sola coda
    
    while(!emptyQueue(q1))
    {
        enqueue(new, dequeue(q1));
    }
    
    while(!emptyQueue(q2))
    {
        enqueue(new, dequeue(q2));
    }
    
    freeQueue(q1);
    freeQueue(q2);
    
    return new;
}

int main(void)
{
    queue q = newQueue();
    queue q1 = newQueue();
    queue q2 = newQueue();
    queue q3 = newQueue();
    queue q4 = newQueue();
    queue concat;
    
    float lun;
    
    printf("\nCreazione punti:\n");
    creaPunti(q);
    
    sottoCode(q, q1, q2, q3, q4);
    
    lun = spezzata(q1);
    printf("\nLunghezza spezzata del quadrante 1: %.2f \n", lun);
    
    concat = concatena(q3, q4);
    concat = concatena(q2, concat);
    concat = concatena (q1, concat);
    printf("\nCoda concatenata in ordine discendente di quadrante:\n ");
    printQueue(concat);
    freeQueue(concat);
    
    return 0;
}
