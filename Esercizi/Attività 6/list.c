#include <stdio.h>
#include <stdlib.h>
#include "list.h"


struct Node
{
  punto value;
  struct Node *next;
};

list newList(void)
{
  return NULL;
}

int emptyList(list l)
{
  return l == NULL;
}


list consList(list l, punto p)
{
  struct Node *new;
  
  new = malloc(sizeof(struct Node));
  if (new != NULL)
  {
    new->value = p;
    new->next = l;
    l = new;
  }
  
  return l;
}

list tailList(list l)
{
  if (l == NULL) return l;
  
  return l->next;
}

punto getFirst (list l)
{
  if(emptyList(l)) return NULLITEM;
  
  return l->value;
}

int sizeList (list l)
{
  if(emptyList(l)) return 0;
  
  int i = 0;
  
  while(!emptyList(l))
  {
    l = tailList(l);
    i++;
  }
  return i;
}

int posItem (list l, punto p)
{
  if(emptyList(l)) return -1;
  
  punto temp;
  int i = 0;
  
  while(!emptyList(l))
  {
    temp = getFirst(l);
    
    if(eq(p, temp))
    {
      return i;
    }
    
    l = tailList(l);
    i++;
  }
  
  return -1;
}

punto getItem (list l, int pos)
{
  if(emptyList(l)) return NULLITEM;
  
  int i = 0;
  
  if(pos == 0)
  {
    return l->value;
  }
  
  while(i<pos && !emptyList(l))
  {
    l = tailList(l);
    i++;
  }

  if(l == NULL) return NULLITEM;

  return l->value;
}

list reverseList (list l)
{
  if (emptyList(l)) return l;
  
  list rev;
  punto temp;
  
  rev = newList();

  while(!emptyList(l))
  {
    temp = getFirst(l);
    rev = consList(rev, temp);
    l = tailList(l);
  }
  
  return rev;
}

void outputList (list l)
{
  int i = 0;

  while(!emptyList(l))
  {
    printf("L'elemento di posizione %d: ", i);
    printItem(l->value);
    printf("\n");
    l = tailList(l);
    i++;
  }
}
