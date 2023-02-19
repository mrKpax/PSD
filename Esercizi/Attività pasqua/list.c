#include <stdio.h>
#include <stdlib.h>
#include "list.h"


struct node
{
  item val;
  struct node *next;
};

list newList(void)
{
  return NULL;
}

int emptyList(list l)
{
  return l == NULL;
}


list addFirst(list l, item p)
{
  struct node *new;
  
  new = malloc(sizeof(struct node));
  if (new != NULL)
  {
    new->val = p;
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

item getFirst (list l)
{
  if(emptyList(l)) return NULLITEM;
  
  return l->val;
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

int posItem (list l, item val)
{
  if(emptyList(l)) return -1;
  
  item temp;
  int i = 0;
  
  while(!emptyList(l))
  {
    temp = getFirst(l);
    
    if(isEqual(val, temp))
    {
      return i;
    }
    
    l = tailList(l);
    i++;
  }

  return -1;
}

item getItem (list l, int pos)
{
  if(emptyList(l)) return NULLITEM;
  
  int i = 0;
  
  if(pos == 0)
  {
    return l->val;
  }
  
  while(i<pos && !emptyList(l))
  {
    l = tailList(l);
    i++;
  }

  if(l == NULL) return NULLITEM;

  return l->val;
}

list reverseList (list l)
{
  if (emptyList(l)) return l;
  
  list rev;
  item temp;
  
  rev = newList();

  while(!emptyList(l))
  {
    temp = getFirst(l);
    rev = addFirst(rev, temp);
    l = tailList(l);
  }
  
  return rev;
}

void outputList(list l)
{
  int i = 0;

  while(!emptyList(l))
  {
    printf("L'elemento di posizione %d: ", i);
    printItem(l->val);
    printf("\n");
    l = tailList(l);
    i++;
  }
}
