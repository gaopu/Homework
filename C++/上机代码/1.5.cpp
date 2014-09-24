#include <iostream>

using namespace std;

int main( )
{ 
	int a, b, c; 

	cin>>a>>b; 
	if(b==0) 
		return -1;
	c= a/b; 
	cout<<"c= "<<c<<'\n';
	
	 return 0;
}