#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <math.h>

#define N 41

using namespace std;

char G[N][N];

void clearSingleGraph()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			G[i][j] = ' ';
}

void getSingleGraph(int n)
{
	clearSingleGraph();
	for (int i = 1; i <= n; i++)
		G[i][i] = G[i][n - i + 1] = 'X';
	return;
}

//参数1：重复度
//参数2：是否为之后的图形
void showSingleGraph(int n, bool flag)
{
	int i = 0, j = 0;
	if (flag)
		i = 2;
	else
		i = j = 1;
	for (; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			cout << G[i][j];
		cout << endl;
	}
}

//参数1：单个图形的规模
//参数2：重复度
void showGraph(int m, int n)
{
	getSingleGraph(m);
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
			showSingleGraph(m, false);
		else
			showSingleGraph(m, true);
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	//showGraph(5, 4);
	int times = 0;
	cin >> times;
	while (times--)
	{
		int m = 0, n = 0;
		cin >> m >> n;
		showGraph(m, n);
	}
	system("pause");
	return 0;
}