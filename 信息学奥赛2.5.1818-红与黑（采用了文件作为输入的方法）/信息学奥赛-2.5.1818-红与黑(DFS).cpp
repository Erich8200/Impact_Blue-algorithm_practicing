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

int dirRow[4] = { 1,-1,0,0 };
int dirCol[4] = { 0,0,1,-1 };
bool vis[N + 2][N + 2];
char maze[N + 2][N + 2];
//vector<int> pathLen;

void DFS(int curRow, int curCol, const int m, const int n, int length,int& num)
{
	static bool firstTime = true;
	if (firstTime)
	{
		vis[curRow][curCol] = true;
		firstTime = false;
	}

	for (int i = 0; i < 4; i++)
	{
		int newRow = curRow + dirRow[i], newCol = curCol + dirCol[i];
		if (!vis[newRow][newCol] && maze[newRow][newCol] == '.' && newRow >= 0 && newRow <= m-1 && newCol >= 0 && newCol <= n-1)
		{
			vis[newRow][newCol] = true;
			num += 1;//步数，可以访问不一定去走，和步数是有区别的
			DFS(newRow, newCol, m, n, length + 1, num);
			//vis[newRow][newCol] = false;//这句加上了理论上是没错，但是会路径爆炸
		}
	}

	//pathLen.push_back(length);
	return;
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
	
	//freopen("1.txt", "r", stdin);
	
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

	int num = 1;
	DFS(startRow, startCol, m, n, 0, num);

	//vector<int>::iterator it = max_element(pathLen.begin(), pathLen.end());
	//cout << *it << endl;

	cout << num << endl;

	//fclose(stdin);
	return 0;
}
