typedef int item;

#define NULLITEM 0

//il tipo item è l'insieme degli interi positivi
//NULLITEM è un elemento che viene restituito quando la precondizione di getFirst viene violata

int eq(item x, item y);
void input_item(item *x);
void output_item(item x);
char itemtoch (item e);
item chtoitem (char c);
