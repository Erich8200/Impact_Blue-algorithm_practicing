#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <memory.h>
#define N 100
#define M 6

using namespace std;

int salary[N + 2];
int money[M] = { 100,50,10,5,2,1 };
//int moneyCount[M];

int dispatch(int n)
{
	int moneyCount = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < sizeof(money) && salary[i]; j++)
		{
			int count = salary[i] / money[j];
			if (count)
			{
				moneyCount += count;
				salary[i] = salary[i] % money[j];
			}
		}
	}
	return moneyCount;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			cin >> salary[i];
		cout << dispatch(n) << endl;
		memset(salary, 0x00, sizeof(salary));
	}
	system("pause");
	return 0;
}