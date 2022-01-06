#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <stdio.h>

#define N 100

using namespace std;

vector< pair<string, int> > testRec[N + 2];
vector<int> ranks;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	if (a.second > b.second)
		return true;
	else if (a.second == b.second)//二级判断指标
		if (a.first == "DaDa")
			return true;
	return false;
}

int getRank(const vector< pair<string, int> >& test)
{
	for (int i = 0; i < test.size(); i++)
	{
		if (test[i].first == "DaDa")
			return (i + 1);
	}
}

void getRanks(const int m)
{
	for (int i = 0; i < m; i++)
	{
		sort(testRec[i].begin(), testRec[i].end(), cmp);
		int rank = getRank(testRec[i]);
		ranks.push_back(rank);//虽然这里就可以输出了，但是我并不像这么做
	}
}

int main(int argc, char** argv)
{
	int n = 0,m = 0;
	string junk[N+2];

	//freopen("test.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> junk[i];
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			string p;
			int s;
			cin >> s >> p;
			pair<string, int> temp(p, s);
			testRec[i].push_back(temp);
		}
	}

	getRanks(m);

	for (vector<int>::iterator it = ranks.begin(); it < ranks.end(); it++)
		cout << *it << endl;

	//fclose(stdin);

	system("pause");
	return 0;
}
