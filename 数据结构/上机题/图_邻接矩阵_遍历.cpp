#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

const int MAXVEX = 20;
const int MAXNUM = 2147483647;
const int space = 3;//输出结果的时候每个结果占得空间

class AdjMatrix
{
private:
    int arcs[MAXVEX][MAXVEX];
    char vex[MAXVEX];
    int vexnum;
    int arcnum;
    int visited[MAXVEX];
public:
    AdjMatrix(int v,int a);//参数是点个数，边个数
    void Input();
    void DFSTraverse();
    void BFSTraverse();
    void DFS(int v);
    void BFS(int v);
    friend ostream & operator<<(ostream & os,const AdjMatrix & t);
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
    char cha,chb;

    cout<<"请输入节点名称：";
    for (int i = 0;i < vexnum;i++) {
        cin>>vex[i];
    }
    for (int i = 0;i < arcnum;i++) {
        cout<<"请输入第"<<i + 1<<"个关系以及权值（eg:AB 10）：";
        cin>>cha>>chb;


        int j,k;
        for (j = 0;j < arcnum && vex[j] != cha;j++);
        for (k = 0;k < arcnum && vex[k] != chb;k++);
        cin>>arcs[j][k];
    }
}

void AdjMatrix::BFSTraverse() {
    for (int i = 0;i < vexnum;i++) {
        visited[i] = 0;
    }

    cout<<"广度优先搜索：";
    for (int i = 0;i < vexnum;i++) {
        if (!visited[i]) {
            BFS(i);
        }
    }
    cout<<endl;
}

void AdjMatrix::BFS(int v) {
    queue<int> q;
    int t;

    visited[v] = 1;
    cout<<vex[v]<<" ";
    q.push(v);
    while (!q.empty()) {
        t = q.front();
        q.pop();
        for (int i = 0;i < vexnum;i++) {
            if (arcs[t][i] != MAXNUM && !visited[i]) {
                visited[i] = 1;
                cout<<vex[i]<<" ";
                q.push(i);
            }
        }
    }
}

void AdjMatrix::DFSTraverse() {
    for (int i = 0;i < vexnum;i++) {
        visited[i] = 0;
    }

    cout<<"深度优先搜索：";
    for (int i = 0;i < vexnum;i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    cout<<endl;
}

void AdjMatrix::DFS(int v) {
    cout<<vex[v]<<" ";
    visited[v] = 1;

    int i;
    for (i = 0;i < vexnum && (arcs[v][i] == MAXNUM || visited[i]);i++);

    while (i != vexnum) {
        DFS(i);
        for (i = 0;i < vexnum && (arcs[v][i] == MAXNUM || visited[i]);i++);
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
        os<<right;
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
    cout<<t;
    t.DFSTraverse();
    t.BFSTraverse();

    return 0;
}
