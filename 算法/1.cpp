/**
* 最小重量机器设计
* 回溯法
* 厂商id和部件id都从0开始
**/
#include <iostream>
#include <cmath>
 
using namespace std;
 
const int width = 3;
const int height = 3;
//列表示厂商
//行表示部件
//下面这个示例数据:3行3列
//结果是:最少钱数4,最小重量4
int weight[height][width] = {1,2,3,3,2,1,2,2,2};
int money[height][width] = {1,2,3,3,2,1,2,2,2};
 
//部件个数
int componentCount = 3;
//厂商个数
int companyCount = 3;
//最高价格
int maxMoney = 4;
 
//表示当前整个机器的重量
int nowWeight = 0;
//表示当前整个机器的价格
int nowMoney = 0;
//表示每个部件的厂商id
int companyIdOfComponent[height] = {0};
 
//参数表示部件id
void calc(int componentId) {
    //对当前部件遍历每一个厂商
    for (int i = 1;i < companyCount;i++) {
        //如果当前的总钱数已经超过最高限制,那么只要钱数可以降低到最大钱数以内,不论重量多少都算是一种可以考虑的解
        if (nowMoney > maxMoney) {
            if (nowMoney - abs(money[componentId][i] - money[componentId][companyIdOfComponent[componentId]]) <= maxMoney) {
                //更改重量
                nowWeight -= weight[componentId][companyIdOfComponent[componentId]];
                nowWeight += weight[componentId][i];
 
                //更改钱数
                nowMoney -= money[componentId][companyIdOfComponent[componentId]];
                nowMoney += money[componentId][i];
 
                //更改此部件选择的厂商id
                companyIdOfComponent[componentId] = i;
            }
        }
        //当前钱数没有超过最高限制,那么必须要比现在的重量小,并且替换后钱数不超过最大钱数,才替换为现在的这个厂商
        else {
            //重量比当前小
            if (weight[componentId][i] < weight[componentId][companyIdOfComponent[componentId]]) {
                 
                //减去本部件原先花的钱数后其他部件花的钱数
                int lastMoney = nowMoney - money[componentId][companyIdOfComponent[componentId]];
                //更改为当前厂商后花的总钱数
                int nextMoney = lastMoney + money[componentId][i];
 
                //钱数不超过最大钱数
                if (nextMoney < maxMoney) {
                    //更改重量
                    nowWeight -= weight[componentId][companyIdOfComponent[componentId]];
                    nowWeight += weight[componentId][i];
 
                    //更改钱数
                    nowMoney -= money[componentId][companyIdOfComponent[componentId]];
                    nowMoney += money[componentId][i];
 
                    //更改此部件选择的厂商id
                    companyIdOfComponent[componentId] = i;
                }
            }
        }
 
        //如果还有部件没有计算到,继续下去
        if (componentId < componentCount - 1) {
            calc(componentId + 1);
        }
    }
}
 
//使最开始的状态是:每个零件选择0号厂商
void init() {
    for (int i = 0;i < componentCount;i++) {
        companyIdOfComponent[i] = 0;
        nowMoney += money[i][0];
        nowWeight += weight[i][0];
    }
}
 
int main(int argc, char const *argv[]) {
    /*cout<<"请依次输入部件个数,厂商个数,钱数上限:";
    cin>>componentCount>>companyCount>>maxMoney;
 
    cout<<"请依次输入重量信息(横向输入,1行代表1个部件在所有厂商处的重量,下同):";
    for (int i = 0;i < componentCount;i++) {
        for (int j = 0;j < companyCount;j++) {
            cin>>weight[i][j];
        }
    }
    cout<<"请依次输入价格信息(横向输入):";
    for (i = 0;i < componentCount;i++) {
        for (int j = 0;j < companyCount;j++) {
            cin>>money[i][j];
        }
    }*/
 
    //初始化
    init();
    //计算,从0号部件开始
    calc(0);
 
    if (nowMoney > maxMoney) {
        cout<<"没有符合要求的选择."<<endl;
    } else {
        cout<<"部件选择的厂商id依次是:";
        for (int i = 0;i < componentCount;i++) {
            cout<<companyIdOfComponent[i]<<" ";
        }
        cout<<endl;
 
        cout<<"总钱数:"<<nowMoney<<" "<<"总重量:"<<nowWeight<<endl;
    }
 
    return 0;
}
