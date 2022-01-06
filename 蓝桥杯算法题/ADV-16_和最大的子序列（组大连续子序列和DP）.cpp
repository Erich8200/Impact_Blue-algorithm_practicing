#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#define N 100000

using namespace std;

int A[N + 2];
int dp[N + 2];

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	dp[0] = A[0];
	for (int i = 1; i <= n-1; i++)
		dp[i] = max(A[i], A[i] + dp[i - 1]);
	int ans = -1;
	for (int i = 0; i <= n; i++)
		if (ans < dp[i])
			ans = dp[i];
	cout << ans << endl;
	return 0;
}
