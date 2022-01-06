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

int dirRow[4] = { 1,-1,0,0 };
int dirCol[4] = { 0,0,1,-1 };
char maze[N + 2][N + 2];
bool vis[N + 2][N + 2];

int BFS(const int startRow, const int startCol, const int m, const int n)
{
	int count = 1;
	queue< pair<int, int> > q;
	pair<int, int> root(startRow, startCol);
	q.push(root);
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int newRow = temp.first + dirRow[i];
			int newCol = temp.second + dirCol[i];
			if (newRow >= 0 && newRow <= m-1 && newCol >= 0 && newCol <= n-1 && maze[newRow][newCol] == '.' && !vis[newRow][newCol])
			{
				pair<int, int> newNode(newRow, newCol);
				q.push(newNode);
				vis[newRow][newCol] = true;
				count += 1;
			}
		}
	}
	return count;
}

void findEntry(int& eRow,int& eCol,const int m,const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maze[i][j] == '@')
			{
				eRow = i;
				eCol = j;
				return;
			}	
		}
	}
}

int main(int argc, char** argv)
{
	int m = 0, n = 0;
	int startRow = 0, startCol = 0;
	
	freopen("1.txt", "r", stdin);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maze[i][j];
		}
		getchar();
	}

	findEntry(startRow, startCol, m, n);

	cout << BFS(startRow, startCol, m, n) << endl;

	fclose(stdin);
	return 0;
}
