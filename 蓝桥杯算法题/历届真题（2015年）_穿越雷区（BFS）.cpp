#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <queue>
#define N 100

using namespace std;

bool Map[N + 2][N + 2];
bool vis[N + 2][N + 2];

int dirRow[] = { -1, 0, 1, 0 };
int dirCol[] = { 0, 1, 0, -1 };

typedef struct {
	bool curPower;
	int curRow;
	int curCol;
	int step;
} Node;

int BFS(int aRow, int aCol, int bRow, int bCol, const int n)
{
	int ans = 0;
	bool firstTime = true;
	queue<Node> Q;
	Node root;
	root.curRow = aRow;
	root.curCol = aCol;
	root.step = 0;
	root.curPower = false;
	Q.push(root);

	while (!Q.empty())
	{
		Node curNode = Q.front();
		Q.pop();

		vis[curNode.curRow][curNode.curCol] = true;

		if (curNode.curRow == bRow && curNode.curCol == bCol)
		{
			ans = curNode.step;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int newRow = curNode.curRow + dirRow[i], newCol = curNode.curCol + dirCol[i];
			bool newPower = Map[newRow][newCol];
			if ((firstTime || (newRow == bRow && newCol == bCol) || newPower == !curNode.curPower) && newRow < n && newRow >= 0 && newCol < n && newCol >= 0 && !vis[newRow][newCol])
			{
				Node newNode;
				newNode.curRow = newRow;
				newNode.curCol = newCol;
				newNode.step = curNode.step + 1;
				newNode.curPower = newPower;
				Q.push(newNode);
				vis[newRow][newCol] = true;
			}
		}
		if (firstTime)
			firstTime = false;
	}
	return ans;
}

int main(void)
{
	freopen("input0.txt", "r", stdin);

	int n = 0;
	cin >> n;

	int aRow = 0, aCol = 0, bRow = 0, bCol = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char temp;
			cin >> temp;
			if (temp == '+')
				Map[i][j] = true;
			else if (temp == '-')
				Map[i][j] = false;
			else if (temp == 'A')
			{
				aRow = i;
				aCol = j;
			}
			else if (temp == 'B')
			{
				bRow = i;
				bCol = j;
			}
		}
	}

	cout << BFS(aRow, aCol, bRow, bCol, n) << endl;

	fclose(stdin);
	return 0;
}
