#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> rec;

int main()
{
	string str;
	cin >> str;
	for (string::iterator it = str.begin(); it < str.end(); it++)
		rec[*it] += 1;

	for (string::iterator it = str.begin(); it < str.end();)
	{
		if (rec[*it] > 1)
			it = str.erase(it);
		else
			it++;
	}

	cout << str << endl;
	system("pause");
	return 0;
}