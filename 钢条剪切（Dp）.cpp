#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>
#define N 50

using namespace std;

int arr[N];
int dp[N];

// DFS
int solve_dfs(int l)
{
	int ans = 0;
	if (l == 1)
		return arr[1];
	else
	{
		for (int x = 1; x <= l/2; x++)
			ans = max(arr[l], solve_dfs(x) + solve_dfs(l - x));
	}
	return ans;
}

// DP
int solve_dp(int n)
{
	dp[1] = arr[1];
	for (int len = 1; len <= n; len++)
		for (int x = 1; x <= len/2; x++)
			dp[len] = max(arr[len], dp[x] + dp[len - x]);
	return dp[n];
}

int main()
{
	freopen("0.txt", "r", stdin);
	
	int l = 0, n = 0;
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	//cout << solve_dfs(l) << endl;
	cout << solve_dp(l) << endl;
	fclose(stdin);
	system("pause");
	return 0;
}
