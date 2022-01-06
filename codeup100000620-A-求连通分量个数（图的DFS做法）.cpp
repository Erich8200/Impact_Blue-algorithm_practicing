#include <iostream>
#define N 1000

using namespace std;

int G[N][N];
bool visited[N] = {false};
bool Hash[N] = {false};//结点编号哈希表
int n;

void DFS(int u,int cur,int& depth)
{
	visited[u] = true;
	//统计操作在这里进行，如果depth小于当前递归层数，则将记忆性变量depth置为递归层数
	if(depth < cur)
	depth = cur;
	for(int v = 1;v <= n;v++){
		if(G[u][v] != INT_MAX && !visited[v]){
			DFS(v,cur + 1,depth);
		}
		else if((u == v && G[u][v] != INT_MAX && visited[v]))//单独讨论环的情况，注意不能进入递归，否则会造成无穷递归
			depth += 1;
	}
}

int DFSTraverse(int n){
	//count是连同图的总数，depth是遍历每个连同分量的层数
	int depth = 0,count = 0;
	for(int u = 1;u <= n;u++){
		if(!visited[u]){
			DFS(u,0,depth);
			//如果层数为0，则是孤立点
			if(depth > 0)
				count += 1;
			depth = 0;
		}
	}
	return count;
}

//初始化图，将所有结点间的连通性置否
void initG()
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			G[i][j] = INT_MAX;
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

int main(int argc, char** argv)
{
	initG();

	int i = 0,j = 0;
	while(true)
	{
		int i = 0,j = 0;
		cin >> i >> j;
		//题意不清，自定义输入0代表退出，所以图数组的下标从1开始，而不是0 
		if(i == 0)
			break;
		else 
		{
			G[i][j] = G[j][i] = 1;
			if(!Hash[i]){
				Hash[i] = true;
			}
			if(!Hash[j]){
				Hash[j] = true;
			}
		}
	}

	n = maxVNum();//查找最大结点的编号

	cout << DFSTraverse(n) << endl;

	return 0;
}
