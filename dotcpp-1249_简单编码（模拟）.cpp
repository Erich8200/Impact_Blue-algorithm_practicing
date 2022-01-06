#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <math.h>

#define N 67

using namespace std;

int main(int argc, char** argv)
{
	string input;
	vector<string> output;
	while (cin >> input)
	{
		if (input == "END")
		{
			break;
		}
		for (string::iterator it = input.begin(); it < input.end(); it++)
		{
			if (*it == 'A' || *it == 'W' || *it == 'F')
				*it = 'I';
			else if (*it == 'D' || *it == 'P' || *it == 'G' || *it == 'B')//D£¬P£¬G£¬B
				*it = 'e';
			else if (*it == 'C')
				*it = 'L';
			else if (*it == 'M')
				*it = 'o';
			else if (*it == 'S')
				*it = 'v';
			else if (*it == 'L')
				*it = 'Y';
			else if (*it == 'X')
				*it = 'u';
		}
		output.push_back(input);
	}
	
	for (vector<string>::iterator it = output.begin(); it < output.end(); it++)
	{
		cout << *it << endl;
	}

	system("pause");
	return 0;
}