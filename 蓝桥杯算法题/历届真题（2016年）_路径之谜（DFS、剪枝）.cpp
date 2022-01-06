#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#define N 20

using namespace std;

int Map[N+2][N+2];
bool vis[N+2][N+2];
int rowRec[N+2], colRec[N+2], rowRequest[N+2], colRequest[N+2];
int rowDir[] = {0, 1, 0, -1};
int colDir[] = {1, 0, -1, 0};

bool checkRec(const int n)
{
	for (int i = 0; i < n; i++)
		if (rowRec[i] != rowRequest[i] || colRec[i] != colRequest[i])
			return false;
	return true;
}

void DFS(int curRow, int curCol, const int n, vector<int>& path, vector<int>& ans)
{
	if (curRow == curCol && curRow == n-1)
	{
		if (checkRec(n))
			ans = path;
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int newRow = curRow + rowDir[i];
			int newCol = curCol + colDir[i];
			if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && !vis[newRow][newCol])
			{
				if (rowRec[newRow] + 1 <= rowRequest[newRow] && colRec[newCol] + 1 <= colRequest[newCol])
				{
					rowRec[newRow] += 1;
					colRec[newCol] += 1;
					path.push_back(Map[newRow][newCol]);
					vis[newRow][newCol] = true;
					DFS(newRow, newCol, n, path, ans);
					vis[newRow][newCol] = false;
					rowRec[newRow] -= 1;
					colRec[newCol] -= 1;
					path.pop_back();
				}
			}
		}
	}
}

int main(void)
{
	int n = 0;
	cin >> n;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Map[i][j] = num;
			num += 1;
		}
	}
	
	for (int i = 0; i < n; i++)
		cin >> colRequest[i];
		
	for (int i = 0; i < n; i++)
		cin >> rowRequest[i];
		
	vis[0][0] = true;
	vector<int> path, ans;
	path.push_back(0);
	rowRec[0] = colRec[0] = 1;
	DFS(0, 0, n, path, ans);
	
	for (vector<int>::iterator it = ans.begin(); it < ans.end(); it++)
		cout << *it << " ";
	cout << "\n";
	return 0;
}
