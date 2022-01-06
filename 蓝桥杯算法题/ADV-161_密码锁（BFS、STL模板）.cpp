#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef struct Status {
	string str;
	int step;
} Status;

unordered_set<string> strStatus;

int BFS(string str)
{
	queue<Status> Q;
	Status root;
	root.str = str;
	root.step = 0;
	Q.push(root);
	while (!Q.empty())
	{
		Status node = Q.front();
		Q.pop();
		if (node.str.find("2012") != string::npos)
			return node.step;	
		for (int i = 0; i < node.str.length()-1; i++)
		{
			string curStr = node.str;
			char temp = curStr[i];
			curStr[i] = curStr[i + 1];
			curStr[i + 1] = temp;
			if (strStatus.find(curStr) == strStatus.end())
			{
				strStatus.insert(curStr);
				Status newNode;
				newNode.str = curStr;
				newNode.step = node.step + 1;
				Q.push(newNode);
			}
		}
	}
	return -1;
}

int main(int argc, char** argv)
{
	int n = 0;
	string str;
	cin >> n;
	cin >> str;
	cout << BFS(str) << endl;
	return 0;
}