#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef struct Id {
	string idNo;
	string date;
};

vector<Id> idArr;

bool cmp(Id a, Id b)
{
	if (a.date > b.date)
		return true;
	else if (a.date == b.date)
	{
		if (a.idNo > b.idNo)
			return true;
	}
	return false;
}

int main(int argc, char** argv)
{
	freopen("input0.txt", "r", stdin);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		string date = temp.substr(6, 8);
		Id id;
		id.idNo = temp;
		id.date = date;
		idArr.push_back(id);
	}
	sort(idArr.begin(), idArr.end(), cmp);
	//for (vector<Id>::iterator it = idArr.begin(); it < idArr.end(); it++)
	//	cout << it->idNo << endl;
	for (int i = 0; i < idArr.size(); i++)
	{
		printf("%s\n", idArr.at(i).idNo.c_str());
	}
	fclose(stdin);
	return 0;
}