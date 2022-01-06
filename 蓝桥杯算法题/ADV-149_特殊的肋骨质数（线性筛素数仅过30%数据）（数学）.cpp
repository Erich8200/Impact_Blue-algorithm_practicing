#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define N 99999999

using namespace std;

bool checkPrime[N];
map<int, int> primeList;//用map把查找复杂度降到O(1)

//线性筛数组
void getPrime(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!checkPrime[i])
			primeList[i] = i;
		for (map<int,int>::iterator it = primeList.begin(); it != primeList.end() && it->second*i <= n; it++)
		{
			checkPrime[it->second*i] = true;
			if (i%it->second*i == 0)
				break;
		}
	}
}

int main(int argc, char** argv)
{
	int x = 0;
	cin >> x;
	int n = 1, m = 1;
	for (int i = 1; i < x; i++)
		m *= 10;
	for (int i = 1; i <= x; i++)
		n *= 10;
	n -= 1;
	getPrime(n);
	for (int i = m; i <= n; i++)
	{
		int temp = i;
		bool shouldShow = true;
		while (temp)
		{
			if (primeList.find(temp) == primeList.end())
			{
				shouldShow = false;
				break;
			}
			temp /= 10;
		}
		if (shouldShow)
			cout << i << endl;
	}
	system("pause");
	return 0;
}