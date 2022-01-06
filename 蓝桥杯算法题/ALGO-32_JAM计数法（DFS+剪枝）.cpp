#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <stdio.h>
#define N 27

using namespace std;

vector<string> strSet;

void DFS(char curAlpha,const char maxAlpha, string curStr, vector<string>& strSet, const int len, const string& startStr)
{
	static int count;
	static bool gotStartStr = false;
	if (count >= 5)
		return;
	else if (curStr.length() == len)
	{
		strSet.push_back(curStr);
		if (curStr == startStr)
			gotStartStr = true;
		else if (gotStartStr)
			count += 1;
		return;
	}
	else if (curAlpha > maxAlpha)
		return;
	else
	{
		string bakStr = curStr;
		curStr += curAlpha;
		DFS(curAlpha + 1, maxAlpha, curStr, strSet, len, startStr);
		curStr = bakStr;
		DFS(curAlpha + 1, maxAlpha, curStr, strSet, len, startStr);
	}
}

int main(int argc, char** argv)
{
	int s = 0, t = 0, len = 0;
	string startStr;
	cin >> s >> t >> len;
	cin >> startStr;
	string str;
	DFS('a' + s - 1, 'a' + t - 1, str, strSet, len, startStr);
	for (vector<string>::iterator it = strSet.end() - 5; it < strSet.end(); it++)
		cout << *it << endl;
	return 0;
}