#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdio.h>
#define N 102

using namespace std;

int Map[N][N];
enum Dir {	U = 0, R = 1, D = 2, L = 3};

class Ant
{
public:
	Dir dir;
	int row, col;
	Ant(int startRow, int startCol, Dir d);
	void moveOnBlack();
	void moveOnWhite();
	void moveForward();
};

Ant::Ant(int r, int c, Dir d):row(r), col(c), dir(d) { }

void Ant::moveForward()
{
	switch (dir)
	{
	case U:
		row -= 1;
		break;
	case R:
		col += 1;
		break;
	case D:
		row += 1;
		break;
	case L:
		col -= 1;
		break;
	default:
		break;
	}
}

void Ant::moveOnBlack()
{
	Map[row][col] = 0;
	dir = (Dir)((dir + 1) % 4);//向右转90°
	moveForward();//先前一步
}

void Ant::moveOnWhite()
{
	Map[row][col] = 1;
	dir = (Dir)((dir + 4 - 1) % 4);//向左转90°
	moveForward();//先前一步
}

pair<int, int> LTAnt(int startRow, int startCol, int startDir, int step)
{
	Ant ant(startRow, startCol, (Dir)startDir);
	while (step)
	{
		int curRow = ant.row, curCol = ant.col;
		if (Map[curRow][curCol] == 0)
			ant.moveOnWhite();
		else
			ant.moveOnBlack();
		step -= 1;
	}
	return pair<int, int>(ant.row, ant.col);
}

int main(int argc, char** argv)
{
	pair<int, int> ans;
	int m = 0, n = 0;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> Map[i][j];
		}
	}

	int x = 0, y = 0, dir = 0, k = 0;
	char s = 0;
	cin >> x >> y >> s >> k;

	switch (s)
	{
	case 'U':
		dir = 0;
		break;
	case 'R':
		dir = 1;
		break;
	case 'D':
		dir = 2;
		break;
	case 'L':
		dir = 3;
		break;
	default:
		break;
	}

	ans = LTAnt(x, y, dir, k);

	cout << ans.first << " " << ans.second << endl;

	//system("pause");
	return 0;
}