#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

vector<int> arr;

int solve(int l, int r)
{
	for (int i = l; i <= r; i++)
		arr[i] = log(arr[i])*1.0 / log(2) + 1;
	int ans = 0;
	for (vector<int>::iterator it = arr.begin(); it < arr.end(); it++)
		ans += *it;
	return ans;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	arr.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}

	for (int i = 1; i <= m; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << solve(l, r) << endl;
	}

	return 0;
}
