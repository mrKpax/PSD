#include "item.h"

typedef struct node *Btree;

Btree newBtree(void);
int emptyBtree(Btree T);
item getItem(struct node *N);
struct node *getRoot(Btree T);
Btree consBtree(item val, Btree sx, Btree dx);
Btree figlioSX(Btree T);
Btree figlioDX(Btree T);
void output_Btree(Btree T, int liv);
int min_Btree(Btree T);
int max_Btree(Btree T);
