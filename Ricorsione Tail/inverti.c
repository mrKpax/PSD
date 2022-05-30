void print_rev (char car)
{
  char c;
  if (car != '.')
  {
    c = getchar();
    print_rev(c); //ogni record di attivazione nello stack memorizza un singolo carattere letto (push); in fase di pop, i caratteri vengono stampati nell'ordine inverso
    printf("%c", car);
  }
  else return;
}
