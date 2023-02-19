#include <stdio.h>
#include "item.h"

void printItem(item it)
{
    printf("%d", it);
}

void input_item(item *it)
{
    printf("Inserisci un numero: ");
    scanf("%d", it);
}

int eq(item it1, item it2)
{
    return it1 == it2;
}
