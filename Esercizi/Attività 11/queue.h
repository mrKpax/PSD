#include "item.h"

typedef struct c_queue *queue;

queue newQueue(void);
int emptyQueue(queue q);
int enqueue(item val, queue q);
item dequeue(queue q);
void output_queue(queue q);
