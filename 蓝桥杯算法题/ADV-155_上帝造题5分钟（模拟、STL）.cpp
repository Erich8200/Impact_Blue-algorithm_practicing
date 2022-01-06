#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> numArr;

bool cmp(int a, int b)
{
	return a < b;
}

int main(void)
{
	freopen("input0.txt", "r", stdin);
	int n, Q;
	cin >> n >> Q;
	for (int i = 0; i < n; i++)
	{
		int n = 0;
		cin >> n;
		numArr.push_back(n);
	}
	
	while (Q--)
	{
		int l = 0, h = 0;
		cin >> l >> h;
		vector<int> temp = numArr;
		sort(temp.begin() + l, temp.begin() + h + 1, cmp);
		cout << *(temp.begin() + l) << endl;
	}
	
	fclose(stdin);
	return 0;
}
