#include <iostream>

using namespace std;

int main( )
{ 
	char *name = new char[100];

	cout<<"���������������";
	cin>>name;
	cout<<"��������ǣ�"<<name<<endl;
	delete name;

	return 0;
}