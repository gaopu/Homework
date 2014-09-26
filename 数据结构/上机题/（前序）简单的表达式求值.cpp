//简单的加减乘除
//前序表达式计算（反着的前序表达式，直接从第一个扫描计算）
#include <iostream>
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

bool NotLow(char a,char b)//是否a的优先级>=b的优先级
{
    if (((a == '+') || (a == '-')) && ((b == '*') || (b == '/'))) {
        return false;
    }
    return true;
}

void change(char *str)     //中序转前序（空格隔开每个元素）
{
    char tmp,*t = str;//t记住str的首地址（最后要把前序表达式赋值进去）
    char FirstStr[100] = {0};//这个是最终的前序表达式的反式
    char Num[100];
    double ChTmp;//接收从字符栈中出来的字符
    Stack ChStack;//字符栈

    //逆置，从后面遍历
    for (int i = 0,j = strlen(str) - 1;i < j;i++,j--)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }

    //遍历终须表达式
    while (*str) {
        if (isdigit(*str)) {//如果是数字那么直接写进前序表达式
            memset(Num,0,sizeof(Num));
            while (isdigit(*str) || *str == '.') {
                strncat(Num,str,1);
                str++;
            }
            for (int i = 0,j = strlen(Num) - 1;i < j;i++,j--)//将数字反过来
            {
                tmp = Num[i];
                Num[i] = Num[j];
                Num[j] = tmp;
            }
            strcat(FirstStr,Num);
            //一个数字结束之后给后面添上一个空格（最后结尾的空格不影响计算）
            strcat(FirstStr," ");
        } else if (*str) {//已经知道不是数字了，那么如果还不是字符串末尾，那么肯定遇到运算符或者括号了
            if(ChStack.Empty()) {//空栈直接入栈
                ChStack.Push((double)(*str));
                str++;
            } else if (*str == ')') {//右括号也直接入栈
                ChStack.Push((double)(*str));
                str++;
            } else if (*str == '(') {//遇见右括号前的栈中所有字符出栈
                ChStack.Pop(ChTmp);
                while ((char)ChTmp != ')') {
                    tmp = (char)ChTmp;
                    strncat(FirstStr,&tmp,1);
                    strcat(FirstStr," ");
                    ChStack.Pop(ChTmp);
                }
                str++;
            } else {//这个字符肯定是+-*/了
                ChStack.GetValue(ChTmp);
                //当前字符>=栈顶字符优先级，或者栈顶是括号，那么直接入栈
                if (NotLow(*str,(char)ChTmp) || ((char)ChTmp == '(') || ((char)ChTmp == ')')) { 
                    ChStack.Push((double)(*str));
                    str++;
                } else {
                    //一个个出栈，直到不低于栈顶字符优先级或者栈顶是括号（栈顶是括号while的判断条件为假）
                    while (!NotLow(*str,(char)ChTmp) && !ChStack.Empty()) {
                        ChStack.Pop(ChTmp);
                        tmp = (char)ChTmp;
                        strncat(FirstStr,&tmp,1);
                        strcat(FirstStr," ");
                        ChStack.GetValue(ChTmp);
                    }
                }
            }
        }
    }

    while (!ChStack.Empty()) {
        ChStack.Pop(ChTmp);
        tmp = (char)ChTmp;
        strncat(FirstStr,&tmp,1);
        strcat(FirstStr," ");
    }

    str = t;
    strcpy(str,FirstStr);
}

double cal(char * str)
{
    char NumStr[20] = {0};          //即将入栈的数字字符串
	double a = 0,b = 0,result = 0;
	Stack NumStack;//数字栈

	while (*str) {
        //如果这个字符是数字
		if (isdigit(*str)) {
            memset(NumStr,0,sizeof(NumStr));
            while (isdigit(*str) || *str == '.') {
                strncat(NumStr,str,1);
                str++;  //加到了空格处或者字符串结尾处
            }
            str--; //配合if-else外面的str++,如果没有这个，外面的str++可能加到\0的后面
            NumStack.Push(atof(NumStr));
		} else if (*str != ' ') {//这个字符不是数字也不是空格，那肯定就是运算符了
			switch(*str) {
				case '+':
					NumStack.Pop(a);
					NumStack.Pop(b);
					NumStack.Push(a + b);
					break;

				case '-':
					NumStack.Pop(a);
					NumStack.Pop(b);
					NumStack.Push(a - b);
					break;

				case '*':
					NumStack.Pop(a);
					NumStack.Pop(b);
					NumStack.Push(a * b);
					break;

				case '/':
					NumStack.Pop(a);
					NumStack.Pop(b);
					NumStack.Push(a / b);
					break;
				default:
					cout<<"运算符是:"<<*str<<"，错误.\n";
			}
		}
        str++;
	}

    NumStack.Pop(result);
    return result;
}

int main(int argc, char *argv[])
{
    char str[100];//录入表达式
    double result = 0;

    cout<<"请输入表达式：";
    cin.getline(str,100);
    change(str);
    cout<<"前序表达式的反式："<<str<<endl;
    result = cal(str);
    cout<<"结果是："<<result<<endl;

    return 0;
}
