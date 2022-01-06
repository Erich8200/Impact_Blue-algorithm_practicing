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

#define N 10

using namespace std;

int dirRow[] = { -2,-2,2,2,-1,-1,1,1 };
int dirCol[] = { 1,-1,1,-1,2,-2,2,-2 };
int pathCount;
bool vis[N + 2][N + 2];

bool checkVis(const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!vis[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void DFS(const int curRow, const int curCol, const int m, const int n, int step)
{
	static bool firstTime = true;
	if (firstTime)
	{
		vis[curRow][curCol] = true;
		firstTime = false;
	}

	for (int i = 0; i < 8; i++)
	{
		int newRow = curRow + dirRow[i];
		int newCol = curCol + dirCol[i];
		if (!vis[newRow][newCol] && newRow >= 0 && newRow <= m - 1 && newCol >= 0 && newCol <= n - 1)
		{
			vis[newRow][newCol] = true;
			DFS(newRow, newCol, m, n, step + 1);
			vis[newRow][newCol] = false;//这句好像一定要加，否则答案不对
		}
	}

	if(checkVis(m, n))
		pathCount += 1;
}

int main(int argc, char** argv)
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	DFS(x, y, n, m, 0);
	cout << pathCount << endl;
	system("pause");
	return 0;
}
