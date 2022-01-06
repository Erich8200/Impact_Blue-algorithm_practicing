#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Item{
public:
	int p, g;
	double pPerG;
	Item(){
	}
	Item(int g, int p) : g(g), p(p){
		pPerG = 1.0*p/g;
	}
};

vector<Item> itemArr;

bool cmp(Item a, Item b)
{
	return a.pPerG > b.pPerG;
}

int main(void)
{
	freopen("input7.txt", "r", stdin);
//不是01背包...
//	int n, w;
//	cin >> n >> w;
//	for (int i = 0; i < n; i++)
//		cin >> g[i] >> p[i];
//	for (int i = 0; i < n; i++)
//		for (int j = w; j >= g[i]; j--)
//			dp[j] = dp[j] > dp[j - g[i]] + p[i] ? dp[j]: dp[j - g[i]] + p[i];
//	cout << dp[w - 1] << endl;

	//部分背包，使用贪心解决
	int n, w;
	cin >> n >> w;
	for (int i = 0; i < n; i++)
	{
		int g, p;
		cin >> g >> p;
		itemArr.push_back(Item(g, p));
	}

	sort(itemArr.begin(), itemArr.end(), cmp);

	double ans = 0;
	vector<Item>::iterator it = itemArr.begin();
	while(w && it < itemArr.end())
	{
		int itemG = it->g;
		if (w > itemG)
		{
			w -= itemG;
			ans += it->p;
		}
		else
		{
			ans += it->pPerG * w;
			w -= w;
		}
		it++;
	}
	
	printf("%.1lf\n", ans);

	fclose(stdin);
	return 0;
}
