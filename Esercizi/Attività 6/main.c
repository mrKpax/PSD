#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "punto.h"

void distanzaMinore(list l, int n)
{
  int coppie = 0;
  float tempd;
  punto prec, p;
  float d;
  
  prec = getFirst(l);
  
  printf("Quale deve essere la distanza massima? ");
  scanf("%f", &d);
  
  for(int i=0; i<n; i++)
  {
    p = getItem(l, i);
    
    tempd = distanza(p, prec);
    
    if(tempd < d)
      coppie++;
    
    prec = p;
  }
  
  printf("Le coppie a distanza minore di %f sono: %d\n", d, coppie);
  return;
}

void distanzaMassima(list l, int n)
{
  float tempd, max;
  int index;
  punto prec, p;
  punto *coppia;
  
  coppia = malloc(sizeof(punto) * 2);
  if(coppia == NULL) return;
  
  prec = getFirst(l);
  p = getItem(l, 1);
  
  tempd = distanza(p, prec);
  max = tempd;
  
  prec = p;
  
  for(int i = 1; i < n; i++)
  {
    p = getItem(l, i);
    
    tempd = distanza(p, prec);
    
    if(max < tempd)
    {
      max = tempd;
      index = i;
    }
    
    prec = p;
    
  }
  
  coppia[0] = getItem(l, index);
  coppia[1] = getItem(l, index+1);
  
  printItem(coppia[1]);
  printItem(coppia[2]);
}

int main (void)
{
  list l;
  int op = 0;
  int n = 0;
  punto p;
  
  l = newList();
  float x, y;

  printf("Coppie di punti da inserire: ");
  scanf("%d", &n);
  for (int i=0; i<n; i++)
  {
    printf("x: "); scanf("%f", &x);
    printf("y: "); scanf("%f", &y);
    p = creaPunto(x, y);
    l = consList(l, p);
  }
  
  l = reverseList(l);
  outputList(l);

  printf("Quale operazione si desidera effettuare? \n");
  printf("1) Conteggio delle coppie di punti a distanza minore di una distanza data in input\n");
  printf("2) Coppia di punti a distanza massima\n");
  printf("NON IMPLEMENTATA! Ordinamento della lista per coordinata e criterio dato in input\n");
  printf("-1 per uscire...\n");
  scanf("%d", &op);

  switch(op)
  {
    case 1:
      distanzaMinore(l,n);
      break;

    case 2:
      distanzaMassima(l, n);
      break;

    default:
      break;
  }

    return 0;
}
