#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include "main.h"

#define N 20

using namespace std;

char maze[N + 2][N + 2][N + 2];
bool vis[N + 2][N + 2][N + 2];
int dirRow[] = { 1,-1,0,0,0,0 };
int dirCol[] = { 0,0,1,-1,0,0 };
int dirLay[] = { 0,0,0,0,1,-1 };
vector<int> stepCount;

typedef struct pos {
	int x,y,z;
}pos;

void searchEntry(const int m, const int n, const int l, pos& startPos)
{
	for (int i = 0; i < l; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
				if (maze[i][j][k] == 'S')
				{
					startPos.z = i;
					startPos.x = j;
					startPos.y = k;
					return;
				}
}

void searchEnd(const int m, const int n, const int l, pos& endPos)
{
	for (int i = 0; i < l; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
				if (maze[i][j][k] == 'E')
				{
					endPos.z = i;
					endPos.x = j;
					endPos.y = k;
					return;
				}
}

void DFS(int step, int curRow, int curCol, int curLay, const int m, const int n, const int l, const pos& endPos)
{
	static bool firstTime = true;
	if (firstTime)
	{
		firstTime = false;
		vis[curRow][curCol][curLay] = true;
	}

	if (curRow == endPos.x && curCol == endPos.y && curLay == endPos.z)
	{
		//到达递归边界，记录步数
		stepCount.push_back(step);
		return;
	}
	else
	{
		for (int i = 0; i < 6; i++)
		{
			int newRow, newCol, newLay;
			newRow = curRow + dirRow[i];
			newCol = curCol + dirCol[i];
			newLay = curLay + dirLay[i];
			if (!vis[newLay][newRow][newCol] && newRow >= 0 && newRow <= m - 1 && newCol >= 0 && newCol <= n - 1 && newLay >= 0 && newLay <= l - 1 && (maze[newLay][newRow][newCol] == '.' || maze[newLay][newRow][newCol] == 'E'))
			{
				vis[newLay][newRow][newCol] = true;
				DFS(step + 1, newRow, newCol, newLay, m, n, l, endPos);
				vis[newLay][newRow][newCol] = false;
			}
		}
	}
}

int getAns()
{
	if (stepCount.size() == 0)
		return 0;
	else
	{
		vector<int>::iterator it = min_element(stepCount.begin(), stepCount.end());
		return *it;
	}
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
	searchEnd(m, n, l, endPos);

	DFS(0, startPos.x, startPos.y, startPos.z, m, n, l, endPos);

	//从步数记录中获取最小步数
	int ans = getAns();
	if (!ans)
		cout << "Trapped!" << endl;
	else
		cout << "Escaped in " << ans << " minute(s)." << endl;
	
	//fclose(stdin);
	return 0;
}
