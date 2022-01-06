#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define N 15

using namespace std;

char Map[N + 2][N + 2];
bool vis[N + 2][N + 2];
int maxLen;
int dirRow[4] = { -1,0,1,0 };
int dirCol[4] = { 0,1,0,-1 };
int r, c;

vector<string> pathArr;

void clearAll()
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			Map[i][j] = vis[i][j] = 0;
}

void clearVis()
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			vis[i][j] = 0;
}

void DFS(int curRow, int curCol, string& path)
{
	for (int i = 0; i < 4; i++)
	{
		int newRow = curRow + dirRow[i];
		int newCol = curCol + dirCol[i];
		if (newRow >= 0 && newRow < r && newCol >= 0 && newCol <c && Map[newRow][newCol] != '#' && !vis[newRow][newCol])
		{
			vis[newRow][newCol] = true;
			path.push_back(Map[newRow][newCol]);
			DFS(newRow, newCol, path);
			path.pop_back();
			vis[newRow][newCol] = false;//不恢复答案会错
		}
	}
	//都不能走了，记录结果，返回上级递归
	int pathLen = path.size();
	//筛选出最长的路径，会稍微降低一点内存开销
	if (pathLen >= maxLen)
	{
		maxLen = pathLen;
		pathArr.push_back(path);
	}
	return;
}
	

void TraverseDFS()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (Map[i][j] != '#')
			{
				clearVis();
				string path;
				DFS(i, j, path);
			}
		}
	}
}

string getAns()
{
	string ans = *pathArr.begin();
	for (vector<string>::iterator it = pathArr.begin(); it < pathArr.end(); it++)
	{
		if (it->length() < maxLen)
			continue;
		if (*it > ans)
			ans = *it;
	}
	return ans;
}

int main(int argc, char** argv)
{
	r = 0, c = 0;
	freopen("input0.txt", "r", stdin);
	while (cin >> r >> c)
	{
		if (r == 0 && c == 0)
			break;

		//录入地图
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
				cin >> Map[i][j];
			getchar();
		}

		TraverseDFS();
		cout << getAns() << endl;
		clearAll();
	}
	fclose(stdin);
	system("pause");
	return 0;
}