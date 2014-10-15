#include <iostream>

using namespace std;

class planet {
protected:
	double distance;
	int revolve;
	// miles from the sun
	// in days
public:
	planet(double d, int r)
	{ 
        distance = d;
	    revolve = r;
	}
};
class earth: public planet{
	double circumference;
	// circumference of orbit
public:
	earth(double d,int r):planet(d,r)
	{
		circumference = 2 * 3.14159 * r;
	}
    void show()
    {
        cout<<"distance:"<<distance<<endl;
        cout<<"revolve:"<<revolve<<endl;
        cout<<"circumference:"<<circumference<<endl;
    }

};
int main( )
{
	earth ob(93000000,365);
	ob.show( );
	return 0;
}

