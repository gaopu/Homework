//简单的加减乘除
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MaxSize = 100;//栈的容量

//栈类的定义
class Stack
{
    double data[MaxSize];
    int top;//栈顶指针，空栈时为-1

public:
    Stack(){top = -1;}
    bool Empty();
    bool Full();
    bool Push(double x);
    bool Pop(double & x);
    bool GetValue(double & x);
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

bool Stack::Push(double x)
{
    if (Full()) {
        return false;
    }
    top++;
    data[top] = x;
    return true;
}

bool Stack::Pop(double & x)
{
    if (Empty()) {
        return false;
    }
    x = data[top];
    top--;
    return true;
}

bool Stack::GetValue(double & x)
{
    if (Empty()) {
        return false;
    }
    x = data[top];
    return true;
}

int youxian(char a,char b)//a比b优先级高返回1，相等返回0，小于返回-1
{
    if ((a == '*' || a == '/') && (b == '*' || b == '/')) {
        return 0;
    }
	if ((a == '+' || a == '-') && (b == '+' || b == '-')) {
		return 0;
	}
	if ((a == '*' || a == '/') && (b == '+' || b == '-')) {
		return 1;
	}
	if ((a == '+' || a == '-') && (b == '*' || b == '/')) {
		return -1;
	}
    return false;
}

double cal(char str[])
{
   int i = 0;
   char pushNum[50] = {0};//即将入栈的数字
   Stack num,ch;//Num是数字栈，Ch是字符栈
   double a = 0,b = 0;//运算时a（+-*/）b
   double c;//运算符
   bool getNum = false;//是否从字符串中取得了数字

    while (str[i]) {
        //memset(pushNum,0,sizeof(pushNum));
        for (int l = 0;l < sizeof(pushNum);l++)
        {
            pushNum[l] = 0;
        }
        getNum = false;
        //数字获取
        while (str[i]) {
            if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
                strncat(pushNum,&str[i],1);
                i++;
                getNum = true;
            } else {
                break;//不是数字的一部分了就跳出
            }
        }
        if (getNum) {
            num.Push(atof(pushNum));//数字压栈
        }
        ch.GetValue(c);//获取当前栈顶字符
        //当前字符与栈顶字符比较，做相应操作
        if (ch.Empty()) {
            ch.Push((double)str[i++]);
        } else if (str[i] && (youxian(str[i],(char)c) == 1)) { 
            //当前字符比栈顶符号优先级高，就入栈，否则计算（即else分支）
            ch.Push((double)str[i++]);
        } else {
			do {
				num.Pop(b);
				num.Pop(a);
				ch.Pop(c);

				switch((char)c) {
					case '+':
						a = a + b;
						num.Push(a);
						break;
					case '-':
						a = a - b;
						num.Push(a);
						break;
					case '*':
						a = a * b;
						num.Push(a);
						break;
					case '/':
						a = a / b;
						num.Push(a);
						break;
					default:
						cout<<"运算符错误！\n";
						exit(1);
				}
				ch.GetValue(c);//获取当前栈顶字符
			}while(!ch.Empty() && str[i] && (youxian(str[i],(char)c) != 1));//计算一遍完毕之后还要拿这个当前字符比较，如果不是比栈顶字符优先级高，就可以计算
            if (str[i]) {
                ch.Push(str[i++]);//运算完成将当前字符入栈
            }
        }
    }

    //栈中可能还有未计算完毕的东西，要全部计算
    while (!ch.Empty()) {
        num.Pop(b);
        num.Pop(a);
        ch.Pop(c);

        switch((char)c) {
            case '+':
                a = a + b;
                num.Push(a);
                break;
            case '-':
                a = a - b;
                num.Push(a);
                break;
            case '*':
                a = a * b;
                num.Push(a);
                break;
            case '/':
                a = a / b;
                num.Push(a);
                break;
        }
    }
    num.GetValue(a);//将结果存贮在a中

    return a;
}

int main(int argc, char *argv[])
{
    char str[100];//录入表达式
    double result = 0;

    cout<<"请输入表达式：";
    cin>>str;
    result = cal(str);
    cout<<"结果是："<<result<<endl;

    return 0;
}