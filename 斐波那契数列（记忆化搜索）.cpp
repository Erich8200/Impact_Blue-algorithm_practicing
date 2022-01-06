#include <iostream>
#include <string>
#include <list>
#include <math.h>
#include <algorithm>
#include <sstream>
#define N 100

using namespace std;

int a[N];

int f(int n)
{
	int ans = 0;
	if (n == 1 || n == 2)
		ans = 1;
	else if (a[n - 1] && a[n - 2])
	{
		ans = a[n - 1] + a[n - 2];
		a[n] = ans;
	}
	else
		ans = f(n - 1) + f(n - 2);
		
	return ans;
}

int main(int argv, char** argc)
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cout << f(i) << " ";
	system("pause");
	return 0;
}
