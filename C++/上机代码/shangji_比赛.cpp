#include <iostream>
#include <map>
#include<string>
using namespace std;

int main()
{
    map<string,string> m;
    m.insert(pair<string,string>("�Ĵ�����","������"));
    m.insert(pair<string,string>("����","����"));
    m.insert(pair<string,string>("����¡","����"));
    m.insert(pair<string,string>("���޵���","ī����"));

    string s;
    cout<<"�����������:"<<endl;
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
