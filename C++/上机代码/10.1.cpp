#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    int number;
    string name;
    float score;
public:
    Student(int number1 = 0,string name1 = "noname",float score1 = 0)
    {
        number = number1;
        name = name1;
        score = score1;
    }
    void modify(float score1)
    {
        score = score1;
    }
    friend istream & operator>>(istream & is,Student & stu);
    friend ostream & operator<<(ostream & os,Student & stu);
};

istream & operator>>(istream & is,Student & stu)
{
    is>>stu.number>>stu.name>>stu.score;
    return is;
}

ostream & operator<<(ostream & os,Student & stu)
{
    os<<stu.number<<" "<<stu.name<<" "<<stu.score;
    return os;
}

int main()
{
    Student stu1;

    cout<<stu1<<endl;
    cin>>stu1;
    cout<<stu1<<endl;

    return 0;
}
