typedef struct c_queue *queue; //realizzato in modo da non dipendere dal tipo degli elementi contenuti

queue newQueue(void);
int emptyQueue(queue q);
item dequeue(queue q); //toglie e restituisce l'elemento in testa alla coda
int enqueue(item val, queue q); //restituisce un intero che indica l'esito dell'operazione
