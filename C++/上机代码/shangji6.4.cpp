#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 3;

template <class T>
class atype {
    T a[SIZE];
public:
    atype( )
    {
        register int i;
        for(i=0; i<SIZE; i++) a[i] = 0;
    }
    T & operator[](int i);
};

template <class T>
T & atype<T>::operator[](int i)
{
    if(i<0 || i> SIZE-1) {
        cout << "\nIndex value of ";
        cout << i << " is out-of-bounds.\n";
        exit(1);
    }
    return a[i];
}

int main( )
{
    atype<int> ob;
    cout << ob[2];  // 输出 2
    cout << " ";
    ob[2] = 25;  // 下标运算符[]出现在赋值运算符的左边
    cout << ob[2];  // 输出 25
    ob[3] = 44; // 产生运行时错误，下标3超出了数组边界
    return 0;
}
