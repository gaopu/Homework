void del(ElemType arr[],int n,ElemType x)
{
    int k = 0;

    for (int i = 0;i < n;i++,k++)
    {
        if (arr[i] != x) {
            arr[k] = arr[i];
        }
    }
}
