#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

//校验字串是否能够成为周期字串的函数
int checkCyc(string& str, string& subString)
{
	int group = 0, more = 0;
	int strLen = str.length(), subLen = subString.length();
	more = strLen % subLen;
	group = strLen / subLen;
	//位数不对立即退出
	if ((more) != 0)
		return 0;
	else
	{
		int offset = 0;
		for (int i = 1; i <= group; i++)
		{
			offset = str.find(subString, offset);
			if (offset != subLen*(i-1))
				return 0;
			offset += 1;
		}
		return subLen;
	}
}

int getT(string& str)
{
	for (int i = 1; i <= str.length()/2; i++)
	{
		string sub = str.substr(0, i);
		int t = 0;
		//校验当前长度的子串是否能够称为周期字符串
		if ((t = checkCyc(str, sub)))
			return t;//校验成功立刻返回
	}
	return str.length();
}

int main()
{
	freopen("input10.txt", "r", stdin);
	string s;
	cin >> s;
	cout << getT(s) << endl;
	//system("pause");
	fclose(stdin);
	return 0;
}