typedef struct c_PQ *PQueue;

PQueue newPQ(void);
int emptyPQ(PQueue q);
int getMax(PQueue q);
int deleteMax(PQueue q);
int insert(PQueue q, int key);

//insert() e deleteMax() restituiscono 0 se l'op. fallisce, 1 se ha successo
