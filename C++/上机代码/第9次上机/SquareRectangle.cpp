#include <iostream>
#include "SquareRectangle.h"

using namespace std;

int main()
{
    Square s1(100);
    Rectangle r1(200,300);
    Square *p;

    //比较下面两个语句
    cout<<"正方形 Squa1(100)的面积为:"<<s1.GetArea()<<endl;
    //静态联编,输出为:10000
    p = &s1;
    cout<<"正方形 Squa1(100)的面积为:"<<p->GetArea()<<endl;
    //cout<<"正方形 Squa1(100)的面积为:"<<objGetArea(&s1)<<endl;
    //比较下面两个语句
    cout<<"矩形 Rect(200,300) 的面积为::"<<r1.GetArea()<<endl;
    //静态联编,输出为 60000
    p = &r1;
    cout<<"矩形 Rect(200,300) 的面积为::"<<p->GetArea()<<endl;
    //cout<<"矩形 Rect(200,300) 的面积为::"<<objGetArea(&r1)<<endl;
    //动态联编,输出为 60000
    return 0;
}