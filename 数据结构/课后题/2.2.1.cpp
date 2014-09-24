//顺序表
void change(ElemType arr[],int n)
{
    ElemType tmp = 0;

    for (int i = 0,j = n-1;i < j;i++,j--)
    {
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

//单链表，带头节点
void change(ElemType *head)
{
    ElemType *p,*q;

    p = head->next;
    head->next = NULL;

    while (p) {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}
