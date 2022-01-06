#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

#define N 100

using namespace std;

int element[N + 2];
vector<int> sortArr;

void printArr()
{
	for (vector<int>::iterator it = sortArr.begin(); it < sortArr.end(); it++)
		cout << *it << " ";
	cout << endl;
}

void insertSort(const int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << "Insert  element[" << i << "]:" << endl;
		int tmp = element[i];
		sortArr.push_back(tmp);
		cout << "  Init:";
		printArr();
		int j;
		for (j = sortArr.size() - 2; j >= 0; j--)
		{
			if (sortArr[j] > tmp)
			{
				sortArr[j + 1] = sortArr[j];
				cout << "  Move  back:";
				printArr();
			}
			else
			{
				break;
			}
		}
		//注意这段要写在内层循环外！
		sortArr[j + 1] = tmp;
		cout << "  Final:";
		printArr();
	}
}

int main(int argc, char** argv)
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> element[i];
	insertSort(n);
	return 0;
}
