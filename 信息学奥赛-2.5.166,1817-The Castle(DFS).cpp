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

#define N 50

using namespace std;

typedef struct square {
	bool wall[4] = { false };
}square;

square Map[N + 2][N + 2];
bool vis[N + 2][N + 2];
int dirRow[] = { -1,0,1,0 };
int dirCol[] = { 0,1,0,-1 };
vector<int> spaceRec;
int romCount, maxRomSpace;

void DFS(int curRow, int curCol, const int m, const int n, int& space)
{
	for (int i = 0; i < 4; i++)
	{
		if (!Map[curRow][curCol].wall[i])
		{
			int newRow = curRow + dirRow[i], newCol = curCol + dirCol[i];
			if (!vis[newRow][newCol] && newRow >= 0 && newRow <= m-1 && newCol >= 0 && newCol <= n-1)
			{
				vis[newRow][newCol] = true;
				space += 1;
				DFS(newRow, newCol, m, n, space);
			}
		}
	}
}

void getRomCount(const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int space = 1;
			if (!vis[i][j])
			{
				vis[i][j] = true;
				DFS(i, j, m, n, space);
				romCount += 1;
				spaceRec.push_back(space);
			}
		}
	}

	maxRomSpace = *(max_element(spaceRec.begin(), spaceRec.end()));

	return;
}

string intToBinStr(int n)
{
	string binStr;
	if (n == 0)
	{
		binStr += '0';
	}
	else
	{
		while (n > 0)
		{
			binStr += ('0' + n % 2);
			n /= 2;
		}
		reverse(binStr.begin(), binStr.end());
	}

	//²¹×ã4Î»£¬4¶ÂÇ½
	if (binStr.length() < 4)
	{
		while (binStr.length() < 4)
		{
			binStr = "0" + binStr;
		}
	}

	return binStr;
}

void fillMap(const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int intWall = 0;
			cin >> intWall;
			string binWall = intToBinStr(intWall);
			square surround;
			for (int dir = 0; dir < 4; dir++)
				surround.wall[dir] = binWall[dir] - '0';
			Map[i][j] = surround;
		}
	}
	return;
}

int main(int argc, char** argv)
{
	int m, n;
	freopen("test.txt", "r", stdin);
	cin >> m >> n;
	fillMap(m, n);

	getRomCount(m, n);

	cout << romCount << "\n" << maxRomSpace << endl;

	system("pause");
	fclose(stdin);
	return 0;
}
