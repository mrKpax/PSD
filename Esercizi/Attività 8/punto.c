#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto.h"

struct Punto
{
    float ascissa;
    float ordinata;
};

punto creaPunto(float x, float y)
{
    punto p;
    
    p = malloc(sizeof(*p));
    if(p==NULL) return NULL;

    p->ascissa = x;
    p->ordinata = y;
    
    return p;
}

float getAscissa(punto p)
{
    return p->ascissa;
}

float getOrdinata(punto p)
{
    return p->ordinata;
}

int eq(punto p1, punto p2)
{
    return (p1->ascissa == p2->ascissa && p1->ordinata == p2->ordinata);
}

float distanza(punto p1, punto p2)
{
    if(p1 == NULLITEM || p2 == NULLITEM) return 0;

    float dx = p1->ascissa - p2->ascissa;
    float dy = p1->ordinata - p2->ordinata;
    float d = sqrt(dx * dx + dy * dy);

    return d;
}

void printItem(punto p)
{
    printf("Ascissa: %f\n", p->ascissa);
    printf("Ordinata: %f\n", p->ordinata);
}
