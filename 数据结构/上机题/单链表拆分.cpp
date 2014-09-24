//    Description:  按照第一个数的将比这个数小的放到前面，大的放到后面
#include <iostream>
using namespace std;

struct ElemType
{
    int num;
    ElemType * next;
};

ElemType * creat()
{
    ElemType * head = NULL,*p = NULL,*q = NULL;
    int x = 0;

    head = p = new ElemType;
    head->next = NULL;

    cout<<"请输入数字，0结束";
    cin>>x;
    
    while (x) {
        q = new ElemType;
        q->num = x;
        q->next = p->next;
        p->next = q;
        p = q;
        cin>>x;
    }

    return head;
}

void chaifen(ElemType *head)
{
    ElemType * q = head->next,* p = head,* t = NULL;//p是q的前驱节点
    ElemType * first = head->next;

    while (q) {
        if (q->num < first->num) {
            t = q;
            q = q->next;
            p->next = q;
            t->next = head->next;
            head->next = t;
        } else {
            p = p->next;
            q = q->next;
        }
    }
}

void print(ElemType * head)
{
    head =head->next;

    while (head) {
        cout<<head->num<<" ";
        head = head->next;
    }
}

void del_link(ElemType * head)
{
    ElemType * p = head;

    while (p) {
        head = head->next;
        delete p;
        p = head;
    }
}

int main(int argc, char *argv[])
{
    ElemType * head;

    head = creat();
    chaifen(head);
    print(head);
    del_link(head);

    return 0;
}

