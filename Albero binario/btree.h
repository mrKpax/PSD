typedef struct node *btree; //l'ADT btree è indipendente dal tipo degli elementi contenuti

btree newBtree(void);
int emptyBtree(btree T);
btree figlioSX(btree T);
btree figlioDX(btree T);
btree consBtree(item val, btree sx, btree dx);
node *getRoot(btree T);
