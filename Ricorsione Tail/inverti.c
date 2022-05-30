#include <stdio.h>
#include <string.h>

void print_rev (char car)
{
  char c;
  if (car != '.')
  {
    c = getchar();
    printf("lettera %c\n", c);
    print_rev(c); //ogni record di attivazione nello stack memorizza un singolo carattere letto (push); in fase di pop, i caratteri vengono stampati nell'ordine inverso
    printf("%c", car);
  }
  else return;
}

main()
{
  char k;
  printf("\nIntrodurre una sequenza terminata da . : \t ");
  k = getchar();
  print_rev(k);
  printf("\n FINE \n");
}
