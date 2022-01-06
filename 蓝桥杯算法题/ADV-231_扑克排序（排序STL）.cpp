#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

string cards[5];
map<char, int> valMap;
map<char, int> colMap;

bool cmp(string a, string b)
{
	if (valMap[a[0]] < valMap[b[0]])	
		return true;
	else if (valMap[a[0]] == valMap[b[0]])
	{
		if (colMap[a[1]] < colMap[b[1]]) 
			return true;
		else 
			return false;
	}
	else 
		return false;
}

int main()
{
	freopen("0.txt", "r", stdin);
	for (int i = 0; i < 5; i++)
	{
		char c1, c2;
		c1 = getchar();
		c2 = getchar();
		cards[i] += c1;
		cards[i] += c2;
	}

	for (int i = 2; i <= 10; i++)
		valMap[i + '0'] = i;
	valMap['J'] = 11;
	valMap['Q'] = 12;
	valMap['K'] = 13;
	valMap['A'] = 14;

	colMap['d'] = 0;
	colMap['c'] = 1;
	colMap['h'] = 2;
	colMap['s'] = 3;

	sort(cards, cards + 5, cmp);

	for (int i = 0; i < 5; i++)
		cout << cards[i] << " ";

	fclose(stdin);
	return 0;
}