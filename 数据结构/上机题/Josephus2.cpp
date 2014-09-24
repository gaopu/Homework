//书上的版本
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int PeopleNum = 0,i = 0;
    list<int>LinkHead;  //双向链表
	vector<int>Key;		//K个数

    cout<<"请输入有多少个人：";
    cin>>PeopleNum;
    
    //编号
    for(i = 0;i < PeopleNum;i++)
    {
        LinkHead.push_back(i + 1);
    }

	//输入K个数
	int tmp = 0;
	int k = 0;
	cout<<"K是几？请输入：";
	cin>>k;

	cout<<"请输入这几个数字：";
	for (i = 0;i < k;i++)
	{
		cin>>tmp;
		Key.push_back(tmp);
	}

    i = 0;  //用i计数
    list<int>::iterator it = LinkHead.begin();   //迭代器指向第一个链表元素
	bool mIsNotOk = false;
	int remaining = PeopleNum;  //圈中剩余人数
    int t = 0;  //用于最后的k个数与数组中的元素一一对应

	//循环的实验每个m
	for (int m = 1;m <= PeopleNum;m++)
	{
		mIsNotOk = false;
		remaining = PeopleNum;
		i = 0;
		it = LinkHead.begin();
        t = 0;

		while (!LinkHead.empty()) {
			i++;
			//到最后会指向尾部的下一个位置
			if (it == LinkHead.end()) {
				it++;
			}

			if (i == m) {
				for (int j = 0;(remaining > k) && (j < k);j++)
				{
					//如果提前出圈的是指定数字中的某一个，m就是不符合要求的
					if (*it == Key[j]) {
						mIsNotOk = true;
                        break;
					}
				}

                //判断剩下的k个数是否与指定次序相同
                if ((remaining <= k) && (*it != Key[t++])) {
                    mIsNotOk = true;
                }

				it = LinkHead.erase(it);
				i = 0;
                remaining--;
			}   else {
				it++;
			}

			if (mIsNotOk) {
				break;
			}
		}
		if (!mIsNotOk) {
			cout<<m<<"可以\n";
		}
		LinkHead.clear();
		//编号
		for(i = 0;i < PeopleNum;i++)
		{
			LinkHead.push_back(i + 1);
		}
	}
    
    return 0;
}
