#include "item.h"

typedef struct c_PQ *pqueue;

pqueue newPQ(void);
int emptyPQ(pqueue q);
int getMax(pqueue q);
int deleteMax(pqueue q);
int insert(pqueue q, int key);
pqueue input_PQ(int *a, int numel);
void output_PQ(pqueue q);
