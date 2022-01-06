#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <stdio.h>
#define N 40

using namespace std;

bool map[N + 2];

void DFS(int curIndex, const int n, int & count)
{
	if (curIndex == n)
	{
		count += 1;
		return;
	}
	else if(curIndex > n)
		return;
	else
	{
		if (map[curIndex + 1])
			DFS(curIndex + 1, n, count);
		if (map[curIndex + 2])
			DFS(curIndex + 2, n, count);
	}
}

int main(int argc, char** argv)
{
	int m, n;
	cin >> n >> m;
	int count = 0;
	for (int i = 0; i < N; i++)
		map[i] = true;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		map[a] = false;
	}
	DFS(1, n, count);
	cout << count << endl;
	return 0;
}