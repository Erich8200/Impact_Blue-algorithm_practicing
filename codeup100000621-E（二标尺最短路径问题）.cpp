#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip> //C++输出格式控制 

#define N 1002
#define INF 0x3FFFFFFF

using namespace std;

int MIN;
bool vis[N] = { false };
int d[N];
int p[N];
int G[N][N];
int C[N][N];

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
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 1;v <=n;v++)
		{
			if(!vis[v] && G[u][v] != INF)
			{
				if(G[u][v] + d[u] < d[v])
				{
					d[v] = G[u][v] + d[u];
					p[v] = C[u][v] + p[u];
				}
				else if(G[u][v] + d[u] == d[v] && C[u][v] + p[u] < p[v])
				{
					p[v] = C[u][v] + p[u];
				}
			}
		}
	}
	return;
}

int main(int argc, char** argv)
{
	initG();
	int n = 0,m = 0,s = 0,t = 0;
	cin >> n >> m;
	for(int i = 0;i < m;i++)
	{
		int a,b,d,p;
		cin >>a >> b >> d >> p;
		G[a][b] = G[b][a] = d;
		C[a][b] = C[b][a] = p;
	}
	cin >> s >> t;
	
	Dijkstra(s,n);
	
	cout << d[t] << " " << p[t];
	
	return 0;
}

