#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

const int N = 50;
//int a[N];

using namespace std;

bool comp(int a, int b)
{
	return a < b;
}

//默认由小到大排序
void BinSearch(vector<int> a, int low, int high, int mid, const int target,int& pos)
{
	if (low > high) return;
	else if (a[mid] == target) { pos = mid; return; }
	else if (a[mid] < target) BinSearch(a, mid + 1, high, (mid + high + 1) / 2, target,  pos);
	else BinSearch(a, low, mid - 1, (mid + low - 1) / 2, target, pos);
}

int BinSearchBasic(vector<int> a, int low, int high, int target)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (a[mid] == target) return mid;
		else if (a[mid] > target) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}

int main(int argc, char** argv)
{
	vector<int> a;
	for (int i = N - 1; i >= 0; i--)
		a.push_back(i);

	sort(a.begin(), a.end(), comp);

	int pos = -1;
	BinSearch(a, 0, N - 1, (N - 1) / 2, 26,pos );
	cout << pos << endl;

	getchar();
	return 0;
}