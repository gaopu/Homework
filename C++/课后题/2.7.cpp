#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class my_string
{
	char * contents;
	int length;
public:
	my_string(const char str[]);
	void Print(){std::cout<<contents;}
	int GetLen(){return length;}
	void Cat(const char str[]);
};

void my_string::Cat(const char str[])
{
	char * tmp = contents;

	contents = new char[length + strlen(str) + 1];
	strcpy(contents,tmp);
	strcat(contents,str);
	length += strlen(str);

	delete tmp;
}

my_string::my_string(const char str[])
{
	length = strlen(str);
	contents = new char[length + 1];
	strcpy(contents,str);
}

int main( ) 
{ 
	my_string a("asd");

	a.Print();
	cout<<endl;
	a.Cat("6767");
	a.Print();
	cout<<endl;

	return 0;
}