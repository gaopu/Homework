//最后一行打印树中间三个空格，如果代码不对，改成三个空格
#include <iostream>
#include <cmath>

using namespace std;

typedef char ElemType;//作为树内数据类型
const ElemType NullValue = '#';
typedef struct BiTreeNode
{
    ElemType data;
    BiTreeNode *lchild,*rchild;
}BiTree;

int height = 0;//存储树的高度
const int size = 1024;
char str[size];//存储行序的结果,0号位不用
int stri = 1;

void CreatTree(BiTree ** root,int level,int i);//i是在结果字符串中的索引值
void paintTree();

int main()
{
    BiTree *t;

    //初始化行序遍历树的结果字符串
    for (int i = 0;i < size - 1;i++) {
        str[i] = '#';
    }

    CreatTree(&t,1,1);
    str[(int)pow(2,height)] = 0;

    paintTree();

    return 0;
}

void CreatTree(BiTree ** root,int level,int i)
{
    ElemType data;

    cin>>data;
    if (data == NullValue) {
        *root = NULL;
    } else {
        *root = new BiTree;
        (*root)->data = data;
        str[i] = (*root)->data;//给结果字符串赋值

        if (level > height) {
            height = level;
        }

        CreatTree(&(*root)->lchild,level + 1,2 * i);
        CreatTree(&(*root)->rchild,level + 1,2 * i + 1);
    }
}

void paintTree()
{
    cout<<"height："<<height<<endl;
    //最后一行放到外面输出，放到里面最后一行最前面多一个空格
    for (int i = height;i > 1;i--) {
        int starti = stri;//这个是本行打印时第一个元素在str中存储的下标（输出左右斜杠时根据是否有孩子，来判断是否该输出斜杠）
        //输出空格到达一号位置
        for (int space = 1;space < ((int)pow(2,i) - 1) - ((int)pow(2,i - 1) - 2);space++) {
            cout<<" ";
        }

        //输出一行的元素
        //循环次数是“要输出的这一层树的元素个数”
        for (int j = 1;j <= (int)pow(2,(height - i));j++) {
            //按是否有孩子输出空格或者下划线
            if (str[2 * stri] == '#') {
                for (int _line = 1;_line <= (int)pow(2,i - 1) - 2;_line++)
                    cout<<" ";
            } else {
                for (int _line = 1;_line <= (int)pow(2,i - 1) - 2;_line++)
                    cout<<"_";
            }

            //输出中间元素
            if (str[stri] != '#') {
                cout<<str[stri];
            } else {
                cout<<" ";
            }

            //按是否有孩子输出空格或者下划线
            if (str[2 * stri + 1] == '#') {
                for (int _line = 1;_line <= (int)pow(2,i - 1) - 2;_line++)
                    cout<<" ";
            } else {
                for (int _line = 1;_line <= (int)pow(2,i - 1) - 2;_line++)
                    cout<<"_";
            }

            //不是最后一个元素的话，应该输出元素之间隔空格，这个循环输出应该输出的那么多空格（元素间隔 - 2 × 下划线个数）
            for (int space = 1;j != (int)pow(2,(height - i)) && (space < (int)pow(2,i + 1) - 2 * ((int)pow(2,i - 1) - 2));space ++) {
                cout<<" ";
            }

            stri++;
        }
        cout<<endl;

        //下面输出左右斜杠
        //到达第一个左斜杠位置
        for (int space = 1;space < (int)pow(2,i - 1);space++) {
            cout<<" ";
        }

        //这个控制输出几对左右斜杠
        for (int j = 1;j <= (int)pow(2,height - i);j++) {
            //没有左孩子那么就输出空格否则输出左斜杠
            if (str[2 * starti] == '#') {
                cout<<" ";
            } else {
                cout<<"/";
            }

            //输出兄弟间的空格
            for (int space = 1;space <= (int)pow(2,i) - 3;space++) {
                cout<<" ";
            }

            //没有右孩子那么就输出空格否则输出右斜杠
            if (str[2 * starti + 1] == '#') {
                cout<<" ";
            } else {
                cout<<"\\";
            }

            //如果不是最后一对输出完了，那么就还要再输出一段空格，以便继续后面的元素输出
            for (int space = 1;(j != (int)pow(2,height - i)) && (space <= (int)pow(2,i) + 1);space++) {
                cout<<" ";
            }
            starti++;
        }
        cout<<endl;
    }

    //输出最后一行
    for (int i = 1;i <= (int) pow(2, height - 1);i++) {
        if (str[stri] != '#') {
            cout<<str[stri];
        } else {
            cout<<" ";
        }
        stri++;
        cout<<"   ";//最后一行是固定的每个元素之间三个空格
    }
}
