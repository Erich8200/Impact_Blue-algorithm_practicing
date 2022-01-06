#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <memory.h>
#include <stdio.h>

#define N 15

using namespace std;

string getAn(int n)
{
	string an;
	char temp[7] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		if (i == n)
			sprintf(temp, "sin(%d)", i);
		else
		{
			if (i%2)
				sprintf(temp, "sin(%d-", i);
			else
				sprintf(temp, "sin(%d+", i);
		}
		an += temp;
		memset(temp, 0x00, sizeof(temp));
	}
	
	for (int i = 1; i < n; i++)
	{
		an += ")";
	}
	return an;
}

string getSn(int n)
{
	string sn;
	char num1[2] = { 0 }, num2[2] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		sprintf(num1, "%d", n - i + 2);
		sprintf(num2, "%d", n - i + 1);
		if (i == 1)
			sn = "sin(1)" + string("+") + string(num2);
		else
			sn = "(" + sn + ")" + getAn(i) + "+" + num2;
	}
	return sn;
}

int main(int argc, char** argv)
{
	int n = 0;
	cin >> n;
	cout << getSn(n) << endl;
	system("pause");
	return 0;
}