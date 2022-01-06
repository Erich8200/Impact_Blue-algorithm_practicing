#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <memory.h>
#include "main.h"

#define N 100

using namespace std;

//char maze[N + 2][N + 2] = { {'.','#','#'},{'.','.','#'},{'#','.','.'} };
//char maze[N + 2][N + 2] = { {'.','.','.','.','.'},{ '#','#','#','.','#' },{ '.','.','#','.','.' },{ '#','#','#','.','.' },{ '.','.','.','#','.' } };
char maze[N + 2][N + 2];
bool vis[N + 2][N + 2] = { false };
bool able;

void initMaze()
{
	for (int i = 0; i < N+2; i++)
		for (int j = 0; j < N+2; j++)
			maze[i][j] = '#';
}

void DFS(int curRow, int curCol, const int terRow, const int terCol, const int n)
{
	static bool firstTime = true;

	if (firstTime)
	{
		//入口或出口被封死
		if (maze[curRow][curCol] == '#' || maze[terRow][terCol] == '#')
		{
			return;
		}
		maze[curRow][curCol] = true;
		firstTime = false;
	}

	if (curCol == terCol && curRow == terRow)
	{
		able = true;
		return;
	}
	else
	{
		if (curRow - 1 >= 0 && maze[curRow - 1][curCol] == '.' && !vis[curRow - 1][curCol])
		{
			vis[curRow - 1][curCol] = true;
			DFS(curRow - 1, curCol, terRow, terCol, n);
			vis[curRow - 1][curCol] = false;
		}

		if (curRow + 1 < n && maze[curRow + 1][curCol] == '.' && !vis[curRow + 1][curCol])
		{
			vis[curRow + 1][curCol] = true;
			DFS(curRow + 1, curCol, terRow, terCol, n);
			vis[curRow + 1][curCol] = false;
		}

		if (curCol - 1 >= 0 && maze[curRow][curCol - 1] == '.' && !vis[curRow][curCol - 1])
		{
			vis[curRow][curCol - 1] = true;
			DFS(curRow, curCol - 1, terRow, terCol, n);
			vis[curRow][curCol - 1] = false;
		}

		if (curCol + 1 < n && maze[curRow][curCol + 1] == '.' && !vis[curRow][curCol + 1])
		{
			vis[curRow][curCol + 1] = true;
			DFS(curRow, curCol + 1, terRow, terCol, n);
			vis[curRow][curCol + 1] = false;
		}

		return;
	}

}

int main(int argc, char** argv)
{
	int k = 0;
	cin >> k;

	while (k--)
	{
		able = false;
		initMaze();
		int n = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> maze[i][j];
			}
			cin.clear();
			cin.sync();
		}

		int ha = 0, la = 0, hb = 0, lb = 0;
		cin >> ha >> la >> hb >> lb;
		DFS(ha, la, hb, lb, n);
		//DFS(0, 0, 4, 2, 5);
		if (able)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}
