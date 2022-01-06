#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

map<int, vector<char> > rules;
set<string> ans;

void DFS(int cur, string curNum, const int n)
{
	//递归结束时将当前数保存到结果集合中
	if (cur > n)
	{
		ans.insert(curNum);
		return;
	}
	for (int i = 0; i < curNum.length(); i++)
	{
		char bak;

		//有规则
		if (rules.find(curNum.at(i)) != rules.end())//已经是O(1)的找规则了
		{
			DFS(cur + 1, curNum, n);//但是不修改
			bak = curNum[i];
			//逐规则修改
			auto rule = rules.at(curNum.at(i));
			for (vector<char>::iterator it = rule.begin(); it < rule.end(); it++)
			{
				curNum[i] = *it;
				DFS(cur + 1, curNum, n);//修改
				curNum[i] = bak;
			}
		}
		else
		{
			DFS(cur + 1, curNum, n);//没有规则就不修改
			bak = curNum[i];
		}
	}
}

int main(int argc, char** argv)
{
	freopen("input2.txt", "r", stdin);
	string n;
	int k = 0;
	char x = 0, y = 0;
	cin >> n >> k;
	//不能把规则放在map中，因为映射是一对多的，感谢地表最强召唤兽的提醒
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		vector<int> temp;
		rules[x].push_back(y);
	}
	DFS(0, n, n.length());
	cout << ans.size() << endl;
	system("pause");
	fclose(stdin);
	return 0;
}