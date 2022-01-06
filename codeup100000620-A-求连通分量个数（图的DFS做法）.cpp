#include <iostream>
#define N 1000

using namespace std;

int G[N][N];
bool visited[N] = {false};
bool Hash[N] = {false};//����Ź�ϣ��
int n;

void DFS(int u,int cur,int& depth)
{
	visited[u] = true;
	//ͳ�Ʋ�����������У����depthС�ڵ�ǰ�ݹ�������򽫼����Ա���depth��Ϊ�ݹ����
	if(depth < cur)
	depth = cur;
	for(int v = 1;v <= n;v++){
		if(G[u][v] != INT_MAX && !visited[v]){
			DFS(v,cur + 1,depth);
		}
		else if((u == v && G[u][v] != INT_MAX && visited[v]))//�������ۻ��������ע�ⲻ�ܽ���ݹ飬������������ݹ�
			depth += 1;
	}
}

int DFSTraverse(int n){
	//count����ͬͼ��������depth�Ǳ���ÿ����ͬ�����Ĳ���
	int depth = 0,count = 0;
	for(int u = 1;u <= n;u++){
		if(!visited[u]){
			DFS(u,0,depth);
			//�������Ϊ0�����ǹ�����
			if(depth > 0)
				count += 1;
			depth = 0;
		}
	}
	return count;
}

//��ʼ��ͼ�������н������ͨ���÷�
void initG()
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			G[i][j] = INT_MAX;
}

//���������ı�ţ������⣬��Ҫ����
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
		//���ⲻ�壬�Զ�������0�����˳�������ͼ������±��1��ʼ��������0 
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

	n = maxVNum();//���������ı��

	cout << DFSTraverse(n) << endl;

	return 0;
}
