#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#define N 1002
#define INF 0x3FFFFFFF

using namespace std;

int MIN;
int d[N];
bool vis[N];
int G[N][N];
vector<int> pre[N];
vector<int> tempPath;
vector<int> resPath[N];

void DFS(int v, const int st)
{
	static int p;
	if (v == st)
	{
		tempPath.push_back(v);
		resPath[p++] = tempPath;
		tempPath.pop_back();
		return;
	}
	else
	{
		tempPath.push_back(v);
		for (int i = 0; i < pre[v].size(); i++)
		{
			DFS(pre[v][i], st);
		}
		tempPath.pop_back();
	}
}

void Dijkstra(int s, int n)
{
	for (int i = 0; i < n; i++)
	{
		int u = -1; MIN = INF;
		for (int j = 0; j < n; j++)
		{
			if (!vis[j] && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++)
		{
			if (d[u] + G[u][v] < d[v])
			{
				pre[v].clear();
				pre[v].push_back(u);
				d[v] = d[u] + G[u][v];
			}
			else if (d[u] + G[u][v] == d[v])
			{
				pre[v].push_back(u);
			}
		}
		
	}
	return;
}

int main(int argc, char** argv)
{


	return 0;
}