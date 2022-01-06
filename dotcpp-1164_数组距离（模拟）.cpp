#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <math.h>
#include <stdio.h>

#define N 1000

using namespace std;

vector<int> f, g, minDist;

int dist(const int m, const int n)
{
	int distArr = 0;
	int minF = f[0], maxF = f[f.size() - 1], minG = g[0], maxG = g[g.size() - 1];
	if (maxF <= minG)
		distArr = minG - maxF;
	else if (minF >= maxG)
		distArr = minF - maxG;
	else
	{
		for (int i = 0; i < m; i++)
		{
			vector<int> eachMinDist;
			for (int j = 0; j < n; j++)
				eachMinDist.push_back(abs(f[i] - g[j]));
			minDist.push_back(*min_element(eachMinDist.begin(), eachMinDist.end()));
		}
		distArr = *min_element(minDist.begin(), minDist.end());
	}

	return distArr;
}

int main(int argc, char** argv)
{
	int m, n, temp;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		f.push_back(temp);
	}
	for (int j = 0; j < n; j++)
	{
		cin >> temp;
		g.push_back(temp);
	}
	cout << dist(m, n) << endl;
	//system("pause");
	return 0;
}
