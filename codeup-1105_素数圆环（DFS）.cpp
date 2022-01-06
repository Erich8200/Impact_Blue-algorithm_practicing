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
	
	//////////������ĿҪ��ֻ��Ҫ1��ͷ�ģ���֦�����Ҫ���������У�������ʡ��
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
			if (!ring.empty())//��ǰ���ǿգ�ȡ��ǰ�����֣�������Ŀ�����������һ�εݹ�
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
			else//����ֱ�ӽ���ǰ���ַ���
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
	DFS(0, ring, n);//�ԷǷ�ֵ0��ͷ
	for (int i = 0; i < rings.size(); i++)
	{
		//���һ�����͵�һ�����Ƿ����������֮ǰʵ�ڲ����жϣ��������
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