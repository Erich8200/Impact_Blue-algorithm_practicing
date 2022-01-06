#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <algorithm>
#define N 10

using namespace std;

//这题思路就是假设两个人同时走
//所以dp数组前两个维度是一个空间，后两个又是一个，分别记录互不干涉
//两个空间中分别个有一个人走，要求他们走的不重复即可
int dp[N + 2][N + 2][N + 2][N + 2];
int A[N + 2][N + 2];

int main()
{
	freopen("input0.txt", "r", stdin);
	int n;
	cin >> n;
	int x, y, num;
	while (cin >> x >> y >> num && x && y && num)
		A[x][y] = num;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				for (int l = 1; l <= n; l++)
				{
					//四种转移方式实际上任意组合均可
					int m1 = max(dp[i - 1][j][k - 1][l], dp[i][j - 1][k][l - 1]);//第一人下、第二人下，第一人右、第二人右
					int m2 = max(dp[i][j - 1][k - 1][l], dp[i - 1][j][k][l - 1]);//第一人右、第二人下，第一人下、第二人右
					//第一个人走的，一定更新
					dp[i][j][k][l] = max(m1, m2) + A[i][j];
					//判断是否重复，不重复则更新
					if (i != k || j != l)
						dp[i][j][k][l] += A[k][l];
				}
			}
		}
	}
	cout << dp[n][n][n][n] << endl;
	fclose(stdin);
	return 0;
}