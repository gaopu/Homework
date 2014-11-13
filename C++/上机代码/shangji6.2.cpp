#include <iostream>
using namespace std;

class complex
{
private:
    double real;
    double imag;
public:
    complex(double r = 0.0,double i = 0.0)
    {
        real = r;
        imag = i;
    }
    friend complex operator+(complex c1,complex c2)
    {
        complex t;

        t.imag = c1.imag + c2.imag;
        t.real = c1.real + c2.real;

        return t;
    }

    friend complex operator-(complex c1,complex c2)
    {
        complex t;

        t.imag = c1.imag - c2.imag;
        t.real = c1.real - c2.real;

        return t;
    }
    void display(){cout<<"复数是："<<real<<"+"<<imag<<"i\n";}
};

int main()
{
    complex a(1,2),b(3,4),c;

    c = a + b;

    c.display();

    return 0;
}
