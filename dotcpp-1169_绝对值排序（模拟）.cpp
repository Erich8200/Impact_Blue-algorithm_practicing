#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

#define N 67

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}

int main(int argc, char** argv)
{
	int n = 0;
	while (cin >> n)
	{
		if (n == 0)
			break;

		int temp = 0;
		vector< pair<int, int> > numMap;

		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			numMap.push_back(pair<int, int>(temp, abs(temp)));
		}

		sort(numMap.begin(), numMap.end(), cmp);

		for (vector< pair<int, int> >::iterator it = numMap.begin(); it < numMap.end(); it++)
			cout << it->first << " ";

		cout << endl;
	}
	system("pause");
	return 0;
}