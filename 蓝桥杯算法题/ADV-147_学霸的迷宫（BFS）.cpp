#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <math.h>
#define N 500

int maze[N + 2][N + 2];
int rowDir[] = { 1,0,0,-1 };
int colDir[] = { 0,-1,1,0 };
//char dirName[] = { 'U','R','D','L' };
//因为只输出字典序最小的，顺序做如下调整
char dirName[] = { 'D','L','R','U' };
bool vis[N + 2][N + 2];//迷宫类题切记不要忘掉

using namespace std;

class Node
{
public:
	int row;
	int col;
	int pathLen;
	string path;
	Node(int row, int col, int pathLen, string path);
};

Node::Node(int row, int col, int pathLen, string path) :row(row), col(col), pathLen(pathLen), path(path) {}

void BFS(int n, int m)
{
	queue<Node> Q;
	string path;
	Node root(1, 1, 0, path);
	Q.push(root);
	vis[1][1] = true;

	while (!Q.empty())
	{
		Node node = Q.front();
		Q.pop();

		//当前结点就是终点
		if (node.row == n && node.col == m)
		{
			cout << node.pathLen << "\n" << node.path << endl;
			break;
		}

		int curRow = node.row;
		int curCol = node.col;
		int len = node.pathLen;
		string path = node.path;
		int newRow = 0, newCol = 0;
		for (int i = 0; i < 4; i++)
		{
			newRow = curRow + rowDir[i];
			newCol = curCol + colDir[i];
			if (newRow >= 1 && newRow <= n && newCol >= 1 && newCol <= m && maze[newRow][newCol] == 0 && !vis[newRow][newCol])
			{
				string newPath = path + dirName[i];
				Node newNode(newRow, newCol, len + 1, newPath);
				Q.push(newNode);
				vis[newRow][newCol] = true;
			}
		}
	}
	return;
}

int main()
{
	int n = 0, m = 0;
	char temp = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> temp;
			maze[i][j] = temp - '0';
		}
		getchar();
	}

	BFS(n, m);
	return 0;
}