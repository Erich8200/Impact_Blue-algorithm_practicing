#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <algorithm>
#define MAX_N 10000

using namespace std;

int dp[MAX_N];

int solve_dfs(int res)
{
	if (res == 0) return 1;
	else if (res < 0) return 0;
	else
	{
		int sum = 0;
		sum += solve_dfs(res - 1);
		sum += solve_dfs(res - 2);
		return sum;
	}
}

int solve_dp(int n)
{
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
		if (i - 2 >= 0)
			dp[i] += dp[i - 1] + dp[i - 2];
		else
			dp[i] += dp[i - 1];
	return dp[n];
}

int main()
{
	int n = 0;
	cin >> n;
	//cout << solve_dfs(n) << endl;
	cout << solve_dp(n) << endl;
	return 0;
}

