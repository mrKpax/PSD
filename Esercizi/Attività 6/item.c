#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "item.h"

struct puntoitem
{
  float x;
  float y;
};

int eq(item a, item b)
{
  return a == b;
}

item creaItem(float a, float b){
  item new = malloc(sizeof(struct puntoitem));
  if (new == NULL)
  {
    fprintf(stderr, "errore \n");
  }

  new->x = a;
  new->y = b;

  return new;
}

void input_item(int *new)
{
    printf("Inserisci un numero: ");
    scanf("%d", new);
}

float distanza(item p1, item p2)
{
  float dx = p1->x - p2->x;
  float dy = p1->y - p2->y;
  float d = sqrt(dx*dx + dy*dy);
  return d;
}


void output_item(item it)
{
  printf("Ascissa: %f\n", it->x);
  printf("Ordinata: %f\n", it->y);
  return;
}
