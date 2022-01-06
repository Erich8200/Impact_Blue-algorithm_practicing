#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#define N 10000

using namespace std;

int request[N];//申请的资源数
int allocated[N];//已分配的资源数
int need[N];//还需要的资源数
int sum;//资源总数

//找到就绪任务，并按照贪心法选择，返回作业的索引
int getReadyJob(int n)
{
	int maxAllocated = 0;
	int index = -1;
	for (int i = 0; i < n; i++)
	{
		if (sum >= need[i] && request[i] > 0)
		{
			//贪心，选择已分配最多的，这样完成后就能收回最多
			if (maxAllocated < allocated[i])
			{
				maxAllocated = allocated[i];
				index = i;
			}
		}
	}
	return index;
}

//刷新所有有作业的need数组
void refreshNeed(int n)
{
	for (int i = 0; i < n; i++)
		if (request[i])
			need[i] = request[i] > allocated[i] ? (request[i] - allocated[i]) : 0;
}

//完成当前作业并回收资源
void finishJob(int i)
{
	sum += allocated[i];
	request[i] = 0;
	allocated[i] = 0;
	need[i] = 0;
}

bool solve(int n)
{
	bool ans = true;
	refreshNeed(n);
	//如果所有作业都可以完成可以，那么每次都会完成一个作业
	for (int time = 1; time <= n; time++)
	{
		int j;
		//返回值是-1说明不能找不到可以继续完成的作业，退出
		if ((j = getReadyJob(n)) >= 0)
		{
			finishJob(j);
			refreshNeed(n);
		}
		else
		{
			ans = false;
			break;
		}
	}
	return ans;
}

int main(int argc, char** argv)
{
	freopen("input5.txt", "r", stdin);
	int m = 0;
	cin >> m;
	while (m--)
	{
		int n = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> allocated[i];
			cin >> request[i];
		}
		if (solve(n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		memset(allocated, 0x00, sizeof(allocated));
		memset(request, 0x00, sizeof(request));
		memset(need, 0x00, sizeof(need));
		sum = 0;
	}
	fclose(stdin);
	return 0;
}