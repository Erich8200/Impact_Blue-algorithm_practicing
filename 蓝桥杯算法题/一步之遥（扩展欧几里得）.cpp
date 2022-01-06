#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

int exGcd(int a, int b, int& x, int& y)
{
	int d = a;
	if (b == 0)
	{
		x = 1;y = 0;
	}
	else
	{
		d = exGcd(b, a%b, y, x);
		y -= (a / b) * x;
	}
	return d;
}

int main()
{
	int a = 97, b = -127, x = 0, y = 0;
	exGcd(a, b, x, y);
	cout << x << " " << y << endl;
	cout << x + y << endl;
	system("pause");
	return 0;
}