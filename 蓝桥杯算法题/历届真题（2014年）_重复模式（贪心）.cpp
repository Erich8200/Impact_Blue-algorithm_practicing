#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>

using namespace std;

int solve(string& str)
{
	int strLen = str.length();
	for (int len = strLen - 1; len >= 1; len--)
	{
		for (int i = 0; i < strLen; i++)
		{
			if (len + i > strLen)
				break;
			string t = str.substr(i, len);
			int times = 0;
			int findIndex = 0;
			while ((findIndex = str.find(t, findIndex)) != string::npos)
			{
				times += 1;
				findIndex += 1;
				if (findIndex >= strLen)
					break;
			}
			if (times >= 2)
				return t.length();
		}
	}
}

int main(void)
{
	string str;
	cin >> str;
	cout << solve(str) << endl;
	system("pause");
	return 0;
}
