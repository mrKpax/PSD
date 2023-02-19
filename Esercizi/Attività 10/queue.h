#include "btree.h"

typedef struct c_queue *queue;

queue newQueue(void);
int emptyQueue(queue q);
int enqueue(queue q, btree t);
btree dequeue(queue q);
//void freeQueue(queue q);
