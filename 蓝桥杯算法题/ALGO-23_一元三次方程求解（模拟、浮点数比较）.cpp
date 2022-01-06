#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <math.h>

#define EPS 0.000001

using namespace std;

int main()
{
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	double x = -100;
	int rootCount = 0;
	while (x <= 100)
	{
		if (rootCount == 3)
		{
			printf("\n");
			break;
		}
		if (fabs(a*x*x*x + b * x*x + c * x + d) < EPS)
		{
			printf("%.2lf ", x);
			rootCount += 1;
		}
		x = x + 0.01;
	}
	system("pause");
	return 0;
}