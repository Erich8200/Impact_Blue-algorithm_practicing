#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#define M 200
#define N 200

using namespace std;

int dirRow[] = { 1,0,-1,0 };
int dirCol[] = { 0,1,0,-1 };
int map[M + 2][N + 2];
bool vis[M + 2][N + 2];

void f(int curRow, int curCol, const int m, const int n, int i)
{
    cout << map[curRow][curCol] << " ";
    vis[curRow][curCol] = true;

    //如果进入了死胡同，则结束递归
    bool shouldRet = true;
    for (int i = 0; i < sizeof(dirRow) / sizeof(int); i++)
    {
        if (!vis[curRow + dirRow[i]][curCol + dirCol[i]])
        {
            shouldRet = false;
            break;
        }
    }
    if (shouldRet) return;

    //试探性地继续向既定方向前进
    int newRow = curRow + dirRow[i % 4], newCol = curCol + dirCol[i % 4];
    //若当前方向上无数可取或已经取过
    if (vis[newRow][newCol] || newRow < 1 || newRow > m || newCol < 1 || newCol > n)
    {
        //转向
        i += 1;
        //模4即可实现循环转向
        newRow = curRow + dirRow[i % 4];
        newCol = curCol + dirCol[i % 4];
    }
    f(newRow, newCol, m, n, i);
}

//把vis数组周围一圈全部围起来，否则会出现输出超限
void surroundVis(int m, int n)
{
    for(int i = 0;i <= m + 1;i++)
        vis[i][0] = vis[i][n+1] = true;
    for(int i = 0;i <= n + 1;i++)
        vis[0][i] = vis[m+1][i] = true;
}

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];
    surroundVis(m, n);;
    f(1, 1, m, n, 0);
    cout << endl;
    return 0;
}
