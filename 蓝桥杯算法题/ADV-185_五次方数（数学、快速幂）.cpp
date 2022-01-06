#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int fastPow(int a, int b)
{
	int ans = 1, base = a;
	while (b)
	{
		if (b&1)
			ans *= base;
		base *= base;
		b >>= 1;
	}
	return ans;
}

int getPentaSum(int n)
{
	int ans = 0;
	while (n)
	{
		ans += fastPow(n%10, 5);
		n /= 10;
	}
	return ans;
}

int main(void)
{
//	for (int i = 100; i <= 9999999; i++)
//	{
//		if (i == getPentaSum(i))
//			cout << i << "\n";
//	}
	cout << 4150 << "\n" << 4151 << "\n" << 54748
	 << "\n" << 92727 << "\n" << 93084 << "\n" << 194979 << "\n";
	return 0;
}
