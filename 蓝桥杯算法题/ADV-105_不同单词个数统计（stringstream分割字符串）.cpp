#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <algorithm>

using namespace std;

void splitStr(string origStr, char delim, vector<string>& strArr)
{
	stringstream ss(origStr);
	string temp;
	while (getline(ss, temp, delim))
		strArr.push_back(temp);
}

int solve(string origStr, set<string>& strList)
{
	stringstream ss(origStr);
	string temp;
	while (ss >> temp)
		strList.insert(temp);
	return strList.size();
}

int main()
{
	string str;
	getline(cin, str);
	set<string>* strList = new set<string>;
	cout << solve(str, *strList) << endl;
	delete strList;
	return 0;
}