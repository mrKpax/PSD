#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "pqueue.h"
#include "item.h"

/*  1. Fogliek(Btree T, int k)
    La funzione conta il numero di foglie (se presenti) al livello k, restituendolo
 
    Specifica sintattica: fogliek(Btree, int) -> int
    dati input: Btree T, int k.
    dati in output: int foglie.
    
    Specifica semantica:
    la funzione prende in input un albero T e un livello k, e conta quante foglie sono presenti al livello specificato
 
    Progettazione:
    1. Passo base:
        1.1 Verifica se il Btree è vuoto, nel caso lo sia restituisce 0.
        1.2. Verifica se il livello k è 0, nel caso lo sia verifica la presenza di foglie. Se il livello (radice) non ha figli, restituisce 1.
    2. Passo ricorsivo: conta le foglie presenti nei figli sommandole e restituendone la somma.
 */

int fogliek(Btree T, int k)
{
    if (emptyBtree(T)) return 0;
    
    if ((k == 0) && (emptyBtree(figlioSX(T))) && (emptyBtree(figlioDX(T)))) return 1;
    
    return (fogliek(figlioSX(T), k-1) + fogliek(figlioDX(T), k-1));
}

/*  2. void PriorityQueueIncrease(Pqueue q)
    La funzione incrementa di 1 la priorità di tutti gli elementi ESCLUSO il primo.
    La coda q (a fine esecuzione) deve contenere il primo elemento + tutti gli altri elementi con priorità +1.
    
    Specifica sintattica: PriorityQueueIncrease(Pqueue) -> void
    dati input: pqueue q.
    dati output: null.
    precondizione: !emptyPQ(q).
    postcondizione: q = (max, a+1, b+1, c+1...).
 
    Specifica semantica: la funzione incrementa di 1 tutti gli elementi della pqueue escluso il primo. A fine esecuzione la coda avrà il primo elemento in testa + tutti gli altri con priorità +1.
 
    Progettazione:
    1. Verifica che q non sia vuota. Nel caso lo sia restituisce il comando.
    2. Salva il max della coda in una variabile, poi la elimina.
    3. Salva tutti gli elementi in una coda temporanea, finché q non è vuota.
    4. Reinserisce tutti gli elementi dalla coda temporanea alla coda originale, incrementando di 1 la loro priorità, finché temp non è vuota.
    5. Aggiunge in fine l'elemento max salvato in precedenza.
 */

void PriorityQueueIncrease(PQueue q)
{
    if(emptyPQ(q)) return;
    
    item max;
    PQueue temp = newPQ();
    
    max = getMax(q);
    deleteMax(q);
    
    while(!emptyPQ(q))
    {
        insert(temp, getMax(q));
        deleteMax(q);
    }
    
    while(!emptyPQ(temp))
    {
        insert(q, getMax(temp)+1);
        deleteMax(temp);
    }
    
    insert(q, max);
    
    return;
}

/*
    3. BOOL strutturalmenteSimili(Btree T1, Btree T2)
    Restituisce true (1) o false (0) se gli alberi sono o meno strutturalmente simili
 
    Specifica sintattica: strutturalmenteSimili(Btree T1, Btree T2) -> boolean
    dati input: Btree T1, Btree T2.
    dati output: boolean result.
    postcondizione: result == 1 se sono strutturalmente simili, result == 0 se non lo sono.
 
    Specifica semantica:
    Restituisce true (1) o false (0) se gli alberi sono o meno strutturalmente simili.
 
    Progettazione:
    1. Passo base:
        1.1 Se entrambi gli alberi sono vuoti, restituisce 1.
        1.2 Se i sottoalberi SX non sono entrambi vuoti o entrambi pieni (idem per i sottoalberi DX) restituisce 0.
    2. Passo ricorsivo:
        2.1 Verifica che i sottoalberi SX e i sottoalberI DX siano strutturalmente simili.
*/

int strutturalmenteSimili(Btree T1, Btree T2)
{
    if(emptyBtree(T1) && emptyBtree(T2)) return 1;
    
    if( (emptyBtree(figlioSX(T1)) != emptyBtree(figlioSX(T2))) || (emptyBtree(figlioDX(T1)) != emptyBtree(figlioDX(T2))) ) return 0;
    
    return (strutturalmenteSimili(figlioSX(T1), figlioSX(T2)) && strutturalmenteSimili(figlioDX(T1), figlioDX(T2)));
    
}

int main(void)
{
    Btree T = newBtree();
    int k = 0;
    int foglie;
    foglie = fogliek(T, k);
    
    PQueue q = newPQ();
    PriorityQueueIncrease(q);
    
    Btree T1, T2;
    T1 = newBtree();
    T2 = newBtree();
    int simili;
    simili = strutturalmenteSimili(T1, T2);
}
