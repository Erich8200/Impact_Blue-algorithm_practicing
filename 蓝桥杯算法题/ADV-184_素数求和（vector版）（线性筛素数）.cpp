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

//����ɸ����
void getPrime(long long n)
{
	for (long long i = 2; i <= n; i++)
	{
		//�����֮ǰ�ͱ���ǵ�����˵������������ôֱ�ӷ�����������
		if (primeCheck[i] == 0)
			primeList.push_back(i);
		//ɸȥ���������������͵�ǰ���ĳ˻����ɵ�����ע��������ֹ����Ӧ�����ϵȺţ�����n���ܲ��ᱻɸ��
		for (long long j = 0; j < primeList.size() && i*primeList[j] <= n; j++)
		{
			primeCheck[i*primeList[j]] = 1;
			//���ظ�ɸȥ����С����
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