#include "item.h"

typedef struct c_stack *stack;

stack newStack(void);
int emptyStack(stack s);
int push(item val, stack s);
int pop(stack s);
item top(stack s);

stack input_stack(stack s);
void output_stack(stack s);
