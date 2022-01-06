#include <iostream>
#include <queue>
#define N 1000

using namespace std;

int G[N][N];
bool visited[N] = {false};
bool inq[N] = {false};
bool Hash[N] = {false};//结点编号哈希表

//n是最大结点编号 
void BFS(int u,int n)
{
	queue<int> q;
	inq[u] = true;
	visited[u] = true;
	q.push(u);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int v = 1;v < n;v++)
		{
			if(G[u][v] != INT_MAX && !visited[v])
				visited[v] = true;
			if(G[u][v] != INT_MAX && !inq[v])
			{
				q.push(v);
				inq[v] = true;
			}
		}
	}
}

//初始化图，将所有结点间的连通性置否
void initG()
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			G[i][j] = INT_MAX;
}

void clearArray(int a[])
{
	for(int i = 0;i < N;i++)
		a[i] = 0;
}

void clearArray(bool a[])
{
	for(int i = 0;i < N;i++)
		a[i] = false;
}

//查找最大结点的编号，依题意，需要计算
int maxVNum()
{
	int max;
	for(max = N;max >= 0;max--)
	{
		if(Hash[max])
			break;
	}
	return max;
}

bool checkCG(int n)
{
	for(int i = 0;i < n;i++)
	{
		if(Hash[i])
		{
			if(!visited[i])
				return false;
		}
	}
	return true;
}

int main(int argc, char** argv)
{
	int m,n,x,y,max;
	m = n = x = y = max = 0;
	
	do{
		initG();
		clearArray(inq);
		clearArray(visited);
		clearArray(Hash);
		
		cin >> n >> m;
		
		for(int i = 0;i < m;i++)
		{
			cin >> x >> y;
			G[x][y] = G[y][x] = 1;
			Hash[x] = Hash[y] = true;
		}
		if(m == 0) break;
		
		max = maxVNum();
	
		BFS(1,max);
	
		if(checkCG(max))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;			
	}while(true);
	
	return 0;
}
