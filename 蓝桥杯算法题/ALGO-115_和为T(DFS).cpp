#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include "main.h"

#define N 22

using namespace std;

vector< vector<int> > solutionSet;
int num[N+2];
int ansCount;

void DFS(int curPos, int curSum, const int T, const int n, vector<int>& solution)
{
	if (curSum == T)
	{
		solutionSet.push_back(solution);
		return;
	}
	else if (curPos >= n)
		return;
	else
	{
		solution.push_back(num[curPos]);
		DFS(curPos + 1, curSum + num[curPos], T, n, solution);
		solution.pop_back();
		DFS(curPos + 1, curSum, T, n, solution);
	}
}

//修正的DFS算法，防止出现要求T为0，与初始状态一致，因而一个数都不选就退出的情况
void _DFS(const int T, const int n)
{
	for (int i = 0; i < n; i++)
	{
		vector<int> solution;
		solution.push_back(num[i]);//先向方案vector中预先放置这次的数
		DFS(i + 1, num[i], T, n, solution);//从下一个数开始执行DFS算法
	}
}

int main(int argc, char** argv)
{
	freopen("test.txt", "r", stdin);

	int n,T;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	cin >> T;

	if (T)
	{
		vector<int> solution;
		DFS(0, 0, T, n, solution);
	}
	else
		_DFS(T, n);

	for (int i = 0; i < solutionSet.size(); i++)
	{
		for (int j = 0;j < solutionSet[i].size();j++)
		{
			cout << solutionSet[i][j] << " ";
		}
		cout << endl;
	}
	cout << solutionSet.size();

	fclose(stdin);
	return 0;
}
