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
	//�ݹ����ʱ����ǰ�����浽���������
	if (cur > n)
	{
		ans.insert(curNum);
		return;
	}
	for (int i = 0; i < curNum.length(); i++)
	{
		char bak;

		//�й���
		if (rules.find(curNum.at(i)) != rules.end())//�Ѿ���O(1)���ҹ�����
		{
			DFS(cur + 1, curNum, n);//���ǲ��޸�
			bak = curNum[i];
			//������޸�
			auto rule = rules.at(curNum.at(i));
			for (vector<char>::iterator it = rule.begin(); it < rule.end(); it++)
			{
				curNum[i] = *it;
				DFS(cur + 1, curNum, n);//�޸�
				curNum[i] = bak;
			}
		}
		else
		{
			DFS(cur + 1, curNum, n);//û�й���Ͳ��޸�
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
	//���ܰѹ������map�У���Ϊӳ����һ�Զ�ģ���л�ر���ǿ�ٻ��޵�����
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