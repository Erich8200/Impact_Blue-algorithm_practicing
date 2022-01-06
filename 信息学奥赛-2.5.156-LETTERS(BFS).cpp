#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip> //C++输出格式控制 

#define N 22

using namespace std;

bool vis[26];
char G[N][N];
//{{'H','F','D','F','F','B'},{'A','J','H','G','D','H'},{'D','G','A','G','E','H'}};//测试用例
vector<int> totalCount;

//参数：起点x，起点y，访问的字母数，迷宫行数，迷宫列数
void DFS(int curX,int curY,int visCount,const int r,const int s)
{
	static bool isFirstTime = true;

	if (isFirstTime)
	{
		vis[G[curY][curX] - 'A'] = true;//将起点记为已访问
	}
	
	if(curY - 1 >= 0)
	{
		int tgt = G[curY - 1][curX] - 'A';
		if(!vis[tgt])
		{
			vis[tgt] = true;
			DFS(curX,curY-1,visCount+1,r,s);		
			vis[tgt] = false;//注意回溯
		}
	}
	
	if(curX + 1 <= s-1)
	{
		int tgt = G[curY][curX + 1] - 'A';
		if(!vis[tgt])
		{
			vis[tgt] = true;
			DFS(curX+1,curY,visCount+1,r,s);		
			vis[tgt] = false;//注意回溯
		}
	}
	
	if(curY + 1 <= r-1)
	{
		int tgt = G[curY + 1][curX] - 'A';
		if(!vis[tgt])
		{
			vis[tgt] = true;
			DFS(curX,curY+1,visCount+1,r,s);	
			vis[tgt] = false;//注意回溯
		}
	}
	
	if(curX - 1 >= 0)
	{
		int tgt = G[curY][curX - 1] - 'A';
		if(!vis[tgt])
		{
			vis[tgt] = true;
			DFS(curX-1,curY,visCount+1,r,s);
			vis[tgt] = false;//注意回溯
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

	DFS(0,0,1,r,s);//注意第三个参数访问的字母数从1开始计算，起点也算访问了一个字母

	int maxCount = 0;

	for (vector<int>::iterator it = totalCount.begin();it < totalCount.end();it++)//从结果vector中筛选最大的值作为解
	{
		if (*it > maxCount)
			maxCount = *it;
	}
		
	cout << maxCount;
	
	return 0;
}