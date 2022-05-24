int sommaFinoA (int n)
{
  if (n==1)
  {
    return 1;
  }
  else
  {
    return sommaFinoA(n-1)+n;
  }
}
