#include <iostream>

using namespace std;


void f(int a[],int n,int & max,int & min)
{
	max = min = a[0];
	for (int i = 0;i < n;i++)
	{
		if(max < a[i])
			max = a[i];
		if(min > a[i])
			min = a[i];
	}
}
int main( )
{ 
	int a[10] = {2,5,3,9,0,8,1,7,6,4};
	int max,min;

	f(a,10,max,min);
	cout<<"max:"<<max<<endl;
	cout<<"min:"<<min<<endl;

	return 0;
}