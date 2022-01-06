#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define N 1000

using namespace std;

class Node{
public:
	int v,w;
	Node(int vertex,int weigh):v(vertex),w(weigh){	}
};

bool inq[N] = {false};
vector<Node> G[N];
int d[N];

void init(int s)
{
	for(int i = 0;i < N;i++)
		d[i] = INT_MAX;
	d[s] = 0;
}

void SPFA(int s)
{
	init(s);
	queue<int> q;
	q.push(s);
	inq[s] = true;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = false;
		for(int j = 0;j < G[u].size();j++)
		{
			int v = G[u][j].v;
			int dis = G[u][j].w;
			if(d[u] + dis < d[v])
			{
				d[v] = d[u] + dis;
				if(!inq[v])
				{
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
}

int main(){
 	
	int n = 0,m = 0;
	cin >> n >> m;
	int u = 0,v = 0,l = 0;
	for(int i = 1;i <= m;i++)
	{
		cin >> u >> v >> l;
		G[u].push_back(Node(v,l));
		//G[v].push_back(Node(u,l));
	}
	
	SPFA(1);
	
	for(int j = 2;j <= n;j++)
		cout << d[j] << endl;
		
	return 0;
} 
