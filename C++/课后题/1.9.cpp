#include <iostream>

using namespace std;

int main( )
{ 
	char *name = new char[100];

	cout<<"请输入你的姓名：";
	cin>>name;
	cout<<"你的姓名是："<<name<<endl;
	delete name;

	return 0;
}