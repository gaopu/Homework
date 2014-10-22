#include <iostream>

using namespace std;

const int SIZE = 100;

template <class T>
class Stack
{
public:
    Stack(){top = -1;}
    bool Push(T n);
    bool Pop(T & n);
private:
    T stack[SIZE];
    int top;
};

template <class T>
bool Stack<T>::Push(T n)
{
    if (top == SIZE - 1) {
        return false;
    }
    top++;
    stack[top] = n;
    return true;
}

template <class T>
bool Stack<T>::Pop(T & n)
{
    if (top == -1) {
        return false;
    }
    n = stack[top];
    top--;
    return true;
}

int main()
{
    cout<<"字符串栈：\n";
    Stack<string> t1;
    int i = 0;
    string data1;

    for (i = 0;i < 5;i++) {
        cin>>data1;
        t1.Push(data1);
    }

    for (i = 0;i < 5;i++) {
        t1.Pop(data1);
        cout<<data1<<" ";
    }
    cout<<endl;

    cout<<"整数栈：\n";
    Stack<int> t2;
    int data2;

    for (i = 0;i < 5;i++) {
        cin>>data2;
        t2.Push(data2);
    }

    for (i = 0;i < 5;i++) {
        t2.Pop(data2);
        cout<<data2<<" ";
    }
    cout<<endl;

    cout<<"浮点数栈：\n";
    Stack<double> t3;
    double data3;

    for (i = 0;i < 5;i++) {
        cin>>data3;
        t3.Push(data3);
    }

    for (i = 0;i < 5;i++) {
        t3.Pop(data3);
        cout<<data3<<" ";
    }
    cout<<endl;

    return 0;   
}













