/*
 *（1）去掉friend之后，编译提示不可以访问对象a,b的私有成员X和Y。
 *（2）第二个没有使用友元的代码只能使用一个对象调用Distance函数然后，参数中包括另一个对象
 * 
 *
 * */

#include <iostream>
#include <cmath>

using namespace std;

class Point
{
public:
    Point(double xi,double yi){X = xi;Y = yi;}
    double GetX(){return X;}
    double GetY(){return Y;}
    friend double Distance(Point & a,Point & b);
private:
    double X,Y;
};

double Distance(Point & a,Point & b)
{
    double dx = a.X-b.X;
    double dy = a.Y-b.Y;
    return sqrt(dx * dx + dy * dy);
}

int main(int argc, char *argv[])
{
    Point p1(3.0,5.0),p2(4.0,6.0);

    double d = Distance(p1,p2);
    cout<<"The distance is "<<d<<endl;

    return 0;
}

