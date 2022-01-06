#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip> //C++输出格式控制 

#define N 102
#define INF 0x3FFFFFFF

using namespace std;

int MIN;
bool vis[N] = { false };
double d[N];
double G[N][N];
int data[N][7];
vector<double> Ans;//答案动态，最后从中选择最短路径 

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
		for(int v = 1;v <= n;v++)
		{
			if(!vis[v] && G[u][v] != INF && G[u][v] + d[u] < d[v])
			{
				d[v] = G[u][v] + d[u];
			}
		}
	}
	return;
}

int main(int argc, char** argv)
{
	initG();
	int S,T,A,B;
	cin >> S >> T >> A >> B;
	int x1,y1,x2,y2,x3,y3,t;
	
	for(int i = 0;i < S;i++)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> t;
		if(i > 0)
		{
			//临时变量，前一组数据 
			int preX1 = data[i-1][1],preY1 = data[i-1][2],preX2 = data[i-1][3],preY2 = data[i-1][4],preX3 = data[i-1][5],preY3 = data[i-1][6],preT = data[i-1][7];
			//当前第1个点分别到上一组第1,2,3个点的花费 
			G[i*3 + 1][(i-1)*3 + 1] = G[(i-1)*3 + 1][i*3 + 1] = T*sqrt((x1-preX1)*(x1-preX1) + (y1-preY1)*(y1-preY1));
			G[i*3 + 1][(i-1)*3 + 2] = G[(i-1)*3 + 2][i*3 + 1] = T*sqrt((x1-preX2)*(x1-preX2) + (y1-preY2)*(y1-preY2));
			G[i*3 + 1][(i-1)*3 + 3] = G[(i-1)*3 + 3][i*3 + 1] = T*sqrt((x1-preX3)*(x1-preX3) + (y1-preY3)*(y1-preY3));
			//当前第2个点分别到上一组第1,2,3个点的花费 
			G[i*3 + 2][(i-1)*3 + 1] = G[(i-1)*3 + 1][i*3 + 2] = T*sqrt((x2-preX1)*(x2-preX1) + (y2-preY1)*(y2-preY1));
			G[i*3 + 2][(i-1)*3 + 2] = G[(i-1)*3 + 2][i*3 + 2] = T*sqrt((x2-preX2)*(x2-preX2) + (y2-preY2)*(y2-preY2));
			G[i*3 + 2][(i-1)*3 + 3] = G[(i-1)*3 + 3][i*3 + 2] = T*sqrt((x2-preX3)*(x2-preX3) + (y2-preY3)*(y2-preY3));
			//当前第3个点分别到上一组第1,2,3个点的花费 
			G[i*3 + 3][(i-1)*3 + 1] = G[(i-1)*3 + 1][i*3 + 3] = T*sqrt((x3-preX1)*(x3-preX1) + (y3-preY1)*(y3-preY1));
			G[i*3 + 3][(i-1)*3 + 2] = G[(i-1)*3 + 2][i*3 + 3] = T*sqrt((x3-preX2)*(x3-preX2) + (y3-preY2)*(y3-preY2));
			G[i*3 + 3][(i-1)*3 + 3] = G[(i-1)*3 + 3][i*3 + 3] = T*sqrt((x3-preX3)*(x3-preX3) + (y3-preY3)*(y3-preY3));
		}
		//当前第1个点到第2个点的花费 
		G[i*3 + 1][i*3 + 2] = G[i*3 + 2][i*3 + 1] = t*sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		//当前第2个点到第3个点的花费 
		G[i*3 + 2][i*3 + 3] = G[i*3 + 3][i*3 + 2] = t*sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
		//当前第3个点到第1个点的花费 
		G[i*3 + 3][i*3 + 1] = G[i*3 + 1][i*3 + 3] = t*sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
		data[i][1] = x1; data[i][2] = y1; data[i][3] = x2; data[i][4] = y2; data[i][5] = x3; data[i][6] = y3; data[i][7] = t;
	}
	
	Dijkstra((A-1)*3 + 1,S*3);
	for(int j = 1,tgt = (B-1)*3;j <= 3;j++)
	{
		//cout << d[tgt + j] << " ";
		Ans.push_back(d[tgt + j]);
	}
	
	Dijkstra((A-1)*3 + 2,S*3);
	for(int j = 1,tgt = (B-1)*3;j <= 3;j++)
	{
		//cout << d[tgt + j] << " ";
		Ans.push_back(d[tgt + j]);
	}
	
	Dijkstra((A-1)*3 + 3,S*3);
	for(int j = 1,tgt = (B-1)*3;j <= 3;j++)
	{
		//cout << setprecision(2) << fixed << d[tgt + j] << " ";
		Ans.push_back(d[tgt + j]);
	}
	
	cout << setprecision(2) << fixed << *min_element(Ans.begin(),Ans.end());
	
	return 0;
}

