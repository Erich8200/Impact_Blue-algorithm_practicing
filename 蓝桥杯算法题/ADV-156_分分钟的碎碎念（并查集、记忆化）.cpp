#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <stdio.h>

#define MAX_N 1010

using namespace std;

int from[MAX_N], chainLen[MAX_N];
bool vis[MAX_N];
int n;

int find(int i)
{
	int ans = 1;
	while (from[i] != 0)
	{
		i = from[i];
		if (vis[i])
		{
			ans += chainLen[i];
			break;
		}
		ans += 1;
	}
	return ans;
}

int solve()
{
	int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		int temp = find(i);
		chainLen[i] = temp;
		vis[i] = true;
		if (ans < temp)
			ans = temp;
	}
	return ans;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> from[i];

	cout << solve() << endl;
	return 0;
}