#include <iostream>
#include <cstring>

using namespace std;

void get_next(char * str,int * next);
int find(char *str1,int index,char *str2);

int main()
{
    int next[50];
    char str1[100];
    char str2[100];
    int pos = 0;

    cout<<"请输入主串：";
    cin.getline(str1,100);
    cout<<"请输入要查找的串：";
    cin.getline(str2,100);
    pos = find(str1,0,str2);
    cout<<pos<<endl;
}

//next不用下标为0的位置
void get_next(char * str,int * next)
{
    next[0] = 0;
    next[1] = 0;
    next[2] = 1;

    int i = 2;//遍历串(从下标为2的元素开始)
    int j = i;//j开始时为2，指向next数组中第2个下标

    for (;i < strlen(str);)
    {
        if ( !j || (str[i - 1] == str[next[j] - 1])) {
            next[i + 1] = next[j] + 1;
            i++;
            j = i;
        } else {
            j = next[j];
        }
    }
}

int find(char *str1,int index,char *str2)
{
    int next[100];
    int i = index;//遍历主串
    int j = 0;//指str2

    get_next(str2,next);
    for (;i < strlen(str1) && j < strlen(str2);)
    {
        if (str1[i] == str2[j]) {
            i++;
            j++;
        } else {
            j = next[j + 1] - 1;
            if (j < 0) {
                i++;
                j = 0;
            }
        }
    }

    if (j == strlen(str2)) {
        return i - j;
    } else {
        return 999;
    }
}
