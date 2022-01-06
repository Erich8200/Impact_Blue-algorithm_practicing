#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <memory.h>

#define N 22

using namespace std;

string strData[N];
vector<string> result;
int useTime[N];

void initUseTime()
{
	for (int i = 0;i < N;i++)
	{
		useTime[i] = 2;
	}
}

void DFS(string preWord, string curStr, const int n)
{
	static bool isFirstTime = true;
	for (int i = 0;i < n;i++)
	{
		for (int startPos = preWord.length()-1;startPos >= 0;startPos--)
		{
			string preWordTail = preWord.substr(startPos);
			if (useTime[i] > 0)
			{
				if (strData[i].find(preWordTail) == 0)
				{
					if (strData[i].find(preWord) != string::npos)
					{
						if (isFirstTime)
						{
							isFirstTime = false;
							useTime[i]--;
							DFS(strData[i], curStr + strData[i].substr(preWordTail.length()), n);
							useTime[i]++;
						}
					}
					else
					{
						useTime[i]--;
						DFS(strData[i], curStr + strData[i].substr(preWordTail.length()), n);
						useTime[i]++;
					}
				}
			}
		}
	}
	result.push_back(curStr);
	return;
}

int getAnswer()
{
	int ans = 0;
	for (vector<string>::iterator it = result.begin();it < result.end();it++)
	{
		if (ans < (*it).length())
		{
			ans = (*it).length();
		}
	}
	return ans;
}

int main(int argc, char** argv)
{
	initUseTime();

	int n = 0;
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		string temp;
		cin >> temp;
		strData[i] = temp;
	}

	//输入开始字母
	char c;
	cin >> c;
	char cStr[2] = { 0 };
	cStr[0] = c;

	//初始参数为最后一个输入的字符
	string curStr = string(cStr);
	DFS(cStr, curStr, n);

	cout << getAnswer();

	return 0;
}
