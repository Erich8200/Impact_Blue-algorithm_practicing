#include <iostream>
#include <stdio.h>
#define N 200

using namespace std;

char g[N][N];

int main(void)
{
	//freopen("0.txt", "r", stdin);

	int n = 0;
	cin >> n;

	for (int i = n - 1; i >= 0; i--)
	{
		int spCount = 2*i;
		g[n - i - 1][spCount] = g[n - i - 1][4*(n - 1) - spCount] = g[n + i - 1][spCount] = g[n + i - 1][4*(n - 1) - spCount] = '*';
	}
	
	for (int i = 0; i < 2*n - 1; i++)
	{
		for (int j = 0; j < 4*n; j++)
			printf("%c", g[i][j]);
		printf("\n");
	}


	//fclose(stdin);
	return 0;
}
