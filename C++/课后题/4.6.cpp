#include <iostream>

using namespace std;

class Circle
{
public:
    Circle(float r)
    {
        radius = r;
        ++count;
    }
    ~Circle(){--count;}
    static int num() {return count;}
private:
    float radius;
    static int count;
};

int Circle::count = 0;

int main(int argc, char *argv[])
{ 
    Circle a(10);
    cout<<"有"<<Circle::num()<<"个圆\n";
    Circle b(20);
    cout<<"有"<<Circle::num()<<"个圆\n";
    Circle c(30);
    cout<<"有"<<Circle::num()<<"个圆\n";

    return 0;
}

