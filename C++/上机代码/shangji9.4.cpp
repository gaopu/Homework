#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<float> q;

    q.push(1.23);
    cout <<q.front()<<endl;
    q.pop();

    if (q.empty()) {
        cout<<"队列空了。\n";
    } else {
        cout<<"队列非空。\n";
    }
    return 0;
}
