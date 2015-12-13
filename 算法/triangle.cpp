/**
*
* 动规三角形问题
*
**/
#include <iostream>
#include <algorithm>
#include <string>
#include <time.h>

using namespace std;

#define Max 100

int triangle[Max][Max];//存储三角形
int height;//存储用户输入的三角形行数

int max(int a,int b) {
	return a>b?a:b;
}

//计算最大的和值
int MaxSum(int height){
    int i, j;
	//从倒数第二行开始往上计算
    for(i = height - 2; i >= 0; i--)
        for(j = 0; j <= i; j++){
            triangle[i][j] = max(triangle[i+1][j],triangle[i+1][j+1]) + triangle[i][j];
        }
    return triangle[0][0];
}

//生成随机三角形
void setTriangle() {
	srand(time(NULL));
	for (int i = 0;i < height;i++) {
		for (int j = 0; j <= i;j++) {
			triangle[i][j] = rand() % 10;
		}
	}
}

int main(int argc, char const *argv[])
{
	int i,j;

    cout<<"要生成几行三角形?\n";
	cin>>height;
	setTriangle();

	//打印三角形
	for (i = 0;i < height;i++) {
		for (j = 0;j <= i;j++) {
			cout<<triangle[i][j]<<" ";
		}
		cout<<endl;
	}

    cout << MaxSum(height) << endl;

    return 0;
}
