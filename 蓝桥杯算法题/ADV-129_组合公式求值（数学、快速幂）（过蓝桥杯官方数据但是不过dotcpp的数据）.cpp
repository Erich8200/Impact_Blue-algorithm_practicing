#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#define N 10000

using namespace std;

bool checkFact[N];
double factResult[N];

double fact(double n)
{
	double ans = 1;
	if (checkFact[(int)n])
		ans = factResult[(int)n];
	else
	{
		for (double i = 1; i <= n; i += 1)
			ans *= i;
		checkFact[(int)n] = true;
		factResult[(int)n] = ans;
	}
	return ans;
}

double C(double n, double m)
{
	double nFact = fact(n), mFact = fact(m), nmFact = fact(n - m);
	return nFact/(nmFact*mFact);
}

double F(double n, double m)
{
	double ans = 0;
	for (double i = 0; i <= n; i += 1)
	{
		double a = C(n, m);
		double b = C(n, i);
		ans += C(n, m)*C(n, i)*i*i*i;
	}
	return ans;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	printf("%.0lf", F(n, m)%987654321);
	return 0;
}
