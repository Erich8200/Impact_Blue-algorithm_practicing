#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#define N 30

using namespace std;

int factors_raw[] = { 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
int factors[N];
vector<int> numArr;

int main(int argc, char** argv)
{
	for (int i = 0; i < sizeof(factors_raw)/sizeof(int); i++)
		factors[factors_raw[i]] = factors_raw[i];
	int a, b, c;
	cin >> a >> b >> c;
	//不都是素数
	while (factors[a] == 0 || factors[b] == 0 || factors[c] == 0)
	{
		for (int i = 2; i <= max(max(a, b),max(b, c)); i++)
		{
			bool okPrime = false;
			if (factors[i] != 0)
			{
				if (a%i == 0)
				{
					a /= i;
					okPrime = true;
				}
				if (b%i == 0)
				{
					b /= i;
					okPrime = true;
				}
				if (c%i == 0)
				{
					c /= i;
					okPrime = true;
				}

				if (okPrime)
				{
					numArr.push_back(i);
				}
			}
		}
	}

	int product = a*b*c;
	for (vector<int>::iterator it = numArr.begin(); it < numArr.end(); it++)
	{
		product *= *it;
	}
	cout << product << endl;
	
	system("pause");
	return 0;
}