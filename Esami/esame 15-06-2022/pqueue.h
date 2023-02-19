#include "item.h"

typedef struct c_PQ *PQueue;

PQueue newPQ(void);
int emptyPQ(PQueue q);
int getMax(PQueue q);
int deleteMax(PQueue q);
int insert(PQueue q, int key);
PQueue input_PQ(int *a, int numel);
void output_PQ(PQueue q);
