#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

vector<int> a;

int solve(int n)
{
	int times = n - 1;
	int ans = 0;
	while (times--)
	{
		vector<int> b;
		for (int i = 0; i < a.size() - 1; i++)
			b.push_back(a[i] + a[i + 1]);
		int minIndex = 0, min = b[0];
		for (int i = 0; i < b.size(); i++)
		{
			if (min > b[i])
			{
				min = b[i];
				minIndex = i;
			}
		}
		ans += b[minIndex];
		a[minIndex + 1] = b[minIndex];
		a.erase(a.begin() + minIndex);
	}
	return ans;
}

int main()
{
	freopen("input2.txt", "r", stdin);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		a.push_back(temp);
	}
	cout << solve(n) << endl;
	fclose(stdin);
	return 0;
}