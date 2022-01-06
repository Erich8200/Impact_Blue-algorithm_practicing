#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#define N 3

using namespace std;

int rowDir[] = { -1,0,1,0 };
int colDir[] = { 0,1,0,-1 };

class Square
{
public:
	Square() {}
	char A[N][N];
	int pRow;
	int pCol;
	int time;
	void swap(int row1, int col1, int row2, int col2);
	friend bool operator ==(Square& s1, Square& s2);
};

void Square::swap(int row1, int col1, int row2, int col2)
{
	char temp = A[row1][col1];
	A[row1][col1] = A[row2][col2];
	A[row2][col2] = temp;
	pRow = row2;
	pCol = col2;
	time += 1;
}

bool operator ==(Square& s1, Square& s2)
{
	bool ret = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (s1.A[i][j] != s2.A[i][j])
			{
				ret = false;
				break;
			}
		}
	}
	return ret;
}

vector<Square> squareSet;

int BFS(Square& sStart, Square& sEnd)
{
	int ans = -1;
	queue<Square> Q;
	Q.push(sStart);
	squareSet.push_back(sStart);
	while (!Q.empty())
	{
		Square node = Q.front();
		Q.pop();
		if (node == sEnd)
		{
			ans = node.time;
			break;
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				Square newNode = node;
				int curRow = node.pRow;
				int curCol = node.pCol;
				int newRow = curRow + rowDir[i];
				int newCol = curCol + colDir[i];
				if (newRow >= 0 && newRow <= 2 && newCol >= 0 && newCol <= 2)
				{
					newNode.swap(curRow, curCol, newRow, newCol);
					bool duplication = false;
					for (vector<Square>::iterator it = squareSet.begin(); it < squareSet.end(); it++)
					{
						if ((Square&)newNode == (Square&)(*it))
						{
							duplication = true;
							break;
						}
					}
					if (!duplication)
					{
						squareSet.push_back(newNode);
						Q.push(newNode);
					}
				}
			}
		}
	}
	return ans;
}

Square string2Square(string str)
{
	Square s;
	bool found = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			char c = str[i * 3 + j];
			s.A[i][j] = c;
			if (!found && c == '.')
			{
				s.pRow = i;
				s.pCol = j;
				found = true;
			}
		}
	}

	s.time = 0;
	return s;
}

int main()
{
	freopen("input3.txt", "r", stdin);
	string startStr, endStr;
	cin >> startStr >> endStr;
	Square sStart, sEnd;
	sStart = string2Square(startStr);
	sEnd = string2Square(endStr);
	cout << BFS(sStart, sEnd) << endl;
	fclose(stdin);
	return 0;
}

