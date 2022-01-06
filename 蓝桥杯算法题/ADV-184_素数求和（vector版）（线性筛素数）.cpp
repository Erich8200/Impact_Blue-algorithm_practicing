#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

#define N 5000000

long long primeCheck[N];
vector<long long> primeList;

//线性筛素数
void getPrime(long long n)
{
	for (long long i = 2; i <= n; i++)
	{
		//如果是之前就被标记的数，说明是素数，那么直接放入素数集合
		if (primeCheck[i] == 0)
			primeList.push_back(i);
		//筛去后面所有由素数和当前数的乘积构成的数，注意这里终止条件应当加上等号，否则n可能不会被筛掉
		for (long long j = 0; j < primeList.size() && i*primeList[j] <= n; j++)
		{
			primeCheck[i*primeList[j]] = 1;
			//不重复筛去，减小开销
			if (i%primeList[j] == 0)
				break;
		}
	}
}
long long getPrimeSum(int n)
{
	long long sum = 0;
	for (vector<long long>::iterator it = primeList.begin(); it < primeList.end(); it++)
	{
		if (*it <= n)
			sum += *it;
		else
			break;
	}
	return sum;
}
int main(void)
{
	long long n = 0;
	cin >> n;
	getPrime(n);
	cout << getPrimeSum(n) << endl;
	return 0;
}