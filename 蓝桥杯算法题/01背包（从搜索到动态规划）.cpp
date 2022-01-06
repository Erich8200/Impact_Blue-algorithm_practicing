#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAX_N 210
#define MAX_V 5010

using namespace std;

int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N][MAX_V];
int cache[MAX_N][MAX_V];
bool vis[MAX_N][MAX_V];

int solve_dfs_a(int i, int j)
{
	int res;
	if (i == n)
		res = 0;
	else if (j < w[i])
		res = solve_dfs_a(i + 1, j);
	else
		res = max(solve_dfs_a(i + 1, j), solve_dfs_a(i + 1, j - w[i]) + v[i]);
	return res;
}

int solve_dfs(int index, int res)
{
	int ans = 0;
	if (index == n || res <= 0)
		return 0;
	else
	{
		if (res - w[index] >= 0)
			ans = max(solve_dfs(index + 1, res - w[index]) + v[index], solve_dfs(index + 1, res));
		else
			ans = solve_dfs(index + 1, res);
	}
	return ans;
}

int solve_dfs_m(int i, int j)
{
	if (vis[i][j])
		return cache[i][j];
	int res;
	if (i == n)
		res = 0;
	else if (j < w[i])
		res = solve_dfs_m(i + 1, j);
	else
		res = max(solve_dfs_m(i + 1, j), solve_dfs_m(i + 1, j - w[i]) + v[i]);
	vis[i][j] = true;
	cache[i][j] = res;
	return res;
}

int solve_dp()
{
	dp[0][w[0]] = v[0]; // Init
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (j - w[i] >= 0)
				dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	int ans = 0;	
	for (int j = 0; j <= W; j++)
		if (ans < dp[n - 1][j])
			ans = dp[n - 1][j];
	return ans;
}

int main() 
{
	cin >> n >> W;
	for (int i = 0; i < n; i++)
		cin >> w[i] >> v[i];

	cout << solve_dp() << endl;
	//cout << solve_dfs_m(0, W) << endl;
	//cout << solve_dfs_a(0, W) << endl;
	//cout << solve_dfs(0, W) << endl;
	
	return 0;
}
