#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include "main.h"

#define N 20

using namespace std;

char maze[N + 2][N + 2][N + 2];
int dirRow[] = { 1,-1,0,0,0,0 };
int dirCol[] = { 0,0,1,-1,0,0 };
int dirLay[] = { 0,0,0,0,1,-1 };

typedef struct pos {
	int row, col, lay, step;//修改结构体定义，增加字段阶数，是针对每个结点而言的
}pos;

void searchEntry(const int m, const int n, const int l, pos& startPos)
{
	for (int i = 0; i < l; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
				if (maze[i][j][k] == 'S')
				{
					startPos.lay = i;
					startPos.row = j;
					startPos.col = k;
					startPos.step = 0;
					return;
				}
}

int BFS(pos& startPos, const int m, const int n, const int l)
{
	int step = 0;
	queue<pos> q;
	q.push(startPos);

	while (!q.empty())
	{
		pos node = q.front();
		q.pop();
		int curRow = node.row, curCol = node.col, curLay = node.lay, curStep = node.step;
		if (maze[curLay][curRow][curCol] == 'E')
		{
			return curStep;
		}
		//step += 1;//阶数是针对每个结点而言的，全局性的变量是不能表示阶数的
		for (int i = 0; i < 6; i++)
		{
			int newRow = curRow + dirRow[i], newCol = curCol + dirCol[i], newLay = curLay + dirLay[i], newStep = curStep + 1;//新的下级结点阶数加1
			if (newRow >= 0 && newRow <= m - 1 && newCol >= 0 && newCol <= n - 1 && newLay >= 0 && newLay <= l - 1 && (maze[newLay][newRow][newCol] == '.' || maze[newLay][newRow][newCol] == 'E'))
			{
				pos temp;
				temp.row = newRow;
				temp.col = newCol;
				temp.lay = newLay;
				temp.step = newStep;
				q.push(temp);
			}
		}
	}
	return 0;
}

int main(int argc, char** argv)
{
	int m = 0, n = 0, l = 0;
	//freopen("test.txt", "r", stdin);
	cin >> l >> m >> n;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> maze[i][j][k];
			}
			getchar();
		}
		getchar();
	}

	pos startPos,endPos;
	searchEntry(m, n, l, startPos);

	int ans = BFS(startPos, m, n, l);
	if (ans)
		cout << "Escaped in " << ans << " minute(s)." <<  endl;
	else
		cout << "Trapped!" << endl;

	//fclose(stdin);
	return 0;
}
