#include "item.h"

typedef struct c_queue *queue;

queue newQueue(void);
int emptyQueue(queue q);
queue input_queue(queue q);
int enqueue(item val, queue q);
item dequeue(queue q);
int size_queue(queue q);
void output_queue(queue q);
