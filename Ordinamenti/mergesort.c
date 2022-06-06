void Merge(int A[], int p, int q, int r)
{
    int B[MAX], i=p, j=q+1, k=p;
    while (i<=q && j<=r)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }

    while (i<=q)
    {
        B[k++] = A[i++];
    }

    while (j<=r)
    {
        B[k++] = A[j++];
    }

    for (k=p; k<=r; k++)
    {
        A[k] = B[k];
    }

    return;
}

void Mergesort(int A[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r)/2;
        Mergesort(A, p, q);
        Mergesort(A, q+1, r);
        Merge(A, p, q, r);
    }
    return;
}
