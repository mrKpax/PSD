int ricerca(int v[], int size, int k)
{
	for (int i=0; i<size; i++)
	{
		if (v[i]==k) return i;
	}
	return -1;
}
