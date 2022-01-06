#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

#define N 5000000

long long primeCheck[N];
long long primeList[N];

//线性筛素数，合数都可以由两个素数或一个素数一个合数的乘积表示
int getPrime(long long n)
{
	int pos = 0;
	for (long long i = 2; i <= n; i++)
	{
		//如果是之前就被标记的数，说明是素数，那么直接放入素数集合
		if (primeCheck[i] == 0)
			primeList[pos++] = i;
		//筛去后面所有由素数和当前数的乘积构成的数，注意这里终止条件应当加上等号，否则n可能不会被筛掉
		for (long long j = 0; j < pos && (long long)i*primeList[j] <= n; j++)
		{
			primeCheck[i*primeList[j]] = 1;
			//不重复筛去，减小开销
			if (i%primeList[j] == 0)
				break;
		}
	}
	return pos;//返回素数列表集合的大小
}

//需要把素数集合的大小传入，超出大小则跳出循环，否则可能会出现问题
long long getPrimeSum(int n, int size)
{
	long long sum = 0;
	int i = 0;
	while (primeList[i] <= n && i < size)
	{
		sum += primeList[i];
		i += 1;
	}
	return sum;
}

int main(void)
{
	long long n = 0;
	cin >> n;
	int primeListSize = getPrime(n);
	cout << getPrimeSum(n, primeListSize) << endl;
	system("pause");
	return 0;
}