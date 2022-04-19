int minA (int A[], int n)
{
    int min;
    if (n==1)
    {
        return A[0];
    }

    min = minA(A,n-1);
    if (min<A[n-1])
    {
        return min;
    }
    else
    {
        return A[n-1];
    }
}
