#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string,string> m;

    m.insert(pair<string,string> ("LiHao","18800000000"));
    m.insert(pair<string,string> ("XiaoLi","18800000001"));

    string s;
    cout<<"请输入你的姓名：";
    cin>>s;
    map<string,string>::iterator p = m.find(s);

    if (p != m.end()) {
        cout<<"电话号码是："<<p->second<<endl;
    } else {
        cout<<"没有这个人的电话号码。\n";
    }
    return 0;
}
