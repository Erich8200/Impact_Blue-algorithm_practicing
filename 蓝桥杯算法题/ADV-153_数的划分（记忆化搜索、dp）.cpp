#include <stdio.h>
#include <iostream>
#include <vector>
#define N 110

using namespace std;

vector< vector<int> > ans;
long long cache[N][N];
long long dp[N][N];

long long solve_dfs_dbg(int preNum, int res, vector<int> arr)
{
	if (res == 0)
	{
		ans.push_back(arr);
		return 1LL;
	} 
	else if (res < 0) return 0LL;
	else
	{
		long long sum = 0;
		for (int i = preNum; i <= res; i++)
		{
			arr.push_back(i);
			sum += solve_dfs_dbg(i, res - i, arr);
			arr.pop_back();
		}
			
		return sum;
	}
}

long long solve_dfs(int preNum, int res)
{
	if (cache[preNum][res] != 0)
		return cache[preNum][res];
	if (res == 0) return 1LL;
	else if (res < 0) return 0LL;
	else
	{
		long long sum = 0;
		for (int i = preNum; i <= res; i++)
			sum += solve_dfs(i, res - i);
		cache[preNum][res] = sum;
		return sum;
	}
}

long long solve_dp(int n)
{
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;
	for (int i = n; i >= 0; i--)
		for (int j = 1; j <= n; j++)
			for (int k = i; k <= j; k++)
					dp[i][j] += dp[k][j - k];
	return dp[1][n];
}

int main()
{
	int n = 0;
	cin >> n;
	//cout << solve_dfs(1, n) << endl;
	cout << solve_dp(n) << endl;
	return 0;
}

