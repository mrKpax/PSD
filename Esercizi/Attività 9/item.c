#include <stdio.h>
#include "item.h"

void printItem(item it)
{
    printf("%d", it);
}

void freeItem(item it)
{
    ;
}

int isEqual(item it1, item it2)
{
    return it1 == it2;
}
