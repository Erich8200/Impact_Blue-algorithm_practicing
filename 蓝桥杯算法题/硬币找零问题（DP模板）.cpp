#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#define N 50
#define M 20000

using namespace std;

int cake[N + 2];
int dp[M + 2];

void initDp()
{
	for (int i = 0; i < sizeof(dp)/sizeof(int); i++)
		dp[i] = 0x7FFFFFFF;
	dp[0] = 0;
}

int solve(int total,int n)
{
	for (int i = 0; i <= total; i++)
		for (int j = 0; j < n; j++)
			if (dp[i] > dp[i - cake[j]] + 1 && i - cake[j] >= 0)
				dp[i] = dp[i - cake[j]] + 1;
	return dp[total];
}

int main(int argc, char** argv)
{
	int total = 0;
	int typeCount = 0;
	cin >> total >> typeCount;
	int i = 0;
	for (; i < typeCount; i++)
		cin >> cake[i];
	initDp();
	int ans = solve(total, i);
	if (ans == 0x7FFFFFFF)
		cout << "><" << endl;
	else
		cout << ans << endl;
	fclose(stdin);
	return 0;
}