#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

//У���ִ��Ƿ��ܹ���Ϊ�����ִ��ĺ���
int checkCyc(string& str, string& subString)
{
	int group = 0, more = 0;
	int strLen = str.length(), subLen = subString.length();
	more = strLen % subLen;
	group = strLen / subLen;
	//λ�����������˳�
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
		//У�鵱ǰ���ȵ��Ӵ��Ƿ��ܹ���Ϊ�����ַ���
		if ((t = checkCyc(str, sub)))
			return t;//У��ɹ����̷���
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