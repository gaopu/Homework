//递归实现
#include <iostream>

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
    FirstPrint(t);
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

void FirstPrint(BiTree * root)
{
    if (root) {
        cout<<root->data<<" ";
        FirstPrint(root->lchild);
        FirstPrint(root->rchild);
    }
}

void MidPrint(BiTree * root)
{
    if (root) {
        FirstPrint(root->lchild);
        cout<<root->data<<" ";
        FirstPrint(root->rchild);
    }
}

void LastPrint(BiTree * root)
{
    if (root) {
        FirstPrint(root->lchild);
        FirstPrint(root->rchild);
        cout<<root->data<<" ";
    }
}
