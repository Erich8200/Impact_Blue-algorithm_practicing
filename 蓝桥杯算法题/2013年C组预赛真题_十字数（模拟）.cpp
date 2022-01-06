#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <math.h>

#define N 67

using namespace std;

char G[N][N];

void clearGraph()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			G[i][j] = '.';
}

void printGraph(int m)
{
	for (int i = 1; i <= 4 * m + 5; i++)
	{
		for (int j = 1; j <= 4 * m + 5; j++)
			cout << G[i][j];
		cout << endl;
	}
}

void getSingleGraph(int n, int x)
{
	for (int i = x + 1, j = x + 3; j <= x + n - 2; j++)
		G[i][j] = G[x + n][j] = '$';
	for (int i = x + 3, j = x + 1; i <= x + n - 2; i++) 
		G[i][j] = G[i][x + n] = '$';
	for (int i = x + 1, j = x + 3; i <= x + 3; i++)
		G[i][j] = G[i][x + n - 2] = '$';
	for (int i = x + n - 2, j = x + 3; i <= x + n; i++)
		G[i][j] = G[i][x + n - 2] = '$';
	for (int i = x + 3, j = x + 1;j <= x + 3;j++)
		G[i][j] = G[x + n - 2][j] = '$';
	for (int i = x + 3, j = x + n - 2;j <= x + n;j++)
		G[i][j] = G[x + n - 2][j] = '$';
}

void getGraph(int m)
{
	for (int n = 4 * m + 5, x = 0; n >= 5; n -= 4, x += 2)
	{
		getSingleGraph(n, x);
	}
}

int main(int argc, char** argv)
{
	int n = 0;
	cin >> n;
	clearGraph();
	//getSingleGraph(17, 0);
	getGraph(n);
	printGraph(n);
	system("pause");
	return 0;
}