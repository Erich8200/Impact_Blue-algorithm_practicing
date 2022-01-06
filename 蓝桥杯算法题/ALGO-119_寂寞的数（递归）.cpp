#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#define N 10000

using namespace std;

bool vis[N];

int getDSum(int n)
{
	int bak = n;
	int sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum += bak;
}

void d(int cur, const int max)
{
	if (cur > max)
		return;
	else
	{
		int n = getDSum(cur);
		if (!vis[n])
		{
			vis[n] = true;
			d(n, max);
		}
		return;
	}
}

int main(int argc, char** argv)
{
	int n = 0;
	cin >> n;
	d(1, n);
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			cout << i << endl;
	return 0;
}