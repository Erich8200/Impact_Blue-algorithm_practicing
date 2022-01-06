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
	//��������
	for (; it2 < s.end(); it2++)
	{
		if (isalpha(*it2))
			continue;//������forѭ����������Ϊ���������ǰ�ȫ��
		else
		{
			string temp;
			temp = s.substr(it1 - s.begin(), it2 - it1);
			for (string::iterator i = temp.begin(); i < temp.end(); i++)
				*i = toupper(*i);
			//wordList�л�û�иõ���
			//if (wordList.end() == find(wordList.begin(), wordList.end(), temp))
			if (0 == wordCount[temp])
			{
				wordCount[temp]++;
				wordList.push_back(temp);
			}
			else
				wordCount[temp]++;
			it1 = it2;
			//���������ܷ���'\0'��һ���ʾͱ���...���������ж�it1����һ��Ԫ��
			//���뵥��
			while (!isalpha(*it1) && it1 + 1 < s.end())
				it1++;
			it2 = it1;
		}
	}
}

void output()
{
	//��ȡ������󳤶�
	vector<int> wordLen;
	for (vector<string>::iterator it = wordList.begin(); it < wordList.end(); it++)
		wordLen.push_back(it->length());
	int maxLen = *max_element(wordLen.begin(), wordLen.end());

	//cout << maxLen << endl;

	//����wordList�е�˳�����
	for (vector<string>::iterator it = wordList.begin(); it < wordList.end(); it++)
	{
		int len = it->length();
		int times = wordCount[*it];
		//���ǰ���ո�
		for (int i = 0; i < maxLen - len; i++)
			cout << " ";
		//������ʺ�ð��
		cout << *it << ":";
		//���"*"
		for (int i = 0; i < times; i++)
			cout << "*";
		//���wordCount�е��ʸ�������
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