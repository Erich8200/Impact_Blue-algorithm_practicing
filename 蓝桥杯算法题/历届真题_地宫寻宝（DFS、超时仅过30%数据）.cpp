#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <stdio.h>
#define N 50

using namespace std;

int map[N + 2][N + 2];
int rowDir[] = { 0,1 };
int colDir[] = { 1,0 };
long long ans;

void DFS(int curRow, int curCol, int curItemCount, const int n, const int m, const int k, int maxValue)
{
	if (curRow == n && curCol == m)
	{
		if (curItemCount == k)
		{
			ans += 1;
		}
		return;
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			int newRow = curRow + rowDir[i];
			int newCol = curCol + colDir[i];
			int newValue = map[newRow][newCol];
			//可以拿起
			if (newRow <= n && newCol <= m)
			{
				if (newValue > maxValue && curItemCount < k)
				{
					DFS(newRow, newCol, curItemCount + 1, n, m, k, newValue);//拿
					DFS(newRow, newCol, curItemCount, n, m, k, maxValue);//不拿
				}
				else
				{
					DFS(newRow, newCol, curItemCount, n, m, k, maxValue);//只能不拿
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];

	DFS(1, 1, 1, n, m, k, map[1][1]);
	DFS(1, 1, 0, n, m, k, -1);

	cout << ans % 1000000007 << endl;

	return 0;
}