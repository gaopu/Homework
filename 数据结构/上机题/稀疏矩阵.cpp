// =====================================================================================
//
//       Filename:  系数矩阵.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年10月16日 21时08分43秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  geekgao (geekgao), 936302529@qq.com
//   Organization:  
//
// =====================================================================================

#include <iostream>
#include <cstdlib>

using namespace std;

const int MaxSize = 100;//最多存储100个三元组数据

struct SanYuanZu
{
    int row,col,num;
};

struct JuZhen
{
    SanYuanZu data[MaxSize];
    int rows,cols,count;//count是存储了多少个元素
};

void Input(JuZhen & one,JuZhen & two)
{
    int i = 0;

    cout<<"请输入第一个数组数据：\n";
    cout<<"请输入第一个数组的<行 列 数据个数>（最多100个元素）：";
    cin>>one.rows>>one.cols>>one.count;
    if (one.count > MaxSize) {
        cout<<"数据太多！\n";
        exit(0);
    }
    for (i = 0;i < one.count;i++) {
        cout<<"第"<<i + 1<<"个：";
        cin>>one.data[i].row>>one.data[i].col>>one.data[i].num;
    }

    cout<<"请输入第二个数组数据：\n";
    cout<<"请输入第二个数组的<行 列 数据个数>（最多100个元素）：";
    cin>>two.rows>>two.cols>>two.count;
    if (two.count > MaxSize) {
        cout<<"数据太多！\n";
        exit(0);
    }
    for (i = 0;i < two.count;i++) {
        cout<<"第"<<i + 1<<"个：";
        cin>>two.data[i].row>>two.data[i].col>>two.data[i].num;
    }
}

void add(JuZhen & one,JuZhen & two,JuZhen & result)
{
    int i = 0,j = 0,k = 0;

    result.rows = one.rows;
    result.cols = one.cols;
    while (i < one.count && j < two.count) {
        if (one.data[i].row == two.data[j].row && one.data[i].col == two.data[j].col) {
            result.data[k].row = one.data[i].row;
            result.data[k].col = one.data[i].col;
            result.data[k].num = one.data[i].num + two.data[j].num;
            i++;
            j++;
            k++;
        } else {
            if (one.data[i].row < two.data[j].row) {
                result.data[k].row = one.data[i].row;
                result.data[k].col = one.data[i].col;
                result.data[k].num = one.data[i].num;
                i++;
                k++;
            } else if (one.data[i].row > two.data[j].row) {
                result.data[k].row = two.data[j].row;
                result.data[k].col = two.data[j].col;
                result.data[k].num = two.data[j].num;
                j++;
                k++;
            } else if (one.data[i].col < two.data[j].col) {
                result.data[k].row = one.data[i].row;
                result.data[k].col = one.data[i].col;
                result.data[k].num = one.data[i].num;
                i++;
                k++;
            } else {
                result.data[k].row = two.data[j].row;
                result.data[k].col = two.data[j].col;
                result.data[k].num = two.data[j].num;
                j++;
                k++;
            }
        }
    }

    int t = 0;
    JuZhen *tmp;
    if (i == one.count) {
        tmp = &two;
        t = j;
    } else {
        tmp = &one;
        t = i;
    }

    while (t < tmp->count) {
        result.data[k].row = tmp->data[t].row;
        result.data[k].col = tmp->data[t].col;
        result.data[k].num = tmp->data[t].num;
        k++;
        t++;
    }
}

void subtract(JuZhen & one,JuZhen & two,JuZhen & result)
{
    int i = 0,j = 0,k = 0;

    result.rows = one.rows;
    result.cols = one.cols;
    while (i < one.count && j < two.count) {
        if (one.data[i].row == two.data[j].row && one.data[i].col == two.data[j].col) {
            result.data[k].row = one.data[i].row;
            result.data[k].col = one.data[i].col;
            result.data[k].num = one.data[i].num - two.data[j].num;
            i++;
            j++;
            k++;
        } else {
            if (one.data[i].row < two.data[j].row) {
                result.data[k].row = one.data[i].row;
                result.data[k].col = one.data[i].col;
                result.data[k].num = one.data[i].num;
                i++;
                k++;
            } else if (one.data[i].row > two.data[j].row) {
                result.data[k].row = two.data[j].row;
                result.data[k].col = two.data[j].col;
                result.data[k].num = 0 - two.data[j].num;
                j++;
                k++;
            } else if (one.data[i].col < two.data[j].col) {
                result.data[k].row = one.data[i].row;
                result.data[k].col = one.data[i].col;
                result.data[k].num = one.data[i].num;
                i++;
                k++;
            } else {
                result.data[k].row = two.data[j].row;
                result.data[k].col = two.data[j].col;
                result.data[k].num = 0 - two.data[j].num;
                j++;
                k++;
            }
        }
    }

    int t = 0;
    JuZhen *tmp;
    if (i == one.count) {
        tmp = &two;
        t = j;
    } else {
        tmp = &one;
        t = i;
    }

    while (t < tmp->count) {
        result.data[k].row = tmp->data[t].row;
        result.data[k].col = tmp->data[t].col;
        if (tmp == &two) {
            result.data[k].num = 0 - tmp->data[t].num;
        } else {
            result.data[k].num = tmp->data[t].num;
        }
        k++;
        t++;
    }
}

void Cal(JuZhen & one,JuZhen & two,JuZhen & result)
{
    int sel = 0;

    cout<<"请选择操作：\n";
    cout<<"（1）相加\n（2）相减\n输入：";
    cin>>sel;

    switch (sel) {
        case 1:
            if (one.cols != two.cols || one.rows != two.cols) {
                cout<<"不满足计算条件！\n";
                exit(0);
            }
            add(one,two,result);
            break;
        case 2:
            if (one.cols != two.cols || one.rows != two.cols) {
                cout<<"不满足计算条件！\n";
                exit(0);
            }
            subtract(one,two,result);
            break;
        default:
            cout<<"选择错误！\n";
            exit(0);
    }
}

void Print(JuZhen & t)
{
    int i = 0,j = 0,k = 0;

    for (i = 0;i < t.rows;i++) {
        for (j = 0;j < t.cols;j++) {
            if (i == t.data[k].row && j == t.data[k].col) {
                cout<<t.data[k++].num<<" ";
            } else {
                cout<<"0 ";
            }
        }
        cout<<"\n";
    }
}

int main()
{
    JuZhen one,two,result;
    
    Input(one,two);
    Cal(one,two,result);
    Print(result);

    return 0;
}




















