#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <algorithm>
#define N 40
#define MAX_N 40
#define MAX_V 20010

using namespace std;

int a[N];
int n;
int dp[MAX_N][MAX_V];

int solve_dfs(int index, int res)
{
	if (index >= n)
		return res;
	else
	{
		int res1 = INT_MAX, res2 = INT_MAX;
		if (res - a[index] >= 0)
			res1 = solve_dfs(index + 1, res - a[index]);
		res2 = solve_dfs(index + 1, res);
		return min(res1, res2);
	}
}

int solve_dp(int v)
{
	for (int j = 0; j <= v; j++)
		dp[n][j] = j;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = v; j >= 0; j--)
		{
			int res1 = INT_MAX, res2 = INT_MAX;
			if (j - a[i] >= 0)
				res1 = dp[i + 1][j - a[i]];
			res2 = dp[i + 1][j];
			dp[i][j] = min(res1, res2);
		}
	}
	return dp[0][v];
}

int main()
{
	int V = 0;
	cin >> V >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	//cout << solve_dfs(0, V) << endl;
	cout << solve_dp(V) << endl;
	return 0;
}

