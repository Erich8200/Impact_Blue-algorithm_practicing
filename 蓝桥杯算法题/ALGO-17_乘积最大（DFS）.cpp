#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector< vector<int> > arrSet;

int strToInt(string str)
{
	int ans = 0;
	for (string::iterator it = str.begin(); it < str.end(); it++)
	{
		ans *= 10;
		ans += *it - '0';
	}
	return ans;
}

void DFS(int curPartCount, const int partCount, int curLen, const int totalLen, vector<int> splitArr, vector< vector<int> >& splitArrSet)
{
	if (curLen == totalLen)
	{
		if (curPartCount == partCount)
			splitArrSet.push_back(splitArr);
		return;
	}
	else
	{
		for (int i = 1; i <= totalLen - curLen; i++)
		{
			splitArr.push_back(i);
			DFS(curPartCount + 1, partCount, curLen + i, totalLen, splitArr, splitArrSet);
			splitArr.pop_back();
		}
		return;
	}
}

int solve(int n, int k, string& str)
{
	vector<int> splitArr;
	int ans = 0;
	DFS(0, k + 1, 0, n, splitArr, arrSet);
	for (int i = 0; i < arrSet.size(); i++)
	{
		int temp = 1, startPos = 0;
		for (int j = 0; j < k + 1; j++)
		{
			int len = arrSet[i][j];
			temp *= strToInt(str.substr(startPos, len));
			startPos = startPos + len;
		}
		if (ans < temp)
			ans = temp;
	}
	return ans;
}

int main(int argc, char** argv)
{
	int n = 0, k = 0;
	cin >> n >> k;
	string str;
	cin >> str;
	cout << solve(n, k, str) << endl;
	system("pause");
	return 0;
}