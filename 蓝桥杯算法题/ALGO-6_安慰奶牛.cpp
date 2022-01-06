#include <iostream>
#include <vector>
#include <algorithm>

#define N 10002
#define INF 0x3FFFFFFF

using namespace std;

int MIN, n;
bool vis[N] = { false };
int tTalk[N];
int d[N];
int G[N][N];

void initG()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			G[i][j] = INF;
	}
}

void init()
{
	for (int i = 0; i <= n; i++)
		d[i] = INF;
	d[1] = 0;
}

int Prim()
{
	int ans = 0;
	init();
	for (int i = 0; i < n; i++)
	{
		int u = -1; MIN = INF;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && d[j] + tTalk[j] < MIN)
			{
				u = j;
				MIN = d[j] + tTalk[j];
			}
		}

		if (u == -1) return -1;
		vis[u] = true;
		ans = d[u]  + tTalk[u];
		for (int v = 1; v <= n; v++)
		{
			if (d[v]  > tTalk[v] + G[u][v] && !vis[v] && G[u][v] != INF)
				d[v] = tTalk[v] + G[u][v];
		}
	}
	return ans;
}

int main(int argc, char** argv)
{
	int p = 0, i = 0, j = 0, t = 0;
	cin >> n >> p;
	cin.clear();
	cin.sync();	
	initG();
	for (i = 1; i <= n; i++)
		cin >> tTalk[i];
	cin.clear();
	cin.sync();	
	for (int time = 1; time <= p; time++)
	{
		t = 0;
		cin >> i >> j >> t;
		G[i][j] = G[j][i] = t;
	}

	int Ans = Prim();

	cout << Ans;

	return 0;
}
