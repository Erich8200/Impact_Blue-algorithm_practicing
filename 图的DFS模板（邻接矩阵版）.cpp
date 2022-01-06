#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define N 1000

using namespace std;

bool visited[N] = { false };

int G[N][N] = { 0 };

void initG()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			G[i][j] = INT_MAX;
}

void DFS(int u, int vNum, int cur)
{
	visited[u] = true;
	cout << u << endl;
	for (int v = 0; v < vNum; v++)
	{
		if (visited[v] == false && G[u][v] != INT_MAX)
		{
			DFS(v,vNum ,cur + 1);
		}
	}
}

//必须将顶点的个数作为参数传入
void DFSTraverse(int vNum)
{
	for (int u = 0; u < vNum; u++)
		if (visited[u] == false)
			DFS(u, vNum, 1);
}

int main(int argc, char** argv)
{
	initG();

	G[0][1] = G[1][0] = 2;
	G[0][4] = G[4][0] = 1;
	G[1][0] = G[0][1] = G[1][2] = G[2][1] = G[1][4] = G[4][1] = 2;
	G[2][1] = G[1][2] = 2;
	G[2][3] = G[3][2] = 1;
	G[3][2] = G[2][3] = G[3][4] = G[4][3] = 1;
	G[4][0] = G[0][4] = G[4][3] = G[3][4] = 1;
	G[4][1] = 2;

	DFSTraverse(5);

	getchar();

	return 0;
}