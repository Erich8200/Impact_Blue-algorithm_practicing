#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <stdio.h>
#include "main.h"

#define N 20

using namespace std;
vector<int> pathLenSet;
bool vis[N + 2][N + 2];
char maze[N + 2][N + 2];
int dirRow[] = { -1,0,1,0 };
int dirCol[] = { 0,1,0,-1 };

void DFS(int curRow, int curCol, const int m, const int n, int pathLen)
{
	if (maze[curRow][curCol] == '*')
	{
		pathLenSet.push_back(pathLen);
		return;
	}
	else
	{
		vis[curRow][curCol] = true;
		for (int i = 0; i < 4; i++)
		{
			int newRow = curRow + dirRow[i];
			int newCol = curCol + dirCol[i];
			if (newRow >= 0 && newRow <= m - 1 && newCol >= 0 && newCol <= n - 1 && (maze[newRow][newCol] == '.' || maze[newRow][newCol] == '*') && !vis[newRow][newCol])
			{
				vis[newRow][newCol] = true;
				DFS(newRow, newCol, m, n, pathLen + 1);
				vis[newRow][newCol] = false;
			}
		}
	}
}

int getAns()
{
	int ans = 0;
	if (pathLenSet.size() == 0)
		return ans;
	ans = *(min_element(pathLenSet.begin(), pathLenSet.end()));
	return ans;
}

void getEntry(int& x, int& y, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maze[i][j] == '@')
			{
				x = i, y = j;
				return;
			}
		}
	}
}

int main(int argc, char** argv)
{
	int m, n;
	//freopen("test.txt", "r", stdin);
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maze[i][j];
		}
	}
	int startRow = 0, startCol = 0;
	getEntry(startRow, startCol, m, n);
	DFS(startRow, startCol, m, n, 0);
	int ans = getAns();
	if (ans)
		cout << ans << endl;
	else
		cout << -1 << endl;
	//fclose(stdin);
	system("pause");
	return 0;
}
