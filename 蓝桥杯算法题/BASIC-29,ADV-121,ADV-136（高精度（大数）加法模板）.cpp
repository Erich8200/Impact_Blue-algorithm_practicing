#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <memory.h>

#define N 10000

using namespace std;

class BigInt
{
public:
	BigInt();
	BigInt(string numStr);
	void showInt();
	~BigInt();
	friend BigInt operator+(BigInt& a, BigInt& b);

private:
	int d[N];
	int len;
};

BigInt::BigInt() 
{ 
	len = 0;
	memset(d, 0x00, sizeof(d));
}

BigInt::BigInt(string numStr)
{
	int length = numStr.length();
	this->len = length;
	memset(d, 0x00, sizeof(d));
	for (int i = 0; i < length; i++)
		d[i] = numStr[length - i - 1] - '0';
}

BigInt::~BigInt() { }

void BigInt::showInt()
{
	for (int i = this->len - 1; i >= 0; i--)
		cout << d[i];
	cout << endl;
}

BigInt operator+(BigInt& a, BigInt& b)
{
	BigInt c;
	c.len = a.len > b.len ? a.len : b.len;
	int i;
	for (i = 0; i < c.len; i++)
	{
		c.d[i] += a.d[i] + b.d[i];
		c.d[i + 1] = c.d[i] / 10;
		c.d[i] %= 10;
	}
	c.len = (c.d[i] ? i + 1 : i);
	return c;
}

int main(void)
{
	string strA, strB;
	cin >> strA >> strB;
	BigInt a(strA);
	BigInt b(strB);
	BigInt c = a + b;
	c.showInt();
	return 0;
}
