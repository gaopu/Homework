#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double num;
    try {
        cin>>num;

        if (num < 0) {
            throw "不能为负数!";
        }

        cout<<"结果是"<<sqrt(num)<<endl;
    } catch (char const *msg) {
        cout<<msg;
    }

    return 0;
}
