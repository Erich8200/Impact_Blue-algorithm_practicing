#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

vector< pair<string, int> > colourList;

bool checkUnique(const string& s)
{
	bool unique = true;
	for (int i = 0; i < colourList.size(); i++)
	{
		if (colourList[i].first == s)
		{
			unique = false;
			break;
		}
	}
	return unique;
}

void addColorCount(const string& color)
{
	for (vector< pair<string, int> >::iterator it = colourList.begin(); it < colourList.end(); it++)
	{
		if ((*it).first == color)
		{
			(*it).second += 1;
		}
	}
}

bool cmp(pair<string, int> a, pair<string, int> b)
{
	bool ret = false;
	if (a.second > b.second)
		ret = true;
	else if (a.second == b.second)
	{
		if (a.first < b.first)
		{
			ret = true;
		}
	}
	return ret;
}

void output()
{
	int maxCount = colourList[0].second;
	for (vector< pair<string, int> >::iterator it = colourList.begin(); it < colourList.end(); it++)
	{
		if ((*it).second == maxCount)
		{
			cout << (*it).first << endl;
		}
	}
}

int main(int argc, char** argv)
{
	//freopen("input1.txt", "r", stdin);
	int n = 0;
	cin >> n;
	getchar();
	string temp;
	for (int i = 0; i < n; i++)
	{
		getline(cin, temp);
		if (checkUnique(temp))
		{
			pair<string, int> newColor(temp, 1);
			colourList.push_back(newColor);
		}
		else
		{
			addColorCount(temp);
		}
	}
	sort(colourList.begin(), colourList.end(), cmp);
	output();
	//fclose(stdin);
	//system("pause");
	return 0;
}
