#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<int> A;

void chooseSort(vector<int>::iterator start)
{
	if (start == A.end())
		return;
	vector<int>::iterator nextElem = ++start;
	--start;
	vector<int>::iterator minElem = min_element(start, A.end());
	int temp = *minElem;
	*minElem = *start;
	*start = temp;
	printf("swap(a[%d], a[%d]):", start - A.begin(), minElem - A.begin());
	for (int i = 0; i < A.size(); i++)
		printf("%d ", A[i]);
	printf("\n");
	chooseSort(nextElem);
}

int main(int argc, char** argv)
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		A.push_back(temp);
	}
	chooseSort(A.begin());
	return 0;
}