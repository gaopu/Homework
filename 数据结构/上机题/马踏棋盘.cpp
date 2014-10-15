//注意，只能windows下运行!

#include <iostream>
#include <windows.h>
 
using namespace std;
const int length = 8;
const int width  = 8;//棋盘的长宽
const int Htry1[] = {-2,-1,1,2,2,1,-1,-2};//x坐标变化
const int Htry2[] = {1,2,2,1,-1,-2,-2,-1};//y坐标变化
int ChessBoard[8][8] = {0};//未走过的地方是0
int WalkNum = 1;
int back = 0;//回溯的次数
 
void HorseWalk(int x,int y);//参数是起始位置
void gotoxy(short x,short y);//移动光标位置
 
int main()
{
    int x = 0,y = 0;
    int i = 0;
 
    cout<<"请输入起始位置"<<"(棋盘尺寸"<<length<<"*"<<width<<")：";
    cin>>x>>y;
 
    for(i = 0;i < length;i++)
    {
        gotoxy(3 * (i + 1),1);
        printf("%3d",i);
    }
    for (i = 0;i < width;i++)
    {
        gotoxy(0,i + 2);
        printf("%3d",i);
    }
 
    HorseWalk(x,y);
 
    return 0 ;
}
 
void HorseWalk(int x,int y)
{
    int i = 0,j = 0;
    int tmp = 0;
    int m = 0,n = 0;//计算下一步八个位置各自的可走路数时代替x,y使用
    int a = 0,b = 0;//计算下一步八个位置各自的可走路数时代替x,y使用
    int RoadNum[8]= {0};//下一步八个位置各自的可走路数
    int NextRoad[8] = {0};//存储下一个位置应该走八个位置中的哪个(上面定义的路的下标)，按照可走路数由少到多排序
    int Road = 0;//单个点的路数
 
    if ((x >= 0 && x <= length - 1) && (y >= 0 && y <= width - 1) && !ChessBoard[x][y]) {
        ChessBoard[x][y] = WalkNum++;
        gotoxy(3 * (y + 1),x + 2);//CMD的x和y和数组中的x，y是相反的，这个3时因为以%3d打印了，1是因为CMD最上面有1行提示语句
        printf("%3d",ChessBoard[x][y]);
        //Sleep(250);
        if (WalkNum == length * width) {
            gotoxy(0,width + 2);//移动到打印出的数组的下面一行，输出press anykey ……
            cout<<"回溯"<<back<<"次\n";
            exit(0);
        }
    } else {
        return ;
    }
 
    //计算下一步八个位置各自的可走路数
    for (i = 0;i < 8;i++) 
    {
        Road = 0;
        m = x + Htry1[i];
        n = y + Htry2[i];
        if ((m >= 0 && m <= length - 1) && (n >= 0 && n <= width - 1) && !ChessBoard[m][n]) {
            for (j = 0;j < 8;j++)
            {
                a = m + Htry1[j];
                b = n + Htry2[j];
                if ((a >= 0 && a <= length - 1) && (b >= 0 && b <= width - 1) && !ChessBoard[a][b]) {
                    Road++;
                }
            }
        }
        RoadNum[i] = Road;
    }
 
    //存储该走的路数xy搭配的数组的下标
    gotoxy(0,width + 2);
    for (j = 0;j < 8;j++)
    {
        NextRoad[j] = j;
    }
 
    for (i = 1;i <= 7;i++)
    {
        for (j = 0;j < 8 - i;j++)
        {
            if (RoadNum[j] > RoadNum[j + 1]) {
                tmp = RoadNum[j + 1];
                RoadNum[j + 1] = RoadNum[j];
                RoadNum[j] = tmp;
 
                tmp = NextRoad[j + 1];
                NextRoad[j + 1] = NextRoad[j];
                NextRoad[j] = tmp;
            }
        }
    }
 
    for (i = 0;i < 8;i++)
    {
        if (RoadNum[i] > 0) {
            break;
        }
    }
 
    for (;i < 8;i++) {
        HorseWalk(x + Htry1[NextRoad[i]],y + Htry2[NextRoad[i]]);
    }
 
    ChessBoard[x][y] = 0;
    WalkNum--;
    gotoxy(3 * (y + 1),x + 2);//移动到当前的位置
    printf("   ");//输出三个空格，消除刚才的字
    back++;
}
 
void gotoxy(short x,short y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
