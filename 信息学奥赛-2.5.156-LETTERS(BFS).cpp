#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip> //C++�����ʽ���� 

#define N 22

using namespace std;

bool vis[26];
char G[N][N];
//{{'H','F','D','F','F','B'},{'A','J','H','G','D','H'},{'D','G','A','G','E','H'}};//��������
vector<int> totalCount;

//���������x�����y�����ʵ���ĸ�����Թ��������Թ�����
void DFS(int curX,int curY,int visCount,const int r,const int s)
{
	static bool isFirstTime = true;

	if (isFirstTime)
	{
		vis[G[curY][curX] - 'A'] = true;//������Ϊ�ѷ���
	}
	
	if(curY - 1 >= 0)
	{
		int tgt = G[curY - 1][curX] - 'A';
		if(!vis[tgt])
		{
			vis[tgt] = true;
			DFS(curX,curY-1,visCount+1,r,s);		
			vis[tgt] = false;//ע�����
		}
	}
	
	if(curX + 1 <= s-1)
	{
		int tgt = G[curY][curX + 1] - 'A';
		if(!vis[tgt])
		{
			vis[tgt] = true;
			DFS(curX+1,curY,visCount+1,r,s);		
			vis[tgt] = false;//ע�����
		}
	}
	
	if(curY + 1 <= r-1)
	{
		int tgt = G[curY + 1][curX] - 'A';
		if(!vis[tgt])
		{
			vis[tgt] = true;
			DFS(curX,curY+1,visCount+1,r,s);	
			vis[tgt] = false;//ע�����
		}
	}
	
	if(curX - 1 >= 0)
	{
		int tgt = G[curY][curX - 1] - 'A';
		if(!vis[tgt])
		{
			vis[tgt] = true;
			DFS(curX-1,curY,visCount+1,r,s);
			vis[tgt] = false;//ע�����
		}
	}
	
	totalCount.push_back(visCount);
	return;
}

int main(int argc, char** argv)
{
	int r, s;
	cin >> r >> s;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cin >> G[i][j];
		}
	}

	DFS(0,0,1,r,s);//ע��������������ʵ���ĸ����1��ʼ���㣬���Ҳ�������һ����ĸ

	int maxCount = 0;

	for (vector<int>::iterator it = totalCount.begin();it < totalCount.end();it++)//�ӽ��vector��ɸѡ����ֵ��Ϊ��
	{
		if (*it > maxCount)
			maxCount = *it;
	}
		
	cout << maxCount;
	
	return 0;
}