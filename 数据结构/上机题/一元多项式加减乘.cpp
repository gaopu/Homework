#include <iostream>
#include <string>

using namespace std;
typedef struct Node
{
	double a;//系数
	double b;//次方
	struct Node *next;
}ElemType;

void Creat(ElemType **head1,ElemType **head2);
ElemType * Cal(ElemType *head1,ElemType *head2);
void PrintResult(ElemType *head);
ElemType * jia(ElemType *head1,ElemType *head2);
ElemType * jian(ElemType *head1,ElemType *head2);
ElemType * cheng(ElemType *head1,ElemType *head2);//计算返回结果链的头指针
void del_link(ElemType *head);

int main()
{
	ElemType * head1 = NULL,* head2 = NULL,* result = NULL;

	Creat(&head1,&head2);
	result = Cal(head1,head2);
    if (result) {
        PrintResult(result);
        del_link(result);
    }
}

void Creat(ElemType **head1,ElemType **head2)
{
	ElemType *p,*q;
	*head1 = new ElemType;
	*head2 = new ElemType;

	(*head1)->next = NULL;
	(*head2)->next = NULL;

	double a = 0,b = 0;
	cout<<"请输入如数据，eg：2X^2+3X^4输入时输入2 2 3 4 0\n";
	cout<<"即系数为0结束输入。\n";
	cout<<"请输入第一个一元多项式的数据：\n";
	cin>>a;
	p = *head1;
	while (a) {
		cin>>b;
		q = new ElemType;
		q->a = a;
		q->b = b;
		q->next = p->next;
		p->next = q;
		p = q;
		cin>>a;
		if (!a) {
			break;
		}
	}
	cout<<"请输入第二个一元多项式的数据：\n";
	cin>>a;
	p = *head2;
	while (a) {
		cin>>b;
		q = new ElemType;
		q->a = a;
		q->b = b;
		q->next = p->next;
		p->next = q;
		p = q;
		cin>>a;
		if (!a) {
			break;
		}
	}
}

ElemType * Cal(ElemType *head1,ElemType *head2)
{
	int sel = 0;

	cout<<"你要做什么运算？请选择：";
	cout<<"（1）相加（2）相减（3）相乘\n";
	cin>>sel;

	switch(sel) {
        //相加
		case 1:
            return jia(head1,head2);
        //相减
		case 2:
            return jian(head1,head2);
        //相乘
		case 3:
            return cheng(head1,head2);
		default:
			return NULL;
	}
}

void PrintResult(ElemType *head)
{
	ElemType *q = head->next;

	cout<<"结果是：";
	while (q) {
		if (q->a) {
			cout<<q->a<<"X^"<<q->b<<" + ";
		}
		q = q->next;
	}
	cout<<"\b\b\b   \b\b\b\n";
}

ElemType * jia(ElemType *head1,ElemType *head2)
{
	ElemType *q1 = head1->next,*q2 = head2->next,*tmp = NULL,*prev1 = head1;//prev1是第一条链当前节点的前一个节点

	delete(head2);

    while (q1 && q2) {
        if (q1->b == q2->b) {//q1和q2都下移到下一个节点
            q1->a += q2->a;
            tmp = q2;
            q2 = q2->next;
            delete tmp;
            prev1 = q1;
            q1 = q1->next;
        } else if (q1->b > q2->b) {
            tmp = q2;
            q2 = q2->next;
            tmp->next = prev1->next;
            prev1->next = tmp;
            prev1 = tmp;
        } else if (q1->b < q2->b) {
            for (;q1 && (q1->b < q2->b);prev1 = q1,q1 = q1->next);//链1走到次方数比q2的次方数大的那个节点上
        }
    }
    //如果q2序列没有走完
    if (q2) {
        prev1->next = q2;
    }

    return head1;
}

ElemType * jian(ElemType *head1,ElemType *head2)
{
	ElemType *q1 = head1->next,*q2 = head2->next,*tmp = NULL,*prev1 = head1;//prev1是第一条链当前节点的前一个节点

	delete(head2);

    while (q1 && q2) {
        if (q1->b == q2->b) {//q1和q2都下移到下一个节点
            q1->a -= q2->a;
            tmp = q2;
            q2 = q2->next;
            delete tmp;
            prev1 = q1;
            q1 = q1->next;
        } else if (q1->b > q2->b) {
            q2->a = 0 - q2->a;
            tmp = q2;
            q2 = q2->next;
            tmp->next = prev1->next;
            prev1->next = tmp;
            prev1 = tmp;
        } else if (q1->b < q2->b) {
            for (;q1 && (q1->b < q2->b);prev1 = q1,q1 = q1->next);//链1走到次方数比q2的次方数大的那个节点上
        }
    }
    //如果q2序列没有走完
    if (q2) {
        prev1->next = q2;
    }
    while (q2) {
        q2->a = 0 - q2->a;
        q2 = q2->next;
    }
    return head1;
}

ElemType * cheng(ElemType *head1,ElemType *head2)
{
    ElemType * q1 = head1->next;//遍历链1
    ElemType * q2 = head2->next;//遍历链2
    ElemType * head3 = new ElemType;//head3是第三条链，即最终结果链
    ElemType * p = head3, *q = NULL;//建立新链表时用

    head3->next = NULL;
    //先生成一条链，以便后面的链与这个链相加
    while(q1) {
        q = new ElemType;
        q->a = q1->a * q2->a;
        q->b = q1->b + q2->b;

        q->next = p->next;
        p->next = q;
        p = q;
        q1 = q1->next;
    }

    q2 = q2->next;
    //将链2一个一个乘到第一个链上面
    while (q2) {
        ElemType *head4 = new ElemType;//将这个链加到结果链head3上面
        p = head4;
	head4->next =NULL;
        q1 = head1->next;
        while(q1) {
            q = new ElemType;
            q->a = q1->a * q2->a;
            q->b = q1->b + q2->b;

            q->next = p->next;
            p->next = q;
            p = q;
            q1 = q1->next;
        }
        jia(head3,head4);

        q2 = q2->next;
    }
    //上面计算完毕之后还存在的链是head1,head2,head3
    del_link(head1);
    del_link(head2);
    
    return head3;
}

void del_link(ElemType *head)
{
    ElemType * tmp = NULL;

    while (head) {
        tmp = head->next;
        delete head;
        head = tmp;
    }
}
