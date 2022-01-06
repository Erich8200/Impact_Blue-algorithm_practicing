#include <iostream>
#include <string>
#include <list>
#include <math.h>
#include <algorithm>
#include <sstream>

using namespace std;

int factor(int n)
{
	int ans = 1;
	if (n == 0)
		ans = 1;
	else
	{
		for (int i = 1; i <= n; i++)
			ans *= i;
	}
	return ans;
}

int C(int n, int k)
{
	return factor(n)/(factor(k)*factor(n - k));
}

int main(int argv, char** argc)
{
	int n = 0;

	while (cin >> n)
	{
		if (n == 0)
			break;

		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j == 0)
				{
					for (int k = 1; k <= 3 * (n - i - 1); k++)
						cout << " ";
				}
				cout << C(i, j);
				if (j != i)
					cout << "     ";
			}
			cout << endl;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
