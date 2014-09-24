#include <iostream>
using namespace std;

double max(double a,double b);
int max(int a,int b);
long max(long a,long b);

int main( ) 
{ 
	int a = 10,b = 100;
	double c = 5,d = 7;
	long e = 8,f = 2;
	
	cout<<"max("<<a<<","<<b<<")="<<max(a,b)<<endl;
	cout<<"max("<<c<<","<<d<<")="<<max(c,d)<<endl;
	cout<<"max("<<e<<","<<f<<")="<<max(e,f)<<endl;

	return 0;
}

double max(double a,double b)
{ 
	return a>b?a:b;
}

int max(int a,int b)
{
	return a>b?a:b;
}

long max(long a,long b)
{
	return a>b?a:b;
}