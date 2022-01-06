#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#define N 500

using namespace std;

int dp[N + 2][N + 2];
int A[N + 2][N + 2];

int solve(int n, int m)
{
	int ans = A[1][1];
	//初始化dp数组
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = dp[i][j - 1] + A[i][j];

	//计算最大子阵
	for (int first = 1; first <= m; first++)
	{
		for (int last = first; last <= m; last++)
		{
			int subMatrixSum = 0;
			for (int i = 1; i <= n; i++)
			{
				subMatrixSum += dp[i][last] - dp[i][first - 1];
				ans = ans > subMatrixSum ? ans : subMatrixSum;
				subMatrixSum = subMatrixSum > 0 ? subMatrixSum : 0;//重要，拒绝负子阵。否则有可能会削减最大子阵的值，导致错误结果
			}
		}
	}

	return ans;
}

int main()
{
	freopen("input0.txt", "r", stdin);
	int m, n;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> A[i][j];
	cout << solve(n, m) << endl;
	fclose(stdin);
	system("pause");
	return 0;
}