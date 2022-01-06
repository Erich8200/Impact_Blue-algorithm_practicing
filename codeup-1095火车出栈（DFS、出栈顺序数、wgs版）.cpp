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

void DFS(int curNum, const int maxNum, stack<int> s)//curNum表示1到curNum-1已经放入了栈中,curNum没有,本层递归结束的时候，curNum一定入栈中 
{
	//print(s); 
	if (curNum > maxNum)//结束 
	{
		bool allStored = true;
		for (int i = maxNum; i >= 1; i--)
			if (!stored[i])
				allStored = false;
		if (allStored)// 类似cur==n的功能 
		{
			ansCount += 1;
			return;
		}
		return;//结束 
	}
	else//可以继续放数的情况，说明栈中不为空，存有数据，可以对数据进行出栈操作  | 存数的操作 
	{
		stored[curNum] = true;
		while (true)
		{
			s.push(curNum);//进栈一个数 
			DFS(curNum + 1, maxNum, s);
			s.pop();
			if (!s.empty()) s.pop();//出栈一个数
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