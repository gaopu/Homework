// =====================================================================================
//
//       Filename:  9.6.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年10月21日 20时57分00秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
//        Company:  Alibaba-Inc Aliyun
//
// =====================================================================================

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
/*
template <>
class Stack<char *>
{
public:
    Stack(){top = -1;};
    bool Push(char * n);
    bool Pop(char * n);
private:
    char * stack[SIZE];
    int top;
};*/

int main()
{
    Stack<string> t;
    int i = 0;
    string data;

    for (i = 0;i < 5;i++) {
        cin>>data;
        t.Push(data);
    }

    for (i = 0;i < 5;i++) {
        t.Pop(data);
        cout<<data;
    }
    cout<<endl;

    return 0;   
}













