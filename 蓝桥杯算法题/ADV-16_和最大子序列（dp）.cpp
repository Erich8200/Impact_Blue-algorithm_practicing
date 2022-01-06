#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#define MAX_N 100010

using namespace std;

long long a[MAX_N];
long long dp[MAX_N];

long long solve_dp(int n)
{
	dp[0] = a[0];
	for (int i = 1; i < n; i++)
		dp[i] = max(a[i], dp[i - 1] + a[i]);
		
	long long ans = 0;
	for (int i = 0; i < n; i++)
		if (ans < dp[i])
			ans = dp[i];
		
	return ans;
}

int main()
{
	freopen("0.txt", "r", stdin);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << solve_dp(n) << endl;
	fclose(stdin);
	return 0;
}
