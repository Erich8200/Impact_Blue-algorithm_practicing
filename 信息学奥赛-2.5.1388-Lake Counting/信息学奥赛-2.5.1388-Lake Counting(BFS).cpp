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

bool vis[N + 2][N + 2];
char Map[N + 2][N + 2];
int dirRow[] = {-1,-1,0,1,1,1,0,-1};
int dirCol[] = {0,1,1,1,0,-1,-1,-1};

void BFS(const int startRow, const int startCol, const int m, const int n)
{
	queue< pair<int, int> > q;
	pair<int, int> root(startRow, startCol);
	q.push(root);
	while (!q.empty())
	{
		pair<int, int> node = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int newRow = node.first + dirRow[i], newCol = node.second + dirCol[i];
			if (newRow >= 0 && newRow <= m - 1 && newCol >= 0 && newCol <= n - 1 && Map[newRow][newCol] == 'W' && !vis[newRow][newCol])
			{
				vis[newRow][newCol] = true;
				pair<int, int> temp(newRow, newCol);
				q.push(temp);
			}
		}
	}
}

int getLakeNum(const int m, const int n)
{
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!vis[i][j] && Map[i][j] == 'W')
			{
				BFS(i, j, m, n);
				vis[i][j] = true;
				count += 1;
			}	
		}
	}
	return count;
}

int main(int argc, char** argv)
{
	freopen("test.txt", "r", stdin);
	int m, n;
	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> Map[i][j];
		}
		getchar();
	}

	cout << getLakeNum(m, n) << endl;

	system("pause");
	fclose(stdin);
	
	return 0;
}
