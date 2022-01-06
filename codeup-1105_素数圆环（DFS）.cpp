#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define N 20

using namespace std;

bool vis[N + 2];
vector< vector<int> > rings;

bool isPrime(const int n)
{
	bool ret = true;
	if (n == 1)
	{
		ret = false;
	}
	else
	{
		for (int i = 2; i*i <= n; i++)
		{
			if (n%i == 0)
				ret = false;
		}
	}
	return ret;
}

void DFS(int curNum, vector<int> ring, const int maxNum)
{
	if (ring.size() == maxNum)
	{
		rings.push_back(ring);
		return;
	}
	
	//////////按照题目要求，只需要1开头的，剪枝，如果要求所有排列，则这里省略
	if (!ring.empty())
	{
		if (ring[0] > 1)
		{
			return;
		}
	}
	/////////////////////////////////////////////////////////////////////////

	//else
	//{
	for (int i = 1; i <= maxNum; i++)
	{
		if (!vis[i])
		{
			if (!ring.empty())//当前环非空，取出前驱数字，符合题目条件则进入下一次递归
			{
				if (isPrime(ring.at(ring.size()-1) + i))
				{
					vis[i] = true;
					ring.push_back(i);
					DFS(i, ring, maxNum);
					ring.pop_back();
					vis[i] = false;
				}
			}
			else//环空直接将当前数字放入
			{
				vis[i] = true;
				ring.push_back(i);
				DFS(i, ring, maxNum);
				ring.pop_back();
				vis[i] = false;
			}
		}
	}
	//}
	return;
}

int main(int argc, char** argv)
{
	vector<int> ring;
	int n;
	cin >> n;
	DFS(0, ring, n);//以非法值0开头
	for (int i = 0; i < rings.size(); i++)
	{
		//最后一个数和第一个数是否组成素数，之前实在不好判断，这里过滤
		if (isPrime(rings[i][rings[i].size()-1] + rings[i][0]))
		{
			for (int j = 0; j < rings[i].size(); j++)
			{
				if (j == rings[i].size() - 1)
					cout << rings[i][j];
				else
					cout << rings[i][j] << " ";
			}	
			cout << endl;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}