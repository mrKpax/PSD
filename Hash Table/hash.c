int hash (char *v, int m)
{
  int h = 0, a = 128;
  for (; *v != '\0'; v++)
    h = (a*h + *v) % m;
  return h;
}
