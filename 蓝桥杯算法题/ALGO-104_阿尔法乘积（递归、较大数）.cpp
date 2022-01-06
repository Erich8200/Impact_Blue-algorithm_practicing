#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

int ans;

using namespace std;

void alphaProduct(long long num)
{
	if ((num / 10) == 0)
	{
		ans = num;
		return;
	}
	else
	{
		int product = 1;
		while (num > 0)
		{
			int temp = num % 10;
			if (temp != 0)
				product *= temp;
			num /= 10;
		}
		alphaProduct(product);
	}
	return;
}

int main(int argc, char** argv)
{
	long long n = 0;
	cin >> n;
	//n = 4018224312;
	alphaProduct(n);
	cout << ans << endl;
	system("pause");
	return 0;
}