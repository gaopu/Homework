#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef char ElemType;//作为树内数据类型
const ElemType NullValue = '#';
typedef struct BiTreeNode
{
    ElemType data;
	int level;
    BiTreeNode *lchild,*rchild;
}BiTree;

void CreatTree(BiTree ** root,int level);
void FirstPrint(BiTree * root);
void MidPrint(BiTree * root);
void LastPrint(BiTree * root);
void CengPrint(BiTree * root);

int main()
{
    BiTree *t;

    CreatTree(&t,1);
    CengPrint(t);
    cout<<endl;
	return 0;
}

void CreatTree(BiTree ** root,int level)
{
    ElemType data;

    cin>>data;
    if (data == NullValue) {
        *root = NULL;
    } else {
        *root = new BiTree;
        (*root)->data = data;
		(*root)->level = level;
        CreatTree(&(*root)->lchild,level + 1);
        CreatTree(&(*root)->rchild,level + 1);
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

void CengPrint(BiTree * root)
{
	queue<BiTree *> q;
	BiTree * t = NULL;
	int prolevel = 0;

	if (root) {
		q.push(root);
	}

	while (!q.empty()) {
		t = q.front();
		if (t->level > prolevel) {
			cout<<endl;
		}
		cout<<t->data<<" ";
		prolevel = t->level;
		q.pop();
		if (t->lchild) {
			q.push(t->lchild);
		}
		if (t->rchild) {
			q.push(t->rchild);
		}
	}
}
