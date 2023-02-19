#include "item.h"

typedef struct node *list;

list newList(void);
int isEmpty(list l);
list addFirst(list l, item it);
list tailList(list l);
int sizeList(list l);
int sizeListRec(list l);
void printList(list l);
void freeList(list l);
void destroyList(list l);
