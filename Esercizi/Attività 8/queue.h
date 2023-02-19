#include "punto.h"

typedef struct c_queue *queue;

queue newQueue(void);
int emptyQueue(queue q);
punto dequeue(queue q);
int enqueue(queue q, punto val);
void printQueue(queue q);
void freeQueue(queue q);
