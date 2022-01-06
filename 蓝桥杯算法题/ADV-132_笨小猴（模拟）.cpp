#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stdio.h>

using namespace std;

map<char,int> letterCount;

bool isPrime(const int n)
{
	bool ret = true;
	if (n == 1)
		return false;
	else if (n == 0)
		return false;
	else
	{
		for (int i = 2; i*i <= n; i++)
		{
			if (n%i == 0)
				ret = false;
		}
	}
	return ret;
}

void getLetterCount(string& s)
{
	for (string::iterator it = s.begin(); it < s.end(); it++)
		letterCount[*it]++;
}

void getMinMax(int& min, int& max)
{
	max = 1;
	//对于map的迭代器，要使用!=运算符，<不能再使用
	for (map<char, int>::iterator it = letterCount.begin(); it != letterCount.end(); it++)
		if (it->second > max)
			max = it->second;

	min = max;
	for (map<char, int>::iterator it = letterCount.begin(); it != letterCount.end(); it++)
		if (it->second < min && it->second >= 1)
			min = it->second;
	
}

int main(int argc, char** argv)
{
	string word;
	//初始化map映射表
	/*for (int i = 0; i < 26; i++)
		letterCount['a' + i] = 0;*/
	cin >> word;	

	getLetterCount(word);

	int min = 0, max = 0;
	getMinMax(min, max);

	if (isPrime(max - min))
		cout << "Lucky Word" << "\n" << max - min;
	else
		cout << "No Answer" << "\n" << 0;

	system("pause");
	return 0;
}