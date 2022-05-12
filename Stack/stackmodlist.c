#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"
#include "list.h"

struct c_stack {
    list top;
}

stack newStack(void)
{
    stack s;
    s = xmalloc(sizeof(struct c_stack));
    s->top = newList();
    return s;
}

int emptyStack(stack s)
{
    return emptyList(s->top);
}

int push(item val, stack s)
{
    return insertList(s->top, 0, val);
}

int pop(stack s)
{
    return removeList(s->top, 0);
}

item top(stack s)
{
    return getFirst(s->top);
}
