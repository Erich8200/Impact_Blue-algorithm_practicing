#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>
#define N 15

using namespace std;

int dp[N + 2];
vector<int> A;

int solve1(int n)
{
	int ans = -1;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
			if (A[j] >= A[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		ans = max(ans, dp[i]);
	}
	return ans;
}

int solve2(int n)
{
	int ans = -1;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
			if (A[j] < A[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main()
{
	int n = 0;
	int temp = 0;
	A.push_back(0);//Ìî³ä£¬ÎÞÊµÒå
	while (cin >> temp)
	{
		A.push_back(temp);
		n += 1;
	}
	cout << solve1(n) << endl;
	memset(dp, 0x00, sizeof(dp));
	cout << solve2(n) << endl;
	return 0;
}