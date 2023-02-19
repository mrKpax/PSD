#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "item.h"

/* 1. presenteQ: data una coda Q e un item el, verifica se el è presente in Q.
    Specifica sintattica: presenteQ(queue q, item el) -> boolean
    dati input: queue q, item el
    dati output: boolean
    precondizioni: !emptyQueue(q)
    postcondizioni: el presente: return 1, el non trovato: return 0.
    
    Specifica semantica:
    la funzione prende in input una queue q e un item el e verifica se el è presente in q. Restituisce 0 se non è presente, 1 se lo è.
 
    Progettazione:
    1. Si verifica che q non sia vuota. In caso lo sia return 0.
    2. Inserisci NULLITEM per separare fine e inizio.
    2. Finché top != NULLITEM, estrai il top e confrontalo con el.
        2.2 Se top == el, flag = 1.
        2.3 Reinserisci top in q.
        2.4 Prosegui il ciclo.
    3. Return flag.
*/

int presenteQ(queue q, item el)
{
    if (emptyQueue(q)) return 0;
    
    int flag = 0;
    enqueue(NULLITEM, q);
    item top = dequeue(q);
    
    while(top != NULLITEM)
    {
        if (top == el)
            flag = 1;
        enqueue(top, q);
        top = dequeue(q);
    }
    return flag;
}

/* 2. xorQ: date due code Q1 e Q2, costruisce una nuova coda Q’ contenente gli elementi che sono presenti in Q1 oppure in Q2, ma non in entrambe (unione disgiunta).
 
    Specifica sintattica: xorQ(queue q1, queue q2) -> queue
    dati input: queue q1, queue q2.
    dati output: queue q3.
    postcondizioni: q3 = q1 xor q2.
    
    Specifica semantica:
    la funzione prende due code q1 e q2 e ne crea una terza q3 tale che i suoi elementi siano elementi presenti esclusivamente in q1 o in q2, non in entrambe.
 
    Progettazione:
    1. Crea q3.
    2. Verifica che q1 o q2 non siano vuote.
        1.1 q1 vuota e q2 vuota: restituisci coda vuota.
        1.2 solo q1 vuota: restituisci q2.
        1.3 solo q2 vuota: restituisci q1.
    3. Finché top di q1 != NULLITEM.
        3.1 Confronta top con gli elementi di q2.
        3.2 Se non è presente in q2, inseriscilo.
    4. Finché top di q2 != NULLITEM.
        4.1 Confronta top con gli elementi di q1.
        4.2 Se non è presente in q1, inseriscilo.
    5. Restituisci q3.
*/

queue xorQ(queue q1, queue q2)
{
    queue q3 = newQueue();
    
    if (emptyQueue(q1) && emptyQueue(q2)) return q3;
    if (emptyQueue(q1) && !emptyQueue(q2)) return q2;
    if (!emptyQueue(q1) && emptyQueue(q2)) return q1;
    
    item top;
    top = dequeue(q1);
    enqueue(NULLITEM, q1);
    
    while(top != NULLITEM)
    {
        if (!presenteQ(q2, top))
            enqueue(top, q3);
        
        enqueue(top, q1);
        top = dequeue(q1);
    }
    
    top = dequeue(q2);
    enqueue(NULLITEM, q2);
    while(top != NULLITEM)
    {
        if (!presenteQ(q1, top))
            enqueue(top, q3);
        
        enqueue(top, q2);
        top = dequeue(q2);
    }
    return q3;
}

int main(void)
{
    queue q = newQueue();
    item el;
    int pres = presenteQ(q, el);
    
    queue q1 = newQueue();
    queue q2 = newQueue();
    queue q3 = xorQ(q1, q2);
}
