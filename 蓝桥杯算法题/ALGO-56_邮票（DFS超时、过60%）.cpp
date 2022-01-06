#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stamps;

bool DFS(int curIndex, int curNum, int curVal, const int maxNum, const int tgtVal)
{
	if (curNum > maxNum)
		return false;
	else if (curVal == tgtVal)
		return true;
	else if (curVal > tgtVal)
		return false;
	else if (curIndex >= (int)stamps.size())
		return false;
	else
	{
		bool ret = false;
		ret = DFS(curIndex + 1, curNum + 1, curVal + stamps[curIndex + 1], maxNum, tgtVal);
		if (ret)
			return ret;
		else
		{
			ret = DFS(curIndex + 1, curNum, curVal, maxNum, tgtVal);
			if (ret)
				return ret;
		}
		return ret;
	}
}

bool cmp(int a, int b)
{
	return a < b;
}

void getStamps(int n, int m)
{
	for (int type = 0; type < m; type++)
	{
		int val = 0;
		cin >> val;
		for (int i = 1; i <= n; i++)
			stamps.push_back(val);
	}
	sort(stamps.begin(), stamps.end(), cmp);
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	getStamps(n, m);
	
	int ans = 0;
	int i = 1;
	while(DFS(-1, 0, 0, n, i))
		ans = ++i;
	if (ans)
		cout << ans - 1 << "\n";
	else
		cout << ans << "\n";
	return 0;
}
