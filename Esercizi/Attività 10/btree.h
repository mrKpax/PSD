#include "item.h"

typedef struct node *btree;

btree newBtree(void);
int emptyBtree(btree T);
btree figlioSX(btree T);
btree figlioDX(btree T);
btree consBtree(item val, btree sx, btree dx);
struct node *getRoot(btree T);
item getItem(struct node *N);
void setItem(struct node *N, item el);
void output_Btree(btree T, int liv);
