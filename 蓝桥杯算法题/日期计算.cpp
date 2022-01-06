#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int solve(int y, int m, int d)
{
	if (m < 3)
	{
		m += 12;
		y -= 1;
	}

	int ans = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
	if (ans == 0)
		ans = 7;
	return ans;
}

int main()
{
	int y = 0, m = 0, d = 0;
	cin >> y >> m >> d;
	cout << solve(y, m, d) << endl;
	return 0;
}