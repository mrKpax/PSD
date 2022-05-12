#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"
#define MAX_S_size 81

int verifica(char *expr);
{
    stack S = newStack();
    int c, i = 0;
    itemp top_el;

    if (!expr) return 1;

    while(expr[i] != '\0')
    {
        c = expr[i];
        if (c=='(' || c=='[' || c=='{')
        {
            push (chtoitem(c), S);
        }
        if (c==')' || c==']' || c=='}')
        {
            if (emptyStack(S))
            {
                return 0;
            }
            top_el = top(S);
            pop(S);
            if(!corrisp(itemtoch(top_el), c))
            {
                return 0;
            }
        }
        i++
    }
    
    if (emptyStack(S))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int corrisp(char a, char b)
{
    if (a=='(' || && b==')')
    {
        return 1;
    }
    if (a=='[' || && b==']')
    {
        return 1;
    }
    if (a=='{' || && b=='}')
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    int ris;
    char expr[MAX_S_size];

    printf("Inserire una espressione senza spazi: ");
    scanf("%s", expr);

    ris = verifica(expr);

    if(ris)
    {
        printf("Parentesi bilanciate \n");
    }
    else
    {
        printf("Parentesi non bilanciate \n");
    }

    return 0;
}
