#include <iostream>

using std::cout;
using std::endl;

class student
{
    int age;
public:
    student(int a){age = a;}
    int getAge(){return age;}
};

int main(int argc, char *argv[])
{
    student arr[5] = {student(10),student(20),student(30),student(40),student(50)};

    for (int i = 0;i < 5;i++)
    {
        cout<<arr[i].getAge()<<endl;
    }
    for (int i = 0;i < 5;i++)
    {
        cout<<(arr + i)->getAge()<<endl;
    }

    return 0;
}

