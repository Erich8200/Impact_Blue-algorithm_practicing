#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip> //C++输出格式控制 
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	string str = "0";
	string newStr;
	int n = 0;
	cin >> n;
	while (n--)
	{
		for (string::iterator it = str.begin(); it < str.end(); it++)
		{
			if (*it == '0')
				newStr += '1';
			else if (*it == '1')
				newStr += "01";
		}
		str = newStr;
		newStr = "";
	}
	cout << str << endl;
	system("pause");
	return 0;
}