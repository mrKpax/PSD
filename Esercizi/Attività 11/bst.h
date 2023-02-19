#include "item.h"

typedef struct node *BST;

BST newBST(void);
int emptyBST(BST T);
item getItem(struct node *N);
struct node *getRoot(BST T);
BST figlioSX(BST T);
BST figlioDX(BST T);
BST insert(BST T, item elem);
int contains(BST T, item elem);
BST deleteNode(BST T, item elem);
void output_BST(BST T, int liv);
