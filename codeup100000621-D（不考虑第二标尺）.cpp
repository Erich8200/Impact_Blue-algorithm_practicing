#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define N 1002
#define INF 0x3FFFFFFF

using namespace std;

int MIN;
bool vis[N] = { false };
int d[N];
int G[N][N];
int path[N];

void initG()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			G[i][j] = INF;
	}
}

void init(int s)
{
	for (int i = 0; i < N; i++)
	{
		d[i] = INF;
		vis[i] = false;	
	}
	d[s] = 0;
}

void Dijkstra(int s,int n)
{
	init(s);
	for(int i = 0;i < n;i++)
	{
		int u = -1;MIN = INF;
		for(int j = 1;j <= n;j++)
		{
			if(!vis[j] && d[j] < MIN)
			{
				u = j; MIN = d[j];
			}
		}
		if(u == -1)	return;
		vis[u] = true;
		//cout << u << " ";
		path[i] = u;
		for(int v = 1;v <= n;v++)
		{
			if(!vis[v] && G[u][v]!= INF && d[u] + G[u][v] < d[v])
			{
				d[v] = d[u] + G[u][v];
			}
		}
	}
	return;
}

int main(int argc, char** argv)
{
	initG();
	int n = 0,m = 0,s = 0,t = 0;
	cin >> n >> m >> s >> t;
	for(int i = 0;i < m;i++)
	{
		int u = 0,v = 0,l = 0;
		cin >> u >> v >> l;
		G[u][v] = G[v][u] = l;
	}
	Dijkstra(s,n);
	if(d[t] == INF)
		cout << "can't arrive";
	else
	{
		cout << d[t] << endl;
		int i = 0;
		do
		{
			cout << path[i] << " ";
			i++;
		}while(path[i]);
	}		
	return 0;
}

