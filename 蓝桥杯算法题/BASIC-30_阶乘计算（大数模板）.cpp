#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#define N 100000

using namespace std;

string intToString(int n)
{
	string ans;
	while (n)
	{
		ans += n % 10 + '0';
		n /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

class BigInt {
private:
	int d[N];
	int len;
public:
	BigInt(string numStr);
	BigInt();
	void show();
	int getLen() { return len;}
	friend BigInt operator* (BigInt& a, BigInt& b);
};

BigInt::BigInt()
{
	memset(d, 0x00, sizeof(d) / sizeof(int));
	len = 0;
}

BigInt::BigInt(string numStr)
{
	int i = 0;
	memset(d, 0x00, sizeof(d) / sizeof(int));
	len = 0;
	for (string::iterator it = --numStr.end(); it >= numStr.begin(); it--)
	{
		d[i++] = *it - '0';
		if (it == numStr.begin())
			break;
	}
	len = numStr.length();
}

void BigInt::show()
{
	for (int i = len - 1; i >= 0; i--)
		printf("%d", d[i]);
}

BigInt operator* (BigInt& a, BigInt& b)
{
	BigInt c;
	c.len = a.len + b.len;
	int i, j;
	for (i = 0; i < a.len; i++)
		for (j = 0; j < b.len; j++)
			c.d[i + j] += a.d[i] * b.d[j];
	for (i = 0; i <= c.len; i++)
	{
		c.d[i + 1] += c.d[i] / 10;
		c.d[i] %= 10;
	}
	while (c.d[i])
	{
		c.d[i + 1] += c.d[i] / 10;
		c.d[i] %= 10;
	}
	while (c.len >= 1 && !c.d[i]) i--;
	c.len = i + 1;
	return c;
}

BigInt fact(int n)
{
	if (n == 0)
		return BigInt(intToString(1));
	else
	{
		BigInt a, b("1");
		for (int i = 1; i <= n; i++)
		{
			a = BigInt(intToString(i));
			b = b * a;
		}
		return b;
	}
}

int main(void)
{
	int n;
	cin >> n;
	BigInt ans = fact(n);
	ans.show();
	return 0;
}
