#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#define N 10000

using namespace std;

string necklace;
vector<int> ansSet;

int scanLeft(int startPos, int len)
{
	int totalLen = 0;
	int i = (startPos + len - 1) % len;
	int origI = i;
	bool first = true;
	bool setColor = false;
	char strColor = 0;
	while ((i != origI && !first) || first)
	{
		if (first)
			first = false;
		
		//颜色已决
		if (setColor)
		{
			if (necklace[i] == 'w' || necklace[i] == strColor)
				totalLen += 1;
			else
				break;
		}
		else
		{
			if (necklace[i] != 'w')
			{
				strColor = necklace[i];
				setColor = true;
			}
			totalLen += 1;
		}
		i = (i + len - 1) % len;
	}
	return totalLen;
}

int scanRight(int startPos, int len)
{
	int totalLen = 0;
	int i = (startPos + len) % len;
	bool first = true;
	bool setColor = false;
	char strColor = 0;

	while ((i != startPos && !first) || first)
	{
		if (first)
			first = false;
		//颜色已决
		if (setColor)
		{
			if (necklace[i] == 'w' || necklace[i] == strColor)
				totalLen += 1;
			else
				break;
		}
		else
		{
			if (necklace[i] != 'w')
			{
				strColor = necklace[i];
				setColor = true;
			}
			totalLen += 1;
		}
		i = (i + len + 1) % len;
	}
	return totalLen;
}

int solve()
{
	int len = necklace.length();
	int leftLen = 0, rightLen = 0;
	for (int i = 0; i < len; i++)
	{
		leftLen = scanLeft(i, len);
		rightLen = scanRight(i, len);
		ansSet.push_back(leftLen + rightLen);
	}
	return *max_element(ansSet.begin(), ansSet.end());
}

int main(int argc, char** argv)
{
	freopen("inp4.txt", "r", stdin);
	cin >> necklace;
	cout << solve() << endl;
	fclose(stdin);
	return 0;
}