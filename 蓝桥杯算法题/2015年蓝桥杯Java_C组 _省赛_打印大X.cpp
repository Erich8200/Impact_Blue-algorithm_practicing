#include <iostream>
#include <stdio.h>
#define N 10000

using namespace std;

int g[N][N];

int main()
{
	int m = 0, n = 0;
	cin >> m >> n;
	
	int height = n, brushWidth = m;
	int width = 0;
	
	for (int hOff = 0; hOff < height; hOff++)
	{
		for (int i = 0; i < brushWidth; i++)
		{
			g[hOff][hOff + i] = g[height - hOff - 1][hOff + i] = '*';
			width = hOff + i + 1;
		}
	}
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			printf("%c", (g[i][j] == '*' ? '*' : '.'));
		printf("\n");
	}
	
	return 0;
}

