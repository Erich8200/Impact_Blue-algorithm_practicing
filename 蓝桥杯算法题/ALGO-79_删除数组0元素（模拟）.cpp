#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> numSet;

void getNonZeroArray(int n)
{
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp != 0)
			numSet.push_back(temp);
	}
}

int main(int argc, char** argv)
{
	int n = 0;
	cin >> n;
	getNonZeroArray(n);
	for (vector<int>::iterator it = numSet.begin(); it < numSet.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << numSet.size() << endl;
	system("pause");
	return 0;
}