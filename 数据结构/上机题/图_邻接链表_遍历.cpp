#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

const int MAXVEX = 20;

class AdjList
{
private:
    struct ArcNode
    {
        int adjvex;
        int weight;
        struct ArcNode *nextarc;
    };
    struct VertexNode
    {
        char vexdata;
        ArcNode *firstarc;
    };
    VertexNode vertex[MAXVEX];
    int vexnum;
    int arcnum;
    bool visited[MAXVEX];
public:
    AdjList(int v,int a);//参数是点个数，边个数
    void Input();
    void DFSTraverse();
    void BFSTraverse();
    void DFS(int v);
    void BFS(int v);
    void InDegree();
    void OutDegree();
    friend ostream & operator<<(ostream & os,const AdjList & t);
};

AdjList::AdjList(int v,int a) {
    vexnum = v;
    arcnum = a;
    for (int i = 0;i <vexnum;i++) {
        vertex[i].firstarc = NULL;
    }
}

void AdjList::Input() {
    cout<<"请输入节点名称：";
    for (int i = 0;i < vexnum;i++) {
        cin>>vertex[i].vexdata;
    }

    char cha,chb;
    for (int i = 0;i <arcnum;i++) {
        cout<<"请输入第"<<i + 1<<"个关系以及权值（eg:AB 10）：";
        cin>>cha>>chb;

        int j,k;
        for (j = 0;j < vexnum && vertex[j].vexdata != cha;j++);
        for (k = 0;k < vexnum && vertex[k].vexdata != chb;k++);
        ArcNode * t = new ArcNode;
        t->adjvex = k;
        cin>>t->weight;

        t->nextarc = vertex[j].firstarc;
        vertex[j].firstarc = t;
    }
}

void AdjList::BFSTraverse() {
    cout<<"广度优先遍历：";
    for (int i = 0;i < vexnum;i++) {
        visited[i] = false;
    }
    int count = 1;
    for (int i = 0;i < vexnum;i++) {
        if (!visited[i]) {
            cout<<"第"<<count++<<"次调用BFS：";
            BFS(i);
        }
    }
    cout<<endl;
}

void AdjList::BFS(int v) {
    cout<<vertex[v].vexdata<<" ";
    visited[v] = true;

    queue<int> q;
    int t;
    q.push(v);
    while (!q.empty()) {
        t = q.front();
        q.pop();
        ArcNode *p = vertex[t].firstarc;
        while (p) {
            if (!visited[p->adjvex]) {
                cout<<vertex[p->adjvex].vexdata<<" ";
                q.push(p->adjvex);
                visited[p->adjvex] = true;
            }
            p = p->nextarc;
        }
    }
}

void AdjList::DFSTraverse() {
    cout<<"深度优先遍历：";
    for (int i = 0;i < vexnum;i++) {
        visited[i] = false;
    }

    int count = 1;
    for (int i = 0;i < vexnum;i++) {
        if (!visited[i]) {
            cout<<"第"<<count++<<"次调用DFS：";
            DFS(i);
        }
    }
    cout<<endl;
}

void AdjList::DFS(int v) {
    cout<<vertex[v].vexdata<<" ";
    visited[v] = true;

    ArcNode *p = vertex[v].firstarc;
    while (p && visited[p->adjvex]) {
        p = p->nextarc;
    }

    //此处得到的p是未经访问的节点或者空姐点
    while (p) {
        DFS(p->adjvex);
        p = p->nextarc;

        while (p && visited[p->adjvex]) {
            p = p->nextarc;
        }
    }
}

ostream & operator<<(ostream & os, const AdjList & t) {
    for (int i = 0;i < t.vexnum;i++) {
        os<<t.vertex[i].vexdata<<"-->";
        AdjList::ArcNode *p = t.vertex[i].firstarc;
        if (!p) {
            cout<<"^";
        }
        while (p) {
            cout<<p->adjvex<<","<<p->weight;
            if (p->nextarc) {
                cout<<"-->";
            } else {
                cout<<"-->^";
            }
            p = p->nextarc;
        }
        cout<<endl;
    }

    return os;
}

void AdjList::InDegree() {
    cout<<"入度：";
    cout<<"暂未实现。";
    cout<<endl;
}

void AdjList::OutDegree() {
    cout<<"出度：";
    for (int i = 0;i < vexnum;i++) {
        int count = 0;
        ArcNode *p = vertex[i].firstarc;
        while (p) {
            count++;
            p = p->nextarc;
        }
        cout<<"("<<vertex[i].vexdata<<","<<count<<") ";
    }
    cout<<endl;
}

int main()
{
    int vexnum,arcnum;

    cout<<"请输入点的个数和边的个数：";
    cin>>vexnum>>arcnum;

    AdjList t(vexnum,arcnum);

    t.Input();
    cout<<endl;
    cout<<t;
    t.DFSTraverse();
    t.BFSTraverse();
    t.InDegree();
    t.OutDegree();

    return 0;
}
//测试数据AB 15 AE 9 EC 21 BC 3         5 4
