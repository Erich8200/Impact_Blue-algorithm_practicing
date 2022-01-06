#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define N 100

using namespace std;

int dp[N + 2], w[N + 2], c[N + 2];

int backPack01(int V, int n)
{
	for (int i = 1; i <= n; i++)
		for (int j = V; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
	return dp[V];
}

int main(int argc, char** argv)
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> c[i];
	cout << backPack01(m, n) << endl;
	system("pause");
	return 0;
}