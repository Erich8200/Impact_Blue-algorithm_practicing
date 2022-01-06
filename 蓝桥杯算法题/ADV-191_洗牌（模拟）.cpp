#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>

using namespace std;

void splitStr(string str, char c, vector<string>& strList)
{
	int index1 = 0;
	int index2 = index1;
	int len = str.length();
	while (index1 < len && (index2 = str.find(c, index1)) != string::npos)
	{
		string temp = str.substr(index1, index2 - index1);
		strList.push_back(temp);
		index1 = index2 + 1;
	}
	if (index1 < len)
	{
		string temp = str.substr(index1, len - index1);
		strList.push_back(temp);
	}
	remove(strList.begin(), strList.end(), "");
	//strList.shrink_to_fit();
}

int main()
{
	string temp;
	vector<string> cardArr, washedCardArr;

	while (getline(cin, temp))
		splitStr(temp, ' ', cardArr);

	if (cardArr.size() < 52)
	{
		cout << -1;
		return 1;
	}

	for (int i = 0; i < 52; i++)
	{
		string curCard = cardArr[i];
		int curCardNo = 0;
		if (curCard == "10")
			curCardNo = 10;
		else if (curCard == "J")
			curCardNo = 11;
		else if (curCard == "Q")
			curCardNo = 12;
		else if (curCard == "K")
			curCardNo = 13;
		else
			curCardNo = curCard[0] - '0';

		if (washedCardArr.size() >= curCardNo)
			washedCardArr.insert(washedCardArr.begin() + curCardNo, curCard);
		else
			washedCardArr.push_back(curCard);
	}

	for (vector<string>::iterator it = washedCardArr.begin(); it < washedCardArr.end(); it++)
		cout << *it << " ";
	cout << endl;

	return 0;
}