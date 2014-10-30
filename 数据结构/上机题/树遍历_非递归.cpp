//非递归实现
#include <iostream>
#include <stack>

using namespace std;

typedef char ElemType;//作为树内数据类型
const ElemType NullValue = '#';
typedef struct BiTreeNode
{
    ElemType data;
    BiTreeNode *lchild,*rchild;
}BiTree;

void CreatTree(BiTree ** root);
void FirstPrint(BiTree * root);
void MidPrint(BiTree * root);
void LastPrint(BiTree * root);

int main()
{
    BiTree *t;

    CreatTree(&t);
    MidPrint(t);
    cout<<endl;
}

void CreatTree(BiTree ** root)
{
    ElemType data;

    cin>>data;
    if (data == NullValue) {
        *root = NULL;
    } else {
        *root = new BiTree;
        (*root)->data = data;
        CreatTree(&(*root)->lchild);
        CreatTree(&(*root)->rchild);
    }
}

void FirstPrint(BiTree * node)
{
    stack<BiTree *> s;

    while (node || !s.empty()) {
        if (node) {
            cout<<node->data<<" ";
            s.push(node);
            node = node->lchild;
        } else {
            node = s.top();
            s.pop();
            node = node->rchild;
        }
    }
}

void MidPrint(BiTree * node)
{
    stack<BiTree *> s;

    while (node || !s.empty()) {
        if (node) {
            s.push(node);
            node = node->lchild;
        } else {
            node = s.top();
            cout<<node->data<<" ";
            s.pop();
            node = node->rchild;
        }
    }
}

void LastPrint(BiTree * root)
{

}
