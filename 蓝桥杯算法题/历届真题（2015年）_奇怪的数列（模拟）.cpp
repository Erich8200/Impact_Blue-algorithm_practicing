#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

string intToString(int n)
{
	string str;
	while (n)
	{
		str += n % 10 + '0';
		n /= 10;
	}
	reverse(str.begin(), str.end());
	return str;
}

string translate(string str, int transTimes)
{
	int times = 0, index;
	while (times < transTimes)
	{
		string newStr;
		index = 0;
		while (index < str.length())
		{
			char curChar = str[index];
			int repTimes = 1;
			while (str[++index] == curChar)
				repTimes += 1;
			newStr += intToString(repTimes) + curChar;
		}
		times += 1;
		str = newStr;
	}
	return str;
}

int main(void)
{
	string str;
	int n;
	cin >> str >> n;
	cout << translate(str, n) << "\n";
	return 0;
}
