#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

using namespace std;

bool a[MAX][MAX];

void taint(int x1, int y1, int x2, int y2)
{
	for (int i = y1; i < y2; i++)
		for (int j = x1; j < x2; j++)
			a[i][j] = true;
}

int main(void)
{
	freopen("0.txt", "r", stdin);
	int n = 0;
	cin >> n;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		taint(x1, y1, x2, y2);
		if (x1 > max) max = x1;
		if (x2 > max) max = x2;
		if (y1 > max) max = y1;
		if (y2 > max) max = y2;
	}

	int count = 0;

	for (int i = 0; i <= max; i++)
		for (int j = 0; j <= max; j++)
			if (a[i][j])
				count += 1;

	cout << count << endl;
	fclose(stdin);
	return 0;
}