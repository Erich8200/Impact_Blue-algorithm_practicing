#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <memory.h>

#define N 1002
#define INF 0x3FFFFFFF

using namespace std;

//大数定义 
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
vector<int> tempPath, optPath[N];//路径记录数组 
vector<int> pre[N];//Dijkstra算法生成的前驱数组

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

//大数乘法 
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

//大数加法 
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

//大数乘方 
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

//使用Dijkstra+DFS的组合，先用Dijkstra生成最优路径树 
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
			 //插桩开始，使用的是Dijkstra+DFS的模板 
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

//使用DFS遍历最优路径树
//参数1：当前递归顶点编号，是一个变量 
//参数2：题目设定的开始顶点编号，即递归终点
//参数3：结束顶点的编号，即递归起点，初始传入时与第一个参数相同，是一个常量 
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
 //先判断optPath的长度，如果大于1说明存在路径 
	if (optPath[t].size() > 1)
	{
		BigInt ans(0);
		for (vector<int>::iterator it = optPath[t].begin();it < optPath[t].end() - 1;it++)
			ans = ans + bigIntPow(2, G[*it][*(it + 1)] - 1);//为了在执行Dijkstra时和真实的0区分，边输入是从1开始的，相当于每条边都多加了1，所以要在这里减回去 
		return ans;
	}
	else
	{
	 //如果optPath长度不满足要求，说明是认为添加的-1这一个结点，就返回长度为0的空的BigInt类型，表示非法 
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

 //求解到每一个顶点的路径记录数组 
	for (t = 1;t <= n-1;t++)
	{
		if (d[t] == INF)//通过d[t]判断是否连通，如果不通，则将optPath手动增加一个为-1的结点 
			optPath[t].push_back(-1);
		else
			DFS(t, 0, t); //这里要注意不能写成DFS(0,2);一定要写成(终点,起点)的形式，否则会形成无限递归 
	}

 //求解到每一个顶点的真实距离 
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

