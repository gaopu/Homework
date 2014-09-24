#include <iostream>

using namespace std;

int max(int x, int y);

int main() 
{
	int a, b, c; 
	
	cin>>a>>b; 
	c=max(a ,b); 
	cout<<"max= "<<c<<'\n';
	
	return 0;
} 
int max(int x, int y)
{ 
	int z;
	
	if(x>y)
		z=x;
	else
		z=y; 

	return (z); 
} 