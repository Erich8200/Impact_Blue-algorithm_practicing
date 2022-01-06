#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

void solve(int curNum, string& str)
{
	if (curNum == 0)
	{
		str += "2(0)";
		return;
	}
	else if (curNum == 1)
	{
		str += "2";
		return;
	}
	else if (curNum == 2)
	{
		str += "2(2)";
		return;
	}
	else
	{
		str += "2(";
		vector<int> digitSum;
		int n = curNum, i = 0;
		while (n)
		{
			if (n % 2 != 0)
				digitSum.push_back(i);
			n /= 2;
			i += 1;
		}
		reverse(digitSum.begin(), digitSum.end());
		for (vector<int>::iterator it = digitSum.begin(); it < digitSum.end(); it++)
		{
			solve(*it, str);
			if (it != --digitSum.end())
				str += "+";
		}
		str += ")";
	}
	return;
}

string refine(int n)
{
	if (n == 1)
		return "0";
	else
	{
		string s;
		solve(n, s);
		return s.substr(2, s.length() - 3);
	}
}

int main(int argc, char** argv)
{
	string s;
	int n = 0;
	cin >> n;
	cout << refine(n) << endl;
	system("pause");
	return 0;
}