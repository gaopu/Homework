#include <iostream>
#include <string>
using namespace std;

int main( ) 
{ 
	string * name = new string;
	
	cout<<"Input your name:";
	cin>>*name;
	cout<<"your name is:"<<*name<<endl;
	delete name;

	return 0;
}
