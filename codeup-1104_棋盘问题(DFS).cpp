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
	if (curRow > totalRow)//ֻҪ������ѡ��
	{
		if (curChessCount <= 0)//����������
		{
			ansCount += 1;//�Ƿ�����ĿҪ���һ����	
		}
		return;//�����������Ҫ���̷���
	}
	else if (curChessCount <= 0)
	{
		ansCount += 1;//�Ƿ�����ĿҪ���һ����	
		return;
	}
	else
	{
		//��ÿ�ж�������ѡ���ڸ��з������ӺͲ�����

		//1.�ڵ�ǰ�з�������
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
		//2.���ڵ�ǰ�з�������
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