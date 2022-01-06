#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

#define MOD 1000007
#define N 110
using namespace std;

int a[N];
int n, m;

long long cache[N][N];

long long solve_dfs(int index, int res)
{
	if (cache[index][res])
		return cache[index][res];
	
	if (res == 0) return 1;
	else if (index >= n) return 0;
	else
	{
		long long ans = 0;
		for (long long i = 0; i <= a[index]; i++)
			if (res - i >= 0)
				ans += solve_dfs(index + 1, res - i);
		ans %= MOD;
		cache[index][res] = ans;
		return ans;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << solve_dfs(0, m) << endl;
	return 0;
}