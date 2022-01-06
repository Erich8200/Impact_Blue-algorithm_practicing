#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

set<int> numSet;

int getReNum()
{
	int temp = 0;
	int reduntantNum = -1;
	while (cin >> temp)
	{
		if (numSet.find(temp) != numSet.end())
		{
			reduntantNum = temp;
		}
		else
			numSet.insert(temp);
	}
	return reduntantNum;
}

int getMisNum()
{
	int missingNum = -1;
	set<int>::iterator pre = numSet.begin();
	set<int>::iterator cur = ++numSet.begin();
	for (; cur != numSet.end(); pre++,cur++)
	{
		if (*cur != (*pre + 1))
		{
			missingNum = *pre + 1;
			return missingNum;
		}
	}
	return missingNum;
}

int main(int argc, char** argv)
{
	freopen("input2.txt", "r", stdin);
	int junk;
	cin >> junk;
	int reNum = getReNum();
	int misNum = getMisNum();
	cout << misNum << " " << reNum << endl;
	fclose(stdin);
	system("pause");
	return 0;
}