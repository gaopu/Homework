#include <iostream>

using namespace std;

int main()
{
    int arr[10];
    int count;
    try {
        cout<<"你要访问第几个:";
        cin>>count;

        if (count < 0 || count > 9) {
            throw "越界了!!";
        }

        cout<<arr[count]<<endl;
    } catch (char const *msg) {
        cout<<msg;
    }

    return 0;
}
