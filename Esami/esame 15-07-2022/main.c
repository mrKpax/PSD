#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"
#include "stack.h"
#include "list.h"

/*  1. Conta il numero di figli unici in un btree.
    Specifica sintattica: figliUnici(btree b) -> int
    dati input: btree b.
    dati output: int.
    precondizioni: !emptyBtree(b).
    
    Specifica semantica:
    la funzione prende in input un albero e restituisce il numero di figli unici presenti.
 
    Progettazione:
    1. Passo base:
        1.1 Se b è vuoto restituisci 0.
        1.2 Se b ha un solo figlio restituisci 1 + la somma dei figli unici presenti nei due sottoalberi.
    2. Passo ricorsivo:
        2.1 Restituisci la somma dei figli unici del sottoalbero sx e del sottoalbero dx.
 */

int figliUnici(Btree b)
{
    if (emptyBtree(b)) return 0;
    
    if ( (figlioSX(b) && !figlioDX(b)) || (figlioDX(b) && !figlioSX(b)) )
        return 1 + figliUnici(figlioSX(b)) + figliUnici(figlioDX(b));
    
    return (figliUnici(figlioSX(b)) + figliUnici(figlioDX(b)));
}

/*  2. Dati due stack inserire il secondo stack al centro del primo (il secondo stack deve rimanere invariato).
    Specifica sintattica: inserisciCentro(stack s1, stack s2)
    dati input: stack s1, stack s2.
    dati output: void
    precondizione: s2 stack non vuoto.
    
    Specifica semantica:
    la funzione inserisce il contenuto del secondo stack al centro del primo.
    
    Progettazione:
    1. Verifica che s2 non sia vuoto. Nel caso lo sia, return.
    2. Finché s1 non è vuoto, sposta gli elementi di s1 in uno stack temporaneo temp, aggiornando un contatore circa le dimensioni.
    3. Ottieni la metà (il centro) della dimensione del primo stack dividendo la variabile contatore.
    4. Finché s2 non è vuoto, inserisci gli elementi di s2 in temp2.
    5. Finché temp non è vuoto, re-inserisci gli elementi in s1 finchè l'indice raggiunge il "centro".
    6. Se i == centro, finchè temp2 non è vuoto inserisci gli elementi in s1.
 */

void inserisciCentro(stack s1, stack s2)
{
    if (emptyStack(s2)) return;
    
    stack temp = newStack();
    stack temp2 = newStack();
    int size = 0;
    
    while(!emptyStack(s1))
    {
        push(top(s1), temp);
        pop(s1);
        size++;
    }
    
    int centro = size/2;
    int i = 0;
    
    while(!emptyStack(s2))
    {
        push(top(s2), temp2);
        pop(s2);
    }
    
    while(!emptyStack(temp))
    {
        if(i == centro)
        {
            while(!emptyStack(temp2))
            {
                push(top(temp2), s1);
                push(top(temp2), s2);
                pop(temp2);
                i++;
            }
        }
        
        push(top(temp), s1);
        pop(temp);
        i++;
    }
}

/*  3. Data una lista, crea una lista inversa.
    Specifica sintattica: reverse(list l) -> list
    dati input: list l.
    dati output: list rev.
    precondizione: l non vuota.
 
    Specifica semantica:
    la funzione riceve una lista in input e ne restituisce una in output che è l'inversa della prima.
 
    Progettazione:
    1. Si verifica che l non sia vuota. Nel caso lo sia return l.
    2. Si prende il primo elemento della lista e lo si inserisce nella lista rev.
    3. Si restituisce rev.
 */

list reverse(list l)
{
    if(emptyList(l)) return l;
    
    list rev = newList();
    
    while(!emptyList(l))
    {
        rev = consList(getFirst(l), rev);
    }
    
    return rev;
}

int main(void)
{
    Btree b = newBtree();
    int unici = figliUnici(b);
    
    stack s1 = newStack();
    stack s2 = newStack();
    inserisciCentro(s1, s2);
    
    list l = newList();
    list rev = reverse(l);
}
