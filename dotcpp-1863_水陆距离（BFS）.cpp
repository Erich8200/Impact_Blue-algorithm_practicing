#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#define N 100

using namespace std;

class Node
{
public:
	int row;
	int col;
	int dist;
	Node(int r, int c, int dist);
};

Node::Node(int r, int c, int dist) : row(r), col(c), dist(dist) { }

char map[N + 2][N + 2];
int dists[N + 2][N + 2];

int rowDir[] = { -1,0,1,0 };
int colDir[] = { 0,1,0,-1 };

int BFSGetDist(int row, int col, int n, int m)
{
	Node root(row, col, 0);
	queue<Node> Q;
	Q.push(root);
	while (!Q.empty())
	{
		Node node = Q.front();
		Q.pop();
		int curRow = node.row;
		int curCol = node.col;
		int curDist = node.dist;
		//找到水源，直接返回
		if (map[curRow][curCol] == '0')
			return curDist;
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int newRow = curRow + rowDir[i];
				int newCol = curCol + colDir[i];
				if (newRow >= 1 && newRow <= n && newCol >= 1 && newCol <= m)
				{
					int newDist = curDist + 1;
					Node newNode(newRow, newCol, newDist);
					Q.push(newNode);
				}			
			}
		}
	}
}

void getDists(int n, int m)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (map[i][j] == '1')
				dists[i][j] = BFSGetDist(i, j, n, m);

}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char temp;
			cin >> temp;
			map[i][j] = temp;
		}
		getchar();
	}

	getDists(n, m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << dists[i][j] << " ";
		cout << endl;
	}

	system("pause");

	return 0;
}