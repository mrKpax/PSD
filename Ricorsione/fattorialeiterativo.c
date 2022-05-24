int fact(int n)
{
  int i = 1;
  int F = 1; //inizializzazione del fattoriale

  while (i <= n)
  {
    F = F * i; //differenza con la vers. ricorsiva: ad ogni passo si accumula un risultato intermedio
    i = i + 1;
  }

  return F;
}

//al primo passo F accumula il fattoriale di 1, al secondo passo accumula il fattoriale di 2, al passo i-esimo accumula il fattoriale di i
