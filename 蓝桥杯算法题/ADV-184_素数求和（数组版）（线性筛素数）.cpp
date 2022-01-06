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

//����ɸ����������������������������һ������һ�������ĳ˻���ʾ
int getPrime(long long n)
{
	int pos = 0;
	for (long long i = 2; i <= n; i++)
	{
		//�����֮ǰ�ͱ���ǵ�����˵������������ôֱ�ӷ�����������
		if (primeCheck[i] == 0)
			primeList[pos++] = i;
		//ɸȥ���������������͵�ǰ���ĳ˻����ɵ�����ע��������ֹ����Ӧ�����ϵȺţ�����n���ܲ��ᱻɸ��
		for (long long j = 0; j < pos && (long long)i*primeList[j] <= n; j++)
		{
			primeCheck[i*primeList[j]] = 1;
			//���ظ�ɸȥ����С����
			if (i%primeList[j] == 0)
				break;
		}
	}
	return pos;//���������б��ϵĴ�С
}

//��Ҫ���������ϵĴ�С���룬������С������ѭ����������ܻ��������
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