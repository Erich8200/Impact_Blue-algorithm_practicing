#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#define MAX_N 1000
#define MAX_M 1000

using namespace std;

int t[MAX_N], status[MAX_M];

int solve(int n, int m)
{
	sort(t, t + n);
	
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sort(status, status + m);
		sum += status[0];
		status[0] += t[i];
	}
	
	return sum;
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> t[i];
	cout << solve(n, m) << endl;
	return 0;
}
