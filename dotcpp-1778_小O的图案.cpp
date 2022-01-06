#include <iostream>
#include <stdio.h>
#define N 200

using namespace std;

char g[N][N];

void printSingle(int hOff, int vOff, int sideLen)
{
	for (int i = 0; i < sideLen; i++)
		g[hOff + i][vOff] = g[hOff][vOff + i] = g[hOff + sideLen - 1][vOff + i] = g[hOff + i][vOff + sideLen - 1] = '*';
}

void clearG(int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = ' ';
}

void printG(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%c",g[i][j]);
		printf("\n");
	}
}

int main(void)
{
	//freopen("0.txt", "r", stdin);

	int n = 0;
	while (cin >> n)
	{
		int maxSideLen = 2*n - 1;
		printf("%d\n", n);
		clearG(maxSideLen);
		int hOff = 0, vOff = 0;
		for (int i = maxSideLen; i >= (n%2 ? 1 : 3); i -= 4)
		{
			printSingle(hOff, vOff, i);
			hOff += 2;
			vOff += 2;
		}
		printG(maxSideLen);
	}

	//fclose(stdin);
	return 0;
}
