#include <stdio.h>
#include "item.h"

int isEqual(item it1, item it2)
{
    return it1 == it2;
}

void inputItem(item *x)
{
    printf("Insert item value: ");
    scanf("%d", x);
}

void printItem(item it)
{
    printf("%d", it);
}
