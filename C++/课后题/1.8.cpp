#include <iostream>

using namespace std;

inline int max(int a,int b){return a>b?a:b;}
inline long max(long a,long b){return a>b?a:b;}
inline double max(double a,double b){return a>b?a:b;}

int main( )
{ 
	int a,b;
	double c,d;
	long e,f;

	cout<<"int:";
	cin>>a>>b;
	cout<<"max:"<<max(a,b)<<endl;

	cout<<"double:";
	cin>>c>>d;
	cout<<"max:"<<max(c,d)<<endl;

	cout<<"long:";
	cin>>e>>f;
	cout<<"max:"<<max(e,f)<<endl;

	return 0;
}