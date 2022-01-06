#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define N 24

bool stored[N + 2];
int ansCount;

using namespace std;
void print(stack<int> s)
{
	cout << "stackSize=" << s.size() << "  ";
	while (!s.empty())
	{
		int temp = s.top();
		s.pop();
		cout << "stac[i]=" << temp << "  ";
	}
	cout << endl;
}

void DFS(int curNum, const int maxNum, stack<int> s)//curNum��ʾ1��curNum-1�Ѿ�������ջ��,curNumû��,����ݹ������ʱ��curNumһ����ջ�� 
{
	//print(s); 
	if (curNum > maxNum)//���� 
	{
		bool allStored = true;
		for (int i = maxNum; i >= 1; i--)
			if (!stored[i])
				allStored = false;
		if (allStored)// ����cur==n�Ĺ��� 
		{
			ansCount += 1;
			return;
		}
		return;//���� 
	}
	else//���Լ��������������˵��ջ�в�Ϊ�գ��������ݣ����Զ����ݽ��г�ջ����  | �����Ĳ��� 
	{
		stored[curNum] = true;
		while (true)
		{
			s.push(curNum);//��ջһ���� 
			DFS(curNum + 1, maxNum, s);
			s.pop();
			if (!s.empty()) s.pop();//��ջһ����
			else break;
		}
	}
}

int main(int argc, char** argv)
{
	stack<int> s;
	int m;
	cin >> m;
	DFS(1, m, s);
	cout << ansCount << endl;
	system("pause");
	return 0;
}