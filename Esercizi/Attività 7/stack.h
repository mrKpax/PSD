#include "item.h"

typedef struct c_stack *stack;

stack newStack(void);
int emptyStack(stack s);
int push(stack s, item it);
int pop(stack s);
item top(stack s);
stack reverseStack(stack s);
void printStack(stack s);
void freeStack(stack s);
stack merge(stack s1, stack s2);
stack deleteItems(stack s, item it);
