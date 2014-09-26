#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MaxSize = 100;//栈的容量
const int YingsheNum = 10;//映射的数量

//栈类的定义
class Stack
{
    char data[MaxSize];
    int top;//栈顶指针，空栈时为-1

public:
    Stack(){top = -1;}
    bool Empty();
    bool Full();
    bool Push(char x);
    bool Pop(char & x);
    bool GetValue(char & x);
};

bool Stack::Empty()
{
    if (top == -1) {
        return true;
    }
    return false;
}

bool Stack::Full()
{
    if (top == MaxSize - 1) {
        return true;
    }
    return false;
}

bool Stack::Push(char x)
{
    if (Full()) {
        return false;
    }
    top++;
    data[top] = x;
    return true;
}

bool Stack::Pop(char & x)
{
    if (Empty()) {
        return false;
    }
    x = data[top];
    top--;
    return true;
}

bool Stack::GetValue(char & x)
{
    if (Empty()) {
        return false;
    }
    x = data[top];
    return true;
}

struct Yingshe
{
    char left;
    char right[100];
};

int main(int argc, char *argv[])
{
    struct Yingshe mowang[YingsheNum];
    char tmp[100];
    char MoWangLanguage[500] = {0};//魔王的语言
    char PeopleLanguage[500] = {0};//转换后人类的语言
    int count = 0;//映射的数量
    bool change = false;//标记是否对应关系有改变
    Stack ChStack;

    cout<<"请输入对应关系的数量：";
    cin>>count;

    cout<<"请输入映射关系（eg:A->abcd）：";
    for (int i = 0;i < count;i++)
    {
        cin>>tmp;
        mowang[i].left = tmp[0];
        strcpy(mowang[i].right,tmp + 3);
    }

    for (int i = 0,j = 0;i < count;i++,j = 0)//将映射关系中的大写字母，按照映射关系，转换成小写的
    {
        change = false;
        memset(tmp,0,sizeof(tmp));

        while (mowang[i].right[j]) {
            if (mowang[i].right[j] >= 'A' && mowang[i].right[j] <= 'Z') {
                int k = 0;
                for (k = 0;k < count && (mowang[i].right[j] != mowang[k].left);k++)   ;
                if (k != count) {
                    strcat(tmp,mowang[k].right);
                } else {
                    cout<<"对应关系有问题，魔王的语言词汇没有对应的人类语言";
                    exit(1);
                }
                change = true;
            } else {
                strncat(tmp,&mowang[i].right[j],1);
            }
            j++;
        }
        if (change) {
            strcpy(mowang[i].right,tmp);
        }
    }

    cout<<"请输入魔王的语言：";
    cin>>MoWangLanguage;
    
    int i = 0,j = 0;
    while (MoWangLanguage[i]) {
        if (MoWangLanguage[i] >= 'A' && MoWangLanguage[i] <= 'Z') {
            int k = 0;
            for (k = 0;k < count && (MoWangLanguage[i] != mowang[k].left);k++)   ;
            if (k != count) {
                strcat(PeopleLanguage,mowang[k].right);
                j = strlen(PeopleLanguage);
            } else {
                cout<<"对应关系有问题，魔王的语言词汇没有对应的人类语言";
                exit(1);
            }
        } else {
            PeopleLanguage[j++] = MoWangLanguage[i];
        }
        i++;
    }

    i = 0,j = 0;
    //里面右括号的话，要根据第二个对应规则改变，此处结果存MoWangLanguage里面
    while (PeopleLanguage[i]) {
        if (PeopleLanguage[i] != '(' && PeopleLanguage[i] != ')') {
            MoWangLanguage[j++] = PeopleLanguage[i];
            i++;
        } else {
            if (PeopleLanguage[i] == '(') {
                char t1 = PeopleLanguage[i + 1],t2 = 0;
                i += 2;
                while (PeopleLanguage[i] != ')') {
                    ChStack.Push(PeopleLanguage[i++]);
                }
                i++;//跳过右括号
                MoWangLanguage[j++] = t1;
                while (!ChStack.Empty()) {
                    ChStack.Pop(t2);
                    MoWangLanguage[j++] = t2;
                    MoWangLanguage[j++] = t1;
                }
            }
        }
    }

    cout<<"转换成人类语言是："<<MoWangLanguage<<endl;

    return 0;
}




























