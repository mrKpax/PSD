#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "set.h"

struct node {
    item value;
    struct node *next;
};

struct c_set {
    struct node *first;
    int size;
};

//implementazione simile a quella di ADT list

set newSet(void)
{
    struct c_set *s;
    s = xmalloc(sizeof(struct c_set));
    s->first = NULL;
    s->size = 0;
    return s;
}

int emptySet(set s)
{
    if (s==NULL) return -1;
    return (s->size == 0);
}

int cardinality(set s)
{
    if (s==NULL) return -1;
    return s->size;
}

int contains(set s, item e)
{
    if (s==NULL) return 0;
    int found = 0;
    struct node *temp = s->first; //per attraversare i nodi

    while (temp != NULL && !found) //visita finalizzata
    {
        if (eq(temp->value, e))
            found = 1; //elemento trovato
        else
            temp = temp->next; //continua ricerca
    }

    return found;
}

//funzione privata usata da operatore insert
static struct node *makeNode(item e, struct node *next)
{
    struct node *nuovo = malloc(sizeof(struct node));

    if (nuovo != NULL)
    {
        nuovo->value = e;
        nuovo->next = next;
    }

    return nuovo;
}

int insertSet(set s, item e)
{
    if (s==NULL) return -1;

    if (s->first == NULL) //caso s vuoto
    {
        s->first = makeNode(e, NULL);
        if (s->first == NULL)
            return -1; //inserimento non riuscito
        s->size++;
        return 1; //inserimento riuscito
    }

    struct node *temp = s->first; //per attraversare i nodi
    
    if(eq(temp->value, e))
        return 0; //elemento già presente in prima posizione
    
    //visita del resto della struttura a puntatori
    //temp punta a nodo precedente quello corrente
    int found = 0;
    while (temp->next != NULL && !found) //visita finalizzata
    {
        if(eq(temp->next->value, e))
            found = 1; //elemento trovato
        else 
            temp = temp->next; //continua ricerca
    }
    if(found) return 0; //elemento già presente

    //se found == 0, allora temp punta all'ultimo nodo
    temp->next = makeNode(e, NULL);
    if (temp->next == NULL)
        return -1; //inserimento non riuscito
    s->size++;
    return 1; //inserimento riuscito
}

int removeSet(set s, item e)
{
    if (s==NULL) return 0;

    if(s->first == NULL) //caso s vuoto
    {
        return 0; //rimozione non riuscita
    }
    
    struct node *temp = s->first; //per attraversare i nodi

    if(eq(temp->value, e)) //elemento presente
    {
        s->first = s->first->next; //in prima posizione
        free(temp);
        s->size--;
        return 1;
    }

    int found = 0;

    while (temp->next != NULL && !found) //visita finalizzata
    {
        if(eq(temp->next->value, e))
            found = 1; //elemento trovato
        else
            temp = temp->next; //continua ricerca
    }

    if(!found) //elemento non presente
        return 0;
    
    //se found == 1, temp punta a nodo precedente a quello da rimuovere (che contiene e)

    struct node *temp1 = temp->next; //nodo da rimuovere
    temp->next = temp1->next;
    free(temp1);
    s->size--;
    return 1; //eliminazione riuscita
}

int unionSet(set s1, set s2)
{
    if (s1==NULL || s2==NULL) return 0; //operazione non riuscita

    struct node *temp = s2->first;
    int res = 0;
    //scorriamo s2 e inseriamo in s1 gli elementi di s2
    while (temp != NULL && res != -1) //visita di s2
    {
        res = insertSet(s1, temp->value);
        temp = temp->next;
    } //temp->value inserito in s1 solo se non presente

    if (res == -1) return 0; //operazione non riuscita
    return 1;
}

int intersectSet(set s1, set s2)
{
    if (s1==NULL || s2==NULL) return 0; //operazione non riuscita

    if (s1->first == NULL)
        return 1; //se s1 è vuoto, resta vuoto
    
    struct node *temp = s1->first;
    struct node *temp1;

    //eliminiamo da s1 gli elementi non presenti in s2
    //si scorre s1 a partire dal secondo elemento, trattando il primo alla fine

    while (temp->next != NULL)
    {
        if(!contains(s2, temp->next->value))
        {
            temp1= temp->next; //nodo da rimuovere
            temp->next = temp1->next;
            s1->size--;
            free(temp1);
        }
        else
            temp = temp->next;
    }

    //ora trattiamo il primo elemento di s1
    if(!contains(s2, s1->first->value))
    {
        temp1 = s1->first; //rimuoviamo primo elemento
        s1->first = s1->first->next;
        s1->size--;
        free(temp1);
    }
    return 1;
}
