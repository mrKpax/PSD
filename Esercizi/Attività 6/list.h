#include "punto.h"

typedef struct Node *list;

list newList(void);
int emptyList(list l);
list consList(list l, punto p);
list tailList(list l);
punto getFirst (list l);
int sizeList (list l);
int posItem (list l, punto p);
punto getItem (list l, int pos);
list reverseList (list l);
void outputList (list l);

