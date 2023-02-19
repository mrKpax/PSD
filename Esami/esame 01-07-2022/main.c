#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "queue.h"
#include "item.h"
#include "list.h"

/*  1. Contare i figli sinistri di un albero.
    
    Specifica sintattica: conta_figliSX(Btree T) -> int
    dati input: Btree T.
    dati output: int.
    
    Specifica semantica:
    la funzione prende in input un Btree T e ne conta il numero di figli sinistri (sottoalberi sinistri) e restituisce in output il numero di tali figli.
 
    Progettazione:
    1. Passo base:
        1.1 Verifica che non sia un albero vuoto. In caso lo sia restituisce 0.
        1.2 Verifica la presenza di un figlio SX. Se non ce ne sono li cerca nel sottoalbero DX.
    2. Passo ricorsivo:
        2.1 Restituisce 1 + i figli sinistri nei rispettivi sottoalberi.
 
 */

int conta_figliSX(Btree T)
{
    if (emptyBtree(T)) return 0;
    
    if (emptyBtree(figlioSX(T))) return conta_figliSX(figlioDX(T));
    
    return 1 + (conta_figliSX(figlioSX(T)) + conta_figliSX(figlioDX(T)));
}

/* 2. Date due code, eliminare dalla coda 1 gli elementi che non sono presenti nella coda 2.
    Specifica sintattica: differenza(queue q1, queue q2)
    dati in input: queue q1, queue q2.
    dati in output: void.
    
    Specifica semantica:
    la funzione prende in input due code ed elimina dalla prima gli elementi contenuti nella seconda.
 
    Progettazione:
    1. Verifica che q1 o q2 non siano vuote. In caso un delle due o entrambe lo siano, restituisce il controllo.
    3. Crea una coda temporanea temp nella quale salva tutti gli elementi di q1.
        3.1 Inserisce in temp l'elemento di testa di q1, lo eliminandolo da q1, finché q1 non è vuota.
    4. Reinserisce gli elementi di temp in q1, effettuando un controllo per verificare che non vengano inseriti elementi presenti in q2, finché temp non è vuota.
        4.1 Verifica che l'elemento di testa di temp non sia presente in q2. In caso lo sia, non lo aggiunge.
        4.2 Se l'elemento non è presente in q2, lo inserisce in q1.
*/

int confronta(item target, queue q)
{
    item x;
    while(!emptyQueue(q))
    {
        x = dequeue(q);
        if (target == x) return 1;
    }
    return 0;
}

void differenza(queue q1, queue q2)
{
    if (emptyQueue(q1) || emptyQueue(q2)) return;
    
    queue temp = newQueue();
    item x;
    
    while (!emptyQueue(q1))
    {
        x = dequeue(q1);
        enqueue(x, temp);
    }
    
    while (!emptyQueue(temp))
    {
        x = dequeue(temp);
        
        if (!confronta(x, q2))
        {
            enqueue(x, q1);
        }
    }
}

/*  3. Cercare l'elemento centrale di una lista non conoscendo la dimensione.
    Specifica sintattica: cercaMid(list l) -> item
    Dati input: list l.
    Dati output: item
    Precondizione: !emptyList(l).
    Postcondizione: posizione di item = sizeList/2.
    
    Specifica semantica:
    La funzione prende in input una lista, ne calcola la dimensione e restituisce l'elemento centrale.
    
    Progettazione:
    1. Verifica che non sia una lista vuota. In caso lo sia restituisce 0.
    2. Estrae il primo elemento della lista salvandolo in una lista temporanea, incrementando il contatore, finché la lista non è vuota.
    3. Divide il contatore per 2, ottenendo la posizione dell'elemento centrale.
    4. Reinserisce gli elementi da temp a l, individuando l'item centrale.
 
 */

item cercaMid(list l)
{
    item x;
    int n = 0;
    list temp = newList();
    
    if (emptyList(l)) return n;
    
    while(!emptyList(l))
    {
        x = getFirst(l);
        consList(x, temp);
        l = tailList(l);
        n++;
    }
    
    int centro = n/2;
    int m = 0;
    item target;
    
    while(!emptyList(temp))
    {
        m++;
        x = getFirst(temp);
        consList(x, l);
        temp = tailList(temp);
        
        if (m == centro)
            target = x;
    }
    
    return target;
}

int main(void)
{
    Btree T = newBtree();
    int figliSX;
    figliSX = conta_figliSX(T);
    
    queue q1, q2;
    q1 = newQueue();
    q2 = newQueue();
    differenza(q1, q2);
    
    list l = newList();
    item x = cercaMid(l);
}
