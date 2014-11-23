#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int MAXVEX = 20;
const int MAXNUM = 2147483647;
const int space = 3;

class AdjMatrix
{
private:
    int arcs[MAXVEX][MAXVEX];
    char vex[MAXVEX];
    int vexnum;
    int arcnum;
    int lowcost[MAXVEX];//这就是prim算法中的那个数组
    int wholink[MAXVEX];//这个存储谁到上面那个数组对应的元素
public:
    AdjMatrix(int v,int a);//参数是点个数，边个数
    void Input();
    void prim(int v);
    friend ostream & operator<<(ostream & os, const AdjMatrix & t);
};

AdjMatrix::AdjMatrix(int v,int a) {
    vexnum = v;
    arcnum = a;
    for (int i = 0;i < vexnum;i++) {
        for (int j = 0;j < vexnum;j++) {
            arcs[i][j] = MAXNUM;
        }
    }
}

void AdjMatrix::Input() {
    int i;
    char cha,chb;

    cout<<"请输入节点名称：";
    for (i = 0;i < vexnum;i++) {
        cin>>vex[i];
    }
    for (i = 0;i < arcnum;i++) {
        cout<<"请输入第"<<i + 1<<"个关系以及权值（eg:AB 10）：";
        cin>>cha>>chb;


        int j,k;
        for (j = 0;j < arcnum && vex[j] != cha;j++);
        for (k = 0;k < arcnum && vex[k] != chb;k++);
        cin>>arcs[j][k];
        arcs[k][j] = arcs[j][k];//无向图有这一句
    }
}

void AdjMatrix::prim(int v) {
    if (v >= vexnum) {
        cout<<"起始点越界.";
        exit(0);
    }

    int i;
    for (i = 0;i < vexnum;i++) {
        lowcost[i] = MAXNUM;
    }
    //下面三行初始化第一个选择的节点
    lowcost[v] = 0;
    int last = v;//上次选择的是谁，下轮其他的和这个比较

    int j;
    //控制次数，节点数减一次
    for (i = 1;i <= vexnum - 1;i++) {
        for (j = 0;j < vexnum;j++) {
            //这个点到已选节点集合的距离不是0，代表没被选择过，
            //并且最新的点到这个点的距离更小就改变数组的值
            if (lowcost[j] && arcs[last][j] < lowcost[j]) {
                lowcost[j] = arcs[last][j];
                wholink[j] = last;
            }
        }

        //使last等于第一个不是0的值
        for (j = 0;j < vexnum && !lowcost[j];j++);
        last = j;

        //找出到已选集合路径最短的点
        for (j = last + 1;j < vexnum;j++) {
            if (lowcost[j] && lowcost[last] > lowcost[j]) {
                last = j;
            }
        }
        cout<<"("<<vex[wholink[last]]<<","<<vex[last]<<") ";
        lowcost[last] = 0;
    }
}

ostream & operator<<(ostream & os, const AdjMatrix & t) {
    int i,j;

    os<<right;
    os<< setw(space)<<" ";//输出三个空格
    for (i = 0;i < t.vexnum;i++) {
        os<<right;
        os<<setw(space)<<t.vex[i];
    }
    os<<endl;

    for (i = 0;i < t.vexnum;i++) {
        os<<left;
        os<< setw(space)<<t.vex[i];
        for (j = 0;j < t.vexnum;j++) {
            os<<right;
            os<< setw(space);
            if (t.arcs[i][j] == MAXNUM) {
                os<<"@";
            } else {
                os<<t.arcs[i][j];
            }
        }
        os<<endl;
    }
    return os;
}


int main()
{
    int vexnum,arcnum;

    cout<<"请输入点的个数和边的个数：";
    cin>>vexnum>>arcnum;

    AdjMatrix t(vexnum,arcnum);

    t.Input();
    cout<<endl;
    cout<<t<<endl;

    cout<<"从哪个点开始寻找最小生成树？请输入(序号从0开始)：";
    int start;
    cin>>start;
    t.prim(start);
    cout<<endl;

    return 0;
}

//AB 5 AC 6 BD 3 CD 6 CE 3 DE 3 DF 4 EF 1 DG 4 EH 4 FI 5 GJ 4 HI 2 IJ 2
