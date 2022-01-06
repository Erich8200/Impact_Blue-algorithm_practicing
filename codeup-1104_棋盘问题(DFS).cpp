#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define N 8

bool stored[N + 2];
int ansCount;
char Map[N + 2][N + 2];
bool visCol[N + 2];

using namespace std;

void DFS(int curRow, int curChessCount, const int totalRow, const int totalCol)
{
	if (curRow > totalRow)//只要棋盘行选完
	{
		if (curChessCount <= 0)//且棋子用完
		{
			ansCount += 1;//是符合题目要求的一个解	
		}
		return;//两种情况都需要立刻返回
	}
	else if (curChessCount <= 0)
	{
		ansCount += 1;//是符合题目要求的一个解	
		return;
	}
	else
	{
		//对每行都有两种选择，在该行放置棋子和不放置

		//1.在当前行放置棋子
		for (int i = 1; i <= totalCol; i++)
		{
			if (Map[curRow][i] == '#')
				if (!visCol[i])
				{
					visCol[i] = true;
					DFS(curRow + 1, curChessCount - 1, totalRow, totalCol);
					visCol[i] = false;
				}
		}
		//2.不在当前行放置棋子
		DFS(curRow + 1, curChessCount, totalRow, totalCol);
	}
	return;
}

int main(int argc, char** argv)
{
	int n, chessCount;
	//freopen("test2.txt", "r", stdin);
	cin >> n >> chessCount;
	getchar();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> Map[i][j];
		}
		getchar();
	}

			
	DFS(1, chessCount, n, n);
	cout << ansCount << endl;
	//fclose(stdin);
	system("pause");
	return 0;
}