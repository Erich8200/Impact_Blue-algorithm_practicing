#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <limits.h>
#include <math.h>

#define N 2000
#define MAX_N 100000
using namespace std;

bool nPrime[N];
vector<int> primeList;
int dp[MAX_N];

void getPrime(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (nPrime[i] == false)
			primeList.push_back(i);
		for (int j = 0; j < primeList.size() && i*primeList[j] <= n; j++)
		{
			nPrime[i*primeList[j]] = true;
			if (i % primeList[j] == 0)
				break;
		}
	}
}

int solve_dfs(int res)
{
	if (res < 4)
		return res;
	else
	{
		int ans = INT_MAX;
		for (int i = 0; i < primeList.size() && primeList[i]*primeList[i] <= res; i++)
		{
			if (res - 2 * primeList[i] >= 0)
			{
				int temp = solve_dfs(res - 2 * primeList[i]);
				if (temp < ans)
					ans = temp;
			}
		}
		return ans;
	}
}

int solve_dp(int n)
{
	dp[1] = 1;dp[2] = 2;dp[3] = 3;
	for (int i = 4; i <= n; i++)
	{
		int ans = INT_MAX;
		for (int j = 0; primeList[j]*primeList[j] <= i; j++)
		{
			if (i - 2 * primeList[j] >= 0)
				ans = min(dp[i - 2 * primeList[j]], ans);
		}
		dp[i] = ans;
	}
	return (n - dp[n]) / 2;
}

int main()
{
	int n = 0;
	cin >> n;
	getPrime(317);
	//cout << (n - solve_dfs(n))/2 << endl;

	int ans = solve_dp(n);

	if (n % 2)
		cout << ans - 1 << endl;
	else
		cout << ans << endl;
	
	system("pause");
	return 0;
}