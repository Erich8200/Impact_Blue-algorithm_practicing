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

bool vis[N+2][N+2];
char Map[N+2][N+2];
int dirRow[] = {-1,-1,0,1,1,1,0,-1};
int dirCol[] = {0,1,1,1,0,-1,-1,-1};

void DFS(int curRow, int curCol, const int m, const int n)
{
	vis[curRow][curCol] = true;

	for (int i = 0; i < 8; i++)
	{
		int newRow = curRow + dirRow[i];
		int newCol = curCol + dirCol[i];
		if (newRow >= 0 && newRow <= m - 1 && newCol >= 0 && newCol <= n - 1 && !vis[newRow][newCol] && Map[newRow][newCol] == 'W')
		{
			vis[newRow][newCol] = true;
			DFS(newRow, newCol, m, n);
			//vis[newRow][newCol] = false;
		}
	}
}

int getLakeNum(int m, int n)
{
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!vis[i][j] && Map[i][j] == 'W')
			{
				vis[i][j] = true;
				DFS(i, j, m, n);
				count += 1;
			}
		}
	}
	return count;
}

int main(int argc, char** argv)
{
	int m, n;
	
	freopen("test.txt", "r", stdin);

	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> Map[i][j];
		}
		getchar();
	}

	int ans = getLakeNum(m, n);

	cout << ans << endl;

	system("pause");
	fclose(stdin);

	return 0;
}
