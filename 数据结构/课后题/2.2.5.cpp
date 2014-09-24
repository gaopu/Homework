void del_this(ElemType *it)
{
    ElemType *tmp = it,*t;

    while (tmp->next->next != it) 
		tmp = tmp->next;
	t = tmp->next;
	tmp->next = it;
    delete t;
}
