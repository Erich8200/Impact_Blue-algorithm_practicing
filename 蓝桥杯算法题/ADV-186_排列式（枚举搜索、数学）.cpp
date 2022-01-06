#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef struct Expression {
	int c;//乘积
	int a;//较小的乘数
	int b;//较大的乘数
};

vector<Expression> ans;

bool cmp(Expression a, Expression b)
{
	if (a.c < b.c)
		return true;
	else if (a.c == b.c)
	{
		if (a.a < b.a)//次级条件
			return true;
		else
			return false;
	}
	else
		return false;
}

bool check(int n)
{
	bool ret = true;
	bool vis[10] = { false };
	while (n)
	{
		int curNum = n % 10;
		if (vis[curNum] || curNum == 0)
		{
			ret = false;
			break;
		}
		vis[curNum] = true;
		n /= 10;
	}
	return ret;
}

void pushNumToSet(int n, set<int>& s)
{
	while (n)
	{
		int curNum = n % 10;
		s.insert(curNum);
		n /= 10;
	}
}

void solve()
{
	//1位乘以4位
	for (int a = 1; a <= 9; a++)
	{
		for (int b = 1000; b <= 9999; b++)
		{
			if (!check(b))
				continue;
			int c = a*b;
			if (c > 9999)
				break;
			set<int> numSet;
			pushNumToSet(a, numSet);
			pushNumToSet(b, numSet);
			pushNumToSet(c, numSet);
			if (numSet.size() == 9)
			{
				if (find(numSet.begin(), numSet.end(), 0) == numSet.end())
				{
					Expression expr;
					expr.a = a;
					expr.b = b;
					expr.c = c;
					ans.push_back(expr);
				}
			}
		}
	}

	//2位乘以3位
	for (int a = 10; a <= 99; a++)
	{
		if (!check(a))
			continue;
		for (int b = 100; b <= 999; b++)
		{
			if (!check(b))
				continue;
			int c = a*b;
			if (c > 9999) 
				break;
			set<int> numSet;
			pushNumToSet(a, numSet);
			pushNumToSet(b, numSet);
			pushNumToSet(c, numSet);
			if (numSet.size() == 9)
			{
				if (find(numSet.begin(), numSet.end(), 0) == numSet.end())
				{
					Expression expr;
					expr.a = a;
					expr.b = b;
					expr.c = c;
					ans.push_back(expr);
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	solve();
	sort(ans.begin(), ans.end(), cmp);
	for (vector<Expression>::iterator it = ans.begin(); it < ans.end(); it++)
		cout << it->c << " = " << it->a << " x " << it->b << endl;
	system("pause");
 	return 0;
}