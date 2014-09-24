#include <iostream>

using namespace std;

class Rectangle
{
	double length;
	double width;
public:
	Rectangle(double l,double w){width = w;length = l;}
	double area(){return length * width;}
};

int main()
{
	Rectangle a(10,5);

	cout<<a.area()<<endl;
}