ElemType * merge(ElemType *a,ElemType *b,int m,int n)
{
    ElemType *head = NULL;
    ElemType *tmp = NULL;
    ElemType *tmp1 = NULL;
    ElemType *tmp2 = NULL;
    
    if (m <= n) {
        head = a;
        tmp1 = a->next;
        tmp2 = b->next;
        free(b);
    }   else {
        head = b;
        tmp1 = b->next;
        tmp2 = a->next;
        free(a);
    }
    tmp = head;

    while (tmp1 && tmp2) {
        tmp->next = tmp1;
        tmp->next->next = tmp2;
        tmp = tmp2;

        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    
    while (tmp2) {
        tmp->next = tmp2;
		tmp2 = tmp2->next;
    }
    tmp->next = NULL;

    return head;
}
