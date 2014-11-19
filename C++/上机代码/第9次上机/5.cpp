#include <iostream>

using namespace std;

class X
{
private:
    int *p;
public:
    X(){p = new int[2];cout<<"X().\n";}
     virtual ~X(){delete [] p;cout<<"~X().\n";}
};

class Y:public X
{
private:
    int *q;
public:
    Y(){q = new int[1023];cout<<"Y():T::q="<<q<<".\n";}
    ~Y(){delete q;cout<<"~Y()\n";}
};

int main()
{
    for (int i = 0;i < 8;i++) {
        X * r = new Y;
        delete r;
    }
    return 0;
}
