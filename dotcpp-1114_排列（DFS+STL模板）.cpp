#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <set>
#define N 4

using namespace std;

int num[N + 2];
vector< vector<int> > combs;//������ϵ���ϼ�

//��������ǰ��������ǰ��ϣ����������Ҫ�����ϳ���
void DFS(int curIndex, vector<int> comb, const int maxIndex, const int combLen)
{
	if (curIndex > maxIndex)
	{
		//��ѡ�������ָ�������Ҫ��ĸ���ʱ������һ������Ҫ��Ľ⣬����ǰ��Ϸ�����ϼ���
		if (comb.size() == combLen)
			combs.push_back(comb);
		return;
	}
	else if (comb.size() == combLen)
	{
		combs.push_back(comb);
		return;
	}
	else
	{
		comb.push_back(num[curIndex]);
		DFS(curIndex + 1, comb, maxIndex, combLen);//ѡ��ǰ��
		comb.pop_back();
		DFS(curIndex + 1, comb, maxIndex, combLen);//��ѡ��ǰ��
	}
	return;
}

bool cmp(int a, int b)
{
	return a < b;
}

void printCombPerm()
{
	for (int i = 0; i < combs.size(); i++)
	{
		sort(combs.at(i).begin(), combs.at(i).end(), cmp);//�Ϲ�أ�������
		do
		{
			for (vector<int>::iterator it = combs.at(i).begin(); it < combs.at(i).end(); it++)
			{
				cout << *it << " ";
			}
			cout << endl;
		} while (next_permutation(combs.at(i).begin(), combs.at(i).end()));
	}
}

int main(int argc, char** argv)
{
	for (int i = 0; i < 4; i++)
		cin >> num[i];
	vector<int> curComb;
	DFS(0, curComb, N - 1, 3);
	printCombPerm();
	system("pause");
	return 0;
}