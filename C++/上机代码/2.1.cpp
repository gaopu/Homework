#include <iostream>

const int model = 90; // model is a const 
const int v[]={1,2,3,4}; // v[i] is a const 
const int x = 0; // error: no initializer 

void f() 
{ 
	//model =200; // error 
	//v[2]++; // error 
} 

int main()
{
	f();

	return 0;
}