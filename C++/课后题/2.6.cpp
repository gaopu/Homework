#include <iostream>

using namespace std;

class counter
{
	int value;
public:
	counter(int number){value = number;}
	void increment(){value++;}
	void decrement(){value--;}
	int getvalue(){return value;}
	void print(){std::cout<<value<<endl;}
};

int main( ) 
{ 
	counter a(10);

	a.print();
	a.increment();
	a.increment();
	a.print();
	a.decrement();
	a.print();

	cout<<a.getvalue();

	return 0;
}