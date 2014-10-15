#include <iostream>
#include <cstring>

using namespace std;

class Person
{
public:
	Person(const char* s)
	{ 
        name = new char[strlen(s)+1];
        strcpy(name, s);
        cout<<"父构运行\n";
    }
	~Person()
    {
        delete [] name;
        cout<<"父析运行\n";
    }
protected:
	char * name;
};

class Student : public Person
{
public:
    Student(const char * s):Person(s)
    {cout<<"子构运行\n";};
    ~Student(){cout<<"子析运行\n";};
};

int main()
{
    Student a("abc");
}
