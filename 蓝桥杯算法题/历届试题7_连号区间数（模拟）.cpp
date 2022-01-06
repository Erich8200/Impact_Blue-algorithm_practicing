#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numSet;

int getContiSection()
{
	int max, min;
	int contiSecCount = 0;
	for (int i = 0; i < numSet.size(); i++)
	{
		min = max = numSet[i];
		//标记j向前移动的同时，获取区间最大值和最小值
		for (int j = i; j < numSet.size(); j++)
		{
			if (numSet[j] < min)
				min = numSet[j];
			if (numSet[j] > max)
				max = numSet[j];
			if (max - min + 1 == j - i + 1)
				contiSecCount += 1;
		}
	}
	return contiSecCount;
}

int main(int argc, char** argv)
{
	int n = 0, ans = 0, temp = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		numSet.push_back(temp);
	}
	ans = getContiSection();
	cout << ans << endl;
	system("pause");
	return 0;
}