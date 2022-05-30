int fact (int n)
{
  return factIt(n, 1, 1); //1 = inizializzazione dell'accumulatore (fattoriale di 1); 1 = contatore del passo
}

int factIt(int n, int F,int i)
{
  if (i <= n)
  {
    F = i*F;
    i = i+1;
    return factIt(n, F, i);
  }
  return F;
}
