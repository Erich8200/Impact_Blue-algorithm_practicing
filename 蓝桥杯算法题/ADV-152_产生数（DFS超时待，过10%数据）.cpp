#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector< pair<char, char> > rules;
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
		pair<char, char> rule;
		for (int j = 0; j < rules.size(); j++)
		{
			rule = rules.at(j);
			if (rule.first == curNum.at(i))
			{
				DFS(cur + 1, curNum, n);//有规则，但是不修改
				bak = curNum[i];
				curNum[i] = rule.second;
				DFS(cur + 1, curNum, n);//有规则，修改
				curNum[i] = bak;
			}
			else
			{
				DFS(cur + 1, curNum, n);//没有规则就不修改
				bak = curNum[i];
			}

		}
	}
}

int main(int argc, char** argv)
{
	freopen("input1.txt", "r", stdin);
	string n;
	int k = 0;
	char x = 0, y = 0;
	cin >> n >> k;
	//不能把规则放在map中，因为映射是一对多的
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		pair<char, char> temp(x, y);
		rules.push_back(temp);
		
	}
	DFS(0, n, n.length());
	cout << ans.size() << endl;
	system("pause");
	fclose(stdin);
	return 0;
}