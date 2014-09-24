#include <iostream>
#include <string>
#include <cmath>

using namespace std;
typedef struct Node
{
	double a;//系数
	double b;//次方
	struct Node * next;
}ElemType;

void Creat(ElemType ** head);
double Cal(ElemType * head,double num);

int main()
{
	ElemType *head = NULL;
    double x = 0,result = 0;

	Creat(&head);
    cout<<"请输入X：";
    cin>>x;
	result = Cal(head,x);
	cout<<"结果是"<<result<<endl;
}

void Creat(ElemType ** head)
{
	ElemType *p,*q;
	*head = new ElemType;

	(*head)->next = NULL;

	double a = 0,b = 0;
	cout<<"请输入如数据，eg：2X^2+3X^4输入时输入2 2 3 4 0\n";
	cout<<"即系数为0结束输入。\n";
	cout<<"请输入一元多项式的数据：\n";
	cin>>a;
	p = *head;
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

double Cal(ElemType * head,double num)
{
	ElemType * tmp = head->next;
    double result = 0;

	while (tmp) {
        result = result + tmp->a * pow(num,tmp->b);
        tmp = tmp->next;
	}
    while (head) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    return result;
}
