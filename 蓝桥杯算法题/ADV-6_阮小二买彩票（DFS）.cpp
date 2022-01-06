#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stdio.h>
#include <cctype>

#define N 6

using namespace std;

vector<int> numArr;
set< vector<int> > permutations;//使用set，排序、唯一性判断都免了
bool vis[N + 2];

bool cmp(int a, int b)
{
	return a < b;
}

void getNumArr(int n)
{
	while (n > 0)
	{
		numArr.push_back(n % 10);
		n /= 10;
	}
	sort(numArr.begin(), numArr.end(), cmp);
}

void DFS(int cur, const int n, vector<int>& curPermutation)
{
	if (cur >= n)
	{
		permutations.insert(curPermutation);
		return;
	}
	else
	{
		for (int i = 0; i < numArr.size(); i++)
		{
			if (!vis[i])
			{
				curPermutation.push_back(numArr[i]);
				vis[i] = true;
				DFS(cur + 1, n, curPermutation);
				vis[i] = false;
				curPermutation.pop_back();
				
			}
		}
		return;
	}
}

int main(int argc, char** argv)
{
	int n = 0;
	cin >> n;
	getNumArr(n);
	vector<int> permutation;
	DFS(0, numArr.size(), permutation);
	for (set< vector<int> >::iterator i = permutations.begin(); i != permutations.end(); i++)
	{
		for (int j = 0; j < i->size(); j++)
		{
			cout << (*i)[j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}