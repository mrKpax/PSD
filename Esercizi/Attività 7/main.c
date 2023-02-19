#include <stdio.h>
#include "stack.h"

void inserisci(stack s)
{
    int val = 0;
    
    while(val != -1)
    {
        printf("Inserisci valore: ");
        scanf("%d", &val);
        
        if(val != -1)
            push(s, val);
    }
}

stack clone(stack s)
{
    stack c = newStack();
    stack temp = newStack();
    
    while(!emptyStack(s))
    {
        push(temp, top(s));
        pop(s);
    }
    
    while(!emptyStack(temp))
    {
        push(c, top(temp));
        push(s, top(temp));
        pop(temp);
    }
    
    freeStack(temp);
    
    return c;
}

stack inverti(stack s)
{
    stack rev = newStack();
    stack temp = clone(s);
    
    while(!emptyStack(temp))
    {
        push(rev, top(temp));
        pop(temp);
    }
    
    freeStack(temp);
    
    return rev;
}

stack append(stack s, stack rev)
{
    stack res = newStack();
    stack temp1 = clone(s);
    stack temp2 = clone(rev);
    
    while(!emptyStack(temp1))
    {
        push(res, top(temp1));
        pop(temp1);
    }
    
    while(!emptyStack(temp2))
    {
        push(res, top(temp2));
        pop(temp2);
    }
    
    res = inverti(res);
    
    freeStack(temp1);
    freeStack(temp2);
    
    return res;
}

void removeItems(stack s, item target)
{
    stack new = newStack();
    
    while(!emptyStack(s))
    {
        if(!eq(target, top(s)))
            push(new, top(s));
        
        pop(s);
    }
    
    while(!emptyStack(new))
    {
        push(s, top(new));
        pop(new);
    }
    
    freeStack(new);
    
    printf("\nStack aggiornato: \n");
    printStack(s);
    printf("\n\n");
}

int main(void)
{
    stack s = newStack();
    inserisci(s);
    printf("\nStack: \n");
    printStack(s);
    printf("\n");
    
    stack rev = newStack();
    rev = inverti(s);
    printf("\nStack invertito: \n");
    printStack(rev);
    printf("\n");
    
    append(s, rev);
    
    stack merge = newStack();
    merge = append(s, rev);
    printf("\nStack merge: \n");
    printStack(merge);
    printf("\n");
    
    item target;
    printf("\nQuale item vuoi rimuovere? ");
    scanf("%d", &target);
    removeItems(merge, target);
    
    freeStack(s);
    freeStack(rev);
    freeStack(merge);
    
    return 0;
}
