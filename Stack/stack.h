typedef struct c_stack *stack;

stack newStack(void);
int emptyStack(stack s);
int pop(stack s);   //restituisce l'esito dell'operazione
int push(item val, stack s);   //restituisce l'esito dell'operazione
item top(stack s);
