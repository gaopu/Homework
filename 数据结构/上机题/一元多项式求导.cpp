#include <iostream>
#include <string>

using namespace std;
typedef struct Node
{
	double a;//系数
	double b;//次方
	struct Node *next;
}ElemType;

void Creat(ElemType **head);
void Cal(ElemType *head);
void PrintResult(ElemType *head);

int main()
{
	ElemType *head = NULL;

	Creat(&head);
	Cal(head);
	PrintResult(head);
}

void Creat(ElemType **head)
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

void Cal(ElemType *head)
{
	ElemType *q = head->next;

	while (q) {
		q->a = q->b * q->a;
		q->b--;
		q = q->next;
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
