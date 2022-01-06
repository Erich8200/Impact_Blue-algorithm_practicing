#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stdio.h>
#include <cctype>

using namespace std;

vector<string> wordList;
map<string, int> wordCount;

void getWordCount(string& s)
{
	string::iterator it1, it2;
	it1 = it2 = s.begin();
	//步出单词
	for (; it2 < s.end(); it2++)
	{
		if (isalpha(*it2))
			continue;//用外面for循环的条件作为守卫条件是安全的
		else
		{
			string temp;
			temp = s.substr(it1 - s.begin(), it2 - it1);
			for (string::iterator i = temp.begin(); i < temp.end(); i++)
				*i = toupper(*i);
			//wordList中还没有该单词
			//if (wordList.end() == find(wordList.begin(), wordList.end(), temp))
			if (0 == wordCount[temp])
			{
				wordCount[temp]++;
				wordList.push_back(temp);
			}
			else
				wordCount[temp]++;
			it1 = it2;
			//迭代器不能访问'\0'，一访问就报错...所以这里判断it1的下一个元素
			//步入单词
			while (!isalpha(*it1) && it1 + 1 < s.end())
				it1++;
			it2 = it1;
		}
	}
}

void output()
{
	//获取单词最大长度
	vector<int> wordLen;
	for (vector<string>::iterator it = wordList.begin(); it < wordList.end(); it++)
		wordLen.push_back(it->length());
	int maxLen = *max_element(wordLen.begin(), wordLen.end());

	//cout << maxLen << endl;

	//根据wordList中的顺序输出
	for (vector<string>::iterator it = wordList.begin(); it < wordList.end(); it++)
	{
		int len = it->length();
		int times = wordCount[*it];
		//输出前导空格
		for (int i = 0; i < maxLen - len; i++)
			cout << " ";
		//输出单词和冒号
		cout << *it << ":";
		//输出"*"
		for (int i = 0; i < times; i++)
			cout << "*";
		//输出wordCount中单词个数计数
		cout << times << endl;
	}
}

int main(int argc, char** argv)
{
	string s;
	getline(cin, s);
	getWordCount(s);
	output();
	//system("pause");
	return 0;
}