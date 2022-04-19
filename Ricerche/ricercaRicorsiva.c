int cercaA(int A[], int val, int n)
{
    if (val==A[n-1])
    {
        return 1;
    }

    if (n==1)
    {
        return 0;
    }

    return cercaA (A,val,n-1);
}
