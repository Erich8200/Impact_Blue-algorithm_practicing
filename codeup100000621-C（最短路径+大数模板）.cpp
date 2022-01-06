#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <memory.h>

#define N 1002
#define INF 0x3FFFFFFF

using namespace std;

//�������� 
class BigInt {
private:
	int d[1000];
	int len;
public:
	BigInt() {
		memset(d, 0, 1000);
		len = 0;
	}
	BigInt(string str);
	BigInt(int n);
	void show();
	int getLen()
	{
		return this->len;
	}
	friend BigInt operator*(const BigInt& a, const BigInt& b);
	friend BigInt operator+(const BigInt& a, const BigInt& b);
};

int MIN;
bool vis[N] = { false };
int d[N];
int G[N][N];
vector<int> tempPath, optPath[N];//·����¼���� 
vector<int> pre[N];//Dijkstra�㷨���ɵ�ǰ������

BigInt::BigInt(string str)
{
	this->len = 0;
	memset(d, 0, 1000);
	for (string::iterator it = str.end() - 1;it >= str.begin();it--)
	{
		d[len++] = *it - '0';
	}
}

BigInt::BigInt(int n)
{
	this->len = 0;
	memset(d, 0, 1000);
	do
	{
		d[len++] = n % 10;
		n /= 10;
	} while (n > 0);
}

void BigInt::show()
{
	for (int i = len - 1;i >= 0;i--)
		cout << d[i];
}

//�����˷� 
BigInt operator*(const BigInt& a, const BigInt& b)
{
	BigInt c;
	c.len = a.len + b.len;
	int i, j;
	for (i = 0;i < a.len;i++)
		for (j = 0;j < b.len;j++)
			c.d[i + j] += a.d[i] * b.d[j];
	for (i = 0;i < c.len - 1;i++)
	{
		c.d[i + 1] += c.d[i] / 10;
		c.d[i] %= 10;
	}
	while (c.d[i])
	{
		c.d[i + 1] = c.d[i] / 10;
		c.d[i] %= 10;
		i++;
	}
	while (i >= 1 && !c.d[i]) i--;
	c.len = i + 1;
	return c;
}

//�����ӷ� 
BigInt operator+(const BigInt& a, const BigInt& b)
{
	BigInt c;
	int carry = 0;
	for (int i = 0;i < a.len || i < b.len;i++)
	{
		int temp = a.d[i] + b.d[i] + carry;
		carry = temp / 10;
		c.d[c.len++] = temp % 10;
	}
	if (carry != 0) c.d[c.len++] = carry;
	return c;
}

//�����˷� 
BigInt bigIntPow(int base, int power)
{
	BigInt ans(1);
	for (int i = 1;i <= power;i++)
		ans = ans * BigInt(base);
	return ans;
}

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

//ʹ��Dijkstra+DFS����ϣ�����Dijkstra��������·���� 
void Dijkstra(int s, int n)
{
	init(s);
	for (int i = 0;i < n;i++)
	{
		int u = -1;MIN = INF;
		for (int j = 0;j < n;j++)
		{
			if (!vis[j] && d[j] < MIN)
			{
				u = j; MIN = d[j];
			}
		}
		if (u == -1)	return;
		vis[u] = true;
		for (int v = 0;v < n;v++)
		{
			if (!vis[v] && G[u][v] != INF)
			{
			 //��׮��ʼ��ʹ�õ���Dijkstra+DFS��ģ�� 
				if (d[u] + G[u][v] < d[v])
				{
					d[v] = d[u] + G[u][v];
					pre[v].push_back(u);
				}
				else if (d[u] + G[u][v] == d[v])
				{
					pre[v].push_back(u);
				}
			}
		}
	}
	return;
}

//ʹ��DFS��������·����
//����1����ǰ�ݹ鶥���ţ���һ������ 
//����2����Ŀ�趨�Ŀ�ʼ�����ţ����ݹ��յ�
//����3����������ı�ţ����ݹ���㣬��ʼ����ʱ���һ��������ͬ����һ������ 
void DFS(int v, int st,const int& t)
{
	if (v == st)
	{
		tempPath.push_back(v);
		optPath[t] = tempPath;
		tempPath.pop_back();
		return;
	}
	else
	{
		tempPath.push_back(v);
		for (int i = 0;i < pre[v].size();i++)
		{
			DFS(pre[v][i], st, t);
		}
		tempPath.pop_back();
	}
}

BigInt calcTotalPath(int t)
{
 //���ж�optPath�ĳ��ȣ��������1˵������·�� 
	if (optPath[t].size() > 1)
	{
		BigInt ans(0);
		for (vector<int>::iterator it = optPath[t].begin();it < optPath[t].end() - 1;it++)
			ans = ans + bigIntPow(2, G[*it][*(it + 1)] - 1);//Ϊ����ִ��Dijkstraʱ����ʵ��0���֣��������Ǵ�1��ʼ�ģ��൱��ÿ���߶������1������Ҫ���������ȥ 
		return ans;
	}
	else
	{
	 //���optPath���Ȳ�����Ҫ��˵������Ϊ��ӵ�-1��һ����㣬�ͷ��س���Ϊ0�Ŀյ�BigInt���ͣ���ʾ�Ƿ� 
		BigInt errAns;
		return errAns;
	}
}

int main(int argc, char** argv)
{
	initG();
	int n = 0, m = 0, u = 0, v = 0;
	cin >> n >> m;
	for (int i = 1;i <= m;i++)
	{
		cin >> u >> v;
		G[u][v] = G[v][u] = i;
	}

	Dijkstra(0, n);

	int t = 1;

 //��⵽ÿһ�������·����¼���� 
	for (t = 1;t <= n-1;t++)
	{
		if (d[t] == INF)//ͨ��d[t]�ж��Ƿ���ͨ�������ͨ����optPath�ֶ�����һ��Ϊ-1�Ľ�� 
			optPath[t].push_back(-1);
		else
			DFS(t, 0, t); //����Ҫע�ⲻ��д��DFS(0,2);һ��Ҫд��(�յ�,���)����ʽ��������γ����޵ݹ� 
	}

 //��⵽ÿһ���������ʵ���� 
	for (t = 1;t <= n-1;t++)
	{
		BigInt ans = calcTotalPath(t);
		if (ans.getLen())
			ans.show();
		else
			cout << -1;
		cout << endl;
	}

	return 0;
}

