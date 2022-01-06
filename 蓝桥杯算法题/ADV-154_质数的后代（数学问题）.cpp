#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> primeList;

bool isPrimeFast(int n)
{
	for (int i = 0; primeList[i] <= n; i++)
		if (n == primeList[i])
			return true;
	return false;
}

bool isPrime(const int n)
{
	bool ret = true;
	for (int i = 2; i*i <= n; i++)
		if (n%i == 0)
			ret = false;
	return ret;
}

void getPrime(int n)
{
	for (int i = primeList.size() == 0 ? 2 : *(--primeList.end()); i <= n; i++)
		if (isPrime(i))
			primeList.push_back(i);
}

bool checkOffspring(int n)
{
	bool ret = false;
	for (int i = 0; primeList[i]*primeList[i] <= n; i++)
	{
		int curPrime = primeList[i];
		if (n % curPrime == 0)
		{
			int res = n / curPrime;
			if (isPrimeFast(res))
			{
				ret = true;
				break;
			}
		}
	}
	return ret;
}

int main(int argc, char** argv)
{
	freopen("input10.txt", "r", stdin);
	int T = 0;
	cin >> T;
	int maxNum = 0;
	while (T--)
	{
		int num = 0;
		cin >> num;
		if (num > maxNum)
		{
			maxNum = num;
			getPrime(num);
		}
		if (checkOffspring(num))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	fclose(stdin);
	system("pause");
	return 0;
}