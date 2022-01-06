#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <cctype>

#define N 24

using namespace std;

int weight[N + 2];
int obj[N + 2];
bool able[N + 2];

void DFS(int cur, int curWeight, const int tgtWeight, const int n, const int objNo)
{
	if (cur > n)
		return;
	else if (curWeight == tgtWeight)
	{
		able[objNo] = true;
		return;
	}
	else
	{
		//砝码和物品分开放
		DFS(cur + 1, curWeight + weight[cur], tgtWeight, n, objNo);
		//不放
		DFS(cur + 1, curWeight, tgtWeight, n, objNo);
		//砝码和物品放一起
		DFS(cur + 1, curWeight - weight[cur], tgtWeight, n, objNo);
	}
}

int main(int argc, char** argv)
{
	freopen("input1.txt", "r", stdin);
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> weight[i];
	for (int i = 0; i < m; i++)
		cin >> obj[i];
	for (int i = 0; i < m; i++)
		DFS(0, 0, obj[i], n, i);
	for (int i = 0; i < m; i++)
	{
		if (able[i] == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	//system("pause");
	fclose(stdin);
	return 0;
}