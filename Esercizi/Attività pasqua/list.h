#include "item.h"

typedef struct node *list;

list newList(void);
int emptyList(list l);
list addFirst(list l, item val);
list tailList(list l);
item getFirst (list l);
int sizeList (list l);
int posItem (list l, item val);
item getItem (list l, int pos);
list reverseList (list l);
void outputList (list l);
