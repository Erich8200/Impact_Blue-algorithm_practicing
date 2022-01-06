#include <iostream>
#include <stdio.h>
#define N 50

using namespace std;

int n;
int* arr;
int dp[N][N];

// ËÑË÷
int solve_dfs(int index, int preIndex)
{
	int money1 = 0, money2 = 0;
	if (index > n) return 0;
	else
	{
		if (index - preIndex > 1)
			money1 = solve_dfs(index + 1, index) + arr[index];
		money2 = solve_dfs(index + 1, preIndex);
	}
	return money1 > money2 ? money1 : money2;
}

// ¶¯Ì¬¹æ»®
int solve_dp()
{
	int money1 = 0, money2 = 0;

	for (int j = 0; j < n; j++)
		dp[n - 1][j] = n - 1 - j > 1 ? arr[n - 1] : 0;

	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (i - j > 1)
				money1 = dp[i + 1][i] + arr[i];
			else if (i == j)
				money1 = dp[i + 1][i] + arr[i];
			else
				money1 = dp[i + 1][j];
			money2 = dp[i + 1][j];
			dp[i][j] = money1 > money2 ? money1 : money2;
		}
	}

	int ans = 0;
	for (int j = 0; j < n; j++)
	{
		if (ans < dp[0][j])
			ans = dp[0][j];
	}

	return ans;
}

int main()
{
	cin >> n;
	arr = new int[n]();
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	//cout << solve_dfs(0, -2) << endl;
	
	cout << solve_dp() << endl;

	delete arr;
	system("pause");
	return 0;
}
