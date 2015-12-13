/**
*   最短编辑距离
**/
#include <iostream>
#include <string>
 
using namespace std;
 
int array[1000][1000];
 
inline int Max(int a,int b)
{
    return a>b?a:b;
}
 
inline int Min(int a,int b)
{
    return a<b?a:b;
}
 
void edit(string s1,string s2)
{
    int i,j;
    //给矩阵的第一行和第一列赋值
    for (i = 0; i <= Max(s1.length(),s2.length()); i++) {
        array[i][0] = i;
        array[0][i] = i;
    }
 
    for (i=1; i <= s1.length(); i++) {
        for (j=1; j <= s2.length(); j++) {
            //如果两个字符相等,取左上的数
            if (s1[i-1] == s2[j-1]) {
				array[i][j] = array[i - 1][j - 1];
            } else {//不相等,取左边，上边，左上最小值加1
				array[i][j] = Min(Min(array[i - 1][j - 1],array[i - 1][j]),array[i][j - 1]) + 1;
            }
        }
    }
    cout<<array[s1.length()][s2.length()]<<endl;
}
 
int main()
{
    string s1,s2;
 
	while (true) {
		cout<<"请输入第一个字符串:";
		cin>>s1;
		cout<<"请输入第二个字符串:";
		cin>>s2;
 
		edit(s1,s2);
	}
 
    return 0;
}