#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#define N 10000

using namespace std;

vector<int> primeArr;
bool primeCheck[N];

void getPrimeArr(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!primeCheck[i])
			primeArr.push_back(i);
		for (vector<int>::iterator it = primeArr.begin(); it < primeArr.end() && *it*i <= n; it++)
		{
			primeCheck[*it*i] = true;
			if (*it%i == 0)
				break;
		}
	}
}

void fract(int n, vector<int>& arr)
{
	if (n <= 0)
		return;
	for (vector<int>::iterator it = primeArr.begin(); it < primeArr.end(); it++)
	{
		int prime = *it;
		if (n%prime == 0)
		{
			arr.push_back(prime);
			n /= prime;
			fract(n, arr);
			break;//这句比较重要，一开始漏了
		}
	}
	return;
}

int main(void)
{
	int n = 0;
	cin >> n;
	getPrimeArr(n);
	vector<int> arr;
	fract(n, arr);
	for (vector<int>::iterator it = arr.begin(); it < arr.end(); it++)
	{
		if (it == --arr.end())
			cout << *it << "\n";
		else
			cout << *it << '*';
	}
	return 0;
}
