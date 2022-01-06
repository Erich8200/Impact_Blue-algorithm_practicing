#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#define N 500

using namespace std;

vector<int> A;

bool isInti(int n, int sum)
{
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	if (n/100000)//六位数
	{
		a = n / 100000;
		b = n % 10;
		c = n / 10000 % 10;
		d = n / 10 % 10;
		e = n / 1000 % 10;
		f = n / 100 % 10;
		if (!(a == b && c == d && e == f))//不回文
			return false;
	}
	else//五位数
	{
		a = n / 10000;
		b = n % 10;
		c = n / 1000 % 10;
		d = n / 10 % 10;
		e = n / 100 % 10;
		if (!(a == b && c == d))//不回文
			return false;
	}

	//和为指定值
	if (a + b + c + d + e + f == sum)
		return true;
	else
		return false;
}

int main()
{
	int sum = 0;
	cin >> sum;
	for (int i = 10000; i <= 999999; i++)
		if (isInti(i, sum))
			A.push_back(i);
	if (A.size())
	{
		for (vector<int>::iterator it = A.begin(); it < A.end(); it++)
			cout << *it << endl;
	}
	else
		cout << -1;
	system("pause");
	return 0;
}