//实验PPT上的版本
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int PeopleNum = 0,i = 0,m = 0 ,start_key = 0;  //m是步长
    list<int>LinkHead;  //双向链表
	vector<int>Key;		//密码

    cout<<"请输入有多少个人：";
    cin>>PeopleNum;
    
    //编号
    for(i = 0;i < PeopleNum;i++)
    {
        LinkHead.push_back(i + 1);
    }

    cout<<"请输入初始密码：";
    cin>>start_key;
    m = start_key;

	int tmp = 0;
	cout<<"请依次输入密码：";
	for (i = 0;i < PeopleNum;i++)
	{
		cin>>tmp;
		Key.push_back(tmp);
	}

    i = 0;  //用i计数
    list<int>::iterator it = LinkHead.begin();   //迭代器指向第一个链表元素
    while (!LinkHead.empty()) {
        i++;
        //到最后会指向尾部的下一个位置
        if (it == LinkHead.end()) {
            it++;
        }

        if (i == m) {
            m = Key[*it - 1];   //下一次的密码
            cout<<*it<<"->";
            it = LinkHead.erase(it);
            i = 0;
        }   else {
            it++;
        }
    }
    cout<<"\b\b  \n";
    
    return 0;
}
