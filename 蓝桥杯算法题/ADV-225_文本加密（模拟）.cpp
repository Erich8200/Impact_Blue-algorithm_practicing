#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

string keyArr;

int main(void)
{
	string str;
	getline(cin, str);
	
	for (char ch = 'A'; ch <= 'Z'; ch++)
		keyArr.push_back(ch);
		
	for (char ch = 'a'; ch <= 'z'; ch++)
		keyArr.push_back(ch);
	
	for (string::iterator it = str.begin(); it < str.end(); it++)
	{
		switch(isalpha(*it))
		{
		case 1:
			if (*it == 'Z')
				*it = 'a';
			else
			   *it += 1;
			break;
		case 2:
			if (*it == 'z')
				*it = 'A';
			else
			   *it += 1;
			break;
		}
	}
	cout << str << endl;
	return 0;
}
