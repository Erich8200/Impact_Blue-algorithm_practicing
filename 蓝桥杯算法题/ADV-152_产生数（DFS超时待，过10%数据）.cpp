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
	//�ݹ����ʱ����ǰ�����浽���������
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
				DFS(cur + 1, curNum, n);//�й��򣬵��ǲ��޸�
				bak = curNum[i];
				curNum[i] = rule.second;
				DFS(cur + 1, curNum, n);//�й����޸�
				curNum[i] = bak;
			}
			else
			{
				DFS(cur + 1, curNum, n);//û�й���Ͳ��޸�
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
	//���ܰѹ������map�У���Ϊӳ����һ�Զ��
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