#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <set>
#define N 25

using namespace std;

int importance[N + 2];
int value[N + 2];
vector<long long> maxProducts;

//参数：当前物品索引，当前价值，物品数量，总金额，最大乘积
void DFS(int curIndex, int curValue, long long curProduct, const int n, const int maxValue, long long & maxProduct)
{
	if (curIndex >= n)
	{
		if (curProduct > maxProduct && curValue <= maxValue)//这里要限制，不能超过最大金额
		{
			maxProduct = curProduct;
		}
		return;
	}
	else if(curValue > maxValue)
	{
		return;
	}
	else
	{
		DFS(curIndex + 1, curValue + value[curIndex], curProduct + importance[curIndex] * value[curIndex], n, maxValue, maxProduct);
		DFS(curIndex + 1, curValue, curProduct, n, maxValue, maxProduct);
	}
	return;
}

int main(int argc, char** argv)
{
	int n = 0, m = 0;
	cin >> n >> m;
	int v = 0, p = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> v >> p;
		value[i] = v;
		importance[i] = p;
	}

	long long ans = 0;
	DFS(0, 0, 0, m, n, ans);
	cout << ans << endl;
	return 0;
}