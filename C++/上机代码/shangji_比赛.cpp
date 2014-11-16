#include <iostream>
#include <map>
#include<string>
using namespace std;

int main()
{
    map<string,string> m;
    m.insert(pair<string,string>("澳大利亚","西班牙"));
    m.insert(pair<string,string>("荷兰","智利"));
    m.insert(pair<string,string>("喀麦隆","巴西"));
    m.insert(pair<string,string>("克罗地亚","墨西哥"));

    string s;
    cout<<"输入队伍名称:"<<endl;
    cin>>s;

    map<string,string>::iterator p;
    p=m.find(s);
    if(p!=m.end()) {
        cout<<p->second<<endl;
    } else {
        p = m.begin();
        while (p != m.end()) {
            if (s == p->second) {
                cout<<p->first<<endl;
            }
            p++;
        }
    }
    return 0;
}
